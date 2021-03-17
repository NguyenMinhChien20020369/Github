#ifndef SDL_utils_h
#define SDL_utils_h

#include <bits/stdc++.h>
#include <SDL.h>

using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const string WINDOW_TITLE="Snake";
static const int time_delay=50;
static const int threshold_appears_big_point=5;

void logSDLError(ostream& os, const string &msg, bool fatal);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

#endif // SDL_utils_h
