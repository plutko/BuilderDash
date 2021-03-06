#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Game.h"

Game * game = nullptr;	

int main(int argc, char* args[])
{
	const int FPS = 60; // Target FPS
	const int UPS = 10; // Updates per second (game updates less often than is drawned)
	const int FPU = FPS / UPS; // 6 - number of Frame per Update
	const int UpdateDelay = 1000 / UPS; // maximum, update time, circa 100ms
	const int frameDelay = 1000 / FPS; // maximum frame time, circa 16ms

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("BuilderDash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 736, false);
	int FPUCounter = 0;
	while (game->running())
	{
		FPUCounter++;
		frameStart = SDL_GetTicks();

		game->handleEvents();
		if (FPUCounter == FPU)
		{
			game->update();
			FPUCounter = 0;
		}
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