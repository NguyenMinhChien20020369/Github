#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_setup.h"

using namespace std;

bool inRect(const int& x,const int& y,const SDL_Rect& rect)
{
    return x>=rect.x&&x<=rect.x+rect.w&&y>=rect.y&&y<=rect.y+rect.h;
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
    const int boxnum_of_menu =2 ;
    SDL_Rect pos_arr[boxnum_of_menu];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;

    textHandle text_menu[boxnum_of_menu];
    text_menu[0].SetText("Play game");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    bool selected[boxnum_of_menu]= {0,0};
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
        for(int i=0; i<boxnum_of_menu; i++)
        {
            text_menu[i].CreateText(texture,renderer,sourceRect);
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
                for(int i=0; i<boxnum_of_menu; i++)
                {
                    if(inRect(xm,ym,text_menu[i].GetRect()))
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
                for(int i=0; i<boxnum_of_menu; i++)
                {
                    if(inRect(xm,ym,text_menu[i].GetRect()))
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

int menu_final(SDL_Renderer* renderer,long long& num_score)
{
    const int boxnum_of_menu =2 ;
    SDL_Rect pos_arr[boxnum_of_menu];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;

    textHandle text_menu[boxnum_of_menu];
    text_menu[0].SetText("Play again");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    bool selected[boxnum_of_menu]= {0,0};
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
        for(int i=0; i<boxnum_of_menu; i++)
        {
            text_menu[i].CreateText(texture,renderer,sourceRect);
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
                for(int i=0; i<boxnum_of_menu; i++)
                {
                    if(inRect(xm,ym,text_menu[i].GetRect()))
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
                for(int i=0; i<boxnum_of_menu; i++)
                {
                    if(inRect(xm,ym,text_menu[i].GetRect()))
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

void printScore(SDL_Renderer* renderer,long long& num_score,string _mes_score)
{
    string mes_score=_mes_score+to_string(num_score);
    textHandle score;
    score.SetRect(SCREEN_WIDTH/2,0);
    score.SetColor(textHandle::BLACK_TEXT);
    score.SetText(mes_score);
    score.CreateText(texture,renderer,sourceRect);
}

void printTime(SDL_Renderer* renderer,int& time_to_minus)
{
    string mes_time="Time: "+to_string(5-time_to_minus/1000);
    textHandle time;
    time.SetRect(0,0);
    time.SetColor(textHandle::BLACK_TEXT);
    time.SetText(mes_time);
    time.CreateText(texture,renderer,sourceRect);
}

void open_menu_final(SDL_Renderer* renderer,long long& num_score,bool& play,SDL_Event& befor,char* head,Snake& snake,Point& point)
{
    int ret_menu_final=menu_final(renderer,num_score);
    if(ret_menu_final==1)
    {
        play=false;
    }
    else
    {
        befor.key.keysym.sym=SDLK_d;
        head="snake_head_right.bmp";
        snake.stepX=0;
        snake.stepY=0;
        num_score=0;
        snake.position_arr.erase(snake.position_arr.begin(),snake.position_arr.begin()+snake.position_arr.size());
        snake.position_arr.push_back(snake.positionH);
        snake.position_arr.push_back(snake.positionT);
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
        chunk=Mix_LoadWAV("changebrg.wav");
        Mix_PlayChannel(-1,chunk,0);
    }
}
