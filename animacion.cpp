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

    // int limites_x [] ={ 0,800 };
    // int limites_y [] = {0, 600};

    // inicializacion de asteroides
    gfx_xpos();

    for(int i = 0; i < asteroides.capacity(); i++){
        // se establece un numero de puntos entre 8 y 13 para formar un poligono
        // que se acerque mas a la forma de un meteorito
        asteroides[i].setNumPuntos(rand()%(13 - 8 +1) + 8);

        // se coloca la posicion en distintas zonas de la pantalla
        asteroides[i].setPosicionInicial();
        // se elige un tamano de meteorito entre 1 y 50, con eso tambien se determinara
        // su velocidad de avance
        asteroides[i].setSize(rand()%(50-1 +1) +1);
        asteroides[i].inicializar();
    }
    // variable para manejar la rotacion de los asteroides
    double rot = 0.1;
    for(t = 0; t <= 10000; t++){
        gfx_clear();
        for(int i = 0; i < asteroides.capacity(); i++){
            if(!asteroides[i].dibujar(t,rot)){
                asteroides[i].setPosicionInicial();
            }
            
        }
        
        rot+=0.01;
        gfx_flush();
        usleep(31600);

    }
    return 0;
}