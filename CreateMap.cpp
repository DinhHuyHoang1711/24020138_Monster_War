#include "CreateMap.h"
#include "Level.h"

void UpdateCreateMap(SDL_Renderer* renderer, int &Money, int &Food, Level *Lv, int n, Level *LvHard, int n1)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_Texture*  background;
    background = loadIMG("images\\bando.jpg", renderer, background);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\ThanhMenu.jpg", renderer, background);
    SDL_Rect MenuRect = {0, 530, SCREEN_WIDTH, 70};
    SDL_RenderCopy(renderer, background, NULL, &MenuRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\Money.png", renderer, background);
    SDL_Rect MoneyRect = {50, 550, 25, 25};
    SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_Rect BlackRect = {80, 555, 120, 20};
    SDL_RenderFillRect(renderer, &BlackRect);

    int* text_w = new int(0);
    int* text_h = new int(0);

    background = loadText(to_string(Money).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(16), renderer, background);
    SDL_Rect TextRect = {80, 555, 0, 0};
    SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
    SDL_RenderCopy(renderer, background, NULL, &TextRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\Food.png", renderer, background);
    SDL_Rect FoodRect = {300, 550, 25, 25};
    SDL_RenderCopy(renderer, background, NULL, &FoodRect);
    SDL_DestroyTexture(background);
    background = nullptr;
    BlackRect = {330, 555, 120, 20};
    SDL_RenderFillRect(renderer, &BlackRect);

    background = loadText(to_string(Food).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(16), renderer, background);
    TextRect = {330, 555, 0, 0};
    SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
    SDL_RenderCopy(renderer, background, NULL, &TextRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\Bag.png", renderer, background);
    SDL_Rect BagRect = {800, 535, 60, 60};
    SDL_RenderCopy(renderer, background, NULL, &BagRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\Gear.png", renderer, background);
    SDL_Rect GearRect = {870, 535, 60, 60};
    SDL_RenderCopy(renderer, background, NULL, &GearRect);
    SDL_DestroyTexture(background);

    background = loadIMG("images\\Magnifier.png", renderer, background);
    SDL_Rect MagnifierRect = {730, 535, 60, 60};
    SDL_RenderCopy(renderer, background, NULL, &MagnifierRect);
    SDL_DestroyTexture(background);


    background = nullptr;
    //Ve cac LV
    background = loadIMG((Lv[1].check == true) ? Lv[1].Button[2].c_str() : Lv[1].Button[1].c_str(), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &Lv[1].Rect);
    SDL_DestroyTexture(background);
    background = nullptr;
    for(int i = 2; i <= n; i++)
    {
        background = loadIMG((Lv[i - 1].check == true) ? Lv[i].Button[1].c_str() : Lv[i].Button[0].c_str(), renderer, background);
        if(Lv[i].check == true) background = loadIMG(Lv[i].Button[2].c_str(), renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &Lv[i].Rect);
        SDL_DestroyTexture(background);
        background = nullptr;
    }
    //Ve LV Hard
    for(int i = 1; i <= n1; i++)
    {
        background = loadIMG(LvHard[i].Button[3].c_str(), renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &LvHard[i].Rect);
        SDL_DestroyTexture(background);
        background = nullptr;
    }
    delete text_w;
    text_w = nullptr;
    delete text_h;
    text_h = nullptr;
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_RenderPresent(renderer);
}
