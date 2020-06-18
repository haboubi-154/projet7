#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>



#include "h.h"

void initialiservie(vie *v){
v->nb=0;
v->position.x=100;
v->position.y=370;

v->fond[0]=IMG_Load("v1.png");
v->fond[1]=IMG_Load("v2.png");
v->fond[2]=IMG_Load("v3.png");
}



void initialiserperso(perso *perso)
{
perso->dirc=0;
perso->position.x = 100 ;
perso->position.y = 435 ;
perso->droi[0]=IMG_Load("0.png");
perso->droi[1]=IMG_Load("1.png");
perso->droi[2]=IMG_Load("2.png");
perso->droi[3]=IMG_Load("3.png");
perso->gau[0]=IMG_Load("a.png");
perso->gau[1]=IMG_Load("b.png");
perso->gau[2]=IMG_Load("c.png");
perso->gau[3]=IMG_Load("d.png");
perso->nb=0;
initialiservie(&perso->v);
perso->score=0;

}
void gestionvie(perso *p,int c){
if(c==1){

if((p->v.nb)>=0 && (p->v.nb)<2){
(p->v.nb)++;

p->position.x=p->position.x-30;
p->v.position.x=p->v.position.x-30;



}
}
}








void mvtpers(perso *pers,SDL_Event event,int i)
{


switch (event.key.keysym.sym){

case(SDLK_RIGHT):
if(i==0){


(pers->position).x=(pers->position).x+10;
(pers->v.position).x=(pers->v.position).x+10;
}



break;
case (SDLK_LEFT):



(pers->position).x=(pers->position).x-10;
(pers->v.position).x=(pers->v.position).x-10;
break;
case (SDLK_UP):



(pers->position).y=(pers->position).y-10;
(pers->v.position).y=(pers->v.position).y-10;


break;
case (SDLK_DOWN):



(pers->position).y=(pers->position).y+10;
(pers->v.position).y=(pers->v.position).y+10;

break;
}
}



void animationpers(perso *pers,SDL_Event event){

switch (event.key.keysym.sym){
case(SDLK_RIGHT):
if(pers->dirc==1){
pers->dirc=0;
pers->nb=0;
}
switch(pers->nb){
case 0:
pers->nb=1;
break;
case 1:
pers->nb=2;
break;
case 2:
pers->nb =3;
break;
case 3:
pers->nb=0;
break;
}
break;

case (SDLK_LEFT):
if(pers->dirc==0){
pers->dirc=1;
pers->nb=0;
}
switch(pers->nb){
case 0:
pers->nb=1;
break;
case 1:
pers->nb=2;
break;
case 2:
pers->nb =3;
break;
case 3:
pers->nb=0;
break;
}
break;
}

}
void animationperauto(perso *p,int k){

if(k<0){
if(p->dirc==1){
p->dirc=0;
p->nb=0;
}
switch(p->nb){
case 0:
p->nb=1;
break;
case 1:
p->nb=0;
break;
case 2:
p->nb=1;
break;
case 3:
p->nb=0;
break;


}
}
if(k>0){
if(p->dirc==0){
p->dirc=1;
p->nb=0;
}
switch(p->nb){
case 0:
p->nb=1;
break;
case 1:
p->nb=0;
break;
case 2:
p->nb=3;
break;
case 3:
p->nb=0;
break;

}
}
}

void jump(SDL_Surface *ecran,perso *p,SDL_Surface *map,SDL_Rect deg,enti e){

int ta= SDL_GetTicks();
int i=1;
int tp=ta;
float w=(2*M_PI-M_PI/3);
float y=p->position.y;
float x=p->position.x;
while(p->position.y<=y){
ta = SDL_GetTicks();
if(p->dirc==0){
ta=ta-tp;
//if(p->position.x<400){}
p->position.y=(2000*ta*ta/1000000)+(1500*sin(w)*ta/1000)+y;
p->position.x=(1500*cos(w)*ta/1000)+x;
p->v.position.x=p->position.x;


//else
/*
p->position.y=(2000*ta*ta/1000000)+(1500*sin(w)*ta/1000)+y;
deg->x=(1500*cos(w)*ta/1000);
p->v.position.y=p->position.y-30;
*/

}
else{
ta=ta-tp;
p->position.y=(2000*ta*ta/1000000)+(1500*sin(w)*ta/1000)+y;
p->position.x=x-(1500*cos(w)*ta/1000);
p->v.position.x=p->position.x;
p->v.position.y=p->position.y-30;



}
affiche(ecran,map,*p,deg,e,i);
tp=ta;
}




}

