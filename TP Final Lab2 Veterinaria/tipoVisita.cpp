#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "visuales.h"
#include "fecha.h"
#include "tipoVisita.h"

    ///MOSTRAR
void TipoVisita::mostrarIDTipoVisita(){
    cout << IDTipoVisita;
}
void TipoVisita::mostrarImporte(){
    cout << importe;
}
void TipoVisita::mostrarNombreTipoVisita(){
    cout << nombreTipoVisita;
}
void TipoVisita::mostrarPorcentajeHonorario(){
    cout << porcentajeHonorario << "%" << endl;
}

    ///SETs
void TipoVisita::setIDTipoVisita(int valor){
    IDTipoVisita = valor;
}
void TipoVisita::setNombreTipoVisita(const char*cadena){
        strcpy(nombreTipoVisita,cadena);
}
void TipoVisita::setImporte(float valor){
    importe=valor;
}
void TipoVisita::setPorcentajeHonorario(int valor){
    porcentajeHonorario=valor;
}

    ///GETs
int TipoVisita::getIDTipoVisita(){
    return IDTipoVisita;
}
const char*TipoVisita::getNombreTipoVisita(){
    return nombreTipoVisita;
}
float TipoVisita::getImporte(){
    return importe;
}
int TipoVisita::getPorcentajeHonorario(){
    return porcentajeHonorario;
}

    ///DISCO
int TipoVisita::buscarTipoVisita(int ID){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return -1;
    }
    int n;
    while(fread(this,sizeof (TipoVisita),1,p)==1){
        if(ID==IDTipoVisita){
            n=(ftell(p)/sizeof (TipoVisita));
            fclose(p);
            return n;
        }
    }
    fclose(p);
    return -1;
}
bool TipoVisita::guardarTipoVisita(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool TipoVisita::leerTipoVisita(int pos){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (TipoVisita),0);
    if(fread(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool TipoVisita::modificarTipoVisita(int pos){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb+");
    if(p==NULL){
        return false;
    }
    pos--;
    fseek(p,(pos*sizeof (TipoVisita)),0);
    if(fwrite(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}
bool TipoVisita::mostrarTodoElArchivo(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return -1;
    }
    while(fread(this,sizeof (TipoVisita),1,p)==1){
        this->mostrarIDTipoVisita();
        this->mostrarNombreTipoVisita();
        this->mostrarImporte();
        this->mostrarPorcentajeHonorario();
        cout << "................" << endl;
    }
    pausar();
    fclose(p);
    return false;
}
