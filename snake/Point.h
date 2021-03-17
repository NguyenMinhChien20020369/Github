#ifndef Point_h
#define Point_h

#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Position.h"

using namespace std;

struct Point {
    int size=10;
    Position position;

    void render(SDL_Renderer* renderer)
    {
        SDL_Rect filled_rect;
        filled_rect.x=this->position.x;
        filled_rect.y=this->position.y;
        filled_rect.w=this->size;
        filled_rect.h=this->size;
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
        SDL_RenderFillRect(renderer,&filled_rect);
    }
};

#endif // Point_h
