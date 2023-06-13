#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Interface
{
public:
	void drawUI(SDL_Rect& button, SDL_Renderer* renderer, const std::string& texturePath);
	bool buttonPressed(SDL_Rect& button, int mouseX, int mouseY);
	void clearUI(SDL_Renderer* renderer);
};

