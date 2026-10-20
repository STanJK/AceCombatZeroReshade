#include "ReShade.fxh"

// ACZLighting.fx
// Conservative screen-space lighting layer for ACZ.
//
// Current design intentionally avoids any dependency on a real sun direction.
// Enabled by default:
//   - near-field aircraft mask
//   - Fresnel clearcoat
//   - very weak camera-relative environment sheen
//   - very weak near-field SSIL/color bleed
//
// A manual directional shape-light is available for experiments, but defaults
// to OFF until a trustworthy ACZ sun/light direction is recovered.

uniform int DebugView <
    ui_label = "Debug View";
    ui_type = "combo";
    ui_items = "Final\0Aircraft Mask\0Normals\0Fresnel\0Near SSIL\0";
> = 0;

// -----------------------------------------------------------------------------
// Near-field / aircraft admission
// -----------------------------------------------------------------------------

uniform float AircraftDepthStart <
    ui_label = "Aircraft Depth Start";
    ui_type = "drag";
    ui_min = 0.0; ui_max = 0.25; ui_step = 0.001;
    ui_category = "Aircraft Mask";
> = 0.000;

uniform float AircraftDepthEnd <
    ui_label = "Aircraft Depth End";
    ui_type = "drag";
    ui_min = 0.001; ui_max = 0.50; ui_step = 0.001;
    ui_category = "Aircraft Mask";
> = 0.080;

uniform float AircraftMaskPower <
    ui_label = "Aircraft Mask Power";
    ui_type = "slider";
    ui_min = 0.25; ui_max = 4.0;
    ui_category = "Aircraft Mask";
> = 1.0;

uniform float DepthEdgeReject <
    ui_label = "Depth Edge Reject";
    ui_tooltip = "Suppresses lighting around strong depth discontinuities to reduce sky/terrain halos.";
    ui_type = "drag";
    ui_min = 0.0; ui_max = 0.05; ui_step = 0.0005;
    ui_category = "Aircraft Mask";
> = 0.008;

// -----------------------------------------------------------------------------
// Clearcoat / environment sheen
// -----------------------------------------------------------------------------

uniform bool EnableClearcoat <
    ui_label = "Enable Clearcoat";
    ui_category = "Clearcoat";
> = true;

uniform float ClearcoatStrength <
    ui_label = "Clearcoat Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 0.20;
    ui_category = "Clearcoat";
> = 0.030;

uniform float ClearcoatPower <
    ui_label = "Clearcoat Fresnel Power";
    ui_type = "slider";
    ui_min = 1.0; ui_max = 10.0;
    ui_category = "Clearcoat";
> = 5.0;

uniform bool EnableEnvironmentSheen <
    ui_label = "Enable Environment Sheen";
    ui_category = "Environment Sheen";
> = true;

uniform float EnvironmentStrength <
    ui_label = "Environment Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 0.15;
    ui_category = "Environment Sheen";
> = 0.025;

uniform float3 SkyTint <
    ui_label = "Sky Tint";
    ui_type = "color";
    ui_category = "Environment Sheen";
> = float3(0.45, 0.60, 0.82);

uniform float3 GroundTint <
    ui_label = "Ground Tint";
    ui_type = "color";
    ui_category = "Environment Sheen";
> = float3(0.24, 0.25, 0.23);

// -----------------------------------------------------------------------------
// Near-field SSIL / color bleed
// -----------------------------------------------------------------------------

uniform bool EnableNearSSIL <
    ui_label = "Enable Near-field SSIL";
    ui_tooltip = "Very short-range bilateral color bleed, depth-limited to the near field.";
    ui_category = "Near-field SSIL";
> = true;

uniform float SSILRadiusPixels <
    ui_label = "SSIL Radius";
    ui_type = "slider";
    ui_min = 1.0; ui_max = 24.0;
    ui_units = "px";
    ui_category = "Near-field SSIL";
> = 6.0;

uniform float SSILStrength <
    ui_label = "SSIL Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 0.15;
    ui_category = "Near-field SSIL";
> = 0.020;

uniform float SSILSaturation <
    ui_label = "SSIL Color Saturation";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.5;
    ui_category = "Near-field SSIL";
> = 0.70;

uniform float SSILDepthTolerance <
    ui_label = "SSIL Depth Tolerance";
    ui_tooltip = "Relative depth difference accepted for nearby bounce samples.";
    ui_type = "slider";
    ui_min = 0.02; ui_max = 1.0;
    ui_category = "Near-field SSIL";
> = 0.28;

// -----------------------------------------------------------------------------
// Manual shape light - deliberately disabled by default
// -----------------------------------------------------------------------------

uniform bool EnableManualShapeLight <
    ui_label = "Enable Manual Shape Light";
    ui_tooltip = "Experimental camera-relative directional relight. Keep OFF until a reliable ACZ sun direction is available.";
    ui_category = "Manual Shape Light";
