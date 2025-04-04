#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "BasicFunctions.h"
#include "Level.h"
#include "Monster.h"
#include <fstream>

using namespace std;


struct GameState
{
    int MoneyState;
    int FoodState;
    vector <Monster> PlayerMonsterState;
    vector <Monster> InventoryState;
    vector <int> InventoryToSquadState;
    vector <bool> LvState;
    vector <bool> LvHardState;
};

void saveState(const GameState& state, const std::string& filename);

bool loadState(GameState& state, const std::string& filename);
