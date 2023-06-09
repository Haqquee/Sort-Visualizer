#pragma once
#include <vector>
#include <SDL.h>
#include <random>

class Vector
{
private:
	std::vector<int> vector;
	int a;
	int b;
	bool sorted = false;

public:
	void generateVector();
	std::vector<int> getVector();
	void drawVectorInstant(std::vector<int> vect, SDL_Renderer* renderer);
	void drawVectorState(std::vector<int> vect, SDL_Renderer* renderer, int a, int b);
	void clearVector();
	void sortVector(std::vector<int> vect);
};

