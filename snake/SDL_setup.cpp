#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"

using namespace std;

bool inRect(const int& x,const int& y,const SDL_Rect& rect)
{
    return (x>=rect.x&&x<=rect.x+rect.w&&y>=rect.y&&y<=rect.y+rect.h);
}

void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os<<msg<<" Error: "<<SDL_GetError()<<endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

bool initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        logSDLError(cout, "SDL_Init",true);
        return false;
    }

    if(TTF_Init()<0)
    {
        cout<<"TTF_Init"<<" Error: "<<TTF_GetError()<<endl;
        return false;
    };

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,2048)==-1)
    {
        cout<<"Mix_OpenAudio"<<" Error: "<<Mix_GetError()<<endl;
        return false;
    }

    window= SDL_CreateWindow(WINDOW_TITLE.c_str(),SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if (window ==nullptr) logSDLError(cout,"CreateWindow",true);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |
                                SDL_RENDERER_PRESENTVSYNC);
    //renderer=SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer==nullptr) logSDLError(cout,"CreateRenderer",true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
    return true;
};

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
};

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if(SDL_WaitEvent(&e)!=0&&
                (e.type==SDL_KEYDOWN||e.type==SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

int menu_first(SDL_Renderer* renderer)
{
    SDL_Rect pos_arr[boxnum_of_menu_first];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;
    pos_arr[2].x=100;
    pos_arr[2].y=300;

    textHandle text_menu[boxnum_of_menu_first];
    text_menu[0].SetText("New game");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Game type");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    text_menu[2].SetText("Exit");
    text_menu[2].SetColor(textHandle::BLACK_TEXT);
    text_menu[2].SetRect(pos_arr[2].x,pos_arr[2].y);

    bool selected[boxnum_of_menu_first]= {0, 0, 0};
    int xm=0;
    int ym=0;

    SDL_Event m_event;
    while(true)
    {
        tempSurface=SDL_LoadBMP("menu.bmp");
        if(tempSurface==NULL)
        {
            return boxnum_of_menu_first-1;
        }
        texture=SDL_CreateTextureFromSurface(renderer,tempSurface);
        SDL_FreeSurface(tempSurface);
        SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w,&sourceRect.h);
        sourceRect.x=0;
        sourceRect.y=0;
        desRect.x=0;
        desRect.y=0;
        desRect.w=SCREEN_WIDTH;
        desRect.h=SCREEN_HEIGHT;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
        for(int i=0; i<boxnum_of_menu_first; i++)
        {
            text_menu[i].CreateText(renderer);
        }
        if(SDL_PollEvent(&m_event)!=0)
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                return boxnum_of_menu_first-1;
            case SDL_MOUSEMOTION:
            {
                xm=m_event.motion.x;
                ym=m_event.motion.y;
                for(int i=0; i<boxnum_of_menu_first; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        if(selected[i]==false)
                        {
                            selected[i]=true;
                            text_menu[i].SetColor(textHandle::RED_TEXT);
                            chunk=Mix_LoadWAV("tick.wav");
                            Mix_PlayChannel(-1,chunk,0);
                        }
                    }
                    else
                    {
                        if(selected[i]==true)
                        {
                            selected[i]=false;
                            text_menu[i].SetColor(textHandle::BLACK_TEXT);
                        }
                    }
                }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                xm=m_event.button.x;
                ym=m_event.button.y;
                for(int i=0; i<boxnum_of_menu_first; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        return i;
                    }
                }
            }
            break;
            default:
                break;
            }
        }
        SDL_RenderPresent(renderer);
    }
}

void menu_type(SDL_Renderer* renderer, bool& again, int& ret_menu_type, SDL_Texture** Image, int& wallSize)
{
    SDL_Rect pos_arr[boxnum_of_menu_type];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;

    textHandle text_menu[boxnum_of_menu_type];
    text_menu[0].SetText("Classic");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Box");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    bool selected[boxnum_of_menu_type]= {0, 0};
    int xm=0;
    int ym=0;

    SDL_Event m_event;
    while(true)
    {
        texture=Image[MENU];
        SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w,&sourceRect.h);
        sourceRect.x=0;
        sourceRect.y=0;
        desRect.x=0;
        desRect.y=0;
        desRect.w=SCREEN_WIDTH;
        desRect.h=SCREEN_HEIGHT;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
        for(int i=0; i<boxnum_of_menu_type; i++)
        {
            text_menu[i].CreateText(renderer);
        }
        if(SDL_PollEvent(&m_event)!=0)
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                return;
            case SDL_MOUSEMOTION:
            {
                xm=m_event.motion.x;
                ym=m_event.motion.y;
                for(int i=0; i<boxnum_of_menu_type; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        if(selected[i]==false)
                        {
                            selected[i]=true;
                            text_menu[i].SetColor(textHandle::RED_TEXT);
                            chunk=Mix_LoadWAV("tick.wav");
                            Mix_PlayChannel(-1,chunk,0);
                        }
                    }
                    else
                    {
                        if(selected[i]==true)
                        {
                            selected[i]=false;
                            text_menu[i].SetColor(textHandle::BLACK_TEXT);
                        }
                    }
                }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                xm=m_event.button.x;
                ym=m_event.button.y;
                for(int i=0; i<boxnum_of_menu_type; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        ret_menu_type=i;
                        if(i==boxnum_of_menu_type-1)
                        {
                            wallSize=20;
                        }else wallSize=0;
                        again=true;
                        return;
                    }
                }
            }
            break;
            default:
                break;
            }
        }
        SDL_RenderPresent(renderer);
    }
}