> = false;

uniform float ShapeLightAzimuth <
    ui_label = "Azimuth";
    ui_type = "drag";
    ui_min = -180.0; ui_max = 180.0; ui_step = 1.0;
    ui_units = "deg";
    ui_category = "Manual Shape Light";
> = 35.0;

uniform float ShapeLightElevation <
    ui_label = "Elevation";
    ui_type = "drag";
    ui_min = -89.0; ui_max = 89.0; ui_step = 1.0;
    ui_units = "deg";
    ui_category = "Manual Shape Light";
> = 35.0;

uniform float ShapeLightStrength <
    ui_label = "Shape Light Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 0.25;
    ui_category = "Manual Shape Light";
> = 0.040;

// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

float ACZLuminance(float3 color)
{
    return dot(color, float3(0.2126, 0.7152, 0.0722));
}

float ACZDepth(float2 uv)
{
    return ReShade::GetLinearizedDepth(uv);
}

float3 ACZViewPosition(float2 uv, float depth)
{
    // Match the same projection-free reconstruction used by ReShade's
    // DisplayDepth normal debug path. Exact FOV is intentionally not assumed.
    return float3(uv - 0.5, 1.0) * depth;
}

float3 ACZScreenNormal(float2 uv)
{
    // Keep this reconstruction intentionally identical to ReShade's
    // DisplayDepth.fx GetScreenSpaceNormal(), except that we return the
    // signed [-1,+1] normal rather than its display-encoded [0,1] value.
    const float3 offset =
        float3(BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT, 0.0);

    const float2 posCenter = uv;
    const float2 posNorth  = posCenter - offset.zy;
    const float2 posEast   = posCenter + offset.xz;

    const float3 vertCenter =
        float3(posCenter - 0.5, 1.0) *
        ACZDepth(posCenter);

    const float3 vertNorth =
        float3(posNorth - 0.5, 1.0) *
        ACZDepth(posNorth);

    const float3 vertEast =
        float3(posEast - 0.5, 1.0) *
        ACZDepth(posEast);

    return normalize(
        cross(
            vertCenter - vertNorth,
            vertCenter - vertEast));
}

float ACZAircraftMask(float2 uv, float centerDepth)
{
    const float endDepth =
        max(AircraftDepthEnd, AircraftDepthStart + 0.0001);

    float mask =
        1.0 - smoothstep(
            AircraftDepthStart,
            endDepth,
            centerDepth);

    mask = pow(saturate(mask), AircraftMaskPower);

    // Most of the screen is sky/terrain. Avoid the four extra edge-depth
    // taps entirely when the center pixel is outside the near-field mask.
    if (mask <= 0.000001)
        return 0.0;

    if (DepthEdgeReject > 0.000001)
    {
        const float2 px =
            float2(BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT);

        const float dL = ACZDepth(uv - float2(px.x, 0.0));
        const float dR = ACZDepth(uv + float2(px.x, 0.0));
        const float dU = ACZDepth(uv - float2(0.0, px.y));
        const float dD = ACZDepth(uv + float2(0.0, px.y));

        float edge =
            max(
                max(abs(dL - centerDepth), abs(dR - centerDepth)),
                max(abs(dU - centerDepth), abs(dD - centerDepth)));

        const float edgeMask =
            1.0 - smoothstep(
                DepthEdgeReject,
                DepthEdgeReject * 2.0,
                edge);

        mask *= edgeMask;
    }

    return saturate(mask);
}

void ACZAccumulateSSIL(
    float2 sampleUV,
    float centerDepth,
    inout float3 colorSum,
    inout float weightSum)
{
    const float sampleDepth = ACZDepth(sampleUV);

    const float endDepth =
        max(AircraftDepthEnd, AircraftDepthStart + 0.0001);

    const float nearMask =
        1.0 - smoothstep(
            AircraftDepthStart,
            endDepth * 1.15,
            sampleDepth);

    const float relativeDepth =
        abs(sampleDepth - centerDepth) /
        max(centerDepth, 0.001);

    const float depthWeight =
        1.0 - smoothstep(
            SSILDepthTolerance * 0.5,
            SSILDepthTolerance,
            relativeDepth);

    const float weight =
        saturate(nearMask * depthWeight);

    colorSum +=
        tex2D(ReShade::BackBuffer, sampleUV).rgb *
        weight;

    weightSum += weight;
}

