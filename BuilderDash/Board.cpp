#pragma once
#include "Board.h"
#include "Game.h"

Board::Board()
{
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			Table[i][j] = nullptr;
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			delete Table[i][j];
		}
	}
}