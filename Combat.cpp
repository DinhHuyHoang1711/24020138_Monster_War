#include "Combat.h"

bool Combat(Level &Lv, const vector <Monster> &PlayerMonster, SDL_Renderer* renderer, SDL_Window* window)
{
    SDL_Event e;
    SDL_Rect MenuRect = {0, 500, SCREEN_WIDTH, 100};
    SDL_Texture* background;

    vector <Monster> EnemyMonster;
    for(auto x : Lv.M)
    {
        EnemyMonster.push_back(x);
    }

    vector <int> PlayerHp;
    vector <int> EnemyHp;
    vector <int> PlayerDamaged;
    vector <int> EnemyDamaged;
    vector <bool> PlayerCanMove;
    vector <bool> EnemyCanMove;
    vector <SDL_Rect> PlayerRect;
    vector <SDL_Rect> EnemyRect;

    vector <int> PlayerIdleX = {20, 140, 260, 380};
    vector <int> EnemyIdleX = {880, 760, 640, 520};

    int* PlayerTotalHp = new int(0);
    int* EnemyTotalHp = new int(0);
    int* X = new int(70);
    int* Y = new int(300);
    bool *ok = new bool(true);

    for(auto x: PlayerMonster)
    {
        PlayerCanMove.push_back(true);
        PlayerHp.push_back(x.BaseHp);
        PlayerDamaged.push_back(0);
        PlayerRect.push_back({*X, *Y, x.MonsterWidth, x.MonsterHeight});
        *X += 70;
        *Y += 7;
        *PlayerTotalHp += x.BaseHp;
    }
    *X = 930;
    *Y = 300;
    for(auto x: EnemyMonster)
    {
        EnemyCanMove.push_back(true);
        EnemyHp.push_back(x.BaseHp);
        EnemyDamaged.push_back(0);
        EnemyRect.push_back({*X, *Y, x.MonsterWidth, x.MonsterHeight});
        *X -= 70;
        *Y += 7;
        *EnemyTotalHp += x.BaseHp;
    }

    int time = 0;
    SDL_Rect SurrenderButton = {940, 0, 60, 60};
    while(++time && (*PlayerTotalHp) > 0 && (*EnemyTotalHp > 0))
    {
        *PlayerTotalHp = 0;
        *EnemyTotalHp = 0;
        SDL_RenderClear(renderer);
        for(int i = 0; i < PlayerHp.size(); i++)
        {
            PlayerDamaged[i] = 0;
        }
        for(int i = 0; i < EnemyHp.size(); i++)
        {
            EnemyDamaged[i] = 0;
        }

        if (SDL_PollEvent(&e))
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
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_Point MousePoint = {e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &SurrenderButton))
                {
                    SDL_DestroyTexture(background);
                    background = nullptr;
                    *PlayerTotalHp = 0;
                    break;
                }
            }
        }
        SDL_RenderClear(renderer);
        //ve ban do
        background = loadIMG(Lv.Image.c_str(), renderer, background);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_DestroyTexture(background);
        background = nullptr;

        //Ve nut dau hang
        background = loadIMG("images\\WhiteFlag1.png", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &SurrenderButton);
        SDL_DestroyTexture(background);
        background = nullptr;
        //ve thanh menu
        background = loadIMG("images\\ThanhMenu.jpg", renderer, background);
        SDL_RenderCopy(renderer, background, NULL, &MenuRect);
        SDL_DestroyTexture(background);
        background = nullptr;



        //Ve thanh hp

        SDL_Rect Edge = {495, 500, 10, 100};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &Edge);
        Edge = {475, 480, 35, 35};
        background = loadText("VS", new SDL_Color ({255, 255, 0}), "arial.ttf", new int(35), renderer, background);
        SDL_QueryTexture(background, NULL, NULL, &Edge.w, &Edge.h);
        SDL_RenderCopy(renderer, background, NULL, &Edge);
        SDL_DestroyTexture(background);
        background = nullptr;


        for(int i = 0; i < PlayerHp.size(); i++)
        {
            SDL_Rect IdleRect = {PlayerIdleX[i], 515, 40, 40};
            SDL_Rect RedHpRect = {PlayerIdleX[i], 565, 100, 20};
            SDL_Rect GreenHpRect = {PlayerIdleX[i], 565, 100 * PlayerHp[i] / PlayerMonster[i].BaseHp, 20};

            background = loadIMG(PlayerMonster[i].IdleIMG.c_str(), renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &IdleRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            SDL_SetRenderDrawColor(renderer, 212, 32, 32, 255);
            SDL_RenderFillRect(renderer, &RedHpRect);

            SDL_SetRenderDrawColor(renderer, 57, 232, 37, 255);
            SDL_RenderFillRect(renderer, &GreenHpRect);


            background = loadText(PlayerMonster[i].Name.c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
            SDL_Rect TextRect = {PlayerIdleX[i] + 50, 515, 0, 0};
            SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
            SDL_RenderCopy(renderer, background, NULL, &TextRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            background = loadText(("Lv." + to_string(PlayerMonster[i].Level)).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
            TextRect = {PlayerIdleX[i] + 50, 540, 0, 0};
            SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
            SDL_RenderCopy(renderer, background, NULL, &TextRect);
            SDL_DestroyTexture(background);
            background = nullptr;
        }

        for(int i = 0; i < EnemyHp.size(); i++)
        {
            SDL_Rect IdleRect = {EnemyIdleX[i], 515, 40, 40};
            SDL_Rect RedHpRect = {EnemyIdleX[i], 565, 100, 20};
            SDL_Rect GreenHpRect = {EnemyIdleX[i], 565, 100 * EnemyHp[i] / EnemyMonster[i].BaseHp, 20};

            background = loadIMG(EnemyMonster[i].IdleIMG.c_str(), renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &IdleRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            SDL_SetRenderDrawColor(renderer, 212, 32, 32, 255);
            SDL_RenderFillRect(renderer, &RedHpRect);

            SDL_SetRenderDrawColor(renderer, 57, 232, 37, 255);
            SDL_RenderFillRect(renderer, &GreenHpRect);

            background = loadText(EnemyMonster[i].Name.c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
            SDL_Rect TextRect = {EnemyIdleX[i] + 50, 515, 0, 0};
            SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
            SDL_RenderCopy(renderer, background, NULL, &TextRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            background = loadText(("Lv." + to_string(EnemyMonster[i].Level)).c_str(), new SDL_Color ({255, 255, 255}), "arial.ttf", new int(15), renderer, background);
            TextRect = {EnemyIdleX[i] + 50, 540, 0, 0};
            SDL_QueryTexture(background, NULL, NULL, &TextRect.w, &TextRect.h);
            SDL_RenderCopy(renderer, background, NULL, &TextRect);
            SDL_DestroyTexture(background);
            background = nullptr;
        }
        //Monster bem nhau
        //Ve~ EnemyMonster
        for(int i = 0; i < EnemyHp.size(); i++)
        {
            if(EnemyHp[i] > 0 && EnemyMonster[i].Class == "Melee")
            {
                EnemyCanMove[i] = true;
                for(int j = 0; j < PlayerHp.size(); j++)
                {
                    if(PlayerHp[j] > 0 && Intersection(EnemyRect[i], PlayerRect[j]))
                    {
                        EnemyCanMove[i] = false;
                        if((time % EnemyMonster[i].AttackSpeed) == 0)
                        {
                            background = loadIMG(EnemyMonster[i].AttackIMG[1].c_str(), renderer, background);
                            SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                            SDL_DestroyTexture(background);
                            background = nullptr;
                            if((rand() % 100 + 1) <= EnemyMonster[i].BaseAccuracy)
                            {
                                PlayerDamaged[j] = EnemyMonster[i].BaseAtk;
                                if((rand() % 100 + 1) <= EnemyMonster[i].BaseCritChance)
                                {
                                    PlayerDamaged[j] *= 2;
                                }
                                PlayerDamaged[j] = max(0, PlayerDamaged[j] - PlayerMonster[j].BaseDef);
                            }
                        }
                        else
                        {
                            background = loadIMG(EnemyMonster[i].AttackIMG[0].c_str(), renderer, background);
                            SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                            SDL_DestroyTexture(background);
                            background = nullptr;
                        }
                    }
                    if(EnemyCanMove[i] == false) break;
                }
                if(EnemyCanMove[i] == true)
                {
                    background = loadIMG(EnemyMonster[i].MoveIMG[time % EnemyMonster[i].MoveIMG.size()].c_str(), renderer, background);
                    SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                    SDL_DestroyTexture(background);
                    background = nullptr;
                }
            }
        }
        //Ve~ PlayerMonster
        for(int i = 0; i < PlayerHp.size(); i++)
        {
            if(PlayerHp[i] > 0 && PlayerMonster[i].Class == "Melee")
            {
                PlayerCanMove[i] = true;
                for(int j = 0; j < EnemyHp.size(); j++)
                {
                    if(EnemyHp[j] > 0 && Intersection(PlayerRect[i], EnemyRect[j]))
                    {
                        PlayerCanMove[i] = false;
                        if((time % PlayerMonster[i].AttackSpeed) == 0)
                        {
                            background = loadIMG(PlayerMonster[i].AttackIMG[1].c_str(), renderer, background);
                            SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                            SDL_DestroyTexture(background);
                            background = nullptr;
                            if((rand() % 100 + 1) <= PlayerMonster[i].BaseAccuracy)
                            {
                                EnemyDamaged[j] = PlayerMonster[i].BaseAtk;
                                if((rand() % 100 + 1) <= PlayerMonster[i].BaseCritChance)
                                {
                                    EnemyDamaged[j] *= 2;
                                }
                                EnemyDamaged[j] = max(0, EnemyDamaged[j] - EnemyMonster[j].BaseDef);
                            }
                        }
                        else
                        {
                            background = loadIMG(PlayerMonster[i].AttackIMG[0].c_str(), renderer, background);
                            SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                            SDL_DestroyTexture(background);
                            background = nullptr;
                        }
                    }
                    if(PlayerCanMove[i] == false) break;
                }
                if(PlayerCanMove[i] == true)
                {
                    background = loadIMG(PlayerMonster[i].MoveIMG[time % PlayerMonster[i].MoveIMG.size()].c_str(), renderer, background);
                    SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                    SDL_DestroyTexture(background);
                    background = nullptr;
                }
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        //Cap nhat hp
        for(int i = 0; i < EnemyHp.size(); i++)
        {
            EnemyHp[i] = max(EnemyHp[i] - EnemyDamaged[i], 0);
            *EnemyTotalHp += EnemyHp[i];
        }

        for(int i = 0; i < PlayerHp.size(); i++)
        {
            PlayerHp[i] = max(PlayerHp[i] - PlayerDamaged[i], 0);
            *PlayerTotalHp += PlayerHp[i];
        }
        //Co the di chuyen
        for(int i = 0; i < PlayerHp.size(); i++)
        {
            if(PlayerHp[i] > 0 && PlayerCanMove[i] == true)
            {
                PlayerRect[i].x += PlayerMonster[i].MoveSpeed;
            }
        }
        for(int i = 0; i < EnemyHp.size(); i++)
        {
            if(EnemyHp[i] > 0 && EnemyCanMove[i] == true)
            {
                EnemyRect[i].x -= EnemyMonster[i].MoveSpeed;
            }
        }
        //Cho 1s sau khi xong tran
        if(*PlayerTotalHp == 0 || *EnemyTotalHp == 0)
        {

            background = loadIMG(Lv.Image.c_str(), renderer, background);
            SDL_RenderCopy(renderer, background, NULL, NULL);
            SDL_DestroyTexture(background);
            background = nullptr;


            background = loadIMG("images\\ThanhMenu.jpg", renderer, background);
            SDL_RenderCopy(renderer, background, NULL, &MenuRect);
            SDL_DestroyTexture(background);
            background = nullptr;

            for(int i = 0; i < EnemyHp.size(); i++)
            {
                if(EnemyHp[i] > 0 && EnemyMonster[i].Class == "Melee")
                {
                    EnemyCanMove[i] = true;
                    for(int j = 0; j < PlayerHp.size(); j++)
                    {
                        if(PlayerHp[j] > 0 && SDL_HasIntersection(&EnemyRect[i], &PlayerRect[j]))
                        {
                            EnemyCanMove[i] = false;
                            if((time % EnemyMonster[i].AttackSpeed) == 0)
                            {
                                background = loadIMG(EnemyMonster[i].AttackIMG[1].c_str(), renderer, background);
                                SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                                SDL_DestroyTexture(background);
                                background = nullptr;

                                if((rand() % 100 + 1) <= EnemyMonster[i].BaseAccuracy)
                                {
                                    PlayerDamaged[j] = EnemyMonster[i].BaseAtk;
                                    if((rand() % 100 + 1) <= EnemyMonster[i].BaseCritChance)
                                    {
                                        PlayerDamaged[j] *= 2;
                                    }
                                    PlayerDamaged[j] = max(0, PlayerDamaged[j] - PlayerMonster[j].BaseDef);
                                }
                            }
                            else
                            {
                                background = loadIMG(EnemyMonster[i].AttackIMG[0].c_str(), renderer, background);
                                SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                                SDL_DestroyTexture(background);
                                background = nullptr;

                            }
                            break;
                        }
                    }
                    if(EnemyCanMove[i] == true)
                    {
                        background = loadIMG(EnemyMonster[i].MoveIMG[time % EnemyMonster[i].MoveIMG.size()].c_str(), renderer, background);
                        SDL_RenderCopy(renderer, background, NULL, &EnemyRect[i]);
                        SDL_DestroyTexture(background);
                        background = nullptr;

                    }
                }
            }
            //Ve~ PlayerMonster
            for(int i = 0; i < PlayerHp.size(); i++)
            {
                if(PlayerHp[i] > 0 && PlayerMonster[i].Class == "Melee")
                {
                    PlayerCanMove[i] = true;
                    for(int j = 0; j < EnemyHp.size(); j++)
                    {
                        if(EnemyHp[j] > 0 && SDL_HasIntersection(&PlayerRect[i], &EnemyRect[j]))
                        {
                            PlayerCanMove[i] = false;
                            if((time % PlayerMonster[i].AttackSpeed) == 0)
                            {
                                background = loadIMG(PlayerMonster[i].AttackIMG[1].c_str(), renderer, background);
                                SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                                SDL_DestroyTexture(background);
                                background = nullptr;
                                if((rand() % 100 + 1) <= PlayerMonster[i].BaseAccuracy)
                                {
                                    EnemyDamaged[j] = PlayerMonster[i].BaseAtk;
                                    if((rand() % 100 + 1) <= PlayerMonster[i].BaseCritChance)
                                    {
                                        EnemyDamaged[j] *= 2;
                                    }
                                    EnemyDamaged[j] = max(0, EnemyDamaged[j] - EnemyMonster[j].BaseDef);
                                }
                            }
                            else
                            {
                                background = loadIMG(PlayerMonster[i].AttackIMG[0].c_str(), renderer, background);
                                SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                                SDL_DestroyTexture(background);
                                background = nullptr;
                            }
                            break;
                        }
                    }
                    if(PlayerCanMove[i] == true)
                    {
                        background = loadIMG(PlayerMonster[i].MoveIMG[time % PlayerMonster[i].MoveIMG.size()].c_str(), renderer, background);
                        SDL_RenderCopy(renderer, background, NULL, &PlayerRect[i]);
                        SDL_DestroyTexture(background);
                        background = nullptr;
                    }

                }
            }
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
        }
        SDL_DestroyTexture(background);
        background = nullptr;
    }
    SDL_DestroyTexture(background);
    background = nullptr;
    PlayerHp.clear();
    EnemyHp.clear();
    PlayerDamaged.clear();
    EnemyDamaged.clear();
    PlayerRect.clear();
    EnemyRect.clear();
    EnemyMonster.clear();
    PlayerCanMove.clear();
    EnemyCanMove.clear();
    PlayerIdleX.clear();
    EnemyIdleX.clear();
    delete EnemyTotalHp;
    delete X;
    delete Y;
    delete ok;
    EnemyTotalHp = NULL;
    X = NULL;
    Y = NULL;
    ok = NULL;
    if (*PlayerTotalHp == 0) return false;
    return true;
}
