#include "Point.h"
#include "SDL_setup.h"

using namespace std;

Point::Point()
{
    size=20;
}

void Point::render(SDL_Renderer* renderer, SDL_Texture** Image) const
{
    texture= Image[FOOD];
    SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
    sourceRect.x=0;
    sourceRect.y=0;
    desRect.x=position.x;
    desRect.y=position.y;
    desRect.w=size;
    desRect.h=size;
    SDL_RenderCopy(renderer, texture, &sourceRect, &desRect);
}
