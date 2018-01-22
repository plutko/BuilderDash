#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Board.h"

int level_01[23][40] = // level nr 1
{
	{ 0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,	0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,	0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,	0	,0	,0	,0	,0	,0	,0	,0	,0	,0 },
	{ 1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1 },
	{ 1	,2	,2	,2	,2	,2	,2	,0	,2	,2	,	3	,2	,4	,0	,2	,2	,2	,2	,2	,4	,	2	,4	,2	,2	,2	,2	,2	,2	,2	,0	,	2	,2	,2	,2	,4	,2	,2	,2	,2	,1 },
	{ 1	,2	,4	,0	,4	,2	,2	,2	,2	,2	,	2	,0	,2	,2	,2	,2	,2	,2	,2	,2	,	2	,4	,3	,2	,2	,4	,2	,2	,2	,2	,	0	,2	,2	,2	,2	,2	,0	,2	,2	,1 },
	{ 1	,2	,2	,2	,2	,2	,2	,2	,2	,2	,	2	,0	,2	,2	,4	,2	,2	,2	,2	,2	,	4	,2	,4	,2	,2	,4	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,2	,2	,2	,2	,1 },

	{ 1	,4	,2	,4	,4	,2	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,2	,2	,2	,2	,2	,	2	,4	,2	,2	,4	,2	,2	,2	,2	,4	,	2	,2	,2	,4	,2	,2	,2	,2	,2	,1 },
	{ 1	,4	,2	,0	,4	,2	,2	,2	,2	,2	,	2	,2	,2	,2	,0	,4	,2	,2	,4	,2	,	2	,2	,2	,2	,2	,2	,2	,4	,2	,2	,	2	,2	,2	,2	,4	,2	,4	,4	,2	,1 },
	{ 1	,2	,2	,2	,0	,2	,2	,4	,2	,2	,	2	,2	,2	,2	,2	,2	,4	,2	,2	,2	,	2	,2	,4	,2	,0	,4	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,2	,4	,4	,2	,1 },
	{ 1	,5	,5	,5	,5	,5	,5	,5	,5	,5	,	5	,5	,5	,5	,5	,5	,5	,5	,5	,5	,	5	,5	,5	,5	,5	,5	,5	,5	,5	,5	,	5	,2	,2	,2	,4	,2	,2	,4	,2	,1 },
	{ 1	,2	,0	,2	,2	,2	,4	,2	,2	,3	,	2	,0	,2	,2	,4	,2	,4	,2	,2	,2	,	2	,2	,2	,2	,2	,2	,2	,3	,2	,4	,	3	,2	,2	,2	,2	,2	,2	,0	,2	,1 },

	{ 1	,2	,2	,3	,2	,2	,2	,2	,2	,4	,	2	,2	,2	,2	,2	,0	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,4	,0	,4	,2	,2	,	4	,2	,2	,2	,2	,4	,2	,2	,2	,1 },
	{ 1	,2	,2	,2	,4	,2	,2	,4	,2	,4	,	2	,2	,2	,2	,2	,2	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,0	,2	,4	,2	,2	,	4	,2	,2	,2	,2	,2	,2	,2	,2	,1 },
	{ 1	,2	,4	,2	,2	,2	,2	,2	,4	,2	,	2	,2	,2	,2	,2	,2	,2	,4	,4	,4	,	2	,2	,2	,2	,2	,2	,2	,4	,2	,2	,	0	,2	,3	,2	,2	,2	,2	,4	,2	,1 },
	{ 1	,2	,3	,2	,2	,0	,2	,2	,4	,2	,	0	,0	,2	,2	,2	,2	,2	,4	,2	,4	,	3	,2	,2	,3	,2	,2	,2	,2	,4	,2	,	2	,2	,4	,2	,2	,3	,2	,0	,2	,1 },
	{ 1	,2	,0	,4	,2	,2	,2	,2	,2	,2	,	2	,2	,2	,2	,2	,2	,2	,2	,4	,0	,	4	,2	,2	,4	,2	,2	,2	,2	,2	,2	,	2	,2	,3	,2	,2	,2	,2	,2	,4	,1 },

	{ 1	,2	,2	,2	,2	,2	,2	,2	,2	,5	,	5	,5	,5	,5	,5	,5	,5	,5	,5	,5	,	5	,5	,5	,5	,5	,5	,5	,5	,5	,5	,	5	,5	,5	,5	,5	,5	,5	,5	,5	,1 },
	{ 1	,4	,4	,2	,2	,2	,2	,2	,2	,2	,	2	,2	,4	,2	,2	,2	,3	,2	,2	,2	,	2	,4	,2	,2	,2	,2	,2	,4	,2	,2	,	2	,4	,2	,2	,2	,2	,2	,2	,2	,1 },
	{ 1	,0	,0	,2	,2	,2	,2	,2	,2	,2	,	2	,2	,0	,4	,2	,2	,4	,2	,2	,2	,	2	,2	,2	,2	,2	,4	,2	,2	,2	,2	,	2	,2	,4	,2	,4	,4	,2	,2	,2	,1 },
	{ 1	,2	,0	,2	,2	,4	,2	,2	,2	,2	,	2	,2	,2	,2	,4	,2	,2	,2	,2	,2	,	4	,2	,0	,0	,2	,2	,2	,2	,3	,2	,	2	,2	,4	,2	,4	,4	,2	,2	,2	,1 },
	{ 1	,2	,2	,2	,2	,4	,3	,2	,2	,4	,	2	,2	,2	,2	,2	,2	,2	,2	,4	,2	,	2	,2	,2	,2	,2	,4	,2	,4	,3	,2	,	2	,2	,2	,2	,2	,4	,2	,2	,2	,1 },

	{ 1	,2	,2	,2	,0	,2	,2	,4	,2	,0	,	2	,2	,4	,2	,4	,4	,2	,2	,2	,2	,	2	,2	,2	,2	,2	,4	,2	,4	,3	,2	,	2	,2	,2	,2	,2	,0	,2	,2	,4	,1 },
	{ 1	,2	,3	,2	,2	,2	,2	,0	,2	,2	,	2	,2	,2	,0	,2	,2	,2	,2	,2	,2	,	2	,2	,2	,0	,2	,4	,2	,2	,4	,2	,	2	,2	,2	,4	,2	,2	,2	,4	,2	,1 },
	{ 1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,	1	,1	,1	,1	,1	,1	,1	,1	,1	,1 }
};

