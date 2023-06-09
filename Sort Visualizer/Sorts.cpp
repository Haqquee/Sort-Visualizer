#include "Sorts.h"
#include <iostream>


//// Generates a vector of 100 random integers
//void Sorts::genVector()
//{
//	vect.clear();
//	std::random_device random;
//	std::uniform_int_distribution<int> dist(1, 99);
//	for (int i = 0; i < 100; i++)
//	{
//		vect.push_back(dist(random));
//	}
//}
//
//std::vector<int> Sorts::getVector()
//{
//	return vect;
//}
//
//void Sorts::clearVector()
//{
//	vect.clear();
//}
//
//void Sorts::selectionSort(std::vector<int> vect, SDL_Renderer* renderer)
//{
//	while (!sorted)
//	{
//		for (int i = 0; i < vect.size(); i++)
//		{
//			for (int j = i; j < vect.size(); j++)
//			{
//				if (vect[j] < vect[i])
//				{
//					std::swap(vect[j], vect[i]);
//				}
//
//				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//				SDL_RenderClear(renderer);
//				drawUI(renderer);
//				drawUpdate(vect, renderer, i, j);
//				SDL_RenderPresent(renderer);
//				
//			}
//		}
//		for (int i = 0; i < 100; i++)
//		{
//			std::cout << vect[i] << std::endl;
//		}
//		sorted = true;
//	}
//	
//
//
//}