#include "marcos.h"

///BORDE
void Borde::mostrarFila(){
    char tipoBorde='=';
//    textcolor(color,15);
    gotoxy(x,y);
    cout<<tipoBorde;
}
void Borde::mostrarColumna(){
    char tipoBorde='|';
//    textcolor(color,15);
    gotoxy(x,y);
    cout<<tipoBorde;
}
void Borde::mostrarRincon(){
    char tipoBorde='*';
//    textcolor(color,15);
    gotoxy(x,y);
    cout<<tipoBorde;
}
void Borde::setX(int valor){
    if (valor<75 && valor>=0)
    {
        x=valor;
    }
}
void Borde::setY(int valor){
    if (valor<30 && valor>=0)
    {
        y=valor;
    }
}
void Borde::setColor(int nuevo){
        color=nuevo;
}
int Borde::getX(){
    return x;
}
int Borde::getY(){
    return y;
}
void Borde::setXY(int nuevoX,int nuevoY){
    if (nuevoX<75 && nuevoX>=0){
        x=nuevoX;
    }
    if (nuevoY<30 && nuevoY>=0){
        y=nuevoY;
    }
}

///GLOBALES
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto, short colorFondo){///TEXTO+FONDO
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void dibujarLineaHorizontal(int inicioX,int inicioY,int finX){
    Borde p;
    p.setX(inicioX);
    p.setY(inicioY);
    int i=p.getX();

    while(i!=finX){
        p.mostrarFila();
        if(p.getX()<finX){
            i++;
        }
        else{
            i--;
        }
        p.setX(i);
    }
    p.mostrarFila();
}
void dibujarLineaVertical(int inicioX,int inicioY,int finY){
    Borde p;
    p.setX(inicioX);
    p.setY(inicioY);
    int i=p.getY();
    while(i!=finY){
        p.mostrarColumna();
        if(p.getY()<finY){
            i++;
        }
        else{
            i--;
        }
        p.setY(i);
    }
    p.mostrarColumna();
}
void dibujarRectangulo(int x1,int y1,int x2,int y2){
    Borde p1;
    Borde p2;
    p1.setXY(x1,y1);
    p2.setXY(x2,y2);
    dibujarLineaHorizontal(p1.getX(),p1.getY(),p2.getX());
    dibujarLineaHorizontal(p1.getX(),p2.getY(),p2.getX());
    dibujarLineaVertical(p1.getX(),p1.getY(),p2.getY());
    dibujarLineaVertical(p2.getX(),p2.getY(),p1.getY());
    p1.setXY(x1,y1);
    p1.mostrarRincon();
    p1.setXY(x2,y2);
    p1.mostrarRincon();
    p1.setXY(x1,y2);
    p1.mostrarRincon();
    p1.setXY(x2,y1);
    p1.mostrarRincon();
}