int menu_final(SDL_Renderer* renderer,long long& num_score)
{
    SDL_Rect pos_arr[boxnum_of_menu_final];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;

    textHandle text_menu[boxnum_of_menu_final];
    text_menu[0].SetText("Play again");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    bool selected[boxnum_of_menu_final]= {0,0};
    int xm=0;
    int ym=0;

    SDL_Event m_event;
    while(true)
    {
        tempSurface=SDL_LoadBMP("menu.bmp");
        if(tempSurface==NULL)
        {
            return 1;
        }
        texture=SDL_CreateTextureFromSurface(renderer,tempSurface);
        SDL_FreeSurface(tempSurface);
        SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w,&sourceRect.h);
        sourceRect.x=0;
        sourceRect.y=0;
        desRect.x=0;
        desRect.y=0;
        desRect.w=SCREEN_WIDTH;
        desRect.h=SCREEN_HEIGHT;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
        printScore(renderer,num_score,"Your score: ");
        for(int i=0; i<boxnum_of_menu_final; i++)
        {
            text_menu[i].CreateText(renderer);
        }
        if(SDL_PollEvent(&m_event)!=0)
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
            {
                xm=m_event.motion.x;
                ym=m_event.motion.y;
                for(int i=0; i<boxnum_of_menu_final; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        if(selected[i]==false)
                        {
                            selected[i]=true;
                            text_menu[i].SetColor(textHandle::RED_TEXT);
                            chunk=Mix_LoadWAV("tick.wav");
                            Mix_PlayChannel(-1,chunk,0);
                        }
                    }
                    else
                    {
                        if(selected[i]==true)
                        {
                            selected[i]=false;
                            text_menu[i].SetColor(textHandle::BLACK_TEXT);
                        }
                    }
                }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                xm=m_event.button.x;
                ym=m_event.button.y;
                for(int i=0; i<boxnum_of_menu_final; i++)
                {
                    if(inRect(xm,ym,text_menu[i].rect_))
                    {
                        return i;
                    }
                }
            }
            break;
            case SDL_KEYDOWN:
                if(m_event.key.keysym.sym==SDLK_ESCAPE)
                {
                    return 1;
                }
                break;
            default:
                break;
            }
        }
        SDL_RenderPresent(renderer);
    }
}

