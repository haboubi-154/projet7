


typedef struct
{
	int nb;
	SDL_Rect position;

	SDL_Surface *fond[4];
	
}vie1;

typedef struct 
{
	
	SDL_Rect position;
	SDL_Surface *droi[2];
   	SDL_Surface *gau[2];
       int dirc;

int nb;
vie1 v;

}enti;
void initialiservie1(vie1 *v);
void initialiserenti(enti *enti);
void animationenti(enti *ent,int k);
void deprec(enti *ent,int k);
void despcir(SDL_Rect *position,int ta);





