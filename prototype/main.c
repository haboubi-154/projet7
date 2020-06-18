#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "h.h"

int main(int argc, char *argv[]) 
{

enti e;

int ta=0;
int tp=0;
TTF_Font *police = NULL; 
int continuer = 1;
int i=0;
Imm curseur;
Imm mini_map;
initialiserenti(&e);
    SDL_Event event;
SDL_Surface *map;
SDL_Surface *masq;
SDL_Surface *anim;
    police = TTF_OpenFont("arial.ttf", 25);
SDL_Surface *ecran=NULL;
SDL_Surface *ball=NULL;
SDL_Surface *texte=NULL;

perso p;
initialiserperso(&p);
initmm(&p,&curseur,&mini_map);
loadmm(&curseur,&mini_map);
map=IMG_Load("map2.png");
masq=IMG_Load("masq.png");
ball=IMG_Load("ball.bmp");
anim=IMG_Load("sprit.jpg");
SDL_Rect an[8];
SDL_Rect pos,pos1;
SDL_Rect deg;
deg.x=0;
deg.y=0;
deg.h=600;
deg.w=900;
pos1.x=100;
pos1.y=100;





SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);



    ecran = SDL_SetVideoMode(900,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_BlitSurface(map,&deg,ecran,NULL);
SDL_BlitSurface(p.droi[p.nb],NULL,ecran,&p.position);
SDL_Flip(ecran);



 if(police==NULL){
    while (continuer)
    {
ta = SDL_GetTicks();
i=0;


        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
break;
            case SDL_KEYDOWN:

if(event.key.keysym.sym!=SDLK_a){
if(p.position.x<4000){
mvtpers(&p,event,0);

animationpers(&p,event);
}
else {
scrolling(&deg,event);
animationpers(&p,event);
}


}
else{
jump(ecran,&p,map,deg,e);

}



break;

case SDL_MOUSEBUTTONUP:
            mvsouris(ecran,map,deg,&p,&e,event.button.x,0,0);
            
break;


       }


  i=e.position.x-(p.position.x);

if(p.v.nb<1){
deprec(&e,i);
animationenti(&e,i);
}

despcir(&pos,ta);




gestionvie(&p,colisionentiersec(p.position,e.position));



mini_m(&curseur ,&p);
display(ecran ,&curseur,&mini_map );

affiche(ecran,map,p,deg,e,i);


if(ta-tp>1000){

affichetemps(ecran,texte,ta,police);
tp=ta;

}
}
}
SDL_FreeSurface(map);
TTF_CloseFont(police);
    TTF_Quit();
//freepers;
//freeenti;

    SDL_FreeSurface(texte);
SDL_Quit();

return 0;






}



