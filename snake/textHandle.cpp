#include "textHandle.h"

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

void textHandle::SetRect(const int& x, const int& y)
{
    rect_.x=x;
    rect_.y=y;
}

void textHandle::SetText(const string text)
{
    text_=text;
}

void textHandle::SetColor(const int& type)
{
    if(type==RED_TEXT)
    {
        text_color_= {255,0,0};
    }
    else
    {
        text_color_= {0,0,0};
    }
}

void textHandle::CreateText(SDL_Renderer* renderer, const char* fontType, const int& fontSize)
{
    TTF_Font* font=TTF_OpenFont(fontType, fontSize);
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
