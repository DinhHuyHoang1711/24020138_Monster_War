#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include "Monster.h"

using namespace std;

struct Level
{
    int stt;
    int x;
    int y;
    int w = 10;
    int h = 10;
    int Money;
    int Food;
    int Money2;
    int Food2;
    SDL_Rect Rect;
    SDL_Rect PopUpRect = {100, 50, 800, 500};
    string Image;
    string PopUpImage;
    string Button[4] = {"images\\GrayButton.png", "images\\YellowButton.png",
                        "images\\GreenButton.png", "images\\RedButton.png"};
    vector <Monster> M;
    bool check = false;
    Level(int _x, int _y)
    {
        x = _x;
        y = _y;
        Rect = {_x, _y, 25, 25};
    }
    Level(int _stt, int _x, int _y, int _Money, int _Food, int _Money2, int _Food2, string _Image, string _PopUpImage, vector <Monster> _M)
    {
        stt = _stt;
        x = _x;
        y = _y;
        Rect = {_x, _y, 25, 25};
        Money = _Money;
        Food = _Food;
        Money2 = _Money2;
        Food2 = _Food2;
        Image = _Image.c_str();
        PopUpImage = _PopUpImage.c_str();
        for(int i = 0; i < _M.size(); i++)
        {
            M.push_back(_M[i]);
        }
    }
};

const int TotalLevel = 2;
const Level Lv0(0, 0);
const Level Lv1(1, 500, 300, 100, 100, 20, 20, "images\\Plain.jpg", "images\\Lv1PopUp.png", {Squishee, Hungtree, Squishee, Hungtree});
const Level Lv2(2, 460, 260, 100, 100, 20, 20, "images\\Plain.jpg", "images\\LV1PopUp.png", {Squishee});
