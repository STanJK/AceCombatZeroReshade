#include "ReShade.fxh"

uniform bool ACZSceneCleanFresh <
    source = "acz_scene_clean_fresh";
>;

texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;

sampler2D ACZSceneCleanSampler
{
    Texture = ACZSceneCleanTex;
};

float4 PS_ACZRouteSceneClean(
    in float4 position : SV_Position,
    in float2 texcoord : TEXCOORD) : SV_Target
{
    if (ACZSceneCleanFresh)
    {
        float4 clean = tex2D(ACZSceneCleanSampler, texcoord);
        clean.a = 1.0;
        return clean;
    }

    return tex2D(ReShade::BackBuffer, texcoord);
}

technique ACZRouteSceneClean <
    ui_tooltip = "Routes fresh ACZ SceneClean into the ReShade backbuffer before all other effects.";
>
{
    pass
    {
        VertexShader = PostProcessVS;
        PixelShader = PS_ACZRouteSceneClean;
    }
}
