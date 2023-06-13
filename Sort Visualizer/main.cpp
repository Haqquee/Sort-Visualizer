#include <iostream>
#include <SDL.h>
//#include <SDL.ttf.h>
#include <random>
#include "Sorts.h"
#include "Vector.h"
#include "Interface.h"
#include <SDL_image.h>

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

			// Initialize objects/variables (Some hardcoded values for now, will be updated later)
			vector.generateVector();
			std::vector<int>vec = vector.getVector();
			SDL_Rect generateButton = { GENERATE_BUTTON_X , GENERATE_BUTTON_Y, GENERATE_BUTTON_WIDTH, GENERATE_BUTTON_HEIGHT };
			SDL_Rect SSButton = { GENERATE_BUTTON_X + 12 , GENERATE_BUTTON_Y + 60, GENERATE_BUTTON_WIDTH -25, GENERATE_BUTTON_HEIGHT };
			SDL_Rect BSButton = { GENERATE_BUTTON_X + 12 , GENERATE_BUTTON_Y + 60 * 2, GENERATE_BUTTON_WIDTH - 25, GENERATE_BUTTON_HEIGHT };
			SDL_Rect ISButton = { GENERATE_BUTTON_X + 12 , GENERATE_BUTTON_Y + 60 * 3, GENERATE_BUTTON_WIDTH - 25, GENERATE_BUTTON_HEIGHT };
			interface.drawUI(generateButton, renderer, "assets/generate_button.png");
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
							interface.drawUI(generateButton, renderer, "assets/generate_button.png");
							interface.drawUI(SSButton, renderer, "assets/ss_button.png");
							interface.drawUI(BSButton, renderer, "assets/bs_button.png");
							interface.drawUI(ISButton, renderer, "assets/is_button.png");
							vector.drawVectorInstant(vec, renderer);
							SDL_RenderPresent(renderer);
				
						}
						if (interface.buttonPressed(SSButton, event.button.x, event.button.y))
						{
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							selectionSort(vec, renderer);
							interface.drawUI(generateButton, renderer, "assets/generate_button.png");
							interface.drawUI(SSButton, renderer, "assets/ss_button.png");
							interface.drawUI(BSButton, renderer, "assets/bs_button.png");
							interface.drawUI(ISButton, renderer, "assets/is_button.png");
							SDL_RenderPresent(renderer);

						}
						if (interface.buttonPressed(BSButton, event.button.x, event.button.y))
						{
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							bubbleSort(vec, renderer);
							interface.drawUI(generateButton, renderer, "assets/generate_button.png");
							interface.drawUI(SSButton, renderer, "assets/ss_button.png");
							interface.drawUI(BSButton, renderer, "assets/bs_button.png");
							interface.drawUI(ISButton, renderer, "assets/is_button.png");
							SDL_RenderPresent(renderer);

						}
						if (interface.buttonPressed(ISButton, event.button.x, event.button.y))
						{
							std::vector<int>vec = vector.getVector();
							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							SDL_RenderClear(renderer);
							insertionSort(vec, renderer);
							interface.drawUI(generateButton, renderer, "assets/generate_button.png");
							interface.drawUI(SSButton, renderer, "assets/ss_button.png");
							interface.drawUI(BSButton, renderer, "assets/bs_button.png");
							interface.drawUI(ISButton, renderer, "assets/is_button.png");
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