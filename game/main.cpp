#include "main.h"

int main(int argc, char* argv[])
{
	Game game;
	game.Start();
	while (game.IsRunning())
	{
		game.PollEvents();
		game.Update();
		game.Render();
	}
	return 0;
}