#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "historias.h"
#include "fecha.h"


///MOSTRAR
void Historia::mostrarIDHistoria(){
    cout << IDHistoria;
}
void Historia::mostrarIDCliente(){
    cout << IDCliente;
}
void Historia::mostrarFechaIngreso(){
    fechaIngreso.mostrarFecha();
}
void Historia::mostrarFechaModificacion(){
    fechaModificacion.mostrarFecha();
}
void Historia::mostrarFechaVisita(){
    fechaVisita.mostrarFecha();
}
void Historia::mostrarNombreMascota(){
    cout << nombreMascota;
}
void Historia::mostrarAnamnesis(){
    cout << anamnesis;
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


/// SETs
void Historia::setIDHistoria(int ID){
    IDHistoria=ID;
}
void Historia::setIDCliente(int ID){
    IDCliente=ID;
}
void Historia::setFechaIngreso(){
    fechaIngreso.setFechaActual();
}
void Historia::setFechaVisita(int d, int m, int a){     ///no se si esta bien
    fechaVisita.setFecha(d,m,a);
}
void Historia::setNombreMascota(const char*cadena){
   strcpy(nombreMascota,cadena);
}
void Historia::setAnamnesis(){
    cin.getline(anamnesis,299);
}
void Historia::setControl(bool valor){
    control=valor;
}
void Historia::setFechaControl(int d, int m, int a){
    fechaControl.setFecha(d,m,a);
}


///GETs
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
bool Historia::getControl(){
    return control;
}
Fecha Historia::getFechaControl(){
    return fechaControl;
}


///DISCO
int Historia::buscarHistoria(int ID){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }

    while(fread(this,sizeof (Historia),1,p)==1){
        if(ID==IDHistoria){
            fclose(p);
            return ftell(p)/sizeof (Historia);
        }
    }
    fclose(p);
    return -1;
}
bool Historia::guardarHistoria(){
    FILE*p=fopen(ARCHIVOHISTORIAS,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Historia::leerHistoria(int pos){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (Historia),0);
    if(fread(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
//int Historia::cantidadRegistros(){
//    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
//    if(p==NULL){
//        return -1;
//    }
//    fseek(p,0,2);
//    return ftell(p)/sizeof (Historia);
//}




