#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;


void logErrorAndExit(const char* msg, const char* error);

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);

SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);

SDL_Renderer* createRenderer(SDL_Window* window);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

void drawSomething(SDL_Window* window, SDL_Renderer* renderer);

void renderTexture(SDL_Texture *texture, int x, int y,
                   SDL_Renderer* renderer);


