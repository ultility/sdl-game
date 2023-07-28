#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	bool Create(SDL_Renderer *renderer);
private:
	const char* sprite_path_opt1 = "./images/stickman.png";
	const char* sprite_path_opt2 = ".\\images\\stickman.png";
};