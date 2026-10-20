#include "ReShade.fxh"

uniform bool DisplayRaw <
    ui_label = "Display Raw";
    ui_tooltip = "Show the clean scene captured immediately before the first ACZ HUD draw.";
> = false;

texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;

sampler2D ACZSceneCleanSampler
{
    Texture = ACZSceneCleanTex;
};

float4 PS_ACZSceneClean(
    in float4 position : SV_Position,
    in float2 texcoord : TEXCOORD) : SV_Target
{
    if (DisplayRaw)
        return tex2D(ACZSceneCleanSampler, texcoord);

    return tex2D(ReShade::BackBuffer, texcoord);
}

technique ACZSceneClean <
    ui_tooltip = "Debug view for ACZRenderBridge SceneClean capture.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZSceneClean;
    }
}
