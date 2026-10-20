#include "ReShade.fxh"

uniform bool RemoveHUDBothSides <
    ui_label = "Remove HUD On Both Sides";
    ui_tooltip = "ON: left = raw SceneClean, right = processed clean scene. OFF: left = untouched game final, right = processed final with restored HUD.";
> = true;

uniform float SplitPosition <
    ui_label = "Split Position";
    ui_type = "slider";
    ui_min = 0.0; ui_max = 1.0;
> = 0.5;

uniform bool ShowDivider <
    ui_label = "Show Divider";
> = true;

uniform float DividerWidth <
    ui_label = "Divider Width";
    ui_type = "drag";
    ui_min = 1.0; ui_max = 8.0; ui_step = 0.5;
    ui_units = "px";
> = 2.0;

uniform float3 DividerColor <
    ui_label = "Divider Color";
    ui_type = "color";
> = float3(1.0, 1.0, 1.0);

uniform float SplitFeather <
    ui_label = "Split Feather";
    ui_type = "drag";
    ui_min = 0.0; ui_max = 0.05; ui_step = 0.0005;
> = 0.0;

uniform bool ACZSceneCleanFresh <
    source = "acz_scene_clean_fresh";
>;

uniform bool ACZOriginalFinalFresh <
    source = "acz_original_final_fresh";
>;

uniform bool ACZProcessedCleanFresh <
    source = "acz_processed_clean_fresh";
>;

texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;
texture2D ACZOriginalFinalTex : ACZ_ORIGINAL_FINAL;
texture2D ACZProcessedCleanTex : ACZ_PROCESSED_CLEAN;

sampler2D ACZSceneCleanSampler
{
    Texture = ACZSceneCleanTex;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MinFilter = POINT;
    MagFilter = POINT;
    MipFilter = POINT;
};

sampler2D ACZOriginalFinalSampler
{
    Texture = ACZOriginalFinalTex;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MinFilter = POINT;
    MagFilter = POINT;
    MipFilter = POINT;
};

sampler2D ACZProcessedCleanSampler
{
    Texture = ACZProcessedCleanTex;
    AddressU = CLAMP;
    AddressV = CLAMP;
    MinFilter = POINT;
    MagFilter = POINT;
    MipFilter = POINT;
};

float4 PS_ACZBeforeAfter(
    float4 position : SV_Position,
    float2 texcoord : TEXCOORD) : SV_Target
{
    const float4 currentFinal = tex2D(ReShade::BackBuffer, texcoord);

    // Fail safe: never display stale bridge textures.
    if (!ACZSceneCleanFresh || !ACZOriginalFinalFresh)
        return currentFinal;

    float3 leftColor;
    float3 rightColor;

    if (RemoveHUDBothSides)
    {
        leftColor = tex2D(ACZSceneCleanSampler, texcoord).rgb;

        if (!ACZProcessedCleanFresh)
            return currentFinal;

        rightColor = tex2D(ACZProcessedCleanSampler, texcoord).rgb;
    }
    else
    {
        leftColor = tex2D(ACZOriginalFinalSampler, texcoord).rgb;
        rightColor = currentFinal.rgb;
    }

    float3 result;

    if (SplitFeather <= 0.000001)
    {
        result = texcoord.x < SplitPosition ? leftColor : rightColor;
    }
    else
    {
        const float blend = smoothstep(
            SplitPosition - SplitFeather,
            SplitPosition + SplitFeather,
            texcoord.x);
        result = lerp(leftColor, rightColor, blend);
    }

    if (ShowDivider)
    {
        const float halfWidth =
            0.5 * DividerWidth * BUFFER_RCP_WIDTH;

        if (abs(texcoord.x - SplitPosition) <= halfWidth)
            result = DividerColor;
    }

    return float4(result, currentFinal.a);
}

technique ACZBeforeAfter <
    ui_tooltip = "ACZ-specific before/after split. Keep this technique LAST.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZBeforeAfter;
    }
}
