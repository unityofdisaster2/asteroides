#include "ScreenUtil.h"

/// Crea una ventaja con valores predefinidos
ScreenUtil::ScreenUtil()
{
    gfx_open(800, 600, "Ventana");
    gfx_color(0, 200, 100);
}


/**
 * Crea una ventana con el valor de alto, ancho y titulo establecidos
 * @param ancho anchura de la ventana
 * @param alto altura de la ventana
 * @param titulo cadena de texto con el titulo de la ventana
 */
ScreenUtil::ScreenUtil(int ancho, int alto, const char *titulo)
{
    gfx_open(ancho, alto, titulo);
    gfx_color(0, 200, 100);
}

/// limpia la ventana
void ScreenUtil::limpiarPantalla()
{
    gfx_clear();
}

/// vacia las salidas anteriores de la ventana
void ScreenUtil::limpiarSalidas()
{
    gfx_flush();
}

/**
 * Dibuja la conexion entre los puntos de un asteroide por medio de lineas
 * @param asteroide objeto que se desea utilizar para imprimir los puntos
 */
void ScreenUtil::dibujar(Asteroide asteroide)
{
    int nPuntos = asteroide.getPuntos().size();
    for (int i = 0; i < nPuntos; i++)
    {
        //se conectan todos los puntos desde 0 hasta i - 1 
        if (i != nPuntos - 1)
        {
            gfx_line(asteroide.getPuntos()[i].getXDesplazada(),
                    asteroide.getPuntos()[i].getYDesplazada(),
                    asteroide.getPuntos()[i + 1].getXDesplazada(),
                    asteroide.getPuntos()[i + 1].getYDesplazada() );
        }
        // en el ultimo caso se conecta el ultimo punto con el primero
        // para cerrar el poligono
        else{
            gfx_line(asteroide.getPuntos()[i].getXDesplazada(),
                    asteroide.getPuntos()[i].getYDesplazada(),
                    asteroide.getPuntos()[0].getXDesplazada(),
                    asteroide.getPuntos()[0].getYDesplazada() );

        }
    }
}