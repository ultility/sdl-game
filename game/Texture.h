#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Texture
{
	public:
		Texture(SDL_Renderer* renderer, const char* Filename, SDL_Rect* border = NULL, int angle = 0);
		void render(SDL_Renderer* renderer, SDL_Rect *dst = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	private:
		SDL_Texture *src;
		int angle;
		SDL_Rect *border;
};