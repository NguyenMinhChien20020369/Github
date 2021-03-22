#ifndef Snake_h
#define Snake_h

#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Position.h"
#include "Point.h"

using namespace std;

struct Snake
{
    Position position;
    int size=10;
    int stepX=0;
    int stepY=0;
    int num=10;
    int times=0;
    vector<Position> position_arr;

    Snake(int _x,int _y)
    {
        this->position.x=_x;
        this->position.y=_y;
    }
    void render(SDL_Renderer* renderer)
    {
        for(int i=0; i<position_arr.size(); i++)
        {
            SDL_Rect filled_rect;
            filled_rect.x=position_arr[i].x;
            filled_rect.y=position_arr[i].y;
            filled_rect.w=size;
            filled_rect.h=size;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRect(renderer, &filled_rect);
        }
    }

    void move()
    {
        for(int i=position_arr.size()-1; i>0; i--)
        {
            position_arr[i]=position_arr[i-1];
        }
        position_arr[0].x+=stepX;
        position_arr[0].y+=stepY;
        if(position_arr[0].y>SCREEN_HEIGHT)position_arr[0].y=0;
        if(position_arr[0].y<0)position_arr[0].y=SCREEN_HEIGHT-size;
        if(position_arr[0].x>SCREEN_WIDTH)position_arr[0].x=0;
        if(position_arr[0].x<0)position_arr[0].x=SCREEN_WIDTH-size;
    }

    void turnUp()
    {
        stepY=-num;
        stepX=0;
    }

    void turnDown()
    {
        stepY=num;
        stepX=0;
    }

    void turnLeft()
    {
        stepX=-num;
        stepY=0;
    }

    void turnRight()
    {
        stepX=num;
        stepY=0;
    }
    void eat(Point &point)
    {
        if(this->times==threshold_appears_big_point&&this->position_arr[0].x>=point.position.x&&this->position_arr[0].x<=point.position.x + point.size - this->size
                &&this->position_arr[0].y>=point.position.y&&this->position_arr[0].y<=point.position.y + point.size - this->size)
        {
            this->times=0;
            this->position_arr.push_back(point.position);
            point.position.x=(rand()%(SCREEN_WIDTH/10-1))*10;
            point.position.y=(rand()%(SCREEN_HEIGHT/10-1))*10;
            point.size=10;
        }
        else if(this->position_arr[0].x==point.position.x&&this->position_arr[0].y==point.position.y)
        {
            this->times++;
            this->position_arr.push_back(point.position);
            point.position.x=(rand()%(SCREEN_WIDTH/10))*10;
            point.position.y=(rand()%(SCREEN_HEIGHT/10))*10;
            if(this->times==threshold_appears_big_point)
            {
                point.size=20;
            }
        }
    }
};

#endif
