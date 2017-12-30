#pragma once
#include "Game.h"

class Player
{
public:
	Player(const char * texturesheet, SDL_Renderer * ren, int x, int y);
	~Player();

	void update();
	void render();

	static int MoveX;
	static int MoveY;

private:
	int xpos;
	int ypos;

	SDL_Texture * objTexture;
	SDL_Rect scrRect, destRect;
	SDL_Renderer * renderer;
};