void open_menu_final(SDL_Renderer* renderer,long long& num_score,bool& play,SDL_Event& befor,int& head,Snake& snake,Point& point, int& ret_menu_type, int& wallSize, int& time_to_minus, int& max_score)
{
    int ret_menu_final=menu_final(renderer,num_score);
    if(ret_menu_final==1)
    {
        play=false;
    }
    else
    {
        snake.times=0;
        point.size=20;
        time_to_minus=1000;
        max_score=500;
        befor.key.keysym.sym=SDLK_d;
        head=SNAKE_HEAD_RIGHT;
        snake.stepX=0;
        snake.stepY=0;
        num_score=0;
        snake.position_arr.erase(snake.position_arr.begin(),snake.position_arr.begin()+snake.position_arr.size());
        snake.position_arr.push_back(snake.positionH);
        snake.position_arr.push_back(snake.positionT);
        if(ret_menu_type==boxnum_of_menu_type-1)
        {
            snake.position_arr[0].x=snake.num*2;
            snake.position_arr[0].y=46+snake.num;
            snake.position_arr[1].x=snake.num;
            snake.position_arr[1].y=46+snake.num;
        }
        do
        {
            again=false;
            point.position.x=wallSize+rand()%(SCREEN_WIDTH-point.size-2*wallSize+1);
            point.position.y=wallSize+46+(rand()%(SCREEN_HEIGHT-point.size-46-2*wallSize+1));
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
        chunk=Mix_LoadWAV("changebrg.wav");
        Mix_PlayChannel(-1,chunk,0);
    }
}

void printScore(SDL_Renderer* renderer,long long& num_score,string _mes_score)
{
    string mes_score=_mes_score+to_string(num_score);
    textHandle score;
    score.SetRect(SCREEN_WIDTH/2,0);
    score.SetColor(textHandle::BLACK_TEXT);
    score.SetText(mes_score);
    score.CreateText(renderer);
}

void printTime(SDL_Renderer* renderer,int& time_to_minus)
{
    string mes_time="Time: "+to_string(5-time_to_minus/1000);
    textHandle time;
    time.SetRect(0,0);
    time.SetColor(textHandle::BLACK_TEXT);
    time.SetText(mes_time);
    time.CreateText(renderer);
}

void printWall(SDL_Renderer* renderer, Snake& snake, SDL_Rect& box, bool& play, Point& point, SDL_Texture** Image, int& ret_menu_type, int& head, SDL_Event& befor, int& wallSize, long long& num_score, int& time_to_minus, int& max_score)
{
    if(ret_menu_type!=boxnum_of_menu_type-1)
    {
        return;
    }
    if(!(inRect(snake.position_arr[0].x,snake.position_arr[0].y,box)))
    {
        chunk=Mix_LoadWAV("die.wav");
        Mix_PlayChannel(-1,chunk,0);
        SDL_Delay(2000);
        open_menu_final(renderer,num_score,play,befor,head,snake,point,ret_menu_type,wallSize,time_to_minus, max_score);
    }
    texture=Image[WALL];
    SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w,&sourceRect.h);
    sourceRect.x=0;
    sourceRect.y=0;
    desRect.y=46;
    desRect.w=20;
    desRect.h=20;
    for(int i=0; i<=SCREEN_WIDTH-20; i+=20)
    {
        desRect.x=i;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
    }
    desRect.y=SCREEN_HEIGHT-20;
    for(int i=0; i<=SCREEN_WIDTH-20; i+=20)
    {
        desRect.x=i;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
    }
    desRect.x=0;
    for(int i=46; i<=SCREEN_WIDTH-20; i+=20)
    {
        desRect.y=i;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
    }
    desRect.x=SCREEN_WIDTH-20;
    for(int i=46; i<=SCREEN_WIDTH-20; i+=20)
    {
        desRect.y=i;
        SDL_RenderCopy(renderer,texture,&sourceRect,&desRect);
    }
}

SDL_Texture* create_texture(string name_texture, SDL_Renderer* renderer)
{
    SDL_Surface* surface_=SDL_LoadBMP(name_texture.c_str());
    SDL_SetColorKey(surface_, SDL_TRUE, SDL_MapRGB(surface_->format, 255, 255, 255));
    SDL_Texture* texture_=SDL_CreateTextureFromSurface(renderer, surface_);
    SDL_FreeSurface(surface_);
    return texture_;
}

void gameImage(SDL_Texture** Image, SDL_Renderer* renderer)
{
    Image[FOOD]= create_texture("food.bmp", renderer);
    Image[MENU]= create_texture("menu.bmp", renderer);
    Image[SNAKE_BODY_HORIZONTAL]= create_texture("snake_body_horizontal.bmp", renderer);
    Image[SNAKE_BODY_VERTICAL]= create_texture("snake_body_vertical.bmp", renderer);
    Image[SNAKE_CURVED_BL]= create_texture("snake_curved_bl.bmp", renderer);
    Image[SNAKE_CURVED_LT]= create_texture("snake_curved_lt.bmp", renderer);
    Image[SNAKE_CURVED_RB]= create_texture("snake_curved_rb.bmp", renderer);
    Image[SNAKE_CURVED_TR]= create_texture("snake_curved_tr.bmp", renderer);
    Image[SNAKE_HEAD_BOT]= create_texture("snake_head_bot.bmp", renderer);
    Image[SNAKE_HEAD_LEFT]= create_texture("snake_head_left.bmp", renderer);
    Image[SNAKE_HEAD_RIGHT]= create_texture("snake_head_right.bmp", renderer);
    Image[SNAKE_HEAD_TOP]= create_texture("snake_head_top.bmp", renderer);
    Image[SNAKE_TAIL_BOT]= create_texture("snake_tail_bot.bmp", renderer);
    Image[SNAKE_TAIL_LEFT]= create_texture("snake_tail_left.bmp", renderer);
    Image[SNAKE_TAIL_RIGHT]= create_texture("snake_tail_right.bmp", renderer);
    Image[SNAKE_TAIL_TOP]= create_texture("snake_tail_top.bmp", renderer);
    Image[WALL]= create_texture("wall.bmp", renderer);
}
