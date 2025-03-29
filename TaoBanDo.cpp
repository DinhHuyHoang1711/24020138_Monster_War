#include "TaoBanDo.h"
#include "Level.h"

void UpdateCreateMap(SDL_Renderer* renderer, int &Money, int &Food, Level *Lv, int n)
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
    //Ve cac LV
    background = loadIMG((Lv[1].check == true) ? Lv[1].Button[2].c_str() : Lv[1].Button[1].c_str(), renderer);
    SDL_RenderCopy(renderer, background, NULL, &Lv[1].Rect);
    for(int i = 2; i <= n; i++)
    {
        background = loadIMG((Lv[i - 1].check == true) ? Lv[i].Button[1].c_str() : Lv[i].Button[0].c_str(), renderer);
        if(Lv[i].check == true) background = loadIMG(Lv[i].Button[2].c_str(), renderer);
        SDL_RenderCopy(renderer, background, NULL, &Lv[i].Rect);
    }
    SDL_RenderPresent(renderer);
}
