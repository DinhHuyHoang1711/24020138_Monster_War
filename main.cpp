#include "Const.h"
#include "CreateMap.h"
#include "GameOn.h"
#include "ShowInventory.h"
#include "Shopping.h"
#include "GameState.h"
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

/*void saveGame()
{
    GameState G;
    G.MoneyState = Money;
    G.FoodState = Food;
    G.PlayerMonsterState.clear();
    G.InventoryToSquadState.clear();
    G.InventoryState.clear();
    G.LvState.clear();
    G.LvHardState.clear();
    for(int i = 0; i < PlayerMonster.size(); i++)
    {
        G.PlayerMonsterState.push_back(PlayerMonster[i]);
    }
    for(int i = 0; i < Inventory.size(); i++)
    {
        G.InventoryState.push_back(Inventory[i]);
    }
    for(int i = 0; i < InventoryToSquad.size(); i++)
    {
        G.InventoryToSquadState.push_back(InventoryToSquad[i]);
    }
    for(int i = 0; i < TotalLevel + 1; i++)
    {
        G.LvState.push_back(Lv[i].check);
    }
    for(int i = 0; i < TotalHardLevel + 1; i++)
    {
        G.LvHardState.push_back(LvHard[i].check);
    }
    saveState(G, "save.dat");
}

void loadGame()
{
    GameState G;
    if(loadState(G, "save.dat"))
    {
        Money = G.MoneyState;
        Food = G.FoodState;
        PlayerMonster.clear();
        Inventory.clear();
        InventoryToSquad.clear();
        for(int i = 0; i < G.PlayerMonsterState.size(); i++)
        {
            PlayerMonster.push_back(G.PlayerMonsterState[i]);
        }
        for(int i = 0; i < G.InventoryState.size(); i++)
        {
            Inventory.push_back(G.InventoryState[i]);
        }
        for(int i = 0; i < G.InventoryToSquadState.size(); i++)
        {
            InventoryToSquad.push_back(G.InventoryToSquadState[i]);
        }
        for(int i = 0; i < TotalLevel + 1; i++)
        {
            Lv[i].check = G.LvState[i];
        }
        for(int i = 0; i < TotalHardLevel + 1; i++)
        {
            LvHard[i].check = G.LvHardState[i];
        }
        Lv[0].check = true;
        LvHard[0].check = true;
    }
    else
    {
        PlayerMonster = {Liquiz};
        Inventory = {Liquiz};
        InventoryToSquad = {0};
        Money = 100;
        Food = 100;
        for(int i = 1; i < TotalLevel + 1; i++)
        {
            Lv[i].check = false;
        }
        for(int i = 1; i < TotalHardLevel +1; i++)
        {
            LvHard[i].check = false;
        }
    }
}
*/

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
                    //loadGame();
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
                        for(int i = 1; i < TotalHardLevel; i++)
                        {
                            LvHard[i].check = false;
                        }
                    }

                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel, LvHard, TotalHardLevel);//Cap nhat map, money, food

                    while(*ok)
                    {
                        if(SDL_PollEvent(&e))
                        {
                            if(e.type == SDL_QUIT)//Quit game
                            {
                                //saveGame();
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
                                    //saveGame();
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

