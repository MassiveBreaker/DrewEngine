#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {

	objTexture = TextureManager::LoadTexture(textureSheet);
	xpos = x;
	ypos = y;

}

GameObject::~GameObject() {

}



void GameObject::Update(){
	//SIZE IMPLEMENTATION
	
	xpos++;
	ypos++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcRect.w * 2;
	destR.h = srcRect.h * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destR);
}