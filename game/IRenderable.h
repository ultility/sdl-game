#pragma once

#include "Texture.h"
class IRenderable
{
public:
	virtual void Render(SDL_Renderer* renderer) { texture.render(renderer, dst); };
	void SetVisibility(bool visible) { isShown = visible; };
	bool IsVisible() { return isShown; };
private:
	Texture texture;
	SDL_Rect *dst = NULL;
	bool isShown;
};