#include "Renderer.h"

SDL_Renderer* Kyuubi::Renderer::Init(const RenderSettings& settings)
{
    return SDL_CreateRenderer(settings.Window, settings.DriverIndex, settings.Flags);
}
