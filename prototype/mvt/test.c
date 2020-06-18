#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

int main(int argc, char *argv[]){
int tp= 0, ta = 0;
float w;
int continuer=1;
    SDL_Event event;
SDL_Surface *map;
SDL_Surface *ball;
SDL_Surface *ecran=NULL;
map=IMG_Load("back2.jpg");
ball=IMG_Load("ball.bmp");
SDL_Rect pos,pos1;
pos.x=400;
pos.y=0;
pos1.x=0;
pos1.y=0;
w=((2*M_PI)/10);
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


printf("pi=%f",M_PI);
ecran=SDL_SetVideoMode(700,700,32,SDL_SWSURFACE | SDL_DOUBLEBUF );

SDL_BlitSurface(ball,NULL,ecran,&pos);
SDL_Flip(ecran);

while (continuer)
    {
ta = SDL_GetTicks();
if(ta-tp>=30){
pos.x=200*(cos(w*ta/1000))+350;
pos.y=200*(sin(w*ta/1000));

SDL_BlitSurface(ball,NULL,ecran,&pos);
SDL_Flip(ecran);
tp=ta;
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
