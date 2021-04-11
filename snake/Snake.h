#ifndef Snake_h
#define Snake_h

#include "Position.h"
#include "Point.h"

struct Snake
{
    Position positionH,positionT;
    int sizeS=20;
    int stepX=20;
    int stepY=0;
    int num=20;
    int times=0;
    vector <Position> position_arr;

    Snake();

    void render(SDL_Renderer* renderer,char* head);
    void move();
    void turnUp();
    void turnDown();
    void turnLeft();
    void turnRight();
    void eat(Point &point);
};

#endif
