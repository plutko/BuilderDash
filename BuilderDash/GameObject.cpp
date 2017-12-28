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
}

GameObject::~GameObject()
{}


void GameObject::update()
{
	//xpos++;
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
