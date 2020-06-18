#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "h.h"

void affichetemps(SDL_Surface *ecran,SDL_Surface *texte,int ta,TTF_Font *police)
{
int sec=0;
char ch[20];
    SDL_Rect position;

   position.x=0;
position.y=0;
   
TTF_Init();
 SDL_Color coul = {0, 0, 0};
sec=ta/1000;
            sprintf(ch,"Temps: %d :%d :%d",sec/3600, sec%3600/60, sec%60);
printf("%s",ch);             
 //texte =TTF_RenderText_Blended(police, ch, coul);
//SDL_BlitSurface(texte,NULL,ecran,&position);
  //      SDL_Flip(ecran);




}
