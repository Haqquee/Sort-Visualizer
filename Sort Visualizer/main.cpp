#include <iostream>
#include <SDL.h>
#include <random>
#include "Sorts.h"
#include "Vector.h"
#include "Interface.h"

const int WINDOW_X = 960;
const int WINDOW_Y = 540;
const int GENERATE_BUTTON_WIDTH = 125;
const int GENERATE_BUTTON_HEIGHT = 50;
const int GENERATE_BUTTON_X = 700;
const int GENERATE_BUTTON_Y = 200;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* screenSurface = NULL;


int main(int argc, char* argv[]) 
{
	Vector vector;
	Interface interface;
	
	// SDL Initialization
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

			// Initialize objects/variables
			vector.generateVector();
			std::vector<int>vec = vector.getVector();
			SDL_Rect generateButton = { GENERATE_BUTTON_X , GENERATE_BUTTON_Y, GENERATE_BUTTON_WIDTH, GENERATE_BUTTON_HEIGHT };
			SDL_Rect SSButton = { GENERATE_BUTTON_X + 33 , GENERATE_BUTTON_Y + 60, GENERATE_BUTTON_WIDTH / 2, GENERATE_BUTTON_HEIGHT };
			SDL_Rect BSButton = { GENERATE_BUTTON_X + 33 , GENERATE_BUTTON_Y + 60*2, GENERATE_BUTTON_WIDTH / 2, GENERATE_BUTTON_HEIGHT };
			interface.drawUI(generateButton, renderer);
			SDL_RenderPresent(renderer);

			while (!quit) 
			{ 
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT) 
					{
						quit = true;
					}
					if (event.type == SDL_MOUSEBUTTONDOWN)
					{
	
						if (interface.buttonPressed(generateButton, event.button.x, event.button.y))
						{
							vector.generateVector();
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							interface.drawUI(generateButton, renderer);
							interface.drawUI(SSButton, renderer);
							interface.drawUI(BSButton, renderer);
							vector.drawVectorInstant(vec, renderer);
							SDL_RenderPresent(renderer);
				
						}
						if (interface.buttonPressed(SSButton, event.button.x, event.button.y))
						{
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							selectionSort(vec, renderer);
							interface.drawUI(generateButton, renderer);
							interface.drawUI(SSButton, renderer);
							interface.drawUI(BSButton, renderer);
							SDL_RenderPresent(renderer);

						}
						if (interface.buttonPressed(BSButton, event.button.x, event.button.y))
						{
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							bubbleSort(vec, renderer);
							interface.drawUI(generateButton, renderer);
							interface.drawUI(SSButton, renderer);
							interface.drawUI(BSButton, renderer);
							SDL_RenderPresent(renderer);

						}
		
					}
				}
				
				
			}
		}
	}

	// Selection Sort Algorithm

	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}