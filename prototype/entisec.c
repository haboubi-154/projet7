#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

#include "entisec.h"
void initialiservie1(vie1 *v){
v->nb=0;
v->position.x=600;
v->position.y=370;

v->fond[0]=IMG_Load("v1.png");
v->fond[1]=IMG_Load("v2.png");
v->fond[2]=IMG_Load("v3.png");
}



void initialiserenti(enti *enti)
{
enti->dirc=0;
enti->position.x = 600 ;
enti->position.y = 435 ;
enti->droi[0]=IMG_Load("00.png");
enti->droi[1]=IMG_Load("11.png");

enti->gau[0]=IMG_Load("aa.png");
enti->gau[1]=IMG_Load("bb.png");

enti->nb=0;
initialiservie1(&enti->v);

}
void animationenti(enti *ent,int k){

if(k<0){
if(ent->dirc==1){
ent->dirc=0;
ent->nb=0;
}
switch(ent->nb){
case 0:
ent->nb=1;
break;
case 1:
ent->nb=0;
break;



}
}

else if(k>0){
if(ent->dirc==0){
ent->dirc=1;
ent->nb=0;
}
switch(ent->nb){
case 0:
ent->nb=1;
break;
case 1:
ent->nb=0;
break;


}
}
}
void deprec(enti *ent,int k){
if(k<0){
ent->position.x=ent->position.x+10;
ent->v.position.x=ent->v.position.x+10;
}
if(k>0){
ent->position.x=ent->position.x-10;
ent->v.position.x=ent->v.position.x-10;
}

}



void despcir(SDL_Rect *position,int ta){
float w=w=((2*M_PI)/10);

position->x=500*(cos(w*ta/1000))+350;
position->y=500*(sin(w*ta/1000));



}
