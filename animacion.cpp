#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "Asteroide.h"
#include <vector>
#include <random>
#include "ScreenUtil.h"

#define PI 3.14159265359


using namespace std;
int main(int argc, char **argv)
{
    if(argc < 2){
        printf("debe ingresar una cantidad de asteroides: \n%s n_asteroides\n",argv[0]);
        exit(0);
    }
    srand(time(NULL));
    ScreenUtil util = ScreenUtil(1400,800,"Asteroides");
    
    
    vector<Asteroide> asteroides(atoi(argv[1]));



    for(int i = 0; i < asteroides.size(); i++){
        // se establece un numero de puntos entre 8 y 13 para formar un poligono
        // que se acerque mas a la forma de un meteorito
        asteroides[i].setNumPuntos(rand()%(13 - 8 +1) + 8);

        // se coloca la posicion en zonas aleatorias de los bordes de la ventana
        asteroides[i].setPosicionInicial();
        // se elige un tamano de meteorito entre 1 y 50, con eso tambien se determinara
        // su velocidad de avance
        asteroides[i].setSize(rand()%(50-1 +1) +1);
        // se crean los puntos que conforman al asteroide 
        asteroides[i].inicializar();
    }

    while(1){
        util.limpiarPantalla();
        for(int i = 0; i < asteroides.size(); i++){
            // si mover retorna false significa que el asteroide esta fuera de pantalla
            // y hay que reposicionarlo 
            if(!asteroides[i].mover()){
                asteroides[i].setPosicionInicial();
                asteroides[i].setSize(rand()%(50-1 +1) +1);
                asteroides[i].inicializar();
            }
            util.dibujar(asteroides[i]);
            
        }
    
        util.limpiarSalidas();
        usleep(31600);

    }
    return 0;
}