Player * player;
//GameObject * player2;

const int GAMESIZE_X = 40;
const int GAMESIZE_Y = 23;
const int GRIDSIZE = 32;

GameObject * levelTable[GAMESIZE_Y][GAMESIZE_X];
Board * level1;

Game::Game()
{}

Game::~Game()
{
	delete level1;
	delete player;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	level1 = new Board;
	int flags = 0;

	if (fullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized successfully!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = new Player(level1, "../Resources/player.png", renderer, 3 * GRIDSIZE, 3 * GRIDSIZE);

	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			switch (level_01[i][j])
			{
			case 0: // Hole 
				level1->Table[i][j] = new Hole(level1, level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			case 1: // Wall
				level1->Table[i][j] = new Wall(level1, level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			case 2: // Ground
				level1->Table[i][j] = new Ground(level1, level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			case 3: // Diamond
				level1->Table[i][j] = new Diamond(level1, level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			case 4: // Boulder
				level1->Table[i][j] = new Boulder(level1,level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			case 5: // BrickWall
				level1->Table[i][j] = new BrickWall(level1, level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
				break;
			default:
				break;
			}
		}
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			Player::MoveX = -GRIDSIZE;
			break;
		case SDLK_RIGHT:
			Player::MoveX = GRIDSIZE;
			break;
		case SDLK_UP:
			Player::MoveY = -GRIDSIZE;
			break;
		case SDLK_DOWN:
			Player::MoveY = GRIDSIZE;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			level1->Table[i][j]->update();
		}
	}
	player->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			level1->Table[i][j]->render();
		}
	}

	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running()
{
	return isRunning;
}

