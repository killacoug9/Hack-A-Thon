#include"button.h"

Button::Button() {
	SDL_Surface* panic_sur = IMG_Load("panic.png");
	SDL_Texture* panic_tex = SDL_CreateTextureFromSurface(renderer, panic_sur);
	SDL_FreeSurface(panic_sur);
}

Button::~Button() {
	SDL_DestroyTexture(panic_tex);
	SDL_DestroyRenderer(renderer);
	IMG_Quit;
}

void Button::renderImage(SDL_Texture* panic_tex) {
	
	SDL_RenderClear(renderer);
	SDL_Rect dstrect = { 5, 5, 320, 240 };

	SDL_RenderCopy(renderer, panic_tex, NULL, &dstrect);
	SDL_RenderPresent(renderer);
}