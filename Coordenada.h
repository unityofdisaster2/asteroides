#ifndef COORDENADA_H_
#define COORDENADA_H_
#include <math.h>
class Coordenada{
    private:
        double xInicial,xDesplazada,yInicial,yDesplazada;
    public:
        Coordenada();
        Coordenada(double,double);
        double getXInicial();
        double getYInicial();
        double getXDesplazada();
        double getYDesplazada();

        void setXInicial(double);
        void setYInicial(double);
        
        void setXDesplazada(double);
        void setYDesplazada(double);

        void inicializaCoordenada(double,double);



        void desplazar(double,double, double);


};

#endif