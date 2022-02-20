#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<cmath>


class Button {

    Button();
    void renderImage(SDL_Texture* panic_tex);

    ~Button();
private:
    SDL_Surface* panic_sur;
    SDL_Texture* panic_tex;
    SDL_Renderer* renderer = NULL;      // Pointer for the renderer
};