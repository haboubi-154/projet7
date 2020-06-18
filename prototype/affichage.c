#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "h.h"





void affiche( SDL_Surface *ecran,SDL_Surface *map,perso pers,SDL_Rect deg,enti ent,int k)
{
if(k<0){
if(pers.dirc==0){
SDL_BlitSurface(map,&deg,ecran,NULL);
SDL_BlitSurface(pers.droi[pers.nb],NULL,ecran,&pers.position);
SDL_BlitSurface(ent.gau[ent.nb],NULL,ecran,&ent.position);
SDL_BlitSurface(pers.v.fond[pers.v.nb],NULL,ecran,&pers.v.position);
SDL_BlitSurface(ent.v.fond[ent.v.nb],NULL,ecran,&ent.v.position);
SDL_Flip(ecran);
}
else {
SDL_BlitSurface(map,&deg,ecran,NULL);
SDL_BlitSurface(pers.gau[pers.nb],NULL,ecran,&pers.position);
SDL_BlitSurface(ent.gau[ent.nb],NULL,ecran,&ent.position);
SDL_BlitSurface(pers.v.fond[pers.v.nb],NULL,ecran,&pers.v.position);
SDL_BlitSurface(ent.v.fond[ent.v.nb],NULL,ecran,&ent.v.position);
SDL_Flip(ecran);
}
}
else if(k>0){
if(pers.dirc==0){
SDL_BlitSurface(map,&deg,ecran,NULL);
SDL_BlitSurface(pers.droi[pers.nb],NULL,ecran,&pers.position);
SDL_BlitSurface(ent.droi[ent.nb],NULL,ecran,&ent.position);
SDL_BlitSurface(pers.v.fond[pers.v.nb],NULL,ecran,&pers.v.position);
SDL_BlitSurface(ent.v.fond[ent.v.nb],NULL,ecran,&ent.v.position);
SDL_Flip(ecran);
}
else {
SDL_BlitSurface(map,&deg,ecran,NULL);
SDL_BlitSurface(pers.gau[pers.nb],NULL,ecran,&pers.position);
SDL_BlitSurface(ent.droi[ent.nb],NULL,ecran,&ent.position);
SDL_BlitSurface(pers.v.fond[pers.v.nb],NULL,ecran,&pers.v.position);
SDL_BlitSurface(ent.v.fond[ent.v.nb],NULL,ecran,&ent.v.position);
SDL_Flip(ecran);
}
}
}
void mvsouris(SDL_Surface *ecran,SDL_Surface *map,SDL_Rect deg,perso *p,enti *e,int h,int ce,int cb){
int i;
while(p->position.x!=h  && ce!=1 && cb!=1){
  i=p->position.x-h;
if(i<-10)
p->position.x=p->position.x+10;
else if(i>10)
p->position.x=p->position.x-10;
else 
p->position.x=h;
  
  i=p->position.x-h;
animationperauto(p,i);
  i=e->position.x-(p->position.x);
if(p->v.nb<1){
deprec(e,i);
animationenti(e,i);
}


affiche(ecran,map,*p,deg,*e,i);

}
}

