#include "Const.h"
#include "CreateMap.h"
#include "GameOn.h"
#include "ShowInventory.h"
#include "Shopping.h"
const char* WINDOW_TITLE = "Monsters_War";
using namespace std;


vector <Monster> PlayerMonster = {Eater, Liquiz, Liquiz, Liquiz};
vector <Monster> Inventory = {Eater, Liquiz, Liquiz, Liquiz, Liquiz, Liquiz, Liquiz};
vector <int> InventoryToSquad {0, 1, 2, 3, -1, -1, -1};
vector <Monster> MonsterList = {Eater, Eater, Liquiz, Liquiz, Eater, Liquiz, Eater, Liquiz};

Level Lv[TotalLevel + 1] = {Lv0, Lv1, Lv2};
int Money = 1000;
int Food = 1000;

int main(int argc, char *argv[])
{
    srand(time(0));
    Lv[0].check = true;
    SDL_Window* window;
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //Hien thi giao dien vao game
    SDL_Texture* background;
    background = loadIMG("images\\giaodien.jpg", renderer, background);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_Rect StartRect = {450, 400, 100, 50};
    background = loadText("START", new SDL_Color ({63, 20, 202}), "BASKVILL.TTF", new int(40), renderer, background);
    SDL_RenderCopy(renderer, background, NULL, &StartRect);
    SDL_DestroyTexture(background);
    background = nullptr;
    SDL_RenderPresent(renderer);

    //Kiem tra thoat game hoac start
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
                return 0;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)//Start game
            {
                SDL_Point MousePoint = {e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &StartRect))
                {
                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel);//Cap nhat map, money, food
                    while(true)
                    {
                        if(SDL_PollEvent(&e))
                        {
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
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
                                    }
                                    if(SDL_PointInRect(&MousePoint, &Lv[i].Rect) && Lv[i - 1].check == true)
                                    {
                                        GameOn(Lv[i], PlayerMonster, renderer, window, Money, Food);
                                        UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel);
                                        break;
                                    }
                                }

                                //Mo Inventory
                                if(SDL_PointInRect(&MousePoint, &BagRect))
                                {
                                    ShowInventory(renderer, window, Money, Food, PlayerMonster, Inventory, InventoryToSquad);
                                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel);
                                }

                                //Mo Shop
                                if(SDL_PointInRect(&MousePoint, &MagnifierRect))
                                {
                                    Shop(renderer, window, Money, Food, Inventory, InventoryToSquad, MonsterList);
                                    UpdateCreateMap(renderer, Money, Food, Lv, TotalLevel);
                                }
                            }
                            if(e.type == SDL_QUIT)//Quit game
                            {
                                SDL_DestroyTexture(background);
                                background = NULL;
                                SDL_DestroyRenderer(renderer);
                                renderer = NULL;
                                quitSDL(window, renderer);
                                return 0;
                            }
                        }
                    }

                }
            }
        }
    }
}

