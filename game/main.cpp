#include "main.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char* argv[])
{
	//The frames per second cap timer
	LTimer capTimer;

	//Start counting frames per second
	int countedFrames = 0;
	Game game;
	game.Start();
	Player p;
	p.Create(game.GetRenderer());
	//game.AddObject(p);
	while (game.IsRunning())
	{
		//Start cap timer
		//capTimer.start();
		SDL_Event* event = NULL;
		while (SDL_PollEvent(event))
		{
			if (event != NULL)
			{
				game.HandleEvents(event);
			}
		}
		//game.Update();
		//game.Render();
		/*++countedFrames;
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}*/

	}
	return 0;
}