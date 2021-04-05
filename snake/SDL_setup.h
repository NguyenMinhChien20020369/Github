#ifndef SDL_utils_h
#define SDL_utils_h

#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const string WINDOW_TITLE="Snake";
static const int time_delay=100;
static const int threshold_appears_big_point=5;
static const int FPS = 60;
static const int DELAY_TIME = 1000 / FPS;
static SDL_Window* window=NULL;
static SDL_Renderer* renderer=NULL;
static SDL_Surface* tempSurface=NULL;
static SDL_Texture* texture=NULL;
static SDL_Event e,befor;
static SDL_Rect sourceRect;
static SDL_Rect desRect;
static int number=1;
static Uint32 frameStart;
static Uint32 frameTime;
static char* head="snake_head_right.bmp";
static char* tail=NULL;
static char* body=NULL;

void logSDLError(ostream& os, const string &msg, bool fatal);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

#endif // SDL_utils_h
