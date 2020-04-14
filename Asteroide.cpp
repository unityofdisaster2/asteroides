#include "Asteroide.h"
#include <iostream>
#include <random>
#include <vector>
#include <tuple>
#include "gfx.h"
#include <unistd.h>
#include <math.h>
#define PI 3.14159265359
using namespace std;

/**
 * Constructor vacio que se podra utilizar en caso de que se ocupe el objeto en vectores
*/
Asteroide::Asteroide()
{

}
/**
 * 
 * Constructor que recibe como parametro el numero de puntos
 * */
Asteroide::Asteroide(int n, int ssize)
{
    nPuntos = n;
    size = ssize;
    puntos.reserve(n);
}


void Asteroide::setSize(int ssize){
    size = ssize;
    // cout << "tamano: " << size << " inverso: " << (double)1/size << endl;
}

/**
 * Funcion para establecer el numero de puntos en caso de que no se hayan pasado por el constructor
*/
void Asteroide::setNumPuntos(int n)
{
    nPuntos = n;
    puntos.reserve(n);
}

/**
 * funcion que sirve para rotar el valor x de un punto.
 * se recibe como parametro un indice correspondiente a la Coordenada que se quiere rotar en x
 * y tambien se recibe un offset que sera el nuevo angulo al que se rotara 
 * */
double Asteroide::rotar_x(int index,double offset){
    return puntos[index].getX()*cos(offset) - puntos[index].getY()*sin(offset);
}



/**
 * funcion que sirve para rotar el valor y de un punto.
 * se recibe como parametro un indice correspondiente a la Coordenada que se quiere rotar en y
 * y tambien se recibe un offset que sera el nuevo angulo al que se rotara 
 * */

double Asteroide::rotar_y(int index,double offset){
    return puntos[index].getY()*cos(offset) + puntos[index].getX()*sin(offset);
}


/**
 * Funcion para dibujar en pantalla el asteroide formado.
 * se recibe como parametro el valor de tiempo que desplazara la figura y el valor actual del 
 * offset de rotacion
 * */
void Asteroide::dibujar(int t, double rot)
{
    //gfx_clear();
    // se crea un ciclo para recorrer todos los puntos que conforman al asteroide y dibujar lineas
    // que conecten los puntos
    for(int i = 0; i < puntos.capacity(); i++)
    {
        // mientras no se llegue al ultimo punto se conectara el punto actual con el siguiente
        if( i != nPuntos -1)
        {
            gfx_line(
                t * direccion[0]  * 30 *  ((double)1/size) + posicionInicial.getX() + rotar_x(i,rot),
                t * direccion[1]  * 30 *  ((double)1/size) + posicionInicial.getY() + rotar_y(i,rot),
                t * direccion[2]  * 30 *  ((double)1/size) + posicionInicial.getX() + rotar_x(i+1,rot),
                t * direccion[3]  * 30 *  ((double)1/size) + posicionInicial.getY() + rotar_y(i+1,rot)
                );

        }
        else
        {
            // cuando se llegue al ultimo punto se conectara el actual con el primer punto generado
            gfx_line(
                t * direccion[0] * 30 * ((double)1/size) + posicionInicial.getX() + rotar_x(i,rot),
                t * direccion[1] * 30 * ((double)1/size) + posicionInicial.getY() + rotar_y(i,rot),
                t * direccion[2] * 30 * ((double)1/size) + posicionInicial.getX() + rotar_x(0,rot),
                t * direccion[3] * 30 * ((double)1/size) + posicionInicial.getY() + rotar_y(0,rot)
                );                
        }
        
    }
        // gfx_flush();
        // usleep(31666); //24 por segundo
}


/**
 * funcion que establece la posicion inicial en pantalla del asteroide
 * recibe como parametro los valores (x,y) de la coordenada
 * */
void Asteroide::setPosicionInicial(double x, double y){
    posicionInicial.inicializaCoordenada(x,y);
    switch(rand() % 7){
        case 0:
            direccion[0] = 1; direccion[1] = 1;direccion[2] = 1;direccion[3] = 1;
        break;
        case 1:
            direccion[0] = -1; direccion[1] = 1;direccion[2] = -1;direccion[3] = 1;
        break;
        case 2:
            direccion[0] = 1; direccion[1] = -1;direccion[2] = 1;direccion[3] = -1;
        break;
        case 3:
            direccion[0] = -1; direccion[1] = -1;direccion[2] = -1;direccion[3] = -1;
        break;
        case 4:
            direccion[0] = -1; direccion[1] = 0;direccion[2] = -1;direccion[3] = 0;
        break;
        case 5:
            direccion[0] = 1; direccion[1] = 0;direccion[2] = 1;direccion[3] = 0;
        break;
        case 6:
            direccion[0] = 0; direccion[1] = 1;direccion[2] = 0;direccion[3] = 1;
        break;

    }
    // diagonal derecha hacia abajo
    // direccion[0] = 1; direccion[1] = 1;direccion[2] = 1;direccion[3] = 1;

    // diagonal izquierda hacia abajo
    // direccion[0] = -1; direccion[1] = 1;direccion[2] = -1;direccion[3] = 1;

    // diagonal derecha hacia arriba
    // direccion[0] = 1; direccion[1] = -1;direccion[2] = 1;direccion[3] = -1;

    // diagonal izquierda hacia arriba
    // direccion[0] = -1; direccion[1] = -1;direccion[2] = -1;direccion[3] = -1;

    // izquierda
    // direccion[0] = -1; direccion[1] = 0;direccion[2] = -1;direccion[3] = 0;

    // derecha
    // direccion[0] = 1; direccion[1] = 0;direccion[2] = 1;direccion[3] = 0;

    // abajo
    // direccion[0] = 0; direccion[1] = 1;direccion[2] = 0;direccion[3] = 1;


}




/**
 * Funcion para inicializar los puntos que conformaran al asteroide.
 * Los puntos se inicializaran utilizando la formula de raices complejas ya que 
 * estos generan una circunferencia casi perfecta
 * recibe como parametro el tamano del asteroide.
 * */
void Asteroide::inicializar()
{
    // valor aleatorio del numero real
    double x_comp = rand()%20;
    // valor aleatorio del numero "imaginario"
    double y_comp = rand()%20;
    //int raiz = rand()%(15 - 8 + 1) +8;
    //el numero de raices a calcular se dara basado en el numero de puntos que se hayan establecido
    int raiz = nPuntos;

    

    // se calcula magnitud y argumento del numero complejo al que se sacara raiz
    double magnitud = sqrt(pow(x_comp,2)+pow(y_comp,2));
    
    double argumento = atan(y_comp/x_comp);
    

    // se aplica la raiz nesima a la magnitud
    magnitud = pow(magnitud,(double)1/raiz);
    
    for(int i = 0; i < raiz; i++){
        // para encontrar (x,y) se utiliza la formula de Moivre z^(1/n) = r^(1/n)*(cos((arg+2*pi*k)/n)+ i*sin((arg+2*pi*k)/n) 
        if(rand()%2 == 0){
            puntos[i].inicializaCoordenada(size*(magnitud*cos((argumento+2*PI*i)/raiz)-0.3),size*(magnitud*sin((argumento+2*PI*i)/raiz)-0.5));
        }else{
            puntos[i].inicializaCoordenada(size*magnitud*cos((argumento+2*PI*i)/raiz),size*magnitud*sin((argumento+2*PI*i)/raiz));
        }
    }

}