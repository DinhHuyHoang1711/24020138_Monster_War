#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
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

//Cap do binh thuong
const int TotalLevel = 11;
const Level Lv0(0, 0);
const Level Lv1(1, 500, 300, 200, 200, 50, 50, "images\\Plain.jpg", "images\\Lv1PopUp.png", {Squishee});
const Level Lv2(2, 460, 260, 250, 250, 55, 55, "images\\Plain.jpg", "images\\Lv2PopUp.png", {Bubble});
const Level Lv3(3, 550, 280, 300, 300, 60, 60, "images\\Plain.jpg", "images\\Lv3PopUp.png", {Slimy, Bubble});
const Level Lv4(4, 510, 260, 300, 300, 60, 60, "images\\Plain.jpg", "images\\Lv4PopUp.png", {Slimy, Slimy});
const Level Lv5(5, 480, 220, 350, 350, 60, 60, "images\\Beach.jpg", "images\\Lv5PopUp.png", {FireBomb, Slimy});
const Level Lv6(6, 440, 320, 400, 400, 65, 65, "images\\Plain.jpg", "images\\Lv6PopUp.png", {Squishee, FireBomb, Squishee});
const Level Lv7(7, 530, 340, 450, 450, 70, 70, "images\\Plain.jpg", "images\\Lv7PopUp.png", {FireBomb, Slimy, Bubble});
const Level Lv8(8, 550, 370, 500, 500, 75, 75, "images\\Plain.jpg", "images\\Lv8PopUp.png", {FireBomb, Drowning, Slimy});
const Level Lv9(9, 580, 320, 550, 550, 75, 75, "images\\Plain.jpg", "images\\Lv9PopUp.png", {FireBomb, FireBomb, Slimy});
const Level Lv10(10, 480, 350, 800, 800, 90, 90, "images\\Beach.jpg", "images\\Lv10PopUp.png", {Volcano, FireBomb});
const Level Lv11(11, 400, 440, 550, 550, 75, 75, "images\\Highland.jpg", "images\\Lv11PopUp.png", {Hungtree, Hungtree});

//Cap do kho
const int TotalHardLevel = 1;
const Level LvHard1(-1, 600, 470, 2000, 2000, 1, 1, "images//Cave.jpg", "images\\LvHard1PopUp.png", {LandLord});
