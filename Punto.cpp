#include "Punto.h"


Punto::Punto(double xx,double yy) : x(xx),y(yy)
{

} 


Punto::Punto() : x(0.0),y(0.0)
{

} 


void Punto::inicializaPunto(double xx,double yy)
{
    x = xx;
    y = yy;    
}

double Punto::getX()
{
    return x;
}

double Punto::getY()
{
    return y;
}