#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "historias.h"
#include "fecha.h"
#include "funcionesGlobales.h"


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
void Historia::setFechaModificacion(){
    fechaModificacion=obtenerFechaActual();
}
void Historia::setFechaVisita(int d, int m, int a){     ///no se si esta bien
    fechaVisita.setFecha(d,m,a);
}
void Historia::setNombreMascota(const char*cadena){
   strcpy(nombreMascota,cadena);
}
void Historia::setAnamnesis(){
    char cadena[300];
    cin.getline(cadena,299);
    if(cad_vacia(cadena)){
       strcpy(anamnesis,"NO SE REALIZO NINGUN INGRESO POR TECLADO.");
    }
    else{
        strcpy(anamnesis,cadena);
    }
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
    int n;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    while(fread(this,sizeof (Historia),1,p)==1){
        if(ID==IDHistoria){
            n=(ftell(p)/sizeof (Historia));
            fclose(p);
            return n;
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
    fseek(p,(pos*sizeof (Historia)),0);
    if(fread(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Historia::modificarHistoria(int pos){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb+");
    if(p==NULL){
        return false;
    }
    pos--;
    fseek(p,(pos*sizeof (Historia)),0);
    if(fwrite(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;

}
bool Historia::mostrarTodoElArchivo(){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(this,sizeof (Historia),1,p)==1){
        this->mostrarFechaIngreso();
        this->mostrarIDHistoria();
        this->mostrarAnamnesis();
        this->mostrarIDCliente();
        cout << "................" << endl;
    }
    pausar();
    fclose(p);
    return false;
}



