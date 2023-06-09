#pragma once
#include <vector>
#include <SDL.h>
#include <random>

class Sorts
{
private:
	std::vector<int> vect;
	int a;
	int b;
	bool sorted = false;

public:
	void genVector();
	std::vector<int> getVector();
	void selectionSort(std::vector<int> vect, SDL_Renderer* renderer);
	void clearVector();
};



