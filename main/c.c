#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "h.h"


void menu(SDL_Surface *ecran,SDL_Surface *b[14],SDL_Surface * background,SDL_Surface *back2,SDL_Rect pos1,SDL_Rect pos2,SDL_Rect posj,SDL_Rect poso,SDL_Rect posq,SDL_Rect posr,SDL_Rect pos3,SDL_Rect pos,SDL_Surface *texte,int ba,int e ){

if(ba==0 ){
 
    if(e==0){



SDL_BlitSurface(background,NULL,ecran,&pos);

SDL_BlitSurface(b[0],NULL,ecran,&posj);
SDL_BlitSurface(b[3],NULL,ecran,&poso);
SDL_BlitSurface(b[5],NULL,ecran,&posq);
SDL_Flip(ecran);
}
else if(e==1){
    SDL_BlitSurface(background,NULL,ecran,&pos);
SDL_BlitSurface(b[1],NULL,ecran,&posj);
SDL_BlitSurface(b[3],NULL,ecran,&poso);
SDL_BlitSurface(b[5],NULL,ecran,&posq);
SDL_Flip(ecran);
}
else if(e==2){
   SDL_BlitSurface(background,NULL,ecran,&pos);
SDL_BlitSurface(b[0],NULL,ecran,&posj);
SDL_BlitSurface(b[4],NULL,ecran,&poso);
SDL_BlitSurface(b[5],NULL,ecran,&posq);
SDL_Flip(ecran);

}
else if(e==3){

   SDL_BlitSurface(background,NULL,ecran,&pos);
SDL_BlitSurface(b[0],NULL,ecran,&posj);
SDL_BlitSurface(b[3],NULL,ecran,&poso);
SDL_BlitSurface(b[6],NULL,ecran,&posq);
SDL_Flip(ecran);
}
}

else if(ba==1){
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(back2, NULL, ecran, &pos); 
    SDL_BlitSurface(b[7],NULL,ecran,&posj);
    
    SDL_Flip(ecran);


}
else if(ba==2) {
    if(e==0){
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 SDL_BlitSurface(background, NULL, ecran, &pos);
 SDL_BlitSurface(b[9],NULL,ecran,&pos1);
 SDL_BlitSurface(b[11],NULL,ecran,&pos2);
 SDL_BlitSurface(b[7],NULL,ecran,&posj);
 SDL_BlitSurface(b[13],NULL,ecran,&pos3);

 SDL_Flip(ecran);
    }
else if(e==2)
{SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 SDL_BlitSurface(background, NULL, ecran, &pos);
 SDL_BlitSurface(b[10],NULL,ecran,&pos1);
 SDL_BlitSurface(b[11],NULL,ecran,&pos2);
 SDL_BlitSurface(b[7],NULL,ecran,&posj);
 SDL_BlitSurface(b[13],NULL,ecran,&pos3);

 SDL_Flip(ecran);

}
else if(e==3)
{
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 SDL_BlitSurface(background, NULL, ecran, &pos);
 SDL_BlitSurface(b[9],NULL,ecran,&pos1);
 SDL_BlitSurface(b[12],NULL,ecran,&pos2);
 SDL_BlitSurface(b[7],NULL,ecran,&posj);
 SDL_BlitSurface(b[13],NULL,ecran,&pos3);

 SDL_Flip(ecran);
}
else if(e==4)
{
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 SDL_BlitSurface(background, NULL, ecran, &pos);
 SDL_BlitSurface(b[9],NULL,ecran,&pos1);
 SDL_BlitSurface(b[11],NULL,ecran,&pos2);
 SDL_BlitSurface(b[7],NULL,ecran,&posj);
 SDL_BlitSurface(b[14],NULL,ecran,&pos3);

 SDL_Flip(ecran);

}

 
    

}
SDL_BlitSurface(texte,NULL,ecran,&posr);
SDL_Flip(ecran);








}







