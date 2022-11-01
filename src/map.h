#ifndef MAP_H
#define MAP_H

#include <string>
#include "SDL.h"

class Map {
public:
    Map();
    ~Map();
    void renderTexture(SDL_Renderer *sdl_renderer, const std::size_t screen_width, const std::size_t screen_height);

private:
    std::string _mapImage{"../resource/space_2.bmp"};
    SDL_Texture *sdl_texture;
    SDL_Surface *loadedImage;
    const std::size_t _screen_width{0};
    const std::size_t _screen_height{0};
};

#endif