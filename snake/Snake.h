#ifndef Snake_h
#define Snake_h

#include "Position.h"
#include "Point.h"

using namespace std;

struct Snake
{
    Position positionH, positionT;
    int sizeS, num, stepX, stepY, times;
    vector <Position> position_arr;

    Snake();

    void render(SDL_Renderer* renderer, const int& head, SDL_Texture** const Image) const;
    void move();
    void turnUp();
    void turnDown();
    void turnLeft();
    void turnRight();
    void eat(Point& point, long long& num_score, int& time_to_minus, const int& wallSize);
};

#endif
