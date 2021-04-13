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

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
        logSDLError(cout, "SDL_Init",true);

    if(TTF_Init()<0)
    {
        cout<<"TTF_Init"<<" Error: "<<TTF_GetError()<<endl;
        TTF_Quit();
    };

    window= SDL_CreateWindow(WINDOW_TITLE.c_str(),SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if (window ==nullptr) logSDLError(cout,"CreateWindow",true);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |
                                SDL_RENDERER_PRESENTVSYNC);
    //renderer=SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer==nullptr) logSDLError(cout,"CreateRenderer",true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer,SCREEN_WIDTH,SCREEN_HEIGHT);
};

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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

int menu(SDL_Renderer* renderer)
{
    const int kMenuIntNum =2 ;
    SDL_Rect pos_arr[kMenuIntNum];
    pos_arr[0].x=100;
    pos_arr[0].y=200;
    pos_arr[1].x=100;
    pos_arr[1].y=250;

    textHandle text_menu[kMenuIntNum];
    text_menu[0].SetText("Play game");
    text_menu[0].SetColor(textHandle::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(textHandle::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

    bool selected[kMenuIntNum]= {0,0};
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
        for(int i=0; i<kMenuIntNum; i++)
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
                for(int i=0; i<kMenuIntNum; i++)
                {
                    if(inRect(xm,ym,text_menu[i].GetRect()))
                    {
                        if(selected[i]==false)
                        {
                            selected[i]=true;
                            text_menu[i].SetColor(textHandle::RED_TEXT);
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
                for(int i=0; i<kMenuIntNum; i++)
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

void printScore(SDL_Renderer* renderer,long long& num_score)
{
    string mes_score="Score: "+to_string(num_score);
    textHandle score;
    score.SetRect(SCREEN_WIDTH/2,0);
    score.SetColor(textHandle::BLACK_TEXT);
    score.SetText(mes_score);
    score.CreateText(texture,renderer,sourceRect);
}
