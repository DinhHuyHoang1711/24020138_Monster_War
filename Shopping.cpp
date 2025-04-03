#include "Shopping.h"

void Shop(SDL_Renderer* renderer, SDL_Window* window, int &Money, int& Food, vector <Monster> &Inventory, vector <int> &InventoryToSquad, const vector <Monster> &MonsterList)
{
    Mix_Chunk *click = Mix_LoadWAV("Sounds\\MouseClick.mp3");
    SDL_Texture* background;
    SDL_Event e;
    SDL_Rect TextRect;

    vector <Monster> ShopItem = {};
    SDL_Rect GoldToFoodRect = {200, 50, 120, 30};
    SDL_Rect FoodToGoldRect = {200, 90, 120, 30};
    SDL_Rect RollButton = {600, 50, 200, 100};
    SDL_Rect Xrect = {850, 50, 50, 50};

    while(true)
    {
        background = loadIMG("images\\ShopBackground.png", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_DestroyTexture(background);
        background = nullptr;

        //Hien thi nut X
        background = loadIMG("images\\RedX.png", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &Xrect);
        SDL_DestroyTexture(background);
        background = nullptr;

        //Hien thi nut Roll
        background = loadIMG("images\\RollButton.png", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &RollButton);
        SDL_DestroyTexture(background);
        background = nullptr;


        background = loadText("ROLL", new SDL_Color({255, 247, 0}), "BASKVILL.TTF", new int(40), renderer, background);
        TextRect = {645, 70, 200, 100};
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadText("-300G", new SDL_Color({255, 247, 0}), "BASKVILL.TTF", new int(30), renderer, background);
        TextRect = {645, 110, 200, 100};
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        // Hien thi Money va Food
        SDL_SetRenderDrawColor(renderer, 55, 50, 50, 0);

        SDL_Rect MoneyRect = {400, 50, 150, 30};
        SDL_RenderFillRect(renderer, &MoneyRect);

        background = loadText(to_string(Money).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(28), renderer, background);
        MoneyRect = {400, 50, 30, 30};
        SDL_QueryTexture(background, NULL, NULL, &MoneyRect.w, &MoneyRect.h);
        SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadIMG("images\\Money.png", renderer, background);
        MoneyRect = {360, 50, 30, 30};
        SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
        SDL_DestroyTexture(background);
        background = nullptr;


        SDL_Rect FoodRect = {400, 90, 150, 30};
        SDL_RenderFillRect(renderer, &FoodRect);

        background = loadIMG("images\\Food.png", renderer, background);
        FoodRect = {360, 90, 30, 30};
        SDL_RenderCopy(renderer, background, NULL, &FoodRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadText(to_string(Food).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(28), renderer, background);
        FoodRect = {400, 90, 30, 30};
        SDL_QueryTexture(background, NULL, NULL, &FoodRect.w, &FoodRect.h);
        SDL_RenderCopy(renderer, background, NULL, &FoodRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        // Doi Gold sang Food, Food sang Gold;
        SDL_SetRenderDrawColor(renderer, 102, 0, 0, 0);


        SDL_RenderFillRect(renderer, &GoldToFoodRect);
        SDL_RenderFillRect(renderer, &FoodToGoldRect);

        background = loadText("100Gold->80Food", new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
        TextRect = {200, 56, 120, 30};
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadText("100Food->80Gold", new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
        TextRect = {200, 96, 120, 30};
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        //Hien thi danh sach Monster trong Shop

        TextRect = {100, 190, 30, 30};
        background = loadText("Name", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {220, 190, 30, 30};
        background = loadText("Level", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {310, 190, 30, 30};
        background = loadText("Hp", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {400, 190, 30, 30};
        background = loadText("Atk", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {490, 190, 30, 30};
        background = loadText("Def", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {580, 190, 30, 30};
        background = loadText("Acc", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {670, 190, 30, 30};
        background = loadText("Crt", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        int *y = new int(230);
        vector <SDL_Rect> BuyRect;
        for(int i = 0; i < ShopItem.size(); i++)
        {
            BuyRect.push_back({760, *y, 70, 30});
            *y += 50;
        }

        *y = 230;

        for(int i  = 0; i < ShopItem.size(); i++)
        {
            SDL_Rect I;
            I = {10, *y, 20, 20};
            background = loadText((to_string(i + 1) + ".").c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            background = loadIMG(ShopItem[i].IdleIMG.c_str(), renderer, background);
            I = {40, *y, 40, 40};
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {100, *y, 20, 20};
            background = loadText(ShopItem[i].Name.c_str(), new SDL_Color ({0, 137, 255}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {220, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].Level)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {310, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].BaseHp)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {400, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].BaseAtk)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {490, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].BaseDef)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {580, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].BaseAccuracy)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {670, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].BaseCritChance)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            background = loadIMG("images\\BuyButton.png", renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &BuyRect[i]);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {835, *y, 20, 20};
            background = loadText((to_string(ShopItem[i].UpgradeCost)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(15), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            I = {835, *y + 15, 20, 20};
            background = loadIMG("images\\Money.png", renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &I);
            SDL_DestroyTexture(background);
            background = nullptr;

            *y += 50;
        }
        SDL_RenderPresent(renderer);
        bool *ok =  new bool(true);
        while (*ok)
        {
            if(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    SDL_DestroyTexture(background);
                    background = nullptr;
                    SDL_DestroyRenderer(renderer);
                    renderer = nullptr;
                    Mix_FreeChunk(click);
                    click = nullptr;
                    Mix_CloseAudio();
                    quitSDL(window, renderer);
                    exit(1);
                }
                if(e.type == SDL_MOUSEBUTTONDOWN)

                {
                    Mix_PlayChannel(-1, click, 0);
                    SDL_Point MousePoint = {e.button.x, e.button.y};
                    if(SDL_PointInRect(&MousePoint, &Xrect))
                    {
                        return;
                    }
                    if(SDL_PointInRect(&MousePoint, &GoldToFoodRect))
                    {
                        if(Money >= 100)
                        {
                            Money -= 100;
                            Food += 80;
                            break;
                        }
                        else
                        {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops", "Không đủ Gold", window);
                            break;
                        }
                    }
                    if(SDL_PointInRect(&MousePoint, &FoodToGoldRect))
                    {
                        if(Food >= 100)
                        {
                            Food -= 100;
                            Money += 80;
                            break;
                        }
                        else
                        {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops", "Không đủ Food", window);
                            break;
                        }
                    }
                    if(SDL_PointInRect(&MousePoint, &RollButton))
                    {
                        if(Money >= 300)
                        {
                            ShopItem.clear();
                            Money -= 300;
                            for(int i = 1; i <= 5; i++)
                            {
                                ShopItem.push_back(MonsterList[rand() % (MonsterList.size())]);
                            }
                            break;
                        }
                        else
                        {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops", "Không đủ vàng", window);
                            break;
                        }
                    }
                    for(int i = 0; i < BuyRect.size(); i++)
                    {
                        if(SDL_PointInRect(&MousePoint, &BuyRect[i]))
                        {
                            if(Money >= ShopItem[i].UpgradeCost)
                            {
                                Money -= ShopItem[i].UpgradeCost;
                                Inventory.push_back(ShopItem[i]);
                                InventoryToSquad.push_back(-1);
                                ShopItem.erase(ShopItem.begin() + i);
                                BuyRect.erase(BuyRect.begin() + i);
                                *ok = false;
                                break;
                            }
                            else
                            {
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops", "Không đủ vàng", window);
                                *ok = false;
                                break;
                            }
                        }
                    }
                }
            }
            SDL_Delay(16);
        }
        BuyRect.clear();
        delete y;
        y = nullptr;
        delete ok;
        ok = nullptr;
    }
    ShopItem.clear();
    Mix_FreeChunk(click);
    click = nullptr;
}

