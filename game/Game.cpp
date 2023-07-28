#include "Game.h"

void Game::HandleEvents(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
		return;
	}
	for (GameObject object : objectList)
	{
		object.HandleEvent(event);
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
	SDL_RenderClear(renderer);
	static int c = 0;
	SDL_SetRenderDrawColor(renderer, c, c, c++, SDL_ALPHA_OPAQUE);
	for (GameObject object : objectList)
	{
		if (object.IsVisible())
		{
			object.Render(renderer);
		}
	}
	SDL_RenderPresent(renderer);
	SDL_ShowWindow(window);
}

void Game::Start()
{
	if (!isInitialized)
	{
		InitializeSDL();
		isInitialized = true;
	}
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

SDL_Renderer* Game::GetRenderer()
{
	return renderer;
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
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
	window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
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
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

