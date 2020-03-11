#include "Coordenada.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada() : x(0.0),y(0.0)
{

}

Coordenada::Coordenada(double xx,double yy){
    x = xx;
    y = yy;
}

void Coordenada::inicializaCoordenada(double xx,double yy){
    x = xx;
    y = yy;
}

double Coordenada::getX(){
    return x;
}


double Coordenada::getY(){
    return y;
}
