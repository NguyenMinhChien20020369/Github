#ifndef Point_h
#define Point_h

#include "Position.h"

struct Point
{
    int size;
    Position position;

    Point();

    void render(SDL_Renderer* renderer,SDL_Surface* tempSurface, SDL_Texture** Image);
};

#endif // Point_h
