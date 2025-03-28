#include "TaoBanDo.h"

void UpdateCreateMap(SDL_Window* window, SDL_Renderer* renderer, int &Money, int &Food)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_Texture*  background = loadIMG("images\\bando.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);

    background = loadIMG("images\\ThanhMenu.jpg", renderer);
    SDL_Rect MenuRect = {0, 530, SCREEN_WIDTH, 70};
    SDL_RenderCopy(renderer, background, NULL, &MenuRect);

    background = loadIMG("images\\Money.png", renderer);
    SDL_Rect MoneyRect = {50, 550, 25, 25};
    SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
    SDL_Rect BlackRect = {80, 555, 120, 20};
    SDL_RenderFillRect(renderer, &BlackRect);

    int text_w = 0, text_h = 0;

    background = loadText(to_string(Money), SDL_Color {255, 255, 255}, "arial.ttf", 16, renderer);
    GetSizeOfText(to_string(Money), "arial.ttf", 16, text_w, text_h);
    SDL_Rect TextRect = {80, 555, text_w, text_h};
    SDL_RenderCopy(renderer, background, NULL, &TextRect);

    background = loadIMG("images\\Food.png", renderer);
    SDL_Rect FoodRect = {300, 550, 25, 25};
    SDL_RenderCopy(renderer, background, NULL, &FoodRect);
    BlackRect = {330, 555, 120, 20};
    SDL_RenderFillRect(renderer, &BlackRect);

    background = loadText(to_string(Food), SDL_Color {255, 255, 255}, "arial.ttf", 16, renderer);
    GetSizeOfText(to_string(Food), "arial.ttf", 16, text_w, text_h);
    TextRect = {330, 555, text_w, text_h};
    SDL_RenderCopy(renderer, background, NULL, &TextRect);

    background = loadIMG("images\\Bag.png", renderer);
    SDL_Rect BagRect = {800, 535, 60, 60};
    SDL_RenderCopy(renderer, background, NULL, &BagRect);

    background = loadIMG("images\\Gear.png", renderer);
    SDL_Rect GearRect = {870, 535, 60, 60};
    SDL_RenderCopy(renderer, background, NULL, &GearRect);

    SDL_RenderPresent(renderer);

}
