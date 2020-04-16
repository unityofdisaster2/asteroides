#include "Coordenada.h"
#include <iostream>
using namespace std;

/// constructor donde se establece por defecto los valores iniciales en 0.0
Coordenada::Coordenada() : xInicial(0.0),yInicial(0.0)
{

}

/**
 * Constructor con argumentos para inicializar x e y inicial
 * @param xx valor que se guardara en xInicial
 * @param yy valor que se guardara en yInicial
 */
Coordenada::Coordenada(double xx,double yy){
    xInicial = xx;
    yInicial = yy;
}



/**
 * Inicializa los valores de x e y inicial
 * @param xx valor que se guardara en xInicial
 * @param yy valor que se guardara en yInicial
 */
void Coordenada::inicializaCoordenada(double xx,double yy){
    xInicial = xx;
    yInicial = yy;
}


/// para obtener xInicial
double Coordenada::getXInicial(){
    return xInicial;
}

/// para obtener yInicial
double Coordenada::getYInicial(){
    return yInicial;
}

/// para obtener xDesplazada
double Coordenada::getXDesplazada(){
    return xDesplazada;
}

/// para obtener yDesplazada
double Coordenada::getYDesplazada(){
    return yDesplazada;
}


/// establece el valor de xInicial
void Coordenada::setXInicial(double xx){
    xInicial = xx;
}


/// establece el valor de yInicial
void Coordenada::setYInicial(double yy){
    yInicial = yy;
}

/// establece el valor de xDesplazada
void Coordenada::setXDesplazada(double xx){
    xDesplazada = xx;
}

/// establece el valor de xDesplazada
void Coordenada::setYDesplazada(double yy){
    yDesplazada = yy;
}

/**
 * funcion que guarda valores de desplazamiento y rotacion en xDesplazada e yDesplazada
 * @param x valor desplazado en el eje x
 * @param y valor desplazado en el eje y
 * @param angulo se utiliza para realizar un desplazamiento tomando como referencia xInicial e yInicial
 */
void Coordenada::desplazar(double x, double y, double angulo){
    double xAux,yAux;
    // se realiza calculo para la rotacion en ambos ejes
    xAux = xInicial * cos(angulo) - yInicial * sin(angulo);
    yAux = yInicial * cos(angulo) + xInicial * sin(angulo);
    
    // se actualiza el valor de desplazamiento
    xDesplazada = x + xAux;
    yDesplazada = y + yAux;
}