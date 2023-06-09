#include "Interface.h"

void Interface::drawUI(SDL_Rect& button, SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &button);

}

void Interface::clearUI(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
}

bool Interface::buttonPressed(SDL_Rect& button, int mouseX, int mouseY)
{
	bool pressed = false;
	if (mouseX >= button.x && mouseX <= button.x + button.w &&
		mouseY >= button.y && mouseY <= button.y + button.h)
	{
		pressed = true;
	}
	return pressed;
}
