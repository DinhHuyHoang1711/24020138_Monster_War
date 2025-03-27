#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Const.h"

using namespace std;



void logErrorAndExit(const char* msg, const char* error);

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);

SDL_Texture *loadIMG(const char *filename, SDL_Renderer* renderer);

SDL_Renderer* createRenderer(SDL_Window* window);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

void drawSomething(SDL_Window* window, SDL_Renderer* renderer);

void renderTexture(SDL_Texture *texture, int x, int y,
                   SDL_Renderer* renderer);

SDL_Texture* loadText(const std::string& text, SDL_Color color, string font_path, int font_size, SDL_Renderer* renderer);

void HienThiChu(string s, SDL_Color color, string font_path, int font_size, int x, int y, int w, int h, SDL_Renderer* renderer);
void UpdateAndCreateMap();


