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

	int getID();

private:
	int xpos;
	int ypos;
	int ID;
	bool canBePushed = false; // can Player push that object 
	bool canMove = false; // can Player move there 
	bool canFall = false; // can that object Fall
	bool canExpload = false; // can expload??
	bool isFalling = false; // is that object falling atm


	SDL_Texture * objTexture;
	SDL_Rect scrRect, destRect;
	SDL_Renderer * renderer;
};