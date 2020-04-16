#ifndef SCREENUTIL_H_
#define SCREENUTIL_H_
#include "Asteroide.h"
#include "gfx.h"

class ScreenUtil{
    public:
        ScreenUtil();
        ScreenUtil(int, int, const char *);
        void limpiarPantalla();
        void limpiarSalidas();
        void dibujar(Asteroide);
};


#endif