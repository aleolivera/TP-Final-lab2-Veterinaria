#include <iostream>
#include <ctime>
using namespace std;
#include "fecha.h"

void Fecha::mostrarFecha(){
    cout << dia <<"/"<< mes << "/" << anio << endl;
}
void Fecha::cargarFecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
}
void Fecha::getFechaActual(){
    time_t timestamp;
    timestamp=time(NULL); //asigna a timestamp el tiempo actual
    tm *p;
    p = localtime(&timestamp);
    dia = p->tm_mday;
    mes = p->tm_mon+1;
    anio= p->tm_year +1900;
}
void Fecha::cargarFecha(){
    cout << "DIA/MES/ANIO: ";
    cin >> dia;
    cin >> mes;
    cin >> anio;
}
