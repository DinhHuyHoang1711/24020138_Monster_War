#include "ShowInventory.h"


void ShowInventory(SDL_Renderer* renderer, SDL_Window* window, int &Money, int& Food, vector <Monster> &PlayerMonster, vector <Monster> &Inventory, vector <int> &InventoryToSquad)
{
    SDL_Texture* background;
    SDL_Event e;
    SDL_Rect TextRect;
    int *ScrollOfSet = new int(0);
    while(true)
    {
        background = loadIMG("images\\InventoryBackground.png", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_DestroyTexture(background);
        background = nullptr;

        //Hien thi nut X
        background = loadIMG("images\\RedX.png", renderer, background);
        SDL_Rect Xrect = {950, 0, 50, 50};
        SDL_RenderCopy(renderer, background, NULL, &Xrect);
        SDL_DestroyTexture(background);
        background = nullptr;

        SDL_SetRenderDrawColor(renderer, 55, 50, 50, 0);

        //Hien thi Gold va Food
        SDL_Rect MoneyRect = {750, 40, 150, 30};
        SDL_RenderFillRect(renderer, &MoneyRect);

        background = loadText(to_string(Money).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(28), renderer, background);
        MoneyRect = {790, 40, 30, 30};
        SDL_QueryTexture(background, NULL, NULL, &MoneyRect.w, &MoneyRect.h);
        SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadIMG("images\\Money.png", renderer, background);
        MoneyRect = {750, 40, 30, 30};
        SDL_RenderCopy(renderer, background, NULL, &MoneyRect);
        SDL_DestroyTexture(background);
        background = nullptr;


        SDL_Rect FoodRect = {750, 80, 150, 30};
        SDL_RenderFillRect(renderer, &FoodRect);

        background = loadIMG("images\\Food.png", renderer, background);
        FoodRect = {750, 80, 30, 30};
        SDL_RenderCopy(renderer, background, NULL, &FoodRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        background = loadText(to_string(Food).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(28), renderer, background);
        FoodRect = {790, 80, 30, 30};
        SDL_QueryTexture(background, NULL, NULL, &FoodRect.w, &FoodRect.h);
        SDL_RenderCopy(renderer, background, NULL, &FoodRect);
        SDL_DestroyTexture(background);
        background = nullptr;


        //Hien thi doi hinh
        TextRect = {80, 50, 130, 60};
        for(int i = 0 ; i < PlayerMonster.size(); i++)
        {
            SDL_Rect IMGRect = {TextRect.x, 50, 60, 60};
            background = loadIMG(PlayerMonster[i].IdleIMG.c_str(), renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &IMGRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            IMGRect.x += 65;
            background = loadText(PlayerMonster[i].Name.c_str(), new SDL_Color ({247, 255, 0}), "arial.ttf", new int(15), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &IMGRect.w, &IMGRect.h);
            SDL_RenderCopy(renderer, background, NULL, &IMGRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            IMGRect. y += 25;
            background = loadText(("Lv." + to_string(PlayerMonster[i].Level)).c_str(), new SDL_Color ({247, 255, 0}), "arial.ttf", new int(15), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &IMGRect.w, &IMGRect.h);
            SDL_RenderCopy(renderer, background, NULL, &IMGRect);
            SDL_DestroyTexture(background);
            background = nullptr;
            TextRect.x += 150;
        }

        for(int i = 1; i <= MaxTeamMember - PlayerMonster.size(); i++)
        {
            SDL_Rect IMGRect = {TextRect.x, 50, 60, 60};
            background = loadIMG("images\\PlusSymbol.png", renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &IMGRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            IMGRect.x += 65;
            background = loadText("Blanked", new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
            SDL_QueryTexture(background, NULL, NULL, &IMGRect.w, &IMGRect.h);
            SDL_RenderCopy(renderer, background, NULL, &IMGRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            TextRect.x += 150;
        }

        //Hien thi danh sach Monster

        TextRect = {100, 150, 30, 30};
        background = loadText("Name", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {220, 150, 30, 30};
        background = loadText("Level", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {310, 150, 30, 30};
        background = loadText("Hp", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {400, 150, 30, 30};
        background = loadText("Atk", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {490, 150, 30, 30};
        background = loadText("Def", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {580, 150, 30, 30};
        background = loadText("Acc", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        TextRect = {670, 150, 30, 30};
        background = loadText("Crt", new SDL_Color ({0, 97, 127}), "arial.ttf", new int(22), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
        SDL_RenderCopy(renderer, background, NULL, &TextRect);
        SDL_DestroyTexture(background);
        background = nullptr;

        vector <SDL_Rect> R1;
        vector <SDL_Rect> R2;
        vector <SDL_Rect> R3;
        int *y = new int(190);
        for(int i = 0; i < Inventory.size(); i++)
        {
            R1.push_back({760, *y + *ScrollOfSet, 30, 30});
            R2.push_back({820, *y + *ScrollOfSet, 30, 30});
            R3.push_back({880, *y + *ScrollOfSet, 70, 40});
            *y += 50;
        }

        *y = 190;
        for(int i  = 0; i < Inventory.size(); i++)
        {
            if(*y + *ScrollOfSet >= 190)
            {
                SDL_Rect I;
                I = {10, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(i + 1) + ".").c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                background = loadIMG(Inventory[i].IdleIMG.c_str(), renderer, background);
                I = {40, *y + *ScrollOfSet, 40, 40};
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {100, *y + *ScrollOfSet, 20, 20};
                background = loadText(Inventory[i].Name.c_str(), new SDL_Color ({0, 137, 255}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {220, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].Level)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {310, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].BaseHp)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {400, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].BaseAtk)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {490, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].BaseDef)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {580, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].BaseAccuracy)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {670, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].BaseCritChance)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(20), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {960, *y + *ScrollOfSet, 20, 20};
                background = loadText((to_string(Inventory[i].UpgradeCost)).c_str(), new SDL_Color ({0, 0, 0}), "arial.ttf", new int(15), renderer, background);
                SDL_QueryTexture(background, NULL, NULL, &I.w, &I.h);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;

                background = loadIMG((InventoryToSquad[i] != -1) ? "images\\OutSquad.png" : "images\\InSquad.png", renderer, background);
                SDL_RenderCopy(renderer, background, NULL, &R1[i]);
                SDL_DestroyTexture(background);
                background = nullptr;

                background = loadIMG("images\\TrashCan.png", renderer, background);
                SDL_RenderCopy(renderer, background, NULL, &R2[i]);
                SDL_DestroyTexture(background);
                background = nullptr;

                background = loadIMG("images\\Upgrade.png", renderer, background);
                SDL_RenderCopy(renderer, background, NULL, &R3[i]);
                SDL_DestroyTexture(background);
                background = nullptr;

                I = {960, *y + *ScrollOfSet + 15, 20, 20};
                background = loadIMG("images\\Food.png", renderer, background);
                SDL_RenderCopy(renderer, background, NULL, &I);
                SDL_DestroyTexture(background);
                background = nullptr;


            }
            *y += 50;
        }
        //Them, Bot Monster ra khoi doi hinh, nang cap Monster
        if(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                SDL_DestroyTexture(background);
                background = nullptr;
                SDL_DestroyRenderer(renderer);
                renderer = nullptr;
                quitSDL(window, renderer);
                exit(1);
            }
            if (e.type == SDL_MOUSEWHEEL)
            {
                *ScrollOfSet += e.wheel.y * ScrollSpeed;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_Point MousePoint = {e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &Xrect))
                {
                    break;
                }
                for(int i = 0; i < Inventory.size(); i++)
                {
                    //Them, Bot Monster ra khoi doi hinh
                    if(SDL_PointInRect(&MousePoint, &R1[i]) && R1[i].y >= 190)
                    {
                        if(InventoryToSquad[i] != -1) // Trong doi hinh
                        {
                            PlayerMonster.erase(PlayerMonster.begin() + InventoryToSquad[i]);
                            for(int j = 0; j < Inventory.size(); j++)
                            {
                                if(j != i && InventoryToSquad[j] != -1 && InventoryToSquad[j] > InventoryToSquad[i])
                                {
                                    InventoryToSquad[j] -= 1;
                                }
                            }
                            InventoryToSquad[i] = -1; //Khong con trong doi hinh
                        }
                        else //Khong trong doi hinh
                        {
                            if(PlayerMonster.size() < MaxTeamMember)// Con cho trong trong doi hinh
                            {
                                PlayerMonster.push_back(Inventory[i]);
                                InventoryToSquad[i] = PlayerMonster.size() - 1;
                            }
                            else// Het cho trong doi hinh
                            {
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Team is full!", "Đội hình đầy chỗ rồi!", window);
                            }
                        }
                        break;
                    }
                    //Duoi Monster ra khoi Inventory (Tuc la cho Monster Cook vinh vien !!!!)
                    if(SDL_PointInRect(&MousePoint, &R2[i]) && R2[i].y >= 190)
                    {
                        if(Inventory.size() > 1) // Duoi het Monster di thi lay j choi game???
                        {
                            if(InventoryToSquad[i] != -1)// Trong doi hinh
                            {
                                PlayerMonster.erase(PlayerMonster.begin() + InventoryToSquad[i]);

                                for(int j = 0; j < Inventory.size(); j++)
                                {
                                    if(j != i && InventoryToSquad[j] != -1 && InventoryToSquad[j] > InventoryToSquad[i])
                                    {
                                        InventoryToSquad[j] -= 1;
                                    }
                                }
                            }
                            Inventory.erase(Inventory.begin() + i);
                            InventoryToSquad.erase(InventoryToSquad.begin() + i);
                        }
                        else
                        {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Không được đuổi hết Monster ra khỏi đội!", window);
                        }
                        break;
                    }
                    if(SDL_PointInRect(&MousePoint, &R3[i]) && R3[i].y >= 190)
                    {
                        if(Food >= Inventory[i].UpgradeCost && Inventory[i].Level < 10)
                        {
                            Food -= Inventory[i].UpgradeCost;
                            Inventory[i].LevelUp();
                            if(InventoryToSquad[i] != -1) PlayerMonster[InventoryToSquad[i]].LevelUp();
                        }
                        else
                        {
                            if(Inventory[i].Level == 10) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops!", "Đã đạt cấp tối đa", window);
                            else SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Ooops!!!", "Không đủ Food! Đi cày thêm đi!", window);
                        }
                    }
                }
            }
        }


        R1.clear();
        R2.clear();
        R3.clear();
        delete y;
        y = nullptr;
        SDL_RenderPresent(renderer);
        SDL_Delay(16);

    }
    delete ScrollOfSet;
    ScrollOfSet = nullptr;
    SDL_DestroyTexture(background);
    background = nullptr;
    return;
}
