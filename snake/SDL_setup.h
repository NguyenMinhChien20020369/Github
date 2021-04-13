#ifndef SDL_utils_h
#define SDL_utils_h

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "textHandle.h"

using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const string WINDOW_TITLE="Snake";
static const int time_delay=100;
static const int threshold_appears_big_point=5;
static SDL_Window* window=NULL;
static SDL_Renderer* renderer=NULL;
static SDL_Surface* tempSurface=NULL;
static SDL_Surface* img_menu=NULL;
static SDL_Texture* texture=NULL;
static SDL_Event e,befor;
static SDL_Rect sourceRect;
static SDL_Rect desRect;
static int number=1;
static char* head="snake_head_right.bmp";
static char* tail=NULL;
static char* body=NULL;
static bool again;
static long long num_score=0;

void logSDLError(ostream& os, const string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void printScore(SDL_Renderer* renderer,long long& num_score);
int menu(SDL_Renderer* renderer);
bool inRect(const int& x,const int& y,const SDL_Rect& rect);

#endif // SDL_utils_h
