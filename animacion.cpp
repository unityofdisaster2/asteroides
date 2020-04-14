#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "Asteroide.h"
#include <vector>
#include <random>
#define PI 3.14159265359


using namespace std;
int main(int argc, char **argv)
{
    if(argc < 2){
        printf("debe ingresar una cantidad de asteroides: \n%s n_asteroides\n",argv[0]);
        exit(0);
    }
    srand(time(NULL));
    int t;
    vector<Asteroide> asteroides(atoi(argv[1]));
    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0, 200, 100);
    int limites_x [] ={ -100,900 };
    int limites_y [] = {-100, 700};
    for(int i = 0; i < asteroides.capacity(); i++){
        asteroides[i].setNumPuntos(rand()%(13 - 8 +1) + 8);
        //asteroides[i].setNumPuntos(8);
        if(rand() % 2 == 0){
            asteroides[i].setPosicionInicial(limites_x[rand()%2],rand()%600);
        }else{
            asteroides[i].setPosicionInicial(rand()%800,limites_y[rand()%2]);
        }
        //asteroides[i].setPosicionInicial(rand()%800,rand()%600);
        asteroides[i].setSize(rand()%(50-1 +1) +1);
        asteroides[i].inicializar();
    }
    double rot = 0.1;
    for(t = 0; t < 10000; t++){
        gfx_clear();
        for(int i = 0; i < asteroides.capacity(); i++){
            asteroides[i].dibujar(t,rot);
        }
        rot+=0.01;
        gfx_flush();
        usleep(31600);

    }
    return 0;
}