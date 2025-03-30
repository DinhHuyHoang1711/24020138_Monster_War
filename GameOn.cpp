#include "GameOn.h"
#include "Combat.h"

void GameOn(Level &Lv, const vector <Monster> &PlayerMonster, SDL_Renderer* renderer, SDL_Window* window, int &Money, int &Food)
{
    SDL_Texture* background;
    background = loadIMG(Lv.PopUpImage.c_str(), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &Lv.PopUpRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_Rect QuitButton = {300, 400, 80, 40};
    SDL_Rect StartButton = {200, 400, 80, 40};
    background = loadIMG("images\\StartButton.png", renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &StartButton);
    SDL_DestroyTexture(background);
    background = nullptr;

    background = loadIMG("images\\QuitButton.png", renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &QuitButton);
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_RenderPresent(renderer);


    SDL_Event e;
    while (true)
    {
        if (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)//Quit game
            {
                SDL_DestroyTexture(background);
                background = nullptr;
                SDL_DestroyRenderer(renderer);
                renderer = NULL;
                quitSDL(window, renderer);
                exit(1);
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_Point MousePoint = {e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &QuitButton))
                {
                    SDL_DestroyTexture(background);
                    background = NULL;
                    return;
                }
                if(SDL_PointInRect(&MousePoint, &StartButton))
                {
                    background = loadIMG("images\\StartButton2.png", renderer, background);
                    SDL_RenderCopy(renderer, background, NULL, &StartButton);
                    SDL_DestroyTexture(background);
                    background = nullptr;
                    SDL_RenderPresent(renderer);
                    SDL_Delay(1000);
                    bool result = Combat(Lv, PlayerMonster, renderer, window);
                    if(result)
                    {
                        Money += Lv.Money;
                        Food += Lv.Food;
                        Lv.check = true;
                        SDL_RenderClear(renderer);
                        background = loadIMG("images\\WinScene.png", renderer, background);
                        SDL_RenderCopy(renderer, background, NULL, NULL);
                        SDL_DestroyTexture(background);
                        background = nullptr;
                        SDL_RenderPresent(renderer);
                        SDL_Delay(1000);
                        SDL_DestroyTexture(background);
                        background = NULL;
                        return;
                    }
                    else
                    {
                        SDL_RenderClear(renderer);
                        background = loadIMG("images\\LoseScene.png", renderer, background);
                        SDL_RenderCopy(renderer, background, NULL, NULL);
                        SDL_DestroyTexture(background);
                        background = nullptr;
                        SDL_RenderPresent(renderer);
                        SDL_Delay(1000);
                        return;
                        SDL_DestroyTexture(background);
                        background = NULL;
                    }
                }
            }
        }
    }
}


