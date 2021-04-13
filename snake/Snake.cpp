#include <bits/stdc++.h>
#include <SDL.h>
#include "Snake.h"
#include "SDL_setup.h"

using namespace std;

Snake::Snake()
{
    this->positionH.x=20;
    this->positionH.y=0;
    this->positionT.x=0;
    this->positionT.y=0;
}

void Snake::render(SDL_Renderer* renderer,char* head)
{
    for(int i=0; i<position_arr.size(); i++)
    {
        if(i==0)
        {
            tempSurface=SDL_LoadBMP(head);
        }
        else if(i==position_arr.size()-1)
        {
            //1
            //2
            if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y+sizeS==position_arr[i].y)
            {
                tail="snake_tail_bot.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
            {
                tail="snake_tail_top.bmp";
            }
            //12
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail="snake_tail_right.bmp";
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail="snake_tail_left.bmp";
            }
            //2
            //1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS)
            {
                tail="snake_tail_top.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y)
            {
                tail="snake_tail_bot.bmp";
            }
            //21
            else if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y)
            {
                tail="snake_tail_left.bmp";
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y)
            {
                tail="snake_tail_right.bmp";
            }
            tempSurface=SDL_LoadBMP(tail);
        }
        else
        {
            //3
            //21
            if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x+sizeS&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i-1].x>position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body="snake_curved_bl.bmp";
            }
            //1
            //23
            else if(position_arr[i+1].x==position_arr[i].x+sizeS&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x+sizeS&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i+1].x>position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i+1].x>position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body="snake_curved_bl.bmp";
            }
            //21
            //3
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x+sizeS==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x+sizeS==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x<position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x<position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_lt.bmp";
            }
            //23
            //1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x+sizeS==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x<position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x+sizeS==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x<position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_lt.bmp";
            }
            //32
            // 1
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x==position_arr[i+1].x+sizeS&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x>position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x+sizeS&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y>position_arr[i].y&&
                    position_arr[i].x>position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y)
            {
                body="snake_curved_tr.bmp";
            }
            //12
            // 3
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x==position_arr[i-1].x+sizeS&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x+sizeS&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y+sizeS&&
                    position_arr[i].x>position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i+1].x==position_arr[i].x&&position_arr[i+1].y>position_arr[i].y&&
                    position_arr[i].x>position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y)
            {
                body="snake_curved_tr.bmp";
            }
            // 3
            //12
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i-1].x+sizeS==position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y==position_arr[i+1].y+sizeS)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i-1].x<position_arr[i].x&&position_arr[i-1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i+1].x&&position_arr[i].y>position_arr[i+1].y)
            {
                body="snake_curved_rb.bmp";
            }
            // 1
            //32
            else if(position_arr[i+1].x+sizeS==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body="snake_curved_lt.bmp";
            }
            else if(position_arr[i+1].x<position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y==position_arr[i-1].y+sizeS)
            {
                body="snake_curved_tr.bmp";
            }
            else if(position_arr[i+1].x+sizeS==position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body="snake_curved_bl.bmp";
            }
            else if(position_arr[i+1].x<position_arr[i].x&&position_arr[i+1].y==position_arr[i].y&&
                    position_arr[i].x==position_arr[i-1].x&&position_arr[i].y>position_arr[i-1].y)
            {
                body="snake_curved_rb.bmp";
            }
            else if(position_arr[i-1].x==position_arr[i].x&&position_arr[i-1].y<position_arr[i].y)
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

void Snake::move()
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
    if(position_arr[0].y>=SCREEN_HEIGHT)position_arr[0].y=0;
    if(position_arr[0].y<0)position_arr[0].y=SCREEN_HEIGHT-sizeS;
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

void Snake::eat(Point &point,long long& num_score,int& max_score)
{
    if(this->times==threshold_appears_big_point&&this->position_arr[0].x>point.position.x-sizeS&&this->position_arr[0].x<point.position.x + point.size
            &&this->position_arr[0].y>point.position.y-sizeS&&this->position_arr[0].y<point.position.y + point.size)
    {
        num_score+=max_score;
        this->times=0;
        this->position_arr.push_back(point.position);
        do
        {
            again=false;
            point.position.x=rand()%(SCREEN_WIDTH-point.size+1);
            point.position.y=rand()%(SCREEN_HEIGHT-point.size+1);
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
    }
    else if(this->position_arr[0].x>point.position.x-sizeS&&this->position_arr[0].x<point.position.x + point.size
            &&this->position_arr[0].y>point.position.y-sizeS&&this->position_arr[0].y<point.position.y + point.size)
    {
        num_score++;
        this->times++;
        this->position_arr.push_back(point.position);
        do
        {
            again=false;
            point.position.x=rand()%(SCREEN_WIDTH-point.size+1);
            point.position.y=rand()%(SCREEN_HEIGHT-point.size+1);
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
        }
    }
}















