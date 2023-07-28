// game.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include "Texture.h"
#include "GameObject.h"

class Game
{
public:
	void HandleEvents(SDL_Event* event);
	void Update();
	void Render();
	void Start();
	void Restart();
	bool IsRunning();
	bool AddObject(GameObject object);
	bool RemoveObject(GameObject object);
	SDL_Renderer* GetRenderer();
	~Game();
private:
	SDL_Window *window = NULL;
	SDL_Renderer* renderer = NULL;
	bool isRunning = false;
	bool isInitialized = false;
	std::vector<GameObject> objectList;
	void InitializeSDL();

};