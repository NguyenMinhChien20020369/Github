#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"
#include "Snake.h"

int main(int argc, char* argv[])
{
    srand(time(nullptr));
    if(!initSDL(window,renderer))
    {
        return -1;
    }
    bool play= true, Can_move;
    int time_to_minus= 1000;
    int ret_menu_type= 0;
    int wallSize= 20;

    Snake snake;
    snake.position_arr.push_back(snake.positionH);
    snake.position_arr.push_back(snake.positionT);
    Point point;

    SDL_Rect rect, box;

    rect.x=0;
    rect.y=0;
    rect.w=SCREEN_WIDTH;
    rect.h=SCORE_BOX_HEIGHT;

    box.x= wallSize;
    box.y= SCORE_BOX_HEIGHT+ wallSize;
    box.w= SCREEN_WIDTH-2*wallSize-snake.sizeS;
    box.h= SCREEN_HEIGHT-SCORE_BOX_HEIGHT-wallSize*2-snake.sizeS;

    SDL_Texture* Image[numImage];

    gameImage(Image, renderer);

    do
    {
        again=false;
        point.position.x=wallSize+rand()%(SCREEN_WIDTH-point.size-2*wallSize+1);
        point.position.y=wallSize+SCORE_BOX_HEIGHT+(rand()%(SCREEN_HEIGHT-point.size-2*wallSize+1));
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

    do
    {
        again=false;
        int ret_menu_first=menu_first(renderer, Image);
        if(ret_menu_first==boxnum_of_menu_first-1)
        {
            play=false;
        }
        else if(ret_menu_first==boxnum_of_menu_first-2)
        {
            menu_type(renderer, again, ret_menu_type, Image, wallSize);
        }
    }
    while(again);

    chunk=Mix_LoadWAV("changebrg.wav");
    Mix_PlayChannel(-1,chunk,0);

    befor.key.keysym.sym=SDLK_d;

    if(ret_menu_type==boxnum_of_menu_type-1)
    {
        snake.position_arr[0].x=snake.num*2;
        snake.position_arr[0].y=SCORE_BOX_HEIGHT+snake.num;
        snake.position_arr[1].x=snake.num;
        snake.position_arr[1].y=SCORE_BOX_HEIGHT+snake.num;
    }

    while(play)
    {
        SDL_SetRenderDrawColor(renderer, 185, 211, 238, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        printWall(renderer, snake, box, play, point, Image, ret_menu_type, head, befor, wallSize, num_score, time_to_minus, max_score, again);
        for(int i=1; i<snake.position_arr.size(); i++)
        {
            if(snake.position_arr[0].x==snake.position_arr[i].x&&snake.position_arr[0].y==snake.position_arr[i].y)
            {
                chunk=Mix_LoadWAV("die.wav");
                Mix_PlayChannel(-1,chunk,0);
                SDL_Delay(2000);
                open_menu_final(renderer,num_score,play,befor,head,snake,point,ret_menu_type,wallSize, time_to_minus, max_score,Image, again);
                if(!play) break;
            }
        }
        if(!play) break;
        snake.render(renderer, head, Image);
        point.render(renderer, Image);
        printScore(renderer, num_score, "Score: ");
        if(snake.times==threshold_appears_big_point)
        {
            printTime(renderer, time_to_minus);
        }

        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(window);

        SDL_Delay(speed);

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
                    case SDLK_LEFT:
                        snake.turnLeft();
                        head=SNAKE_HEAD_LEFT;
                        break;
                    case SDLK_RIGHT:
                        snake.turnRight();
                        head=SNAKE_HEAD_RIGHT;
                        break;
                    case SDLK_DOWN:
                        snake.turnDown();
                        head=SNAKE_HEAD_BOT;
                        break;
                    case SDLK_UP:
                        snake.turnUp();
                        head=SNAKE_HEAD_TOP;
                        break;
                    case SDLK_a:
                        snake.turnLeft();
                        head=SNAKE_HEAD_LEFT;
                        break;
                    case SDLK_d:
                        snake.turnRight();
                        head=SNAKE_HEAD_RIGHT;
                        break;
                    case SDLK_s:
                        snake.turnDown();
                        head=SNAKE_HEAD_BOT;
                        break;
                    case SDLK_w:
                        snake.turnUp();
                        head=SNAKE_HEAD_TOP;
                        break;
                    default:
                        break;
                    }
                    befor.key.keysym.sym=e.key.keysym.sym;
                }
            }
        }
        snake.eat(point, num_score, time_to_minus, wallSize);
        snake.move();
    }
    quitSDL(window,renderer);
    return 0;
}
