#ifndef Snake_h
#define Snake_h

#include "Position.h"
#include "Point.h"

struct Snake
{
    Position positionH,positionT;
    int sizeS=20;
    int num=20;
    int stepX=0;
    int stepY=0;
    int times=0;
    vector <Position> position_arr;

    Snake();

    void render(SDL_Renderer* renderer,int& head,SDL_Surface* tempSurface, SDL_Texture** Image);
    void move();
    void turnUp();
    void turnDown();
    void turnLeft();
    void turnRight();
    void eat(Point &point,long long& num_score, int& max_score,int& time_big_point_appears, int& time_to_minus, int& wallSize);
};

#endif
