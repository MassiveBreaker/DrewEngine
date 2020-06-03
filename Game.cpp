#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;


Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		printf("Initialized\n");

		window = SDL_CreateWindow(title, xpos, ypos, width, height,flags);

		if (window) {
			printf("Window created\n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			printf("Renderer created\n");
		}

		isRunning = true;


	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/man.png", renderer,0,0);
	enemy = new GameObject("assets/enemy.png", renderer, 50, 0);

}

void Game::update() {

	player->Update();
	enemy->Update();
	
}
void Game::render() {

	SDL_RenderClear(renderer);
	//this is where we add stuff to render

	player->Render();
	enemy->Render();

	SDL_RenderPresent(renderer);
}

void Game::handleEvents(){
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
	}

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game cleaned\n");
}



