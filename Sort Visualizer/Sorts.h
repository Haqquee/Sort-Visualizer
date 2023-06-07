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

public:
	void genVector();
	std::vector<int> getVector();
	std::vector<int> selectionSort(std::vector<int> vect);
	void clearVector();
};



