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
    Position positionH,positionT;
    int sizeS=20;
    int stepX=20;
    int stepY=0;
    int num=20;
    int times=0;
    vector <Position> position_arr;

    Snake()
    {
        this->positionH.x=20;
        this->positionH.y=0;
        this->positionT.x=0;
        this->positionT.y=0;
    }

    void render(SDL_Renderer* renderer)
    {
        for(int i=0; i<position_arr.size(); i++)
        {
            if(i==0)
            {
                tempSurface=SDL_LoadBMP(head);
            }
            else if(i==position_arr.size()-1)
            {
                if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
                {
                    tail="snake_tail_bot.bmp";
                }
                else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
                {
                    tail="snake_tail_right.bmp";
                }
                else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y)
                {
                    tail="snake_tail_top.bmp";
                }
                else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
                {
                    tail="snake_tail_left.bmp";
                }
                tempSurface=SDL_LoadBMP(tail);
            }
            else
            {
                if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
                {
                    body="snake_body_vertical.bmp";
                }
                else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
                {
                    body="snake_body_horizontal.bmp";
                }
                else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y)
                {
                    body="snake_body_vertical.bmp";
                }
                else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
                {
                    body="snake_body_horizontal.bmp";
                }
                tempSurface=SDL_LoadBMP(body);
            }
            texture=SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_FreeSurface(tempSurface);
            SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w,&sourceRect.h);
            sourceRect.x=0;
            sourceRect.y=0;
            desRect.x=position_arr[i].x;
            desRect.y=position_arr[i].y;
            desRect.w=sizeS;
            desRect.h=sizeS;
            SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
        }
    }

    void move()
    {
        if(!(position_arr.size()==2&&position_arr[0].x==20&&position_arr[0].y==0&&position_arr[1].x==0&&position_arr[1].x==0))
        {
            for(int i=position_arr.size()-1; i>0; i--)
            {
                position_arr[i]=position_arr[i-1];
            }
        }
        position_arr[0].x+=stepX;
        position_arr[0].y+=stepY;
        if(position_arr[0].y>SCREEN_HEIGHT)position_arr[0].y=0;
        if(position_arr[0].y<0)position_arr[0].y=SCREEN_HEIGHT-sizeS;
        if(position_arr[0].x>SCREEN_WIDTH)position_arr[0].x=0;
        if(position_arr[0].x<0)position_arr[0].x=SCREEN_WIDTH-sizeS;
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
        if(this->times==threshold_appears_big_point&&this->position_arr[0].x>=point.position.x-10&&this->position_arr[0].x<point.position.x + point.size
                &&this->position_arr[0].y>=point.position.y-10&&this->position_arr[0].y<point.position.y + point.size)
        {
            this->times=0;
            this->position_arr.push_back(point.position);
            point.position.x=(rand()%(SCREEN_WIDTH/10-1))*10;
            point.position.y=(rand()%(SCREEN_HEIGHT/10-1))*10;
            point.size=20;
        }
        else if(this->position_arr[0].x>=point.position.x-10&&this->position_arr[0].x<point.position.x + point.size
                &&this->position_arr[0].y>=point.position.y-10&&this->position_arr[0].y<point.position.y + point.size)
        {
            this->times++;
            this->position_arr.push_back(point.position);
            point.position.x=(rand()%(SCREEN_WIDTH/10))*10;
            point.position.y=(rand()%(SCREEN_HEIGHT/10))*10;
            if(this->times==threshold_appears_big_point)
            {
                point.size=30;
            }
        }
    }
};

#endif
