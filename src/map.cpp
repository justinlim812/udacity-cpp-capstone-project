#include <iostream>
#include <string>
#include "map.h"

Map::Map(){
  
}

Map::~Map(){
  SDL_DestroyTexture(sdl_texture);
}

void Map::renderTexture(SDL_Renderer *sdl_renderer, const std::size_t screen_width, const std::size_t screen_height){
  loadedImage = SDL_LoadBMP(_mapImage.c_str());
  if (loadedImage != nullptr){
      sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, loadedImage);
      SDL_FreeSurface(loadedImage);
      //Make sure converting went ok too
      if (sdl_texture == nullptr){
        std::cerr << "Texture could not be created.\n";
      }
    }
    else {
      std::cerr << "Image could not be created.\n";
    }

  SDL_Rect dst;
  dst.x = 0;
  dst.y = 0;
//   dst.w = screen_width;
//   dst.h = screen_height;
  SDL_QueryTexture(sdl_texture, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, &dst);
}