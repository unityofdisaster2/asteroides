#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
    private:
        double x,y;
    public:
        Coordenada();
        Coordenada(double,double);
        double getX();
        double getY();
        void inicializaCoordenada(double,double);
};

#endif