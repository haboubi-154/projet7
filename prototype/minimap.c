#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "h.h"

void initmm(perso *perso,Imm* curseur,Imm* mini_map)
{
mini_map->srf=NULL;
curseur->srf=NULL;
mini_map->pos.x=0;
mini_map->pos.y=0;
curseur->pos.x=0;
curseur->pos.y=5;

}
void loadmm(Imm* curseur,Imm* mini_map)
{
 mini_map->srf=IMG_Load("mini_map.png");
 curseur->srf=IMG_Load("curseur.png");
}


void display(SDL_Surface *ecran ,Imm* curseur,Imm* mini_map )
{
 mini_map->srf=IMG_Load("mini_map.png");
 curseur->srf=IMG_Load("curseur.png");
SDL_BlitSurface(mini_map->srf,NULL,ecran,&mini_map->pos);
SDL_BlitSurface(curseur->srf,NULL,ecran,&curseur->pos);
SDL_Flip(ecran);
}

void mini_m(Imm * curseur ,perso *perso){
	curseur->pos.x=(float)0.32*(perso->position.x);
	curseur->pos.y=(float)0.32*(perso->position.y);
}
