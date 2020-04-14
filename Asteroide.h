#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <vector>
#include "Coordenada.h"
class Asteroide{
    private:
        std::vector<Coordenada> puntos;
        int nPuntos;
        Coordenada posicionInicial;
        int size;
        int direccion[4];
    public:
        Asteroide();
        Asteroide(int,int);
        void setNumPuntos(int);
        void inicializar();
        void setSize(int);
        void setPosicionInicial(double,double);
        double rotar_x(int,double);
        double rotar_y(int,double);
        void dibujar(int,double);
};

#endif