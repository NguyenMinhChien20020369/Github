#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE="Snake";
int time_delay=50;

struct Position{
    int size=10;
    int x=(rand()%(SCREEN_WIDTH/10-size+1))*10;
    int y=(rand()%(SCREEN_HEIGHT/10-size+1))*10;
};

struct Point {
    int size=10;
    Position position;

    void render(SDL_Renderer* renderer)
    {
        SDL_Rect filled_rect;
        filled_rect.x=this->position.x;
        filled_rect.y=this->position.y;
        filled_rect.w=this->size;
        filled_rect.h=this->size;
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
        SDL_RenderFillRect(renderer,&filled_rect);
    }
};

struct Snake {
    Position position;
    int size=10;
    int stepX=0;
    int stepY=0;
    int num=10;
    vector<Position> position_arr;

    Snake(int _x,int _y){
        this->position.x=_x;
        this->position.y=_y;
    }
    void render(SDL_Renderer* renderer)
    {
        for(int i=0;i<position_arr.size();i++)
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
        for(int i=position_arr.size()-1;i>0;i--){
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
    void eat(Point &point){
        if(this->position_arr[0].x==point.position.x&&this->position_arr[0].y==point.position.y){
            this->position_arr.push_back(point.position);
            point.position.x=(rand()%(SCREEN_WIDTH/10-size+1))*10;
            point.position.y=(rand()%(SCREEN_HEIGHT/10-size+1))*10;
        }
    }
};

int main(int argc,char* argv[])
{
    srand(time(nullptr));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window,renderer);
    bool Exit=false,Can_move;

    Snake snake(0,0);
    snake.position_arr.push_back(snake.position);
    Point point;

    SDL_Event e,befor;
    while(true){
        for(int i=1;i<snake.position_arr.size();i++){
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

        if(SDL_PollEvent(&e)==0){}else
            {
                if(e.type==SDL_QUIT) break;
                if(e.type==SDL_KEYDOWN)
                {
                    Can_move=true;
                    if(befor.key.keysym.sym==SDLK_RIGHT&&e.key.keysym.sym==SDLK_LEFT){
                    Can_move=false;}
                    if(befor.key.keysym.sym==SDLK_LEFT&&e.key.keysym.sym==SDLK_RIGHT){Can_move=false;}
                    if(befor.key.keysym.sym==SDLK_UP&&e.key.keysym.sym==SDLK_DOWN){Can_move=false;}
                    if(befor.key.keysym.sym==SDLK_DOWN&&e.key.keysym.sym==SDLK_UP){Can_move=false;}
                    if(Can_move){
                        switch (e.key.keysym.sym)
                        {
                            case SDLK_ESCAPE: Exit=true; break;
                            case SDLK_LEFT: snake.turnLeft(); break;
                            case SDLK_RIGHT: snake.turnRight(); break;
                            case SDLK_DOWN: snake.turnDown(); break;
                            case SDLK_UP: snake.turnUp(); break;
                            default: break;
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
