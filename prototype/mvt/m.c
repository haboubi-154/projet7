#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

int main(int argc, char *argv[]){
int tp= 0, ta = 0, i=0;
float w;
int continuer=1;
    SDL_Event event;
SDL_Surface *map;
SDL_Surface *ball;
SDL_Surface *ecran=NULL;
map=IMG_Load("back2.jpg");
ball=IMG_Load("ball.bmp");
SDL_Rect pos,pos1;
pos.x=200;
pos.y=300;

w=(2*M_PI-M_PI/3);
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);



ecran=SDL_SetVideoMode(900,700,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
SDL_BlitSurface(map,NULL,ecran,NULL);
SDL_BlitSurface(ball,NULL,ecran,&pos);
SDL_Flip(ecran);

while (continuer)
    {

if(pos.y<302){
ta = SDL_GetTicks();


pos.y=(500*ta*ta/1000000)+(750*sin(w)*ta/1000)+300;
pos.x=750*cos(w)*ta/1000+200;
SDL_BlitSurface(map,NULL,ecran,NULL);
SDL_BlitSurface(ball,NULL,ecran,&pos);
SDL_Flip(ecran);
}


         
SDL_PollEvent(&event);

     







        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;

         
}
}

SDL_FreeSurface(map);
SDL_FreeSurface(ball);
SDL_Quit();

return 0;



}
