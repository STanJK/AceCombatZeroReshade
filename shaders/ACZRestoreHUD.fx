#include "ReShade.fxh"

uniform bool ACZSceneCleanFresh <
    source = "acz_scene_clean_fresh";
>;

uniform bool ACZOriginalFinalFresh <
    source = "acz_original_final_fresh";
>;

uniform float HUDMaskLow <
    ui_type = "drag";
    ui_min = 0.0000;
    ui_max = 0.1000;
    ui_step = 0.0005;
    ui_label = "HUD Mask Low";
    ui_tooltip = "Difference below this threshold is treated as scene, not HUD.";
> = 0.0025;

uniform float HUDMaskHigh <
    ui_type = "drag";
    ui_min = 0.0005;
    ui_max = 0.2000;
    ui_step = 0.0005;
    ui_label = "HUD Mask High";
    ui_tooltip = "Difference above this threshold is treated as HUD.";
> = 0.0150;

uniform float HUDMaskDilate <
    ui_type = "slider";
    ui_min = 0.0;
    ui_max = 1.0;
    ui_label = "HUD Mask 1px Dilate";
    ui_tooltip = "Expands the detected HUD mask by one pixel to catch anti-aliased edges.";
> = 0.0;

uniform float HUDRestoreStrength <
    ui_type = "slider";
    ui_min = 0.0;
    ui_max = 1.0;
    ui_label = "HUD Restore Strength";
> = 1.0;

uniform bool ShowHUDMask <
    ui_label = "Show HUD Mask";
    ui_tooltip = "Debug view: white pixels are restored from the untouched game frame.";
> = false;

texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;
texture2D ACZOriginalFinalTex : ACZ_ORIGINAL_FINAL;

sampler2D ACZSceneCleanSampler
{
    Texture = ACZSceneCleanTex;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MagFilter = POINT;
    MinFilter = POINT;
    MipFilter = POINT;
};

sampler2D ACZOriginalFinalSampler
{
    Texture = ACZOriginalFinalTex;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MagFilter = POINT;
    MinFilter = POINT;
    MipFilter = POINT;
};

float3 ACZQuantizeCleanToHDR10Target(float3 clean)
{
    // ACZRouteSceneClean writes the FP16 SceneClean texture into the game's
    // R10G10B10A2_UNORM HDR target. Reproduce that target-domain conversion
    // before comparing against OriginalFinal so 10-bit quantization itself
    // does not become a false HUD signal.
    clean = saturate(clean);
    return floor(clean * 1023.0 + 0.5) / 1023.0;
}

float ACZHUDDifference(float2 uv)
{
    float3 original =
        tex2D(ACZOriginalFinalSampler, uv).rgb;
    float3 clean =
        ACZQuantizeCleanToHDR10Target(
            tex2D(ACZSceneCleanSampler, uv).rgb);

    float3 delta = abs(original - clean);
    return max(delta.r, max(delta.g, delta.b));
}

float ACZHUDMask(float2 uv)
{
    float signal = ACZHUDDifference(uv);

    if (HUDMaskDilate > 0.001)
    {
        const float2 px =
            float2(BUFFER_RCP_WIDTH, BUFFER_RCP_HEIGHT);

        float neighbor = 0.0;
        neighbor = max(neighbor, ACZHUDDifference(uv + float2( px.x, 0.0)));
        neighbor = max(neighbor, ACZHUDDifference(uv + float2(-px.x, 0.0)));
        neighbor = max(neighbor, ACZHUDDifference(uv + float2(0.0,  px.y)));
        neighbor = max(neighbor, ACZHUDDifference(uv + float2(0.0, -px.y)));

        signal = lerp(signal, max(signal, neighbor), HUDMaskDilate);
    }

    const float high = max(HUDMaskHigh, HUDMaskLow + 0.0001);
    return smoothstep(HUDMaskLow, high, signal);
}

float4 PS_ACZRestoreHUD(
    in float4 position : SV_Position,
    in float2 texcoord : TEXCOORD) : SV_Target
{
    float4 processed =
        tex2D(ReShade::BackBuffer, texcoord);

    if (!ACZSceneCleanFresh || !ACZOriginalFinalFresh)
        return processed;

    const float mask = ACZHUDMask(texcoord);

    if (ShowHUDMask)
        return float4(mask, mask, mask, 1.0);

    float4 original =
        tex2D(ACZOriginalFinalSampler, texcoord);

    const float restore =
        saturate(mask * HUDRestoreStrength);

    float4 result =
        lerp(processed, original, restore);

    result.a = processed.a;
    return result;
}

technique ACZRestoreHUD <
    ui_tooltip = "Restores untouched ACZ HUD pixels after all SceneClean post-processing. Keep this technique LAST.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZRestoreHUD;
    }
}
