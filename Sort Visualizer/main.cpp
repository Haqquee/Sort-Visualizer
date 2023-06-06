#include <iostream>
#include <SDL.h>
#include <random>
#include "SelectionSort.h"

const int window_x = 960;
const int window_y = 540;

void draw(std::vector<int> vector, SDL_Renderer* renderer, int a, int b)
{
	int count = 0;
	for (int i : vector)
	{
		SDL_Rect rect = {count*6, window_y - vector[i] * 5, 5, vector[i] * 5};
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

int main(int argc, char* argv[]) 
{
	// Generate random numbers
	std::random_device random;
	std::uniform_int_distribution<int> dist(1, 99);
	std::vector<int> randomVector;
	for (int i = 0; i < 100; i++)
	{
		randomVector.push_back(dist(random));
	}

	// SDL Setup
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("Sort Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 540, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		/*else
		{
			SDL_Event event;
			bool quit = false;
			while (quit == false) 
			{ 
				while (SDL_PollEvent(&event))
				{ 
					if (event.type == SDL_QUIT) quit = true; 
				} 
			}
		}*/
	}

	// Selection Sort Algorithm
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
			draw(randomVector, renderer, i, j);
			SDL_RenderPresent(renderer);
			SDL_Delay(1);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << randomVector[i] << std::endl;
	}

	SDL_Quit();
	return (0);
}