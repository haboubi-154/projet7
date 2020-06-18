#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

void init_enigme(enigme * enig)
{
	enig->p.x=0;
	enig->p.y=0;	
	enig->img=NULL;


}

 void generate_afficher (SDL_Surface * ecran  , char image [],enigme *enig,int *alea)
{ 
	int test=*alea ;
do
{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 //sprintf(image ,"",*alea);
enig->img = IMG_Load(image);
 SDL_BlitSurface(enig->img,NULL,ecran,&(enig->p)) ;
  SDL_Flip(ecran) ;
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =3;	
 	}
 	return solution;
 }
