#include "Game.h"

void Game::PollEvents()
{
	for (IUpdateable updating : updateList)
	{
		updating.Update();
	}
}

void Game::Update()
{
	
}

void Game::Render()
{
	for (IRenderable rendering : shownObjects)
	{
		rendering.Render(renderer);
	}
}

void Game::Start()
{
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
