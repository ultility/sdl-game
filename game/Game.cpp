#include "Game.h"

void Game::PollEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		for (GameObject object : objectList)
		{
			object.PollEvent(&event);
		}
	}
}

void Game::Update()
{
	for (GameObject object : objectList)
	{
		object.Update();
	}
}

void Game::Render()
{
	for (GameObject object : objectList)
	{
		if (object.IsVisible())
		{
			object.Render(renderer);
		}
	}
}

void Game::Start()
{
	InitializeSDL();
	isRunning = true;
}

void Game::Restart()
{
	Start();
}

bool Game::IsRunning()
{
	return isRunning;
}

bool Game::AddObject(GameObject object)
{
	for (GameObject obj : objectList)
	{
		if (obj == object)
		{
			return false;
		}
	}
	objectList.push_back(object);
	return true;
}

bool Game::RemoveObject(GameObject object)
{
	for (auto i = objectList.begin(); i < objectList.end(); i++)
	{
		if (*i == object)
		{
			objectList.erase(i);
			return true;
		}
	}
	return false;
}

void Game::InitializeSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "ERROR: " << SDL_GetError() << " at line " << __LINE__ << std::endl;
		exit(1);
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "ERROR: " << IMG_GetError() << " at line " << __LINE__ << std::endl;
		exit(1);
	}
	window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "ERROR: " << SDL_GetError() << " at line " << __LINE__ << std::endl;
		exit(1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "ERROR: " << SDL_GetError() << " at line " << __LINE__ << std::endl;
		exit(1);
	}
}

