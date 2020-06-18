prog:person.o main.o entisec.o affichage.o c.o gestiontemps.o minimap.o
	gcc person.o entisec.o affichage.o main.o c.o gestiontemps.o minimap.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
person.o:person.c
	gcc -c person.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm
entisec.o:entisec.c
	gcc -c entisec.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm
affichage.o:affichage.c
	gcc -c affichage.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
c.o:c.c
	gcc -c c.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
gestiontemps.o:gestiontemps.c
	gcc -c gestiontemps.c -lSDL -lSDL_image -lSDL_ttf -
minimap.o:minimap.c
	gcc -c -x minimap.c -lSDL -lSDL_image -lSDL_ttf -
