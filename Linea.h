#ifndef LINEA_H_
#define LINEA_H_

class Linea{
    private:
        double x1,y1;
        double x2,y2;
    public:
        Linea(double,double,double,double);
        Linea();
        void inicializaLinea(double,double,double,double);
        double getX1();
        double getY1();
        double getX2();
        double getY2();

};

#endif