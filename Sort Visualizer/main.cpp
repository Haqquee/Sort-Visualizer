#include <iostream>
#include <SDL.h>
#include <random>
#include "Sorts.h"
#include "Draw.h"

const int WINDOW_X = 960;
const int WINDOW_Y = 540;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* screenSurface = NULL;


int main(int argc, char* argv[]) 
{
	Sorts sort;
	sort.genVector();
	std::vector<int> randomVector = sort.getVector();
	
	// SDL Setup
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("Sort Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_X, WINDOW_Y, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			SDL_Event event;
			bool quit = false;
			while (!quit) 
			{ 
				while (SDL_PollEvent(&event))
				{ 
					if (event.type == SDL_QUIT) 
					{
						quit = true;
					}
				}

				
				for (int i = 0; i < randomVector.size(); i++)
				{
					for (int j = i; j < randomVector.size(); j++)
					{
						if (randomVector[j] < randomVector[i])
						{
							std::swap(randomVector[j], randomVector[i]);
						}
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
						SDL_RenderClear(renderer);
						drawUpdate(randomVector, renderer, i, j);
						drawUI(renderer);
						SDL_RenderPresent(renderer);
						SDL_Delay(1);
					}
				}
				for (int i = 0; i < 100; i++)
				{
					std::cout << randomVector[i] << std::endl;
				}
			}
		}
	}

	// Selection Sort Algorithm

	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}