#ifndef Position_h
#define Position_h

#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Position.h"

using namespace std;

struct Position{
    int size=10;
    int x=(rand()%(SCREEN_WIDTH/10-size+1))*10;
    int y=(rand()%(SCREEN_HEIGHT/10-size+1))*10;
};

#endif // Position_h
