ex_animacion: gfx.o animacion.o Punto.o
	g++ gfx.o Punto.o animacion.o -o ex_animacion -lX11 
animacion.o: animacion.cpp
	g++ animacion.cpp -c
Punto.o: Punto.cpp Punto.h
	g++ Punto.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c 