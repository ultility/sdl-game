#pragma once

#include "Texture.h"
class IRenderable
{
public:
	virtual void Render(SDL_Renderer* renderer) { texture.Render(renderer, dst); };
	void SetVisibility(bool visible) { isShown = visible; };
	bool IsVisible() { return isShown; };
protected:
	Texture texture;
	SDL_Rect *dst = NULL;
	bool isShown;
};