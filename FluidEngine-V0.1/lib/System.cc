#include "./../include/Fluid.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>

SystemCore::SystemCore(uint screenW = 640, uint screenH = 480, const char *winName = "Application") {
  // SDL CORE
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS)) {
    SDL_Log("Error: Failed to initalize SDL Subsystems. SDL_Error: %s", SDL_GetError());
    exit(1);
  }
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    SDL_Log("Warning: Linear texture filtering not enabled.");

  // SDL IMAGE
  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
    SDL_Log("Error: Failed to initalize SDL_image. IMG_Error: %s", IMG_GetError());
    exit(1);
  }

  // WINDOW
  if (!(window = SDL_CreateWindow(winName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN))) {
    SDL_Log("Error: Failed to create a SDL_Window. SDL_Error: %s", SDL_GetError());
    exit(1);
  }

  // RENDERER
  if (!(graphics.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))) {
    SDL_Log("Error: Failed to create a SDL_Renderer. SDL_Error: %s", SDL_GetError());
    exit(1);
  }
}

SystemCore::~SystemCore() {
  if (window)
    SDL_DestroyWindow(window);
  window = NULL;
}

SystemGraphics::SystemGraphics(SDL_Window *window) {
    if (!window) return;
    if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))) {
    SDL_Log("Error: Failed to create a SDL_Renderer. SDL_Error: %s", SDL_GetError());
    exit(1);
  }
}

SystemGraphics::~SystemGraphics() {
  if (renderer)
    SDL_DestroyRenderer(renderer);
  renderer = NULL;
}

SystemAudio::SystemAudio() {

}

SystemAudio::~SystemAudio() {

}
