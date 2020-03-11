#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "Asteroide.h"
#include <vector>
#include <random>
#define PI 3.14159265359


using namespace std;
int main()
{
    int t;
    Asteroide a = Asteroide(6);
    Asteroide b = Asteroide(8);
    vector<Asteroide> asteroides(40);
    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0, 200, 100);

    for(int i = 0; i < asteroides.capacity(); i++){
        asteroides[i].setNumPuntos(rand()%(20 - 8 +1) + 8);
        asteroides[i].setPosicionInicial(rand()%800,rand()%600);
        asteroides[i].inicializar(rand()%50);
    }
    // a.setPosicionInicial(400,600);
    // a.inicializar(50);
    // b.setPosicionInicial(200,300);
    // b.inicializar(5);
    double rot = 0.1;
    for(int t = 0; t < 200; t++){
        gfx_clear();
        for(int i = 0; i < asteroides.capacity(); i++){
            asteroides[i].dibujar(t,rot);
        }
        rot+=0.05;
        gfx_flush();
        usleep(31600);

    }
    return 0;
}