#include <bits/stdc++.h>
#include <SDL.h>
#include "Point.h"
#include "SDL_setup.h"

using namespace std;

void Point::render(SDL_Renderer* renderer)
{
    tempSurface=SDL_LoadBMP("food.bmp");
    texture=SDL_CreateTextureFromSurface(renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_QueryTexture(texture,NULL,NULL,&sourceRect.w,&sourceRect.h);
    sourceRect.x=0;
    sourceRect.y=0;
    desRect.x=position.x;
    desRect.y=position.y;
    desRect.w=size;
    desRect.h=size;
    SDL_RenderCopy(renderer,texture,&sourceRect, &desRect);
}
