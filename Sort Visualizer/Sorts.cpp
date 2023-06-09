#include "Sorts.h"
#include <iostream>
#include "Vector.h"

void selectionSort(std::vector<int> vect, SDL_Renderer* renderer)
{
	bool sorted = false;
	while (!sorted)
	{
		for (int i = 0; i < vect.size(); i++)
		{
			for (int j = i; j < vect.size(); j++)
			{
				if (vect[j] < vect[i])
				{
					std::swap(vect[j], vect[i]);
				}

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				Vector::drawVectorState(vect, renderer, i, j);
				SDL_RenderPresent(renderer);
			}
		}
		/*for (int i = 0; i < 100; i++)
		{
			std::cout << vect[i] << std::endl;
		}*/
		sorted = true;
	}

}

void bubbleSort(std::vector<int> vect, SDL_Renderer* renderer)
{
	bool sorted = false;
	while (!sorted)
	{
		for (int i = 0; i < vect.size() - 1; i++)
		{
			for (int j = 0; j < vect.size() - 1; j++)
			{
				if (vect[j] > vect[j + 1])
				{
					std::swap(vect[j], vect[j+1]);
				}
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				Vector::drawVectorState(vect, renderer, i, j);
				SDL_RenderPresent(renderer);
			}
		}
		sorted = true;
	}
}