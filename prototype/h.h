

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "person.h"
#include "entisec.h"

typedef struct 
{ 
  SDL_Surface* srf;
  SDL_Rect pos;
}Imm; 

void affiche( SDL_Surface *ecran,SDL_Surface *map,perso pers,SDL_Rect deg,enti ent,int k);
int colisionentiersec(SDL_Rect pos,SDL_Rect sec);
void scrolling(SDL_Rect *deg,SDL_Event event);
int colispar(SDL_Surface *masque,SDL_Rect pos,int h,int w);
void affichetemps(SDL_Surface *ecran,SDL_Surface *texte,int ta, TTF_Font *police);
void mvsouris(SDL_Surface *ecran,SDL_Surface *map,SDL_Rect deg,perso *p,enti *e,int h,int ce,int cb);
void jump(SDL_Surface *ecran,perso *p,SDL_Surface *map,SDL_Rect deg,enti e);
void initmm(perso *perso,Imm* curseur,Imm* mini_map);
void loadmm(Imm *curseur,Imm *mini_map);
void display(SDL_Surface *ecran ,Imm* curseur,Imm* mini_map );
void mini_m(Imm *curseur ,perso *perso);







