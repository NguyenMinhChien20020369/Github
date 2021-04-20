#ifndef TEXT_HANDLE_H_
#define TEXT_HANDLE_H_

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

struct textHandle
{
    string text_;
    SDL_Color text_color_;
    SDL_Surface* textSurface;
    SDL_Rect rect_;

    enum TextColor
    {
        RED_TEXT =0 ,
        WHITE_TEXT =1,
        BLACK_TEXT =2,
    };

    textHandle();
    ~textHandle();
    SDL_Rect GetRect() const {return rect_;}
    void SetRect(const int& x, const int& y){rect_.x=x;rect_.y=y;}
    void SetText(const string text){text_=text;}
    void SetColor(const int& type);
    void CreateText(SDL_Texture* texture,SDL_Renderer* renderer,SDL_Rect& sourceRect);
};

#endif // TEXT_HANDLE_H_
