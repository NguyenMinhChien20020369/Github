#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Snake.h"

using namespace std;

int main(int argc,char* argv[])
{
    srand(time(nullptr));
    if(!initSDL(window,renderer))
    {
        return -1;
    }
    bool play=true,Can_move;
    int max_score=500;
    int time_big_point_appears;
    int time_to_minus=1000;

    Snake snake;
    snake.position_arr.push_back(snake.positionH);
    snake.position_arr.push_back(snake.positionT);
    Point point;

    do
    {
        again=false;
        point.position.x=rand()%(SCREEN_WIDTH-point.size+1);
        point.position.y=rand()%(SCREEN_HEIGHT-point.size+1);
        for(int i=0; i<snake.position_arr.size(); i++)
        {
            if(point.position.x>snake.position_arr[i].x-point.size&&point.position.x<snake.position_arr[i].x+snake.sizeS
                    &&point.position.y>snake.position_arr[i].y-point.size&&point.position.y<snake.position_arr[i].y+snake.sizeS)
            {
                again=true;
                break;
            }
        }
    }
    while(again);

    int ret_menu_first=menu_first(renderer);
    if(ret_menu_first==1)
    {
        play=false;
    }

    chunk=Mix_LoadWAV("changebrg.wav");
    Mix_PlayChannel(-1,chunk,0);

    befor.key.keysym.sym=SDLK_d;

    while(play)
    {
        for(int i=1; i<snake.position_arr.size(); i++)
        {
            if(snake.position_arr[0].x==snake.position_arr[i].x&&snake.position_arr[0].y==snake.position_arr[i].y)
            {
                chunk=Mix_LoadWAV("die.wav");
                Mix_PlayChannel(-1,chunk,0);
                SDL_Delay(2000);
                open_menu_final(renderer,num_score,play,befor,head,snake,point);
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        snake.render(renderer,head);
        point.render(renderer);
        printScore(renderer,num_score,"Score: ");
        if(snake.times==threshold_appears_big_point)
        {
            printTime(renderer, time_to_minus);
        }

        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(window);

        SDL_Delay(time_delay);

        if(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT) play=false;
            if(e.type==SDL_KEYDOWN)
            {
                Can_move=true;
                if((befor.key.keysym.sym==SDLK_d||befor.key.keysym.sym==SDLK_RIGHT)&&(e.key.keysym.sym==SDLK_LEFT||e.key.keysym.sym==SDLK_a))
                {
                    Can_move=false;
                }
                if((befor.key.keysym.sym==SDLK_a||befor.key.keysym.sym==SDLK_LEFT)&&(e.key.keysym.sym==SDLK_RIGHT||e.key.keysym.sym==SDLK_d))
                {
                    Can_move=false;
                }
                if((befor.key.keysym.sym==SDLK_w||befor.key.keysym.sym==SDLK_UP)&&(e.key.keysym.sym==SDLK_DOWN||e.key.keysym.sym==SDLK_s))
                {
                    Can_move=false;
                }
                if((befor.key.keysym.sym==SDLK_s||befor.key.keysym.sym==SDLK_DOWN)&&(e.key.keysym.sym==SDLK_UP||e.key.keysym.sym==SDLK_w))
                {
                    Can_move=false;
                }
                if(Can_move)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        play=false;
                        break;
                    case SDLK_LEFT:
                        snake.turnLeft();
                        head="snake_head_left.bmp";
                        break;
                    case SDLK_RIGHT:
                        snake.turnRight();
                        head="snake_head_right.bmp";
                        break;
                    case SDLK_DOWN:
                        snake.turnDown();
                        head="snake_head_bot.bmp";
                        break;
                    case SDLK_UP:
                        snake.turnUp();
                        head="snake_head_top.bmp";
                        break;
                    case SDLK_a:
                        snake.turnLeft();
                        head="snake_head_left.bmp";
                        break;
                    case SDLK_d:
                        snake.turnRight();
                        head="snake_head_right.bmp";
                        break;
                    case SDLK_s:
                        snake.turnDown();
                        head="snake_head_bot.bmp";
                        break;
                    case SDLK_w:
                        snake.turnUp();
                        head="snake_head_top.bmp";
                        break;
                    default:
                        break;
                    }
                    befor.key.keysym.sym=e.key.keysym.sym;
                }
            }
        }
        snake.eat(point,num_score,max_score,time_big_point_appears,time_to_minus);
        snake.move();
    }
    quitSDL(window,renderer);
    return 0;
}
