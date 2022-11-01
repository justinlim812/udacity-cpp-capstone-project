#include <iostream>
#include <string>
#include "map.h"

Map::~Map(){
  SDL_DestroyTexture(sdl_texture);
}

void Map::renderTexture(SDL_Renderer *sdl_renderer, const std::size_t screen_width, const std::size_t screen_height){

    // Load bitmap image
    loadedImage = SDL_LoadBMP(_mapImagePath.c_str());
    if (loadedImage != nullptr){

        // Create texture from loaded image
        sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, loadedImage);

        // Surface not needed anymore after generating texture
        SDL_FreeSurface(loadedImage);

        if (sdl_texture == nullptr){
            std::cerr << "Texture could not be created.\n";
        }   
    }
    else{
        std::cerr << "Image could not be loaded.\n";
    }

    SDL_Rect dst;

    // Set texture to be starting from top left
    dst.x = 0;
    dst.y = 0;

    // Set texture to span through its width and height
    SDL_QueryTexture(sdl_texture, NULL, NULL, &dst.w, &dst.h);

    // Render the texture
    SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, &dst);
}