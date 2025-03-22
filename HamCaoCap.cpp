#include "HamCaoCap.h"
#include "ChuKiHam.h"

const char* WINDOW_TITLE = "Monsters_War";

void sanhcho()
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    SDL_Texture* background = loadTexture("images\\giaodien.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    background = loadTexture("images\\bando.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
}
