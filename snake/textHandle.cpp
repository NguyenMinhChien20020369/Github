#include "textHandle.h"

using namespace std;

textHandle::textHandle()
{
    rect_.x=0;
    rect_.y=0;
    textSurface=NULL;
}

textHandle::~textHandle()
{
    ;
}

void textHandle::SetColor(const int& type)
{
    if(type==RED_TEXT)
    {
        SDL_Color color = {255,0,0};
        text_color_=color;
    }
    else if (type==WHITE_TEXT)
    {
        SDL_Color color = {255,255,0};
        text_color_=color;
    }
    else
    {
        SDL_Color color = {0,0,0};
        text_color_=color;
    }
}

void textHandle::CreateText(SDL_Texture* texture,SDL_Renderer* renderer,SDL_Rect& sourceRect)
{
    TTF_Font* font=TTF_OpenFont("Neverwinter.ttf",40);
    textSurface=TTF_RenderText_Solid(font,text_.c_str(),text_color_);
    texture=SDL_CreateTextureFromSurface(renderer,textSurface);
    SDL_FreeSurface(textSurface);
    TTF_SizeText(font,text_.c_str(),&sourceRect.w,&sourceRect.h);
    sourceRect.x=0;
    sourceRect.y=0;
    rect_.w=sourceRect.w;
    rect_.h=sourceRect.h;
    SDL_RenderCopy(renderer,texture,&sourceRect,&rect_);
};
