#pragma once
#include "Player.h"
#include "Game.h"

Player::Player(Board * thislevel, const char * texturesheet, SDL_Renderer * ren, int x, int y)
{
	level = thislevel;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	scrRect.h = 32;
	scrRect.w = 32;
	scrRect.x = 0;
	scrRect.y = 0;

	destRect.w = scrRect.w * 1;
	destRect.h = scrRect.h * 1;

	xpos = x;
	ypos = y;
}

Player::~Player()
{}

int Player::MoveX = 0;
int Player::MoveY = 0;

void Player::update()
{
	if (level->Table[(int)((ypos + Player::MoveY) / 32)][(int)((xpos + Player::MoveX) / 32)]->canPlayerMoveThere())
	{
		delete level->Table[(int)((ypos + Player::MoveY) / 32)][(int)((xpos + Player::MoveX) / 32)];
		level->Table[(int)((ypos + Player::MoveY) / 32)][(int)((xpos + Player::MoveX) / 32)] = new Hole(level, 0, renderer, xpos + Player::MoveY, ypos  + Player::MoveX);

		xpos = xpos + Player::MoveX;
		ypos = ypos + Player::MoveY;
	}

	destRect.x = xpos;
	destRect.y = ypos;

	Player::MoveX = 0;
	Player::MoveY = 0;
}

void Player::render()
{
	SDL_RenderCopy(renderer, objTexture, &scrRect, &destRect);
}