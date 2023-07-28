#include "Player.h"

bool Player::Create(SDL_Renderer *renderer)
{
	if (!texture.Load(renderer, sprite_path_opt1))
	{
		if (!texture.Load(renderer, sprite_path_opt2))
		{
			return false;
		}
	}
	dst = texture.GetTextureSize();
}
