#include "fecha.h"

///MOSTRAR
void Fecha::mostrarFecha(){
    cout << dia <<"/"<< mes << "/" << anio;
}

///GETs
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}

///SETs
void Fecha::setFecha(int d,int m,int a){
    dia=d;
    mes=m;
    anio=a;
}
void Fecha::setFechaActual(){
    time_t timestamp;
    timestamp=time(NULL); //asigna a timestamp el tiempo actual
    tm *p;
    p = localtime(&timestamp);
    dia = p->tm_mday;
    mes = p->tm_mon+1;
    anio= p->tm_year +1900;

//    struct tm
//    tm_sec	int	seconds after the minute	0-61*
//    tm_min	int	minutes after the hour	0-59
//    tm_hour	int	hours since midnight	0-23
//    tm_mday	int	day of the month	1-31
//    tm_mon	int	months since January	0-11
//    tm_year	int	years since 1900
//    tm_wday	int	days since Sunday	0-6
//    tm_yday	int	days since January 1	0-365
//    tm_isdst int	Daylight Saving Time flag
}

