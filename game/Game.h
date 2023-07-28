// game.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include "Texture.h"
#include "GameObject.h"

class Game
{
public:
	void PollEvents();
	void Update();
	void Render();
	void Start();
	void Restart();
	bool IsRunning();
	bool AddObject(GameObject object);
	bool RemoveObject(GameObject object);
private:
	SDL_Window *window;
	SDL_Renderer* renderer;
	bool isRunning;
	std::vector<GameObject> objectList;
	void InitializeSDL();
};

// TODO: Reference additional headers your program requires here.
