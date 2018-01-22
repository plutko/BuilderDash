#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "TexturePath.h"

GameObject::GameObject(const char * texturesheet, SDL_Renderer * ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren); 
	 
	xpos = x;
	ypos = y;
}

GameObject::GameObject(Board * thisLevel,int ID, SDL_Renderer * ren, int x, int y)
{
	level = thisLevel;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturePath::getTexturePath(ID), ren);
	xpos = x;
	ypos = y;
	scrRect.x = 0;
	scrRect.y = 0;
	scrRect.w = 32;
	scrRect.h = 32;
	destRect.w = scrRect.w * 1;
	destRect.h = scrRect.h * 1;
}

GameObject::~GameObject()
{}

void GameObject::update()
{	
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &scrRect, &destRect);
}

int GameObject::getID()
{
	return ID;
}

bool GameObject::canMoveThere()
{
	return canMove;
}

bool GameObject::canPlayerMoveThere()
{
	return walkable;
}

Hole::Hole(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
	canMove = true;
	walkable = true;
}

Wall::Wall(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
}

Ground::Ground(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
	walkable = true;
}

Diamond::Diamond(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
	//canMove = true;
	canFall = true;
	canExpload = true;
}

Boulder::Boulder(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
	canBePushed = true;
	//canMove = true;
	canFall = true;
	canExpload = true;
}

void Boulder::update()
{
	//brzydki hack na koniec. Powinienem przechowywac pozycje z tabeli a nie na ekranie, ale z braku czasu...
	if (level->Table[(int)((ypos + 32)/32)][(int)((xpos) / 32)]->canMoveThere())
	{
		delete level->Table[(int)((ypos + 32) / 32)][(int)((xpos) / 32)];
		level->Table[(int)((ypos + 32) / 32)][(int)((xpos) / 32)] = this;
		level->Table[(int)((ypos ) / 32)][(int)((xpos) / 32)] = new Hole(level, 0, renderer, xpos, ypos);

		ypos += 32;
		destRect.x = xpos;
		
		destRect.y = ypos;
	}
	else
	{
		destRect.x = xpos;
		destRect.y = ypos;
	}
}

BrickWall::BrickWall(Board * thisLevel, int ID, SDL_Renderer * ren, int x, int y) : GameObject(thisLevel, ID, ren, x, y)
{
}