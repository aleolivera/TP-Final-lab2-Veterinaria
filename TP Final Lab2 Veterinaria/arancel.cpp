#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "fecha.h"
#include "arancel.h"
#include "visuales.h"

///MOSTRAR
void Arancel::mostrarFechaArancel(){
    fechaArancel.mostrarFecha();
}

///GETs
Fecha Arancel::getFechaArancel(){
    return fechaArancel;
}
int Arancel::getIDArancel(){
    return IDArancel;
}
int Arancel::getIDCliente(){
    return IDCliente;
}
int Arancel::getIDHistoria(){
    return IDHistoria;
}
int Arancel::getIDTipoVisita(){
    return IDTipoVisita;
}
float Arancel::getTotalArancel(){
    return totalArancel;
}
char Arancel::getTipoPago(){
    return tipoPago;
}
int Arancel::getPorcentajeHonorario(){
    return porcentajeHonorario;
}
bool Arancel::getAbonado(){
    return abonado;
}

///SETs
void Arancel::setFechaIngreso(){
    fechaArancel.setFechaActual();
}
void Arancel::setIDArancel(int ID){
    IDArancel=ID;
}
void Arancel::setIDCliente(int ID){
    IDCliente=ID;
}
void Arancel::setIDHistoria(int ID){
    IDHistoria=ID;
}
void Arancel::setIDTipoVisita(int ID){
    IDTipoVisita=ID;
}
void Arancel::setTotalArancel(float valor){
    totalArancel=valor;
}
void Arancel::setTipoPago(char caracter){
    tipoPago=caracter;
}
void Arancel::setPorcentajeHonorario(int valor){
    porcentajeHonorario=valor;
}
void Arancel::setAbonado(bool estado){
    abonado=estado;
}

///DISCO
int Arancel::buscarArancel(int ID){
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return -1;
    }
    int n;
    while(fread(this,sizeof (Arancel),1,p)==1){
        if(ID==IDArancel){
            n=(ftell(p)/sizeof (Arancel));
            fclose(p);
            return n;
        }
    }
    fclose(p);
    return -1;
}
bool Arancel::guardarArancel(){         ///GUARDA EL REGISTRO EN EL ARCHIVO EN LA ULTIMA POSICION
    FILE*p=fopen(ARCHIVOARANCELES,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (Arancel),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Arancel::leerArancel(int pos){
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (Arancel),0);
    if(fread(this,sizeof (Arancel),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Arancel::modificarArancel(int pos){ ///GUARDA EL REGISTRO EN EL ARCHIVO EN LA POSICION CORRESPONDIENTE A ESE ID
    FILE*p=fopen(ARCHIVOARANCELES,"rb+");
    if(p==NULL){
        return false;
    }
    pos--;
    fseek(p,(pos*sizeof (Arancel)),0);
    if(fwrite(this,sizeof (Arancel),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}
bool Arancel::mostrarTodoElArchivo(){
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(this,sizeof (Arancel),1,p)==1){
        cout << "IDArancel: "<< IDArancel << endl;
        cout << "IDCliente: "<< IDCliente << endl;
        cout << "    TOTAL: $"<< totalArancel << endl;
        cout << "Tipo Pago: "<< tipoPago << endl;
        cout << "................" << endl;
    }
    pausar();
    fclose(p);
    return false;
}




