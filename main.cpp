#include "Const.h"
#include "ChuKiHam.h"
#include "TaoBanDo.h"
const char* WINDOW_TITLE = "Monsters_War";
using namespace std;

int Money = 0;
int Food = 0;


int main(int argc, char *argv[])
{
    SDL_Window* window;
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //Hien thi giao dien vao game
    SDL_Texture* background = loadIMG("images\\giaodien.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);

    SDL_Rect StartRect = {450, 400, 100, 50};
    SDL_Texture* StartText = loadText("START", SDL_Color{63, 20, 202}, "BASKVILL.TTF", 40, renderer);
    SDL_RenderCopy(renderer, StartText, NULL, &StartRect);
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
                background = NULL;
                SDL_DestroyRenderer(renderer);
                renderer = NULL;
                quitSDL(window, renderer);
                return 0;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)//Start game
            {
                SDL_Point MousePoint ={e.button.x, e.button.y};
                if(SDL_PointInRect(&MousePoint, &StartRect))
                {
                    UpdateCreateMap(window, renderer, Money, Food);//Cap nhat map, money, food
                }
            }
        }

    }
    SDL_DestroyTexture(background);
    background = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    quitSDL(window, renderer);
    return 0;
}

