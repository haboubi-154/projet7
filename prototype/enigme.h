#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct 
{
 SDL_Surface * img;
 SDL_Rect 	p;
}enigme;

void init_enigme(enigme * enig) ;
void  generate_afficher (SDL_Surface * ecran  , char image [],enigme *enig,int *alea) ;
int solution_e (char image []) ;

