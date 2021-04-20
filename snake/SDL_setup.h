#ifndef SDL_setup_h
#define SDL_setup_h

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "textHandle.h"
#include "Snake.h"
#include "Point.h"

using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 646;
static const string WINDOW_TITLE="Snake";
static const int time_delay=60;
static const int threshold_appears_big_point=5;
static const int boxnum_of_menu_first= 3;
static const int boxnum_of_menu_type= 2;
static const int boxnum_of_menu_final= 2;
static const int numImage= 17;
static SDL_Window* window=NULL;
static SDL_Renderer* renderer=NULL;
static SDL_Surface* tempSurface=NULL;
static SDL_Surface* img_menu=NULL;
static SDL_Texture* texture=NULL;
static Mix_Chunk* chunk=NULL;
static SDL_Event e,befor;
static SDL_Rect sourceRect;
static SDL_Rect desRect;
static int number=1;

enum ImageType
{
    FOOD= 0,
    MENU= 1,
    SNAKE_BODY_HORIZONTAL= 2,
    SNAKE_BODY_VERTICAL= 3,
    SNAKE_CURVED_BL= 4,
    SNAKE_CURVED_LT= 5,
    SNAKE_CURVED_RB= 6,
    SNAKE_CURVED_TR= 7,
    SNAKE_HEAD_BOT= 8,
    SNAKE_HEAD_LEFT= 9,
    SNAKE_HEAD_RIGHT= 10,
    SNAKE_HEAD_TOP= 11,
    SNAKE_TAIL_BOT= 12,
    SNAKE_TAIL_LEFT= 13,
    SNAKE_TAIL_RIGHT= 14,
    SNAKE_TAIL_TOP= 15,
    WALL= 16,
};

static int head=SNAKE_HEAD_RIGHT;
static int tail;
static int body;
static bool again;
static long long num_score=0;

void logSDLError(ostream& os, const string &msg, bool fatal);
bool initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void printScore(SDL_Renderer* renderer,long long& num_score,string _mes_score);
void printTime(SDL_Renderer* renderer,int& time_to_minus);
void printWall(SDL_Renderer* renderer, Snake& snake, SDL_Rect& box, bool& play, Point& point, SDL_Texture** Image, int& ret_menu_type, int& head, SDL_Event& befor, int& wallSize, long long& num_score, int& time_to_minus, int& max_score);
int menu_first(SDL_Renderer* renderer);
void menu_type(SDL_Renderer* renderer, bool& again, int& ret_menu_type, SDL_Texture** Image, int& wallSize);
int menu_final(SDL_Renderer* renderer, long long& num_score);
bool inRect(const int& x,const int& y,const SDL_Rect& rect);
void open_menu_final(SDL_Renderer* renderer,long long& num_score,bool& play,SDL_Event& befor,int& head,Snake& snake, Point& point, int& ret_menu_type, int& wallSize, int& time_to_minus, int& max_score);
SDL_Texture* create_texture(string name_texture, SDL_Renderer* renderer);
void gameImage(SDL_Texture** Image, SDL_Renderer* renderer);

#endif // SDL_setup_h
