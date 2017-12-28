#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char * texturesheet, SDL_Renderer * ren, int x, int y);
	GameObject(int ID, SDL_Renderer * ren, int x, int y);

	~GameObject();

	void update();
	void render();
private:
	int xpos;
	int ypos;

	SDL_Texture * objTexture;
	SDL_Rect scrRect, destRect;
	SDL_Renderer * renderer;
};