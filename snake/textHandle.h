#ifndef TEXT_HANDLE_H_
#define TEXT_HANDLE_H_

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_setup.h"

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
        BLACK_TEXT =1,
    };

    textHandle();
    ~textHandle();
    void SetRect(const int& x, const int& y);
    void SetText(const string text);
    void SetColor(const int& type);
    void CreateText(SDL_Renderer* renderer, const char* fontType, const int& fontSize);
};

#endif // TEXT_HANDLE_H_