float3 ACZNearSSIL(
    float2 uv,
    float centerDepth,
    float3 source)
{
    const float2 px =
        float2(BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT) *
        SSILRadiusPixels;

    float3 sum = 0.0;
    float weight = 0.0;

    ACZAccumulateSSIL(uv + float2( 1.000,  0.000) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2(-1.000,  0.000) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2( 0.000,  1.000) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2( 0.000, -1.000) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2( 0.707,  0.707) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2(-0.707,  0.707) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2( 0.707, -0.707) * px, centerDepth, sum, weight);
    ACZAccumulateSSIL(uv + float2(-0.707, -0.707) * px, centerDepth, sum, weight);

    if (weight < 0.001)
        return 0.0;

    const float3 average = sum / weight;
    const float averageLuma = ACZLuminance(average);

    // Keep most of the effect as color bleed rather than a generic brightness
    // lift, since qUINT MXAO already provides broad SSIL in the current stack.
    const float3 colored =
        lerp(
            averageLuma.xxx,
            average,
            SSILSaturation);

    const float3 positiveDifference =
        max(colored - source, 0.0);

    return lerp(
        colored * 0.20,
        positiveDifference,
        0.80);
}

float3 ACZManualLightDirection()
{
    const float degToRad = 0.017453292519943295;
    const float az = ShapeLightAzimuth * degToRad;
    const float el = ShapeLightElevation * degToRad;

    return normalize(
        float3(
            cos(el) * sin(az),
            -sin(el),
            cos(el) * cos(az)));
}

// -----------------------------------------------------------------------------
// Main pass
// -----------------------------------------------------------------------------

float4 PS_ACZLighting(
    float4 position : SV_Position,
    float2 uv : TEXCOORD) : SV_Target
{
    const float4 original =
        tex2D(ReShade::BackBuffer, uv);

    const float depth = ACZDepth(uv);
    const float aircraftMask =
        ACZAircraftMask(uv, depth);

    if (DebugView == 1)
        return float4(aircraftMask.xxx, 1.0);

    // Final mode is intentionally cheap away from the aircraft/near field.
    // Normal reconstruction and the SSIL taps only run for admitted pixels.
    if (aircraftMask <= 0.000001 && DebugView == 0)
        return original;

    const float3 rawNormal =
        ACZScreenNormal(uv);

    const float3 viewRay =
        normalize(float3(uv - 0.5, 1.0));

    // Keep debug output bit-for-bit comparable to ReShade DisplayDepth.
    // Only the lighting path gets a camera-facing orientation fix.
    float3 normal = rawNormal;
    if (dot(normal, viewRay) < 0.0)
        normal = -normal;

    const float noV =
        saturate(dot(normal, viewRay));

    const float fresnel =
        pow(
            saturate(1.0 - noV),
            ClearcoatPower);

    float3 color = original.rgb;
    float3 ssilContribution = 0.0;

    if (EnableNearSSIL &&
        SSILStrength > 0.000001 &&
        aircraftMask > 0.000001)
    {
        ssilContribution =
            ACZNearSSIL(
                uv,
                depth,
                color);

        color +=
            ssilContribution *
            SSILStrength *
            aircraftMask;
    }

    if (EnableManualShapeLight &&
        ShapeLightStrength > 0.000001 &&
        aircraftMask > 0.000001)
    {
        const float3 lightDir =
            ACZManualLightDirection();

        const float noL =
            saturate(dot(normal, lightDir));

        // Center the relight around zero so it shapes rather than simply
        // brightening the whole aircraft.
        const float shape =
            (noL - 0.5) *
            2.0 *
            ShapeLightStrength *
            aircraftMask;

        color *= max(1.0 + shape, 0.0);
    }

    if (EnableEnvironmentSheen &&
        EnvironmentStrength > 0.000001 &&
        aircraftMask > 0.000001)
    {
        const float3 reflection =
            reflect(viewRay, normal);

        // View-space Y is only a camera-relative approximation for now.
        // Keep the default strength intentionally tiny.
        const float skyFactor =
            saturate(
                0.5 -
                0.5 * reflection.y);

        const float3 environment =
            lerp(
                GroundTint,
                SkyTint,
                skyFactor);

        const float broadSheen =
            0.10 +
            0.90 * pow(
                saturate(1.0 - noV),
                2.0);

        color +=
            environment *
            EnvironmentStrength *
            broadSheen *
            aircraftMask;
    }

    if (EnableClearcoat &&
        ClearcoatStrength > 0.000001 &&
        aircraftMask > 0.000001)
    {
        color +=
            fresnel *
            ClearcoatStrength *
            aircraftMask;
    }

    if (DebugView == 2)
        return float4(rawNormal * 0.5 + 0.5, 1.0);

    if (DebugView == 3)
        return float4(fresnel.xxx, 1.0);

    if (DebugView == 4)
        return float4(saturate(ssilContribution * 8.0), 1.0);

    return float4(color, original.a);
}

technique ACZLighting <
    ui_tooltip = "Near-field ACZ lighting enhancement: depth-limited clearcoat, environment sheen and short-range SSIL. Manual directional relight is experimental and OFF by default.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZLighting;
    }
}
