#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Position.h"
#include "Point.h"
#include "Snake.h"

using namespace std;

int main(int argc,char* argv[])
{
    srand(time(nullptr));
    initSDL(window,renderer);
    bool Exit=false,Can_move;

    Snake snake(0,0);
    snake.position_arr.push_back(snake.position);
    Point point;

    while(true)
    {
        for(int i=1; i<snake.position_arr.size(); i++)
        {
            if(snake.position_arr[0].x==snake.position_arr[i].x&&snake.position_arr[0].y==snake.position_arr[i].y)Exit=true;
        }
        if(Exit)break;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        snake.render(renderer);
        point.render(renderer);

        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(window);

        SDL_Delay(time_delay);

        if(SDL_PollEvent(&e)==0) {}
        else
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
    };
    quitSDL(window,renderer);
    return 0;
}
