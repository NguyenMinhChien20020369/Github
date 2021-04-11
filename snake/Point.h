#ifndef Point_h
#define Point_h

#include "Position.h"

struct Point
{
    int size=20;
    Position position;

    void render(SDL_Renderer* renderer);
};

#endif // Point_h
