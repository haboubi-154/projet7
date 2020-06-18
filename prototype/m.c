#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>




int colispar(SDL_Surface *masque,SDL_Rect pos,int h,int w)
{
int c;
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
printf("%d",i);
if(c==0)
return 0;

else
return 1;

}
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
    
    // Coloration de la surface ecran en bleu-vert
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

    SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */

    pause();

    SDL_Quit();

    return EXIT_SUCCESS;
 

}
