#include "Texture.h"


bool Texture::Load(SDL_Renderer* renderer, const char* Filename, SDL_Rect *border, int angle)
{
	SDL_Surface *tempSurface = IMG_Load(Filename);
	if (tempSurface == NULL)
	{
		std::cout << "Loading ERROR: " << IMG_GetError() << std::endl;
		return false;
	}
	src = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (src == NULL)
	{
		std::cout << "Loading ERROR: " << IMG_GetError() << std::endl;
		return false;
	}
	this->border = border;
	this->angle = angle;
	return true;
}

void Texture::Render(SDL_Renderer* renderer, SDL_Rect* dst, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(renderer, src, border, dst, angle, NULL, flip);
}

SDL_Rect* Texture::GetTextureSize()
{
	SDL_Rect size;
	size.x = 0;
	size.y = 0;
	SDL_QueryTexture(src, NULL, NULL, &size.w, &size.y);
	return &size;
}

Texture::~Texture()
{
	SDL_DestroyTexture(src);
}
