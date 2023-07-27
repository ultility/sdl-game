// game.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include "Texture.h"
#include "IRenderable.h"
#include "IUpdateable.h"

class Game
{
public:
	void PollEvents();
	void Update();
	void Render();
	void Start();
	void Restart();
	bool IsRunning();
private:
	SDL_Window *window;
	SDL_Renderer* renderer;
	bool isRunning;
	std::vector<IUpdateable> updateList;
	std::vector<IRenderable> shownObjects;
};

// TODO: Reference additional headers your program requires here.
