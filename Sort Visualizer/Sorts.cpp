#include "Sorts.h"

// Generates a vector of 100 random integers
void Sorts::genVector()
{
	vect.clear();
	std::random_device random;
	std::uniform_int_distribution<int> dist(1, 99);
	for (int i = 0; i < 100; i++)
	{
		vect.push_back(dist(random));
	}
}

std::vector<int> Sorts::getVector()
{
	return vect;
}

void Sorts::clearVector()
{
	vect.clear();
}
