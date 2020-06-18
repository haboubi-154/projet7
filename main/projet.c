#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "h.h"



int main(int argc, char *argv[]) 
{
    int l=0;
int lc=1;
    
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
TTF_Init();
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *musique; 
   musique = Mix_LoadMUS("music.mp3"); 
  int j=60; 
    int continuer ;
    int i,ba=0;
int e=0;
int m=20;
int k=0;

int c=0;
    SDL_Event event;
 SDL_Surface *ecran;
 SDL_Surface *background;
SDL_Surface *back2;

SDL_Surface *b[13];
SDL_Surface *texte;
Uint32 flags;
TTF_Font *police;
police =TTF_OpenFont("ABITE.ttf", 40);
 SDL_Color couleurNoire = {0, 0, 0};        

background=IMG_Load("background.png");
back2=IMG_Load("back2.jpg");
b[0]=SDL_LoadBMP("jouer.bmp");
b[1]=SDL_LoadBMP("jouer1.bmp");
b[2]=SDL_LoadBMP("zozor.bmp");
b[3]=SDL_LoadBMP("option.bmp");
b[4]=SDL_LoadBMP("option1.bmp");
b[5]=SDL_LoadBMP("quit.bmp");
b[6]=SDL_LoadBMP("quit2.bmp");
b[7]=SDL_LoadBMP("retour.bmp");
b[8]=SDL_LoadBMP("retour1.bmp");
b[9]=SDL_LoadBMP("son+.bmp");
b[10]=SDL_LoadBMP("son+1.bmp");
b[11]=SDL_LoadBMP("son-.bmp");
b[12]=SDL_LoadBMP("son-1.bmp");
b[13]=SDL_LoadBMP("FULL.bmp");
b[14]=SDL_LoadBMP("FULL1.bmp");

Mix_PlayMusic(musique, -1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2);

Mix_AllocateChannels(2);
Mix_Chunk *son;
son = Mix_LoadWAV("sound.wav");
Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);

SDL_SetColorKey(b[0], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[1], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[7], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[5], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[6], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[3], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[4], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[9], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[10], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[11], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[12], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[13], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_SetColorKey(b[14], SDL_SRCCOLORKEY, SDL_MapRGB(b[0]->format, 255, 255, 255));
SDL_Rect pos,posj,poso,posq,posr,pos1,pos2,pos3;
pos.x=0;
pos.y=0;
pos3.x=300;
pos3.y=100+b[9]->h+50+b[13]->h;


posj.x=0;
posj.y=m;
poso.x=0;
poso.y=b[0]->h +2*m;
posq.x=0;
posq.y=3*m+b[0]->h+b[3]->h;
posr.x=0;
posr.y=(background->h)-b[7]->h-50;
pos1.x=400;
pos1.y=50;
pos2.x=400;
pos2.y=100+b[9]->h;

texte = TTF_RenderText_Blended(police, "PIRATES", couleurNoire);



continuer=1;
ba=0;
e=0;

while(continuer){

if(c==0){
ecran=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF | flags);
   c=1;
}
menu(ecran,b,background,back2,pos1,pos2,posj,poso,posq,posr,pos3,pos,texte,ba,e);

SDL_PollEvent(&event);

switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEMOTION:
        
if(ba==0){

             if(event.motion.x<b[0]->w && event.motion.y<b[0]->h)
{
    if(e==0){
   Mix_PlayChannel(1, son, 0);           
            
}  


e=1;


}


else if (event.motion.x<b[3]->w && event.motion.y>(b[3]->h)+m*2 && event.motion.y<b[3]->h+m*2+b[3]->h)
{if(e==0)
     Mix_PlayChannel(1, son, 0);

e=2;

}
else if (event.motion.x<b[0]->w && event.motion.y>2*(b[0]->h)+m*3 && event.motion.y<(3*(b[0]->h))+3*m)
{if(e==0)
     Mix_PlayChannel(1, son, 0);

e=3;

}







else 
{  


    e=0;
ba=0;

}
}
else if (ba==1 ){

if(event.motion.x<b[6]->w && event.motion.y<b[6]->h)
e=1;
else

    e=0;



}
else if(ba==2){

    if(event.motion.x<b[6]->w && event.motion.y<b[6]->h)
e=1;


else if(event.motion.x>400 && event.motion.x<400+b[9]->w && event.motion.y>50 && event.motion.y<50+b[9]->h){
    e=2;
    
}

else if(event.motion.x>400 && event.motion.x<400+b[9]->w && event.motion.y>100+b[9]->h && event.motion.y<100+2*(b[9]->h))
{

e=3;


}

else if(event.motion.x>400 && event.motion.x<400+b[13]->w && event.motion.y>100+2*b[13]->h+50 && event.motion.y<150+3*b[13]->h){


e=4;

}




else


e=0;
        }

            break;
case SDL_MOUSEBUTTONUP:
  k=0;
break;
   
 
    case SDL_MOUSEBUTTONDOWN:

    if(ba==2 && e==2 ){
if(k==0 && j<128){
                j=j+20;

Mix_VolumeMusic(j);
}
k=1;
}
else if (ba==2 &&e==3) {
if(k==0 && j>0){
                j=j-20;

Mix_VolumeMusic(j);
}
k=1;
}
else if(ba==2){
 if(e==4){
flags=(ecran->flags^SDL_FULLSCREEN);
c=0;


}
}




    if(e==1 && ba==0){
 
ba=1;

e=0;

}
else if (ba==0 && e==2)
{
    ba=2;
    e=0;


}
else if((ba==1 && e==1) || (ba==2 && e==1))
    {   
e=0;
ba=0;

 }


  
    else if(ba==0 && e==3){
continuer=0;

 }
 

 break;     
 case SDL_KEYDOWN:
            if(ba==0 )              
            { switch (event.key.keysym.sym)
            {
case SDLK_ESCAPE:  
                    continuer = 0;
                    break;


case SDLK_DOWN:
if(k==0){
if(e==0)
e=1;
else if(e==1)
e=2;
else if(e==2)
e=3;
else 
e=0;
}
k=1;          
break;
 case SDLK_UP :
 if(k==0){
if(e==0)
e=3;
else if(e==1)
e=0;
else if(e==2)
e=1;
else 
e=2;
 }
k=1;
break;
case SDLK_e :
if(e==1){
ba=1;
e=0;

}
else if(e==2)
{ba=2;
e=0;
}
else if(e==3)  
continuer=0;

break;

case SDLK_j:
                ba=1;
                e=0;
                break;
            case SDLK_o:
            ba=2;
            e=0;    
            break;
            case SDLK_q:
            continuer=0;
            break;
            }
            }
            else if(ba==1){
                switch (event.key.keysym.sym){
                    case SDLK_r:
                    ba=0;
                    e=0;
                    break;


                }
            }
            else if (ba==2){
                switch (event.key.keysym.sym){
case SDLK_a:
flags=(ecran->flags^SDL_FULLSCREEN);
c=0;
break;
case SDLK_DOWN:
if(k==0){
if(e==2)
e=3;
else if(e==3)
e=4;
else if(e==0)
e=2;
else 
e=0;
}
k=1;
          
break;
 case SDLK_UP :
 if(k==0){
if(e==0)
e=4;
else if(e==2)
e=4;
else if(e==3)
e=2;
else if(e==0)  
e=4;
else if(e==4)
e=3;
else e=0;
} 
k=1;

break;
            





case SDLK_r:
            ba=0;
            e=0;
            break;
            case SDLK_e:
            if(ba==2 && e==2){
if(k==0 && j<128){
                j=j+20;

Mix_VolumeMusic(j);
            
            }
}
else if(e==3 && ba==2){
              
            
            
 if(k==0 && j>0){
     j=j-20;
Mix_VolumeMusic(j);
 
 }
}
 k=1;

            break;  

                }


            }

break;

case SDL_KEYUP:
k=0;
break;


}
}
 Mix_FreeChunk(son);
Mix_FreeMusic(musique);
Mix_CloseAudio(); 
SDL_FreeSurface(background);
SDL_FreeSurface(back2);
SDL_FreeSurface(texte);
for(i=0;i<14;i++)
 SDL_FreeSurface(b[i]);

 TTF_CloseFont(police);
 TTF_Quit();
SDL_Quit();

    return EXIT_SUCCESS;
}
