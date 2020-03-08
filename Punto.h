#ifndef PUNTO_H_
#define PUNTO_H_

class Punto{
    private:
        double x,y;
    public:
        Punto(double,double);
        Punto();
        void inicializaPunto(double,double);
        double getX();
        double getY();

};

#endif