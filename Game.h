#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <stdio.h>
class Game
{
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();

	void update();
	void render();
	void clean();

	bool running(){ return isRunning; }


	bool isRunning;
	SDL_Window* window;
	static SDL_Renderer* renderer;

private:
	int cnt = 0;

};

