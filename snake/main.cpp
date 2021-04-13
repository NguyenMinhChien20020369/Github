#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Snake.h"

using namespace std;

int main(int argc,char* argv[])
{
    srand(time(nullptr));
    initSDL(window,renderer);
    bool Exit=false,Can_move;

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

    int ret_menu=menu(renderer);
    if(ret_menu==1)
    {
        Exit=true;
    }

    while(true)
    {
        for(int i=1; i<snake.position_arr.size(); i++)
        {
            if(snake.position_arr[0].x==snake.position_arr[i].x&&snake.position_arr[0].y==snake.position_arr[i].y)Exit=true;
        }
        if(Exit)break;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        snake.render(renderer,head);
        point.render(renderer);

        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(window);

        SDL_Delay(time_delay);

        if(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT) break;
            if(e.type==SDL_KEYDOWN)
            {
                Can_move=true;
                if(befor.key.keysym.sym==SDLK_RIGHT&&e.key.keysym.sym==SDLK_LEFT)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_LEFT&&e.key.keysym.sym==SDLK_RIGHT)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_UP&&e.key.keysym.sym==SDLK_DOWN)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_DOWN&&e.key.keysym.sym==SDLK_UP)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_d&&e.key.keysym.sym==SDLK_a)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_a&&e.key.keysym.sym==SDLK_d)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_w&&e.key.keysym.sym==SDLK_s)
                {
                    Can_move=false;
                }
                if(befor.key.keysym.sym==SDLK_s&&e.key.keysym.sym==SDLK_w)
                {
                    Can_move=false;
                }
                if(Can_move)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        Exit=true;
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
                    if(Exit)break;
                    befor.key.keysym.sym=e.key.keysym.sym;
                }
            }
        }
        snake.eat(point);
        snake.move();
    }
    quitSDL(window,renderer);
    return 0;
}
