#pragma once
#include "Const.h"

using namespace std;



void logErrorAndExit(const char* msg, const char* error);

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);

SDL_Texture *loadIMG(const char *filename, SDL_Renderer* renderer, SDL_Texture* background);

SDL_Renderer* createRenderer(SDL_Window* window);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

void drawSomething(SDL_Window* window, SDL_Renderer* renderer);


SDL_Texture* loadText(const char* text, SDL_Color* color, const char * font_path, int* font_size, SDL_Renderer* renderer, SDL_Texture* texture);

bool Intersection(SDL_Rect &Left, SDL_Rect& Right);


