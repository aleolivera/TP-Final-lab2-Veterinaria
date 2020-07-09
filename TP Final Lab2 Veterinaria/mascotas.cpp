#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "mascotas.h"
#include "funcionesGlobales.h"
#include "visuales.h"

using namespace std;


bool Mascotas::Cargar_Mascota(){
    int castrado_opcion;
    int vacunado_opcion;
    cout<<"-----REGISTRO--DE--MASCOTAS------"<<endl;

    cin.ignore();
    cout<<" NOMBRE DE LA MASCOTA: ";
    cin.getline(nombreMascota,20);
    if(cad_vacia(nombreMascota)){
        errorIngresoInvalido();
        return false;
    }
    cout<<"  DOMICILIO: ";
    cout<<"     ANIOS :";
    cin>>anios;


    cout<<"   CASTRADO: ";
    cout<<"         1- SI  ";
    cout<<"         2- NO: ";
    cin>>castrado_opcion;
    cin.ignore();
    switch (castrado_opcion)
    {
    case 1:
        castrado= true;
        break;
    case 2:
        castrado= false;
        break;
    }

    cout<<"   VACUNADO: ";
    cout<<"         1- SI  ";
    cout<<"         2- NO:  ";
    cin>>vacunado_opcion;
    cin.ignore();
    if (vacunado_opcion==1){
        vacunado= true;
    }
    else if(vacunado_opcion==2){
        vacunado= false;
    }
    else{
        errorIngresoInvalido();
        return false;
    }

    cout<<"    ESPECIE: ";
    cin.getline(especie,10);
    if(cad_vacia(especie)){
        errorIngresoInvalido();
        return false;
    }

    cout<<"       RAZA: ";
    cin.getline(raza,20);
    if(cad_vacia(raza)){
        errorIngresoInvalido();
        return false;
    }


//    int sexo_opcion;
    cout<<" SEXO 'M'- MACHO | 'H'- HEMBRA :";
    cin>> sexo;
    if(!(sexo=='M' || sexo=='m'|| sexo!='H'|| sexo!='h')){
        errorIngresoInvalido();
        return false;
    }

    vivo=true;
    return true;
}
void Mascotas::mostrar_Mascota(){
    cout<<"-----MASCOTA-----"<<endl;
    if(vivo)
        cout<<"     NOMBRE: "<<nombreMascota<<endl;

//    cout<<"             ID DEL DUENIO: N "<<IDCliente<< endl;  //EL ID DEL CLIENTE.
    cout<<"       EDAD: "<<anios<< " ANIOS" << endl;

    cout<<"   CASTRADO: ";
    if(castrado)
        cout<<" SI "<<endl;
    else
        cout<<" NO "<<endl;

    cout<<"   VACUNADO: ";
    if(vacunado)
        cout<<" SI "<<endl;  /// HAY QUE REVEER ESTA INSTANCIA
    else
        cout<<" NO"<<endl;

    cout<<"    ESPECIE: "<<especie<<endl;

    cout<<"       RAZA: "<<raza<<endl;

    cout<<"       SEXO: ";
    if(sexo=='m'||sexo=='M')
        cout << "MACHO" << endl;
    if(sexo=='h'||sexo=='H')
        cout << "HEMBRA" << endl;
    //cout<<" Fecha de vacuna:"<<fechaVacuna<<endl;
}
void Mascotas::listar_Mascotas(){
//    Mascotas reg;
    int pos=0;
    system("cls");
    while(leerMascota(pos++))
    {
        listardueno(IDCliente);
        mostrar_Mascota();
        system("pause");
    }
}


int Mascotas::buscarMascotaXNombre(char *nombre){
    int pos=0;
    while(leerMascota(pos))
    {
        if(strcmp(nombre,nombreMascota)==0)
        {
            return pos;
            pos++;
        }
    }
    return -1;
}
int Mascotas::buscarMascotaXNombreID(const char* nombre,int ID){
    int pos=0;
    while(leerMascota(pos))
    {
        if(strcmp(nombre,nombreMascota)==0 && ID==IDCliente)
        {
            return pos;
            pos++;
        }
    }
    return -1;
}

