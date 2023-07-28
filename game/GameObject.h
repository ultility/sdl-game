#pragma once
#include "IRenderable.h";

class GameObject : public IRenderable
{
public:
	virtual void Update(){};
	virtual void PollEvent(SDL_Event* event) {};
	inline bool operator==(const GameObject& rhs) { return this == &rhs; }
	inline bool operator!=(const GameObject& rhs) { return this != &rhs; }
};