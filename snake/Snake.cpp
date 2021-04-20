#include <bits/stdc++.h>
#include <SDL.h>
#include "Snake.h"
#include "SDL_setup.h"

using namespace std;

Snake::Snake()
{
    this->positionH.x=num;
    this->positionH.y=46;
    this->positionT.x=0;
    this->positionT.y=46;
}

void Snake::render(SDL_Renderer* renderer,int& head,SDL_Surface* tempSurface, SDL_Texture** Image)
{
    for(int i=0; i<position_arr.size(); i++)
    {
        if(i==0)
        {
            texture=Image[head];
        }
        else if(i==position_arr.size()-1)
        {
            //1
            //2
            if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y+sizeS==position_arr[i].y)
            {
                tail=SNAKE_TAIL_BOT;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
            {
                tail=SNAKE_TAIL_TOP;
            }
            //12
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail=SNAKE_TAIL_RIGHT;
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail=SNAKE_TAIL_LEFT;
            }
            //2
            //1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS)
            {
                tail=SNAKE_TAIL_TOP;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y)
            {
                tail=SNAKE_TAIL_BOT;
            }
            //21
            else if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y)
            {
                tail=SNAKE_TAIL_LEFT;
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail=SNAKE_TAIL_RIGHT;
            }
            texture=Image[tail];
        }
        else
        {
            //3
            //21
            if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            //1
            //23
            else if(position_arr[i+1].x==position_arr[i].x+sizeS&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i+1].x==position_arr[i].x+sizeS&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i+1].x>position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i+1].x>position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            //21
            //3
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x+sizeS==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x+sizeS==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x<position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x<position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_LT;
            }
            //23
            //1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x+sizeS==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x<position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x+sizeS==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x<position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_LT;
            }
            //32
            // 1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x==position_arr[i+1].x+sizeS&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x>position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x+sizeS&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x>position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body=SNAKE_CURVED_TR;
            }
            //12
            // 3
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x==position_arr[i-1].x+sizeS&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x+sizeS&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x>position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x>position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body=SNAKE_CURVED_TR;
            }
            // 3
            //12
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            // 1
            //32
            else if(position_arr[i+1].x+sizeS==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body=SNAKE_CURVED_LT;
            }
            else if(position_arr[i+1].x<position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body=SNAKE_CURVED_TR;
            }
            else if(position_arr[i+1].x+sizeS==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body=SNAKE_CURVED_BL;
            }
            else if(position_arr[i+1].x<position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body=SNAKE_CURVED_RB;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
            {
                body=SNAKE_BODY_VERTICAL;
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                body=SNAKE_BODY_HORIZONTAL;
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y)
            {
                body=SNAKE_BODY_VERTICAL;
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                body=SNAKE_BODY_HORIZONTAL;
            }
            texture=Image[body];
        }
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

void Snake::move()
{
    if(!(stepX==0&&stepY==0))
    {
        for(int i=position_arr.size()-1; i>0; i--)
        {
            position_arr[i]=position_arr[i-1];
        }
    }
    position_arr[0].x+=stepX;
    position_arr[0].y+=stepY;
    if(position_arr[0].y>=SCREEN_HEIGHT)position_arr[0].y=46;
    if(position_arr[0].y<46)position_arr[0].y=SCREEN_HEIGHT-sizeS;
    if(position_arr[0].x>=SCREEN_WIDTH)position_arr[0].x=0;
    if(position_arr[0].x<0)position_arr[0].x=SCREEN_WIDTH-sizeS;
}

void Snake::turnUp()
{
    stepY=-num;
    stepX=0;
}

void Snake::turnDown()
{
    stepY=num;
    stepX=0;
}

void Snake::turnLeft()
{
    stepX=-num;
    stepY=0;
}

void Snake::turnRight()
{
    stepX=num;
    stepY=0;
}

void Snake::eat(Point &point,long long& num_score,int& max_score,int& time_big_point_appears,int& time_to_minus, int& wallSize)
{
    if(time_to_minus==5000)
    {
        this->times=0;
        do
        {
            again=false;
            point.position.x=wallSize+rand()%(SCREEN_WIDTH-point.size-2*wallSize+1);
            point.position.y=wallSize+46+(rand()%(SCREEN_HEIGHT-point.size-46-2*wallSize+1));
            for(int i=0; i<position_arr.size(); i++)
            {
                if(point.position.x>position_arr[i].x-point.size&&point.position.x<position_arr[i].x+sizeS
                        &&point.position.y>position_arr[i].y-point.size&&point.position.y<position_arr[i].y+sizeS)
                {
                    again=true;
                    break;
                }
            }
        }
        while(again);
        point.size=20;
        time_to_minus=1000;
        max_score=500;
    }
    if(times==threshold_appears_big_point&&SDL_GetTicks()-time_big_point_appears>time_to_minus)
    {
        time_to_minus+=1000;
        max_score-=(500-100)/4;
    }
    if(this->times==threshold_appears_big_point&&this->position_arr[0].x>point.position.x-sizeS&&this->position_arr[0].x<point.position.x + point.size
            &&this->position_arr[0].y>point.position.y-sizeS&&this->position_arr[0].y<point.position.y + point.size)
    {
        chunk=Mix_LoadWAV("eat_big_point.wav");
        Mix_PlayChannel(-1,chunk,0);
        num_score+=max_score;
        this->times=0;
        this->position_arr.push_back(point.position);
        do
        {
            again=false;
            point.position.x=wallSize+rand()%(SCREEN_WIDTH-point.size-2*wallSize+1);
            point.position.y=wallSize+46+(rand()%(SCREEN_HEIGHT-point.size-46-2*wallSize+1));
            for(int i=0; i<position_arr.size(); i++)
            {
                if(point.position.x>position_arr[i].x-point.size&&point.position.x<position_arr[i].x+sizeS
                        &&point.position.y>position_arr[i].y-point.size&&point.position.y<position_arr[i].y+sizeS)
                {
                    again=true;
                    break;
                }
            }
        }
        while(again);
        point.size=20;
        time_to_minus=1000;
        max_score=500;
    }
    else if(this->position_arr[0].x>point.position.x-sizeS&&this->position_arr[0].x<point.position.x + point.size
            &&this->position_arr[0].y>point.position.y-sizeS&&this->position_arr[0].y<point.position.y + point.size)
    {
        num_score+=8;
        this->times++;
        this->position_arr.push_back(point.position);
        do
        {
            again=false;
            point.position.x=wallSize+rand()%(SCREEN_WIDTH-point.size-2*wallSize+1);
            point.position.y=wallSize+46+(rand()%(SCREEN_HEIGHT-point.size-46-2*wallSize+1));
            for(int i=0; i<position_arr.size(); i++)
            {
                if(point.position.x>position_arr[i].x-point.size&&point.position.x<position_arr[i].x+sizeS
                        &&point.position.y>position_arr[i].y-point.size&&point.position.y<position_arr[i].y+sizeS)
                {
                    again=true;
                    break;
                }
            }
        }
        while(again);
        if(this->times==threshold_appears_big_point)
        {
            point.size=30;
            time_big_point_appears=SDL_GetTicks();
            //ting
            chunk=Mix_LoadWAV("eat_and_appears.wav");
            Mix_PlayChannel(-1,chunk,0);
        }
        else
        {
            //xoet
            chunk=Mix_LoadWAV("eat_small_point.wav");
            Mix_PlayChannel(-1,chunk,0);
        }
    }
}
