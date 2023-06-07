#pragma once
#include <SDL.h>
#include <vector>
#include "Sorts.h"

void drawUI(SDL_Renderer* ren);
void drawVector(std::vector<int> vector);
void drawUpdate(std::vector<int> vector, SDL_Renderer* renderer, int a, int b);


