#include "Draw.h"

const int BUTTON_X = 75;
const int BUTTON_Y = 50;

void drawUI(SDL_Renderer* renderer)
{
	SDL_Rect generateButton = { 700, 400, BUTTON_X, BUTTON_Y };
	SDL_Rect selectionSortButton = { 800, 400, BUTTON_X, BUTTON_Y };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &generateButton);
	SDL_RenderFillRect(renderer, &selectionSortButton);
}

void drawUpdate(std::vector<int> vector, SDL_Renderer* renderer, int a, int b)
{
	{
		int count = 0;
		for (int i : vector)
		{
			SDL_Rect rect = { count * 6, 540 - vector[i] * 5, 5, vector[i] * 5 };
			if (count == a)
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				//SDL_RenderFillRect(renderer, &rect);
			}
			else if (count == b)
			{
				SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
				//SDL_RenderFillRect(renderer, &rect);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			}
			//SDL_RenderDrawRect(renderer, &rect);
			SDL_RenderFillRect(renderer, &rect);
			count += 1;
		}
	}
}