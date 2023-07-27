#include "Texture.h"


Texture::Texture(SDL_Renderer* renderer, const char* Filename, SDL_Rect *border, int angle)
{
	SDL_Surface *tempSurface = IMG_Load(Filename);
	if (tempSurface == NULL)
	{
		std::cout << "Loading ERROR: " << IMG_GetError() << std::endl;
	}
	src = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (src == NULL)
	{
		std::cout << "Loading ERROR: " << IMG_GetError() << std::endl;
	}
	this->border = border;
	this->angle = angle;
}

void Texture::render(SDL_Renderer* renderer, SDL_Rect* dst, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(renderer, src, border, dst, angle, NULL, flip);
}
