#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "mascotas.h"
#include "funcionesGlobales.h"
#include "visuales.h"

using namespace std;


bool Mascotas::Cargar_Mascota()
{
    int castrado_opcion;
    int vacunado_opcion;
    cout<<"-----REGISTRO--DE--MASCOTAS------"<<endl;

    cin.ignore();
    cout<<" Nombre de mascota :";
    cin.getline(nombreMascota,20);
    if(cad_vacia(nombreMascota))
        return false;


    cout<<"---Edad---";
    cout<<" anios :";
    cin>>anios;


    cout<<" Castrado? ";
    cout<<" 1- SI.  ";
    cout<<" 2- NO.  ";
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

    cout<<" Vacunado? ";
    cout<<" 1- SI.  ";
    cout<<" 2- NO.  ";
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
    cout<<" Especie :";
    cin.getline(especie,10);
    if(cad_vacia(especie)){
        errorIngresoInvalido();
        return false;
    }

    cout<<" Raza :";
    cin.getline(raza,20);
    if(cad_vacia(raza)){
        errorIngresoInvalido();
        return false;
    }


//    int sexo_opcion;
    cout<<" Sexo 'M': macho | 'H':hembra :";
    cin>> sexo;
    if(!(sexo=='M' || sexo=='m'|| sexo!='H'|| sexo!='h')){
        errorIngresoInvalido();
        return false;
    }

    vivo=true;
    return true;
}
void Mascotas::mostrar_Mascota()
{
    cout<<"-----MASCOTA-----"<<endl;
    if(vivo)
        cout<<" Nombre :"<<nombreMascota<<endl;


    cout<<" ID de Duenio :"<<IDCliente<< endl;  //EL ID DEL CLIENTE.

    cout<<"---Edad---"<<endl;
    cout<<" anios :"<<anios<<endl;


    cout<<" Castrado :";
    if(castrado)
        cout<<" SI. "<<endl;
    else
        cout<<" NO. "<<endl;

    cout<<" Vacunado :";
    if(vacunado)
        cout<<" SI. "<<endl;  /// HAY QUE REVEER ESTA INSTANCIA
    else
        cout<<" NO."<<endl;

    cout<<" Especie :"<<especie<<endl;

    cout<<" Raza : "<<raza<<endl;

    cout<<" Sexo : ";
    if(sexo=='m'||sexo=='M')
        cout << "macho";
    if(sexo=='h'||sexo=='H')
        cout << "hembra";
    //cout<<" Fecha de vacuna:"<<fechaVacuna<<endl;
}
void Mascotas::listar_Mascotas()
{
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


int Mascotas::buscarMascotaXNombre(char *nombre)
{
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
bool Mascotas::sobrescribir_mascota(int pos)
{
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
bool Mascotas::modificar_mascota()
{
    int pos;
    cout<<" Ingrese el nombre de la mascota que desea modificar :";
    cin.getline(nombreMascota,20);
    /*cout<<" Apellido del duenio :";
    cin.getline(apellido,30);*/
    pos= buscarMascotaXNombre(nombreMascota);
    if(pos>=0)
    {
        leerMascota(pos);
        cout<<endl;
        mostrar_Mascota();
        cout<<endl;
        cout<<"-----MODIFICAR-----"<<endl;
        cout<<endl;
        int opcastrado;
        cout<<" Castrado :  1-SI.   2-NO. "<<endl;
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
            cout<<" Opcion no valida. ";
            return false;
            break;
        }

        int opestado;
        cout<<" Esta vivo? :  1-SI.  2-NO. "<<endl;
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
        cout<<" Cambiar nombre : 1-SI."<<endl;
        cin>>opnombre;
        cin.ignore();
        if(opnombre==1)
        {
            cout<<" Ingrese el nuevo Nombre: ";
            cin.getline(nombreMascota,20);
        }

        int opsexo;
        cout<<" Cambiar sexo : 1-SI."<<endl;
        cin>>opsexo;
        cin.ignore();
        if(opsexo==1)
        {
            cout<<" Sexo 'M': macho | 'H':hembra :";
            cin>> sexo;
            if(!(sexo=='M' || sexo=='m'|| sexo!='H'|| sexo!='h')){
            errorIngresoInvalido();
            return false;
            }
        }

        if(sobrescribir_mascota(pos))
        {
            cout<<" Mascota modificada. "<<endl;
            system("pause");
        }
        else
        {
            cout<<" No se modifico la mascota. "<<endl;
            system("pause");
        }
    }
    else
    {
        cout<<" No existe la mascota :";
    }
    return true;
}

///GETS
int Mascotas::getIDCliente()
{
    return IDCliente;
}
void Mascotas::getNombre(char*cadena)
{
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

bool Mascotas::leerMascota(int pos)
{
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
