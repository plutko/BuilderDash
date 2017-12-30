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

GameObject::GameObject(int ID, SDL_Renderer * ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturePath::getTexturePath(ID), ren);
	xpos = x;
	ypos = y;

	switch (ID)
	{
	case 0: // Hole

		break;
	case 1: // Wall

		break;
	case 2: // Ground

		break;
	case 3: // Diamond
		canMove = true;
		canFall = true;
		canExpload = true;
		break;
	case 4: // Boulder
		canBePushed = true;
		canMove = true;
		canFall = true;
		canExpload = true;
		break;
	case 5: // BrickWall

		break;
	default:
		break;
	}
}

GameObject::~GameObject()
{}


void GameObject::update()
{
	scrRect.h = 32;
	scrRect.w = 32;
	scrRect.x = 0;
	scrRect.y= 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = scrRect.w * 1;
	destRect.h = scrRect.h * 1;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &scrRect, &destRect);
}

int GameObject::getID()
{
	return ID;
}