#include "Vector.h"

void Vector::generateVector()
{
	vector.clear();
	std::random_device random;
	std::uniform_int_distribution<int> dist(1, 99);
	for (int i = 0; i < 100; i++)
	{
		vector.push_back(dist(random));
	}
}

std::vector<int> Vector::getVector()
{
	return vector;
}

void Vector::clearVector()
{
	vector.clear();
}


void Vector::drawVectorInstant(std::vector<int> vector, SDL_Renderer* renderer)
{
	int count = 0;
	for (int i : vector)
	{
		SDL_Rect rect = { count * 6, 540 - vector[i] * 5, 5, vector[i] * 5 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		SDL_Delay(5);
		count += 1;
	}
}

void Vector::drawVectorState(std::vector<int> vector, SDL_Renderer* renderer, int a, int b)
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
		SDL_Delay(1);
	}
}