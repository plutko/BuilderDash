#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * texturesheet, SDL_Renderer * ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren); 

	xpos = x;
	ypos = y;

}

void GameObject::update()
{
	xpos++;
	scrRect.h = 64;
	scrRect.w = 64;
	scrRect.x = 0;
	scrRect.y= 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = scrRect.w * 2;
	destRect.h = scrRect.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &scrRect, &destRect);
}
