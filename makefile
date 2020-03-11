ex_animacion: animacion.o gfx.o Asteroide.o Coordenada.o
	g++ -g animacion.o gfx.o Asteroide.o Coordenada.o -o ex_animacion -lX11
animacion.o: animacion.cpp
	g++ -g animacion.cpp -c


Asteroide.o: Asteroide.h Asteroide.cpp  gfx.o Coordenada.o
	g++ -g Asteroide.cpp -c

Coordenada.o: Coordenada.h Coordenada.cpp
	g++ -g Coordenada.cpp -c


gfx.o: gfx.h gfx.c
	gcc -g gfx.c -c