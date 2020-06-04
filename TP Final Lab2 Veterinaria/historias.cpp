#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "historias.h"
#include "fecha.h"

//MOSTRAR
void Historia::mostrarIDHistoria(){
    cout << IDHistoria;
}
void Historia::mostrarIDCliente(){
    cout << IDCliente;
}
void Historia::mostrarFechaIngreso(){
    fechaIngreso.mostrarFecha();
}
void Historia::mostrarFechaVisita(){
    fechaVisita.mostrarFecha();
}
void Historia::mostrarNombreMascota(){
    cout << nombreMascota;
}
void Historia::mostrarAmnesis(){
    cout << amnesis;
}
void Historia::mostrarControl(){
    if(control){
        cout << "REQUIERE CONTROL";
    }
    else{
        cout << "NO REQUIRE CONTROL";
    }
}
void Historia::mostrarFechaControl(){
    fechaControl.mostrarFecha();
}

// CARGAR
void Historia::cargarIDHistoria(){
    // no la se hacer aun, se tiene que cargar sola de manera secuencial
}
void Historia::cargarIDCliente(){
    cout << "ID del Cliente:" << endl;
    cin >> IDCliente;
    //habria que validarlo si esta en el archivo
}
void Historia::cargarFechaIngreso(){
    fechaIngreso.getFechaActual();
}
void Historia::cargarFechaVisita(){
    fechaVisita.cargarFecha();
}
void Historia::cargarNombreMascota(){
    cin.getline(nombreMascota,19);
    //habria que validar si esta en el archivo de mascotas y si coincide con el dueño en el mismo archivo
}
void Historia::cargarAmnesis(){
    cin.getline(amnesis,299);
}
void Historia::cargarControl(){
    int op;
    cout << "Se requiere otra visita de control?    1-Si   2-No" << endl;
    cin >> op;

    //habria que validar que se ingreso 1 o 2.

    if(op==1){
        control=true;
    }
    else{
        control=false;
    }
}
void Historia::cargarFechaControl(){
    fechaControl.cargarFecha();
}
void Historia::cargarNuevaHistoria(){
    cargarIDHistoria();
    cargarFechaIngreso();

}

//GETS
int Historia::getIDHistoria(){
    return IDHistoria;
}
int Historia::getIDCliente(){
    return IDCliente;
}
Fecha Historia::getFechaIngreso(){
    return fechaIngreso;
}
Fecha Historia::getFechaVisita(){
    return fechaVisita;
}
void Historia::getNombreMascota(char*cadena){
    strcpy(cadena,nombreMascota);
}
Fecha Historia::getFechaControl(){
    return fechaControl;
}
