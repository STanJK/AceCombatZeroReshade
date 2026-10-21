#include "ReShade.fxh"

uniform bool DisplayRaw <
    ui_label = "Display Raw";
    ui_tooltip = "Show the clean scene captured immediately before the first ACZ HUD draw.";
> = false;

uniform bool ACZSceneCleanFresh <
    source = "acz_scene_clean_fresh";
>;

uniform bool ACZGameControlActive <
    source = "acz_gamecontrol_active";
    ui_label = "GameControl Active";
    ui_tooltip = "Diagnostic raw ACZ lifecycle/control flag at acz.exe+0x32C933. Read-only; not used for gating yet.";
    noedit = true;
>;

texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;

sampler2D ACZSceneCleanSampler
{
    Texture = ACZSceneCleanTex;
};

float4 PS_ACZSceneClean(
    in float4 position : SV_Position,
    in float2 texcoord : TEXCOORD) : SV_Target
{
    if (DisplayRaw && ACZSceneCleanFresh)
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
