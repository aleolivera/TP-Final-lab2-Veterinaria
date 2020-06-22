#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "funcionesGlobales.h"

using namespace std;

int buscarCliente(char*,char*);


int Cliente::cantidad_Clientes()
{
    int cant;
    FILE *p;
    p = fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,2);
    cant = ftell(p)/sizeof(Cliente);
    fclose(p);
    return cant;
}

bool Cliente::cargarCliente()
{
    IDCliente=cantidad_Clientes()+1;
    int encontrado;

    cout<<" DNI :";
    cin>>dni;
    cin.ignore();

    cout<<" Nombre:";
    cin.getline(nombreCliente,30);
    if(cad_vacia(nombreCliente))
        return false;

    cout<<" Apellido :";
    cin.getline(apellido,30);
    if(cad_vacia(apellido))
        return false;

    encontrado=buscarClienteXDni(dni);
    if(encontrado==-1)
    {
        cout<<" Domicilio :";
        cin.getline(domicilio,30);


        cout<<" Telefono :";
        cin>>Telefono;
        cin.ignore();



        cout<<" Email :";
        cin>>email;
        if(validarMail(email))
        {
            cout<<"email no valido"<<endl;    // retocar.
            system("pause");
            return false;
        }
    }
    else
    {
        cout<<" El cliente "<<apellido<<" "<<nombreCliente<<" ya estaba registrado "<<endl; //FALTA MOSTRAR CON QUE MASCOTA ESTA REGISTRADO.

        return false;
    }
    return true;
}

bool Cliente::gurdarClienteEnDisco()
{
    bool guardado;
    FILE *p;
    p=fopen(ARCHIVOCLIENTES,"ab");
    if(p==NULL)
    {
        return false;
    }
    guardado=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return guardado;
}

bool Cliente::LeerDiscoDeCliente(int pos)
{
    bool leido;
    FILE *p;
    p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p,pos*sizeof(Cliente),0);
    leido=fread(this,sizeof(Cliente),1,p);
    fclose(p);
    return leido;
}

int Cliente::buscarClienteXDni(int dni) //COMPARA EL NOMBRE INGRESADO CON LOS REGISTRADOS.
{
    int pos=0;
    Cliente reg;
    while(reg.LeerDiscoDeCliente(pos)==1)
    {
            if(dni==reg.dni)
                return pos;
        pos++;
    }
    return -1;
}

void Cliente::mostrarCliente()
{
    cout<<" ID :"<<IDCliente<<endl;
    cout<<" DNI :"<<dni<<endl;
    cout<<" Nombre :"<<nombreCliente<<endl;
    cout<<" Apellido :"<<apellido<<endl;
    cout<<" Domicilio :"<<domicilio<<endl;
    cout<<" Telefono :"<<Telefono<<endl;
    cout<<" Email :"<<email<<endl;
}

void Cliente::listarClietes()
{
    int pos=0;
    system("cls");
    while(LeerDiscoDeCliente(pos++)==1)
    {
        mostrarCliente();
        cout<<endl;
    }
}

int Cliente::buscraID_Cliente(int pos)
{
    Cliente reg;
    LeerDiscoDeCliente(pos);
    return reg.IDCliente;
}

bool Cliente::sobrescribir_Cliente(int pos) /// NO SOBREESCRIBE.
{
    bool guardado;
    FILE *p;
    p= fopen(ARCHIVOCLIENTES,"rb+");
    if(p==NULL)
    {
        return false;
    }
    fseek(p,pos*sizeof(Cliente),0);
    guardado= fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return guardado;
}

void Cliente::modificar_Cliente()
{
    Cliente reg;
    int pos;
    cout<<" Ingrese el DNI del Cliente que desea modificar :";
    cin>>dni;
    cin.ignore();
    pos= reg.buscarClienteXDni(dni);
    if(pos>=0)
    {
        LeerDiscoDeCliente(pos);
        cout<<endl;
        mostrarCliente();
        cout<<endl;
        cout<<" domicilio :";
        cin.getline(domicilio,50);
        cout<<endl;

        cout<<" Telefono :";
        cin>>Telefono;
        cin.ignore();

        cout<<" Email :";
        cin.getline(email,30);
        if(validarMail(email))
        {
            cout<<"email no valido"<<endl;
            system("pause");
            return;
        }
        if(sobrescribir_Cliente(pos))
        {
            cout<<" Cliente modificado. "<<endl;
        }
        else
        {
            cout<<" No se modifico el Cliente"<<endl;
        }
    }
    else
    {
        cout<<" No existe el Cliente:";
    }

}


///GETs     TE HICE ESTE GET PARA PODER VALIDAR EL ID DEL CLIENTE AL INGRESAR LA HISTORIA CLINICA
int Cliente::getIDCliente()
{
    return IDCliente;
}
void Cliente::getApellido(char*cadena)
{
    strcpy(cadena,apellido);
}
int Cliente::getTelefono()
{
    return Telefono;
}
///MOSTRAR son solo cout de un atributo. LO HICE PARA MOSTRARLO EN LAS HISTORIAS CLINICAS
void Cliente::mostrarTelefono()
{
    cout << Telefono;
}
void Cliente::mostrarApellido()
{
    cout << apellido;
}

