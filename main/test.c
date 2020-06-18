#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



int main(int argc, char *argv[]) 
{

    
SDL_Init(SDL_INIT_VIDEO );
int c=0;
   Mix_Music *musique; 
   musique = Mix_LoadMUS("music.mp3"); 
  int j=MIX_MAX_VOLUME/2; 
    int continuer ;
    int i,ba=0;
int e=0;
int m=20;
    SDL_Event event;
 SDL_Surface *ecran;
 SDL_Surface *background;
SDL_Surface *back2;
SDL_Surface *b[12];
Uint32 flags ;
           

background=IMG_Load("background.jpg");
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
Mix_PlayMusic(musique, -1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2);

Mix_AllocateChannels(2);
Mix_Chunk *son;
son = Mix_LoadWAV("sound.wav");
/*
Mix_VolumeChunk(son, MIX_MAX_VOLUME);
*/
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

SDL_Rect pos,posj,poso,posq,posr,pos1,pos2;

pos.x=0;
pos.y=0;



posj.x=0;
posj.y=m;
poso.x=0;
poso.y=b[0]->h +2*m;
posq.x=0;
posq.y=3*m+b[0]->h+b[3]->h;
posr.x=0;
posr.y=(background->h)-b[7]->h;
pos1.x=400;
pos1.y=50;
pos2.x=400;
pos2.y=100+b[9]->h;



continuer=1;
ba=0;
e=0;
while(continuer){

if(c==0){
ecran=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF | flags);
   c=1;
}
SDL_PollEvent (&event);
if(ba==0 && e==0){

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_BlitSurface(background,NULL,ecran,&pos);
SDL_BlitSurface(b[0],NULL,ecran,&posj);
SDL_BlitSurface(b[3],NULL,ecran,&poso);
SDL_BlitSurface(b[5],NULL,ecran,&posq);
SDL_Flip(ecran);

}
else if(ba==1){
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(back2, NULL, ecran, &pos); 
    SDL_BlitSurface(b[7],NULL,ecran,&posj);
    
    SDL_Flip(ecran);


}
else if(ba==2) {
    if(e==0){
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 SDL_BlitSurface(background, NULL, ecran, &pos);
 SDL_BlitSurface(b[9],NULL,ecran,&pos1);
 SDL_BlitSurface(b[11],NULL,ecran,&pos2);
 SDL_BlitSurface(b[7],NULL,ecran,&posj);
 SDL_Flip(ecran);
    }
 
    

}



switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEMOTION:
if(ba==0){
             if(event.motion.x<b[0]->w && event.motion.y<b[0]->h)
{
    if(e==0)
   Mix_PlayChannel(1, son, 0);           
             SDL_BlitSurface(b[1],NULL,ecran,&posj);
  

SDL_Flip(ecran);
e=1;
ba=0;
}


else if (event.motion.x<b[0]->w && event.motion.y>(b[0]->h)+m*2 && event.motion.y<b[0]->h+m*2+b[3]->h)
{if(e==0)
     Mix_PlayChannel(1, son, 0);
SDL_BlitSurface(b[4],NULL,ecran,&poso);
SDL_Flip(ecran);
e=2;

}
else if (event.motion.x<b[0]->w && event.motion.y>2*(b[0]->h)+m*3 && event.motion.y<(3*(b[0]->h))+3*m)
{if(e==0)
     Mix_PlayChannel(1, son, 0);
    SDL_BlitSurface(b[6],NULL,ecran,&posq);
SDL_Flip(ecran);
e=3;




}







else 
{
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
SDL_BlitSurface(background,NULL,ecran,&pos);
SDL_BlitSurface(b[0],NULL,ecran,&posj);
SDL_BlitSurface(b[3],NULL,ecran,&poso);
SDL_BlitSurface(b[5],NULL,ecran,&posq);
SDL_Flip(ecran);
e=0;
ba=0;
}
}
else if (ba==1 ){
if(event.motion.x<b[6]->w && event.motion.y<b[6]->h)
e=1;
else
{
    e=0;
}


}
else if(ba==2){
    if(event.motion.x<b[6]->w && event.motion.y<b[6]->h)
e=1;


else if(event.motion.x>400 && event.motion.x<400+b[9]->w && event.motion.y>50 && event.motion.y<50+b[9]->h){
    e=2;
      SDL_BlitSurface(b[10],NULL,ecran,&pos1);
SDL_Flip(ecran);
}

else if(event.motion.x>400 && event.motion.x<400+b[9]->w && event.motion.y>100+b[9]->h && event.motion.y<100+2*(b[9]->h))
{
    e=3;
 SDL_BlitSurface(b[12],NULL,ecran,&pos2);
SDL_Flip(ecran);
}
else
e=0;
}

            break;
 
    case SDL_MOUSEBUTTONUP:
    
    if(e==1 && ba==0){
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(back2, NULL, ecran, &pos); 
    SDL_BlitSurface(b[7],NULL,ecran,&posj);
    
    SDL_Flip(ecran);
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
else if(ba==2 && e==2 ){
    if(j==MIX_MAX_VOLUME/2){
    j=((MIX_MAX_VOLUME/3)*2);
               
    }
    else if(j==(MIX_MAX_VOLUME/3)*2)
    j=MIX_MAX_VOLUME;
    else if(j==0)
    j=MIX_MAX_VOLUME/4;
    else if (j==MIX_MAX_VOLUME/4)
    {
        j=MIX_MAX_VOLUME/2;
    }
                   




Mix_VolumeMusic(j); 
} 
else if(ba==2 && e==3){
   if(j==MIX_MAX_VOLUME/2){
    j=MIX_MAX_VOLUME/4;
               
    }
    else if(j==(MIX_MAX_VOLUME/3)*2)
    j=MIX_MAX_VOLUME/2;
    
    else if (j==MIX_MAX_VOLUME/4)
    {
        j=0;
    }
           else if(j== MIX_MAX_VOLUME)
           j=(MIX_MAX_VOLUME/3)*2;
    
               
    
     




Mix_VolumeMusic(j); 
}
           

    



 else if(ba==0 && e==3){
continuer=0;

 }
 

 break;     
 case SDL_KEYDOWN:
            if(ba==0 )              
            { switch (event.key.keysym.sym)
            {
case SDLK_a:
flags=(ecran->flags^SDL_FULLSCREEN);
c=0;
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
            case SDLK_r:
            ba=0;
            e=0;
            break;
            case SDLK_PLUS:
Mix_VolumeMusic(j++);
              
            break;
            case SDLK_MINUS:
Mix_VolumeMusic(j--);
            break;  

                }

            }

 



            
            break;


}
}
 Mix_FreeChunk(son);
Mix_FreeMusic(musique);
Mix_CloseAudio(); 
SDL_FreeSurface(background);
SDL_FreeSurface(back2);

for(i=0;i<12;i++)
 SDL_FreeSurface(b[i]);

 
 
SDL_Quit();

    return EXIT_SUCCESS;
}   
