#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "h.h"


void scrolling(SDL_Rect *deg,SDL_Event event)
{


switch (event.key.keysym.sym){
case(SDLK_RIGHT):



(deg->x)=(deg->x)+10;



break;
case (SDLK_LEFT):



(deg->x)=(deg->x)-10;

break;
case (SDLK_UP):



(deg->y)--; 


break;
case (SDLK_DOWN):



(deg->y)++; 

break;
}
}

int colisionentiersec(SDL_Rect pos,SDL_Rect sec){
int c=0;
if(((pos.x+pos.w)<sec.x) ||(pos.x>sec.x+sec.w) || (pos.y+pos.h<sec.y) ||(pos.y>sec.y+sec.h))
c=0;
else
c=1;
return c;




}
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}

int colispar(SDL_Surface *masque,SDL_Rect pos,int h,int w)
{
int c=0;
pos.w=w;
pos.h=h;
SDL_Color color;
color.r=0;
color.g=0;
color.b=0;
int i=0;
int t[8][2];
t[0][0]=pos.x;
t[0][1]=pos.y;
t[1][0]=(pos.x+pos.w)/2;
t[1][1]=pos.y;;
t[2][0]=pos.x+pos.w;
t[2][1]=pos.y;
t[3][0]=pos.x;
t[3][1]=(pos.y+pos.h)/2;
t[4][0]=pos.x;
t[4][1]=pos.y+pos.h;
t[5][0]=(pos.x+pos.w)/2;
t[5][1]=pos.y+pos.w;
t[6][0]=pos.x+pos.w;
t[6][1]=pos.y+pos.h;
t[7][0]=pos.x+pos.w;
t[7][0]=pos.y+pos.h;





while(i<8 && c==0){
if(GetPixel(masque,t[i][0],t[i][1]).r!=color.r && GetPixel(masque,t[i][0],t[i][1]).b!=color.b && GetPixel(masque,t[i][0],t[i][1]).g!=color.g){
i++;

}
else
c=1;
}

if(c==0)
return 0;

else
return 1;

}


