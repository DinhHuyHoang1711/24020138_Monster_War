#pragma once
#include "Const.h"
#include "Monster.h"

using namespace std;

void Shop(SDL_Renderer* renderer, SDL_Window* window, int &Money, int& Food, vector <Monster> &Inventory, vector <int> &InventoryToSquad, const vector <Monster> &MonsterList);
