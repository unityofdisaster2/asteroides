#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include <vector>
#include "Coordenada.h"
using namespace std;
class Asteroide{
    private:
        vector<Coordenada> puntos;
        int nPuntos;
        Coordenada posicionInicial;
        int size;
        int direccion[4];
        int t;
        double rotacion;
    public:
        Asteroide();
        Asteroide(int,int);
        void setNumPuntos(int);
        void inicializar();
        void setSize(int);
        void setPosicionInicial();
        
        vector<Coordenada> getPuntos();
        bool checarLimites(double, double);
        double rotar_x(int,double);
        double rotar_y(int,double);
        bool mover();
};

#endif