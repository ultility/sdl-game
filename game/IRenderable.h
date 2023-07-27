#pragma once

#include "Texture.h"
class IRenderable
{
public:
	virtual void Render(SDL_Renderer* renderer) { texture.render(renderer, dst); };
private:
	Texture texture;
	SDL_Rect *dst = NULL;
};