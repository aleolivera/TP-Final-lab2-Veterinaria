#ifndef MARCOS_H_INCLUDED
#define MARCOS_H_INCLUDED

#include <iostream>
using namespace std;
#include <cstdlib>
#include <windows.h>

class Borde{
    private:///acá van las PROPIEDADES de la CLASE
        int x;///posición del punto en el eje horizontal x
        int y;///posición del punto en el eje vertical y
        int color;///define el color. Los valores son los del enum de más arriba
    public:
        void mostrarFila();
        void mostrarColumna();
        void mostrarRincon();
        void setX(int);
        void setY(int);
        void setColor(int);
        int getX();
        int getY();
        void setXY(int,int);
};

///GLOBALES
void gotoxy(short, short);
void textcolor(short, short);
void dibujarLineaHorizontal(int,int ,int);
void dibujarLineaVertical(int,int,int);
void pintarFondo(int,int,int,int);
void dibujarRectangulo(int,int,int,int);

#endif // MARCOS_H_INCLUDED
