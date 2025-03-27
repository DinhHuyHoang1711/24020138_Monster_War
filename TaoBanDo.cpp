#include "TaoBanDo.h"

void UpdateCreateMap(SDL_Window* window, SDL_Renderer* renderer, int Money, int Food)
{
    SDL_Texture*  background = loadIMG("images\\bando.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderPresent(renderer);

}
