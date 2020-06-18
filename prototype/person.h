


typedef struct
{
	int nb;
	SDL_Rect position;

	SDL_Surface *fond[4];
	
}vie;

typedef struct perso
{
	
	SDL_Rect position;
	SDL_Surface *droi[4];
   	SDL_Surface *gau[4];
       int dirc;
SDL_Surface *sco;
int score;
int nb;
vie v;
}perso;
void initialiservie(vie *v);
void initialiserperso(perso *perso);
void animationpers(perso *pers,SDL_Event event);
void mvtpers(perso *pers,SDL_Event event,int i);
void gestionvie(perso *p,int c);
void animationperauto(perso *p,int k);  


































