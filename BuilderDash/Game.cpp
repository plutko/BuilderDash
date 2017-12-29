#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

int level_01[23][40] =
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
GameObject * player2;

const int GAMESIZE_X = 40; //40
const int GAMESIZE_Y = 23; //23
const int GRIDSIZE = 32;

GameObject * levelTable[GAMESIZE_Y][GAMESIZE_X];

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
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

	player = new Player("../Resources/player.png", renderer, 32 , 32);
	player2 = new GameObject("../Resources/player.png", renderer, 128, 0);

	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			levelTable[i][j] = new GameObject(level_01[i][j], renderer, j * GRIDSIZE, i * GRIDSIZE);
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

	default:
		break;
	}
}

void Game::update()
{
	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			levelTable[i][j]->update();
		}
	}
	player->update();
	player2->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < GAMESIZE_Y; i++)
	{
		for (int j = 0; j < GAMESIZE_X; j++)
		{
			levelTable[i][j]->render();
		}
	}

	player->render();
	player2->render();
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

