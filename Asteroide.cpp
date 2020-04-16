#include "Asteroide.h"
#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include <math.h>
#define PI 3.14159265359
using namespace std;
int limites_x [] ={ 0,1400 };
int limites_y [] = {0, 800};
/**
 * Constructor vacio que se podra utilizar en caso de que se ocupe el objeto en vectores
*/
Asteroide::Asteroide()
{
}
/**
 * Recibe el numero de puntos y el tamano del asteroide
 * @param n numero de puntos
 * @param ssize tamano del asteroide
 * */
Asteroide::Asteroide(int n, int ssize)
{
    nPuntos = n;
    size = ssize;
    // puntos.reserve(n);
}

/// establece el tamano del asteroide
void Asteroide::setSize(int ssize)
{
    size = ssize;
}

/**
 * establece el numero de puntos que componen al asteroide 
*/
void Asteroide::setNumPuntos(int n)
{
    nPuntos = n;
}

/**
 * funcion para obtener el vector que contiene los puntos que componen al asteroide
 * @return puntos vector que contiene los puntos
 */
vector<Coordenada> Asteroide::getPuntos(){
    return puntos;
}





/**
 * Funcion para dibujar en pantalla el asteroide formado.
 * se recibe como parametro el valor de tiempo que desplazara la figura y el valor actual del 
 * offset de rotacion
 * */
bool Asteroide::mover()
{
    // bandera para verificar si se han pasado los limites de pantalla
    bool flag = true;

    // se crea un ciclo para recorrer todos los puntos que conforman al asteroide y desplazarlos
    for (int i = 0; i < puntos.size(); i++)
    {
        // mientras no se llegue al ultimo punto se conectara el punto actual con el siguiente
        if (i != nPuntos - 1)
        {
            // se ingresa como argumento el valor de desplazamiento de t
            // multiplicado por la correspondiente direccion, un amplificador de velocidad
            // y multiplicado por el inverso del tamano del asteroide la posicion inicial del asteroide y la rotacion
            puntos[i].desplazar(t * direccion[0] * 30 * ((double)1 / size) + posicionInicial.getXInicial(),
                                t * direccion[1] * 30 * ((double)1 / size) + posicionInicial.getYInicial(), rotacion);

            puntos[i + 1].desplazar(t * direccion[2] * 30 * ((double)1 / size) + posicionInicial.getXInicial(), 
                                t * direccion[3] * 30 * ((double)1 / size) + posicionInicial.getYInicial(), rotacion);
        }
        else
        { 
            // cuando se llegue al ultimo punto se conectara el actual con el primer punto generado

            puntos[i].desplazar(t * direccion[0] * 30 * ((double)1 / size) + posicionInicial.getXInicial(),
                                t * direccion[1] * 30 * ((double)1 / size) + posicionInicial.getYInicial(), rotacion);

            puntos[0].desplazar(t * direccion[2] * 30 * ((double)1 / size) + posicionInicial.getXInicial(), 
                                t * direccion[3] * 30 * ((double)1 / size) + posicionInicial.getYInicial(), rotacion);


        }
    }
    // se aumenta el valor de tiempo que se encarga de desplazar y el angulo de rotacion
    t++;
    rotacion += 0.01;


    int xLim, yLim;
    xLim = puntos[0].getXDesplazada();
    yLim = puntos[0].getYDesplazada();

    // se verifica que no se haya pasado los limites de x e y de la pantalla
    if(xLim > 1420.0 || xLim < -30.0){
        return false;
    }else if(yLim > 820.0 || yLim < -30.0){
        return false;
    }else{
        return true;
    }

}

/**
 * funcion que establece la posicion inicial en pantalla del asteroide
 * */
void Asteroide::setPosicionInicial()
{
    // se inicializan valores de tiempo y rotacion
    t = 0;
    rotacion = 0;
    // se crea de forma aleatoria una posicion en cualquier parte de la pantalla
    if(rand() % 2 == 0){
        posicionInicial.inicializaCoordenada(limites_x[rand()%2],rand()%800);
    }else{
        posicionInicial.inicializaCoordenada(rand()%1400,limites_y[rand()%2]);
    }

    // se elige una direccion de desplazamiento aleatoria
    switch (rand() % 8)
    {
    case 0:
        // diagonal derecha hacia abajo
        direccion[0] = 1;
        direccion[1] = 1;
        direccion[2] = 1;
        direccion[3] = 1;
        break;
    case 1:
        // diagonal izquierda hacia abajo
        direccion[0] = -1;
        direccion[1] = 1;
        direccion[2] = -1;
        direccion[3] = 1;
        break;
    case 2:
        // diagonal derecha hacia arriba
        direccion[0] = 1;
        direccion[1] = -1;
        direccion[2] = 1;
        direccion[3] = -1;
        break;
    case 3:
        // diagonal izquierda hacia arriba
        direccion[0] = -1;
        direccion[1] = -1;
        direccion[2] = -1;
        direccion[3] = -1;
        break;
    case 4:
        // izquierda
        direccion[0] = -1;
        direccion[1] = 0;
        direccion[2] = -1;
        direccion[3] = 0;
        break;
        // derecha
    case 5:
        direccion[0] = 1;
        direccion[1] = 0;
        direccion[2] = 1;
        direccion[3] = 0;
        break;
        // abajo
    case 6:
        direccion[0] = 0;
        direccion[1] = 1;
        direccion[2] = 0;
        direccion[3] = 1;
    case 7:
        // arriba
        direccion[0] = 0;
        direccion[1] = -1;
        direccion[2] = 0;
        direccion[3] = -1;

        break;
    }
}

/**
 * Funcion para inicializar los puntos que conformaran al asteroide.
 * Los puntos se inicializaran utilizando la formula de raices complejas ya que 
 * estos generan una circunferencia casi perfecta que se puede deformar posteriormente
 * recibe como parametro el tamano del asteroide.
 * */
void Asteroide::inicializar()
{
    // en caso de existir elementos en el vector de puntos se eliminan
    puntos.clear();
    puntos.shrink_to_fit();
    // valor aleatorio del numero real
    double x_comp = rand() % 20;
    // valor aleatorio del numero "imaginario"
    double y_comp = rand() % 20;
    //int raiz = rand()%(15 - 8 + 1) +8;
    //el numero de raices a calcular se dara basado en el numero de puntos que se hayan establecido
    int raiz = nPuntos;

    // se calcula magnitud y argumento del numero complejo al que se sacara raiz
    double magnitud = sqrt(pow(x_comp, 2) + pow(y_comp, 2));

    double argumento = atan(y_comp / x_comp);

    // se aplica la raiz nesima a la magnitud
    magnitud = pow(magnitud, (double)1 / raiz);

    for (int i = 0; i < raiz; i++)
    {
        // para encontrar (x,y) se utiliza la formula de Moivre z^(1/n) = r^(1/n)*(cos((arg+2*pi*k)/n)+ i*sin((arg+2*pi*k)/n)
        if (rand() % 2 == 0)
        {
            puntos.push_back(Coordenada(size * (magnitud * cos((argumento + 2 * PI * i) / raiz) - 0.3), size * (magnitud * sin((argumento + 2 * PI * i) / raiz) - 0.5)));
        }
        else
        {
            puntos.push_back(Coordenada(size * magnitud * cos((argumento + 2 * PI * i) / raiz), size * magnitud * sin((argumento + 2 * PI * i) / raiz)));
            
        }
    }
}
