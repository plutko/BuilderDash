#include <SDL.h>
#include <stdio.h>
#include "Game.h"

Game * game = nullptr;	

int main(int argc, char* args[])
{
	const int FPS = 60; // Target FPS
	const int frameDelay = 1000 / FPS; // maximum frame time, circa 16ms

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("BuilderDash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime); // delay to have stable FPS
		}
	}
	game->clean();
	
	return 0;
}