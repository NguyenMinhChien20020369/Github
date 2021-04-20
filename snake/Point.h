#ifndef Point_h
#define Point_h

#include "Position.h"
#include <SDL.h>

struct Point
{
    int size;
    Position position;

    Point();

    void render(SDL_Renderer* renderer, SDL_Texture** Image) const;
};

#endif // Point_h
