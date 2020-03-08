#include "gfx.h"
#include "Punto.h"
#include <unistd.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <random>

using namespace std;

float random_flotante(float max, float min){
    float valor = rand() / (float) RAND_MAX; 
    return min + valor * ( max - min );    
}

int main()
{
    int t;
    char c;
    int max=20, min = 8;
    srand(time(NULL));


    gfx_open(800,600,"Ejemplo micro Animacion GFX");
    gfx_color(0,200,100);
    vector<Punto> puntos((rand()%(max-min+1)) + min);
    double x,y;
    for(int i = 0; i < puntos.capacity(); i++)
    {
        if(i > 0 && i < puntos.capacity()/2){
            while(x < puntos[i-1].getX()){
                x = random_flotante(100,0);
            }
        }else if(i > puntos.capacity()/2){
            while(x > puntos[i-1].getX()){
                x = random_flotante(100,0);
            }
        }else{
            x = random_flotante(100,0);
        }
        y = random_flotante(100,0);
        puntos[i].inicializaPunto(x,y);
    }
    printf("capacidad: %ld\n",puntos.capacity());
    for(int j = 0; j < puntos.capacity(); j++){
        if(j == puntos.capacity() - 1){
            gfx_line(puntos[j].getX(),puntos[j].getY(),puntos[0].getX(),puntos[0].getY());
        }
        else{
            gfx_line(puntos[j].getX(),puntos[j].getY(),puntos[j+1].getX(),puntos[j+1].getY());
        }
    }


	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}
    return 0;

}