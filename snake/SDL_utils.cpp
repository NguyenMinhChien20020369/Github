#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE="Snake";

void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os<<msg<<" Error: "<<SDL_GetError()<<endl;
    if (fatal){
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
        logSDLError(cout, "SDL_Init",true);

    window= SDL_CreateWindow(WINDOW_TITLE.c_str(),SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if (window ==nullptr) logSDLError(cout,"CreateWindow",true);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC);
    //renderer=SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer==nullptr) logSDLError(cout,"CreateRenderer",true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
};

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if(SDL_WaitEvent(&e)!=0&&
           (e.type==SDL_KEYDOWN||e.type==SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