bool Mascotas::sobrescribir_mascota(int pos){
    bool guardado;
    FILE *p;
    p= fopen(ARCHIVOMASCOTAS,"rb+");
    if(p==NULL)
    {
        return false;
    }
    fseek(p,pos*sizeof(ARCHIVOMASCOTAS),0);
    guardado=fwrite(this,sizeof(Mascotas),1,p);
    fclose(p);
    return guardado;
}
bool Mascotas::modificar_mascota(){
    int pos,ID;
    cout<<"MODIFICAR MASCOTA" << endl << endl;
    cout<<"  INGRESE EL NOMBRE DE LA MASCOTA: ";
    cin.ignore();
    cin.getline(nombreMascota,20);
    cout<<"                   ID DEL CLIENTE: ";
    cin >> ID;
    /*cout<<" Apellido del duenio :";
    cin.getline(apellido,30);*/
    pos= buscarMascotaXNombreID(nombreMascota,ID);
    if(pos>=0)
    {
        leerMascota(pos);
        cout<<endl;
        mostrar_Mascota();
        cout<<endl;
        cout<<"-----MODIFICAR-----"<<endl;
        cout<<endl;
        int opcastrado;
        cout<<" CASTRADO:  1-SI.   2-NO. "<<endl;
        cin>>opcastrado;
        cin.ignore();
        switch(opcastrado)
        {
        case 1:
            castrado=true;
            break;
        case 2:
            castrado=false;
            break;
        default:
            errorIngresoInvalido();
            return false;
            break;
        }

        int opestado;
        cout<<" SIGUE DADO DE ALTA :  1-SI.  2-NO. "<<endl;
        cin>>opestado;
        cin.ignore();
        switch(opestado)
        {
        case 1:
            vivo=true;
            break;
        case 2:
            vivo=false;
            break;
        default:
            return false;
            break;
        }

        int opnombre;
        cout<<" CAMBIAR NOMBRE: 1-SI. 2-NO. "<<endl;
        cin>>opnombre;
        cin.ignore();
        if(opnombre==1)
        {
            cout<<" INGRESE EL NUEVO NOMBRE: ";
            cin.getline(nombreMascota,20);
        }

        int opsexo;
        cout<<" CAMBIAR SEXO: 1-SI. 2-NO "<<endl;
        cin>>opsexo;
        cin.ignore();
        if(opsexo==1)
        {
            cout<<" SEXO 'M'-MACHO | 'H'-HEMBRA :";
            cin>> sexo;
            if(!(sexo=='M' || sexo=='m'|| sexo!='H'|| sexo!='h')){
            errorIngresoInvalido();
            return false;
            }
        }

        if(sobrescribir_mascota(pos))
        {
            guardadoExitoso();
        }
        else
        {
            errorGuardado();
        }
    }
    else
    {
        errorRegistro();
    }
    return true;
}

///GETS
int Mascotas::getIDCliente(){
    return IDCliente;
}
const char* Mascotas::getNombre(){
    return nombreMascota;
}
bool Mascotas::getVivo(){
    return vivo;
}
///DISCO
bool Mascotas::gurdar_Mascota_EnDisco(){
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
    if(p==NULL)
    {
        return false;
    }
    fseek(p, pos*sizeof (Mascotas),0);
    if(fread(this,sizeof (Mascotas),1,p)==1)
    {
        fclose(p);
        return true;
    }
    else
    {
        fclose(p);
        return false;
    }
}
bool Mascotas::mostrarTodoElArchivo(){
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return -1;
    }
    while(fread(this,sizeof (Mascotas),1,p)==1){
        cout <<"IDcliente: "<< this->IDCliente<< endl;
        cout <<"sexo: "<< this->sexo<< endl;
        cout <<"especie: " << this->especie<< endl;
        cout <<"nombre: " << this->nombreMascota<< endl;
        cout << "................" << endl;
    }
    pausar();
    fclose(p);
    return false;
}
