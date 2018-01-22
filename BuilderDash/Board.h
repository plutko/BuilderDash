#pragma once
#include "GameObject.h"

class GameObject;

class Board
{
public:
	Board();
	~Board();
	GameObject * Table[23][40];
};
