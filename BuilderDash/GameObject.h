#pragma once
#include "Game.h"
#include "Board.h"

class Board;

class GameObject
{
public:

	GameObject(const char * texturesheet, SDL_Renderer * ren, int x, int y);
	GameObject(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~GameObject();

	void virtual update();
	void render();

	int getID();
	bool canMoveThere();
	bool canPlayerMoveThere();

protected:
	Board * level;
	int xpos;
	int ypos;
	int ID;
	bool walkable = false;
	bool canBePushed = false; // can Player push that object 
	bool canMove = false; // can Player or boulder move there 
	bool canFall = false; // can that object Fall
	bool canExpload = false; // can expload??
	bool isFalling = false; // is that object falling atm

	SDL_Texture * objTexture;
	SDL_Rect scrRect, destRect;
	SDL_Renderer * renderer;
};

class Hole : public GameObject
{
public:
	Hole(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~Hole() {};
};

class Wall : public GameObject 
{
public:
	Wall(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~Wall() {};
};

class Diamond :public GameObject 
{
public:
	Diamond(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~Diamond() {};
};

class Ground : public GameObject 
{
public:
	Ground(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~Ground() {};
};

class Boulder : public GameObject
{
public:
	Boulder(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~Boulder() {};
	void virtual update();
};

class BrickWall : public GameObject 
{
public:
	BrickWall(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y);
	virtual ~BrickWall() {};
};