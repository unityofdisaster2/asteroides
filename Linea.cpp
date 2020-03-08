#include "Linea.h"


Linea::Linea(double xx1,double yy1,double xx2,double yy2) : x1(xx1),y1(yy1),x2(xx2),y2(yy2)
{

} 


Linea::Linea() : x1(0.0),y1(0.0),x2(0.0),y2(0.0)
{

} 


void Linea::inicializaLinea(double xx1,double yy1,double xx2,double yy2)
{
    x1 = xx1;
    y1 = yy1;
    x2 = xx2;
    y2 = yy2;    
}

double Linea::getX1()
{
    return x1;
}

double Linea::getX2()
{
    return x2;
}

double Linea::getY1()
{
    return y1;
}
double Linea::getY2()
{
    return y2;
}