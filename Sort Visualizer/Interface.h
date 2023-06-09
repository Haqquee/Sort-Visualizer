#pragma once
#include <SDL.h>

class Interface
{
public:
	void drawUI(SDL_Rect& button, SDL_Renderer* renderer);
	bool buttonPressed(SDL_Rect& button, int mouseX, int mouseY);
	void clearUI(SDL_Renderer* renderer);
};

