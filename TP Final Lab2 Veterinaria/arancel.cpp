#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "fecha.h"
#include "arancel.h"

///MOSTRAR

void Arancel::mostrarIDArancel(){
    cout << IDArancel<< endl;
}
void Arancel::mostrarIDHistoria(){
    cout << IDHistoria<< endl;
}
void Arancel::mostrarIDTipoVisita(){
    cout << IDTipoVisita<< endl;
}
void Arancel::mostrarTotalArancel(){
    cout << totalArancel<< endl;
}
void Arancel::mostrarTipoPago(){
    cout << tipoPago<< endl;
}
void Arancel::mostrarPorcentajeHonorario(){
    cout << porcentajeHonorario << endl;
}
void Arancel::mostrarAbonado(){
    if(abonado){
        cout << "PAGO" << endl;
    }
    else{
        cout << "IMPAGO" << endl;
    }
}

///GETs
int Arancel::getIDArancel(){
    return IDArancel;
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
void Arancel::setIDArancel(int ID){
    IDArancel=ID;
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
        return false;
    }

    if(fread(this,sizeof (Arancel),1,p)==1){
        if(ID==IDArancel){
            fclose(p);
            return ftell(p)/sizeof (Arancel);
        }
    }
    fclose(p);
    return -1;
}
bool Arancel::guardarArancel(){
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
//int Arancel::cantidadRegistros(){
//    FILE*p=fopen(ARCHIVOARANCELES,"rb");
//    if(p==NULL){
//        return -1;
//    }
//    fseek(p,0,2);
//    return (ftell(p)/sizeof (Arancel));
//}





