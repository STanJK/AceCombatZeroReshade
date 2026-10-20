#include "ReShade.fxh"

// ACZ / BF3 photographic-reference baseline.
// Reimplements the clean-room BF3-Render-Stack tone-curve + 32^3 LUT core.
// Includes both the exact SDR-oriented reference path and an ACZ HDR-safe
// path that keeps BF3 chroma/crosstalk while preserving source luminance.

uniform float BF3ExposureEV <
    ui_label = "Exposure EV";
    ui_type = "drag";
    ui_min = -4.0; ui_max = 4.0; ui_step = 0.01;
> = 0.0;

uniform int BF3Mode <
    ui_label = "Mode";
    ui_type = "combo";
    ui_items = "Exact BF3 Reference\0HDR-Safe BF3 Character\0";
> = 1;

uniform float BF3ColorCharacter <
    ui_label = "HDR-Safe Color Character";
    ui_tooltip = "How much BF3 hue/saturation/channel-crosstalk character to keep while preserving ACZ luminance.";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 1.0;

uniform float BF3ToneCharacter <
    ui_label = "HDR-Safe Tone Character";
    ui_tooltip = "0 preserves ACZ luminance/HDR. 1 uses BF3 reference luminance response while keeping the HDR-safe chroma split.";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 0.0;

uniform float BF3HighlightPreserve <
    ui_label = "Highlight Preserve";
    ui_tooltip = "Blends bright HDR regions back toward the ACZ source to protect highlight energy and gamut.";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 0.85;

uniform float BF3HighlightStart <
    ui_label = "Highlight Preserve Start";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 0.55;

uniform float BF3Strength <
    ui_label = "Overall Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 1.0;

uniform float BF3LUTStrength <
    ui_label = "LUT Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 1.0;

uniform bool BF3Vignette <
    ui_label = "BF3 Vignette";
> = true;

uniform float BF3VignetteStrength <
    ui_label = "Vignette Strength";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 1.0;

texture2D BF3ColorGradingTexture <
    source = "BF3_ColorGrading_32.tga";
>
{
    Width = 1024;
    Height = 32;
    Format = RGBA8;
    MipLevels = 1;
};

sampler2D BF3ColorGradingSampler
{
    Texture = BF3ColorGradingTexture;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    MipFilter = POINT;
    SRGBTexture = false;
};

float3 BF3ToneCurve(float3 x)
{
    x = max(x, 0.0);

    const float3 r1 = 0.985521 * x;
    const float3 r2 = 0.985521 * x + 0.058662;
    const float3 numerator = r1 * r2;

    const float3 d1 = 0.774597 * x + 0.048281;
    const float3 d2 = 0.774597 * x + 1.242710;
    const float3 denominator = d1 * d2;

    float3 y = sqrt(max(numerator / denominator, 0.0));

    // 32^3 voxel-center mapping recovered in BF3-Render-Stack:
    // 0 -> 0.5/32, 1 -> 31.5/32.
    return y * 0.96875 + 0.015625;
}

float3 SampleBF3LUT(float3 coord)
{
    coord = saturate(coord);

    // The converter stores the volume as 32 Z slices laid left-to-right,
    // each slice being 32x32 with X=R and Y=G.
    const float z = coord.b * 31.0;
    const float z0 = floor(z);
    const float z1 = min(z0 + 1.0, 31.0);
    const float fz = z - z0;

    const float x = coord.r * 31.0;
    const float y = coord.g * 31.0;

    const float2 uv0 = float2(
        (z0 * 32.0 + x + 0.5) / 1024.0,
        (y + 0.5) / 32.0);

    const float2 uv1 = float2(
        (z1 * 32.0 + x + 0.5) / 1024.0,
        (y + 0.5) / 32.0);

    const float3 c0 = tex2D(BF3ColorGradingSampler, uv0).rgb;
    const float3 c1 = tex2D(BF3ColorGradingSampler, uv1).rgb;
    return lerp(c0, c1, fz);
}

float3 ApplyBF3Vignette(float3 color, float2 uv)
{
    const float2 delta = (uv - 0.5) * float2(1.5, 1.5);
    const float radius2 = dot(delta, delta);
    const float q = radius2 * radius2;
    const float amount = q * 0.5 * BF3VignetteStrength;
    const float3 vignetteColor = float3(0.000, 0.007, 0.013);
    return color * (1.0 + amount * (vignetteColor - 1.0));
}

float ACZLuminance(float3 color)
{
    return dot(color, float3(0.2126, 0.7152, 0.0722));
}

float3 BuildHDRSafeBF3(
    float3 sourceHDR,
    float3 exactBF3)
{
    const float epsilon = 1e-4;

    const float sourceLuma =
        max(ACZLuminance(sourceHDR), epsilon);
    const float bf3Luma =
        max(ACZLuminance(exactBF3), epsilon);

    // Split each image into luminance and normalized chroma direction.
    // The BF3 term retains the 3D LUT's hue shifts, saturation compression
    // and channel crosstalk without inheriting its SDR luminance compression.
    float3 sourceChroma =
        sourceHDR / sourceLuma;
    float3 bf3Chroma =
        exactBF3 / bf3Luma;

    // Guard pathological ratios in almost-black texels.
    sourceChroma = min(sourceChroma, 8.0);
    bf3Chroma = min(bf3Chroma, 8.0);

    const float3 chroma =
        lerp(
            sourceChroma,
            bf3Chroma,
            BF3ColorCharacter);

    // ToneCharacter=0 is the true HDR-preserving baseline.
    const float outLuma =
        lerp(
            sourceLuma,
            bf3Luma,
            BF3ToneCharacter);

    float3 result = chroma * outLuma;

    // Protect the brightest ACZ regions from gamut excursions/clipping.
    // This is deliberately based on the source domain rather than BF3's
    // already-compressed result.
    const float highlightSignal =
        max(sourceHDR.r, max(sourceHDR.g, sourceHDR.b));
    const float highlightMask =
        smoothstep(
            BF3HighlightStart,
            1.0,
            highlightSignal) *
        BF3HighlightPreserve;

    result = lerp(
        result,
        sourceHDR,
        highlightMask);

    return max(result, 0.0);
}

float4 PS_ACZBF3Reference(
    float4 position : SV_Position,
    float2 texcoord : TEXCOORD) : SV_Target
{
    const float3 source =
        tex2D(ReShade::BackBuffer, texcoord).rgb;

    // BF3 captured colorScale is essentially unity.
    const float exposure = exp2(BF3ExposureEV);
    const float3 hdr =
        max(
            source * exposure * 1.0000065565,
            0.0);

    const float3 lutCoord =
        BF3ToneCurve(hdr);
    const float3 lutColor =
        SampleBF3LUT(lutCoord);

    // Exact recovered BF3 photographic result before vignette.
    const float3 exactBF3 =
        lerp(
            saturate(lutCoord),
            lutColor,
            BF3LUTStrength);

    float3 graded;

    if (BF3Mode == 0)
    {
        graded = exactBF3;
    }
    else
    {
        graded =
            BuildHDRSafeBF3(
                hdr,
                exactBF3);
    }

    if (BF3Vignette)
        graded =
            ApplyBF3Vignette(
                graded,
                texcoord);

    return float4(
        lerp(
            source,
            graded,
            BF3Strength),
        1.0);
}

technique ACZBF3Reference <
    ui_tooltip = "BF3 photographic grade. Exact mode reproduces the recovered SDR-oriented reference path; HDR-Safe mode preserves ACZ luminance while retaining BF3 color character.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZBF3Reference;
    }
}
