#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <vector>
#include "Coordenada.h"
class Asteroide{
    private:
        std::vector<Coordenada> puntos;
        int nPuntos;
        Coordenada posicionInicial;
    public:
        Asteroide();
        Asteroide(int);
        void setNumPuntos(int);
        void inicializar(int );
        void setPosicionInicial(double,double);
        double rotar_x(int,double);
        double rotar_y(int,double);
        void dibujar(int,double);
};

#endif