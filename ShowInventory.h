#pragma once
#include "Const.h"
#include "Monster.h"

using namespace std;

void ShowInventory(SDL_Renderer* renderer, SDL_Window* window, int &Money, int& Food, vector <Monster> &PlayerMonster, vector <Monster> &Inventory, vector <int> &InventoryToSquad);
