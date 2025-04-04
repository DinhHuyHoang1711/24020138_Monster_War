#include "Const.h"
#include "CreateMap.h"
#include "GameOn.h"
#include "ShowInventory.h"
#include "Shopping.h"
const char* WINDOW_TITLE = "Monsters_War";
using namespace std;


vector <Monster> PlayerMonster = {Liquiz};
vector <Monster> Inventory = {Liquiz};
vector <int> InventoryToSquad = {0};
vector <Monster> MonsterList = {Liquiz, Eater, Magma, Crops};

Level Lv[TotalLevel + 1] = {Lv0, Lv1, Lv2, Lv3, Lv4, Lv5, Lv6, Lv7, Lv8, Lv9, Lv10, Lv11};
Level LvHard[TotalHardLevel + 1] = {Lv0, LvHard1};
int Money = 100;
int Food = 100;

int main(int argc, char *argv[])
{
    //Setup
    srand(time(0));
    Lv[0].check = true;
    SDL_Window* window;
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //Nhac nen
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* music;
    music = Mix_LoadMUS("Sounds\\BackgroundMusic.mp3");
    Mix_PlayMusic(music, -1);

    Mix_Chunk *click = Mix_LoadWAV("Sounds\\MouseClick.mp3");

    //Hien thi giao dien vao game
    SDL_Texture* background;
    background = loadIMG("images\\giaodien.jpg", renderer, background);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_Rect StartRect = {450, 350, 100, 50};
    background = loadText("START", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &StartRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_Rect NewGameRect = {450, 410, 150, 50};
    background = loadText("NEW GAME", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &NewGameRect);
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_Rect QuitGameRect = {450, 470, 80, 50};
    background = loadText("QUIT", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &QuitGameRect);
    SDL_DestroyTexture(background);
    background = nullptr;


    SDL_RenderPresent(renderer);

    //Kiem tra thoat game hoac start
    SDL_Event e;
    while (true)
    {
        bool *ok = new bool(true);
        if (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)//Quit game
            {

                SDL_DestroyTexture(background);
                background = nullptr;
                SDL_DestroyRenderer(renderer);
                renderer = nullptr;
                Mix_FreeMusic(music);
                music = nullptr;
                Mix_FreeChunk(click);
                click = nullptr;
                Mix_CloseAudio();
                quitSDL(window, renderer);
                return 0;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)//Start game
            {
                Mix_PlayChannel(-1, click, 0);
                SDL_Point MousePoint = {e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &StartRect) || SDL_PointInRect(&MousePoint, &NewGameRect))
                {
                    if(SDL_PointInRect(&MousePoint, &NewGameRect))
                    {
                        PlayerMonster = {Liquiz};
                        Inventory = {Liquiz};
                        InventoryToSquad = {0};
                        Money = 100;
                        Food = 100;
                        for(int i = 1; i <= TotalLevel; i++)
                        {
                            Lv[i].check = false;
                        }
                    }

                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);//Cap nhat map, money, food

                    while(*ok)
                    {
                        if(SDL_PollEvent(&e))
                        {
                            if(e.type == SDL_QUIT)//Quit game
                            {
                                SDL_DestroyTexture(background);
                                background = nullptr;
                                SDL_DestroyRenderer(renderer);
                                renderer = nullptr;
                                Mix_FreeMusic(music);
                                music = nullptr;
                                Mix_FreeChunk(click);
                                click = nullptr;
                                Mix_CloseAudio();
                                quitSDL(window, renderer);
                                return 0;
                            }
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                Mix_PlayChannel(-1, click, 0);

                                MousePoint = {e.button.x, e.button.y};
                                SDL_Rect BagRect = {800, 535, 60, 60};
                                SDL_Rect GearRect = {870, 535, 60, 60};
                                SDL_Rect MagnifierRect = {730, 535, 60, 60};

                                //Click vao 1 man choi
                                for(int i = 1; i <= TotalLevel; i++)
                                {
                                    if(SDL_PointInRect(&MousePoint, &Lv[i].Rect) && Lv[i - 1].check == false)
                                    {
                                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Chưa mở khóa level này.", "Bạn cần hoàn thành level trước đó.", window);
                                        break;
                                    }
                                    if(SDL_PointInRect(&MousePoint, &Lv[i].Rect) && Lv[i - 1].check == true)
                                    {
                                        bool* k = new bool(true);
                                        *k = GameOn(Lv[i], PlayerMonster, renderer, window, Money, Food);
                                        UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);
                                        if(*k)
                                        {
                                            music = Mix_LoadMUS("Sounds\\BackgroundMusic.mp3");
                                            Mix_PlayMusic(music, -1);
                                        }
                                        delete k;
                                        k = nullptr;
                                    }
                                }
                                //Click vao level hard
                                for(int i = 1; i <= TotalHardLevel; i++)
                                {
                                    if(SDL_PointInRect(&MousePoint, &LvHard[i].Rect))
                                    {
                                        bool* k = new bool(true);
                                        *k = GameOn(LvHard[i], PlayerMonster, renderer, window, Money, Food);
                                        UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);
                                        if(*k)
                                        {
                                            music = Mix_LoadMUS("Sounds\\BackgroundMusic.mp3");
                                            Mix_PlayMusic(music, -1);
                                        }
                                        delete k;
                                        k = nullptr;
                                    }
                                }
                                //Mo Inventory
                                if(SDL_PointInRect(&MousePoint, &BagRect))
                                {
                                    ShowInventory(renderer, window, Money, Food, PlayerMonster, Inventory, InventoryToSquad);
                                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);
                                }

                                //Mo Shop
                                if(SDL_PointInRect(&MousePoint, &MagnifierRect))
                                {
                                    Shop(renderer, window, Money, Food, Inventory, InventoryToSquad, MonsterList);
                                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);
                                }
                                //Mo Setting
                                if(SDL_PointInRect(&MousePoint, &GearRect))
                                {
                                    *ok = false;
                                    background = loadIMG("images\\giaodien.jpg", renderer, background);
                                    SDL_RenderCopy(renderer, background, NULL, NULL);
                                    SDL_DestroyTexture(background);
                                    background = nullptr;

                                    background = loadText("START", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
                                    SDL_RenderCopy(renderer, background, NULL, &StartRect);
                                    SDL_DestroyTexture(background);
                                    background = nullptr;

                                    background = loadText("NEW GAME", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
                                    SDL_RenderCopy(renderer, background, NULL, &NewGameRect);
                                    SDL_DestroyTexture(background);
                                    background = nullptr;

                                    background = loadText("QUIT", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
                                    SDL_RenderCopy(renderer, background, NULL, &QuitGameRect);
                                    SDL_DestroyTexture(background);
                                    background = nullptr;

                                    SDL_RenderPresent(renderer);
                                }
                            }
                        }
                    }
                }
                if(SDL_PointInRect(&MousePoint, &QuitGameRect))
                {
                    SDL_DestroyTexture(background);
                    background = nullptr;
                    SDL_DestroyRenderer(renderer);
                    renderer = nullptr;
                    Mix_FreeMusic(music);
                    music = nullptr;
                    Mix_FreeChunk(click);
                    click = nullptr;
                    Mix_CloseAudio();
                    quitSDL(window, renderer);
                    return 0;
                }
            }
        }
        delete ok;
        ok = nullptr;
    }
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    Mix_FreeMusic(music);
    music = nullptr;
    Mix_FreeChunk(click);
    click = nullptr;
    Mix_CloseAudio();
    quitSDL(window, renderer);
    return 0;
}

