#include "Player.h"
#include "TextureManager.h"
#include "TexturePath.h"

Player::Player(const char * texturesheet, SDL_Renderer * ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

Player::~Player()
{}


void Player::update()
{
	xpos++;
	scrRect.h = 32;
	scrRect.w = 32;
	scrRect.x = 0;
	scrRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = scrRect.w * 1;
	destRect.h = scrRect.h * 1;
}

void Player::render()
{
	SDL_RenderCopy(renderer, objTexture, &scrRect, &destRect);
}