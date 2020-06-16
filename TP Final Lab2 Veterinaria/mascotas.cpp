#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "mascotas.h"
#include "funcionesGlobales.h"

using namespace std;

Mascotas::Mascotas(){

}

bool Mascotas::Cargar_Mascota(){
    int castrado_opcion;
    int vacunado_opcion;
    cout<<"-----REGISTRO--DE--MASCOTAS------"<<endl;

    cin.ignore();
    cout<<" Nombre de mascota :";
    cin.getline(nombreMascota,20);
    if(cad_vacia(nombreMascota))return false;



    //IDCliente

    cout<<" Edad:";
    cin>>edad;

    IDCliente;

    cout<<" Castrado? ";
    cout<<" 1- SI.  ";
    cout<<" 2- NO.  ";
    cin>>castrado_opcion;
    cin.ignore();
    switch (castrado_opcion){
    case 1: castrado= true; break;
    case 2: castrado= false; break;}

    cout<<" Vacunado? ";
    cout<<" 1- SI.  ";
    cout<<" 2- NO.  ";
    cin>>vacunado_opcion;
    cin.ignore();
    switch(vacunado_opcion){
    case 1: vacunado= true; break;
    case 2: vacunado= false; break;
    }
    cout<<" Especie :";
    cin.getline(especie,10);
    if(cad_vacia(especie))return false;


    cout<<" Raza :";
    cin.getline(raza,20);
    if(cad_vacia(raza))return false;


    int sexo_opcion;
    cout<<" Sexo :";
    cin.getline(sexo,14);
    if(cad_vacia(sexo))return false;


    vivo=true;
    return true;
}

void Mascotas::mostrar_Mascota(){
    cout<<"-----MASCOTA-----"<<endl;
    if(vivo)
    cout<<" Nombre :"<<nombreMascota<<endl;


    //cout<<" Duenio :"<<<< endl;  //EL ID DEL CLIENTE.

    cout<<" Edad :"<<edad<<endl;


    cout<<" Castrado :";if(castrado)cout<<" SI. "<<endl;
                           else cout<<" NO. "<<endl;

    cout<<" Vacunado :";if(vacunado)cout<<" SI. "<<endl;  /// HAY QUE REVEER ESTA INSTANCIA
                           else cout<<" NO."<<endl;

    cout<<" Especie :"<<especie<<endl;

    cout<<" Raza :"<<raza<<endl;

    cout<<" Sexo :"<<sexo<<endl;

    //cout<<" Fecha de vacuna:"<<fechaVacuna<<endl;
}

void Mascotas::listar_Mascotas(){
    int pos=0;
    system("cls");
    while(leerMascota(pos++)==1){

        mostrar_Mascota();
        cout<<endl;
    }
}

///GETS
int Mascotas::getIDCliente(){
    return IDCliente;
}
void Mascotas::getNombre(char*cadena){
    strcpy(cadena,nombreMascota);
}
///DISCO


bool Mascotas::gurdar_Mascota_EnDisco()
{
    bool guardado;
    FILE *p;
    p=fopen(ARCHIVOMASCOTAS,"ab");
    if(p==NULL)
    {
        return false;
    }
    guardado=fwrite(this,sizeof(Mascotas),1,p);
    fclose(p);
    return guardado;
}

bool Mascotas::leerMascota(int pos){
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (Mascotas),0);
    if(fread(this,sizeof (Mascotas),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}

