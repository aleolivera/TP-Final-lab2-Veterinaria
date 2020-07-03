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
    cout<<"       DNI :";
    cin>>dni;
    cin.ignore();

    cout<<"     NOMBRE:";
    cin.getline(nombreCliente,30);
    if(cad_vacia(nombreCliente))
        return false;

    cout<<"   APELLIDO:";
    cin.getline(apellido,30);
    if(cad_vacia(apellido))
        return false;

    encontrado=buscarClienteXDni(dni);
    if(encontrado==-1)
    {
        cout<<"  DOMICILIO: ";
        cin.getline(domicilio,30);

        cout<<"   TELEFONO: ";
        cin>>Telefono;
        cin.ignore();

        cout<<"      EMAIL: ";
        cin>>email;
        if(validarMail(email))
        {
            errorIngresoInvalido();
            return false;
        }
    }
    else
    {
        cout<<" EL CLIENTE "<<apellido<<" "<<nombreCliente<<" YA ESTABA INGRESADO EN LE ARCHIVO "<<endl; //FALTA MOSTRAR CON QUE MASCOTA ESTA REGISTRADO.

        return false;
    }
    saldo=0;
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

int Cliente::buscarClienteXDni(int dni) //COMPARA EL DNI INGRESADO CON LOS REGISTRADOS.
{
    int pos=0;
    Cliente reg;
    while(reg.LeerDiscoDeCliente(pos))
    {
        if(dni==reg.dni)
            {return pos;}
        pos++;
    }
    return -1;
}

void Cliente::mostrarCliente()
{
    cout<<"         ID: "<<IDCliente<<endl;
    cout<<"        DNI: "<<dni<<endl;
    cout<<"     NOMBRE: "<<nombreCliente<<endl;
    cout<<"   APELLIDO: "<<apellido<<endl;
    cout<<"  DOMICILIO: "<<domicilio<<endl;
    cout<<"   TELEFONO: "<<Telefono<<endl;
    cout<<"      EMAIL: "<<email<<endl;
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

int Cliente::buscraID_Cliente(int pos)// NO FUNCIONA.
{
    Cliente reg;
    if(LeerDiscoDeCliente(pos))
        {return reg.IDCliente;}
    return -1;
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
    cout<<"MODIFICAR CLIENTE" << endl << endl;
    cout<<"    INGRESE EL DNI DEL CLIENTE:";
    cin>>dni;
    cin.ignore();
    pos= reg.buscarClienteXDni(dni);
    if(pos>=0)
    {
        LeerDiscoDeCliente(pos);
        cout<<endl;
        mostrarCliente();
        cout<<endl;
        cout<<"  DOMICILIO: ";
        cin.getline(domicilio,50);
        cout<<endl;
        cout<<"   TELEFONO: ";
        cin>>Telefono;
        cin.ignore();

        cout<<"     EMAIL : ";
        cin.getline(email,30);
        if(validarMail(email))
        {
            errorIngresoInvalido();
            return;
        }
        if(sobrescribir_Cliente(pos))
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

}


///GETs     TE HICE ESTE GET PARA PODER VALIDAR EL ID DEL CLIENTE AL INGRESAR LA HISTORIA CLINICA
int Cliente::getIDCliente()
{
    return IDCliente;
}
float Cliente::getSaldo(){
    return saldo;
}
const char* Cliente::getNombreCliente()
{
    return nombreCliente;
}
const char* Cliente::getApellido()
{
    return apellido;
}
int Cliente::getTelefono()
{
    return Telefono;
}

///SETs
void Cliente::setSaldo(float importe){
    saldo=importe;
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
///DISCO        NECESITABA PONER COMO DEUDOR A UN CLIENTE DESDE ARANCELES
int Cliente::buscarClientePorID(int ID){
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return -1;
    }
    int n;
    while(fread(this,sizeof (Cliente),1,p)==1){
        if(ID==IDCliente){
            n=(ftell(p)/sizeof (Cliente));
            fclose(p);
            return n;
        }
    }
    fclose(p);
    return -1;
}
bool Cliente::guardarCliente(){
    FILE*p=fopen(ARCHIVOCLIENTES,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (Cliente),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Cliente::leerCliente(int pos){
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof*this,0);
    if(fread(this,sizeof* this,1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Cliente::modificarClienteDisco(int pos){
    FILE*p=fopen(ARCHIVOCLIENTES,"rb+");
    if(p==NULL){
        return false;
    }
    pos--;
    fseek(p,(pos*sizeof (Cliente)),0);
    if(fwrite(this,sizeof (Cliente),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}
bool Cliente::mostrarTodoElArchivo(){
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(this,sizeof (Cliente),1,p)==1){
        cout <<"    IDcliente: "<< IDCliente << endl;
        cout <<"nombre/Apelli: "<< nombreCliente << " " << apellido << endl;
        cout <<"     Telefono: "<< Telefono << endl;
        cout <<"        Saldo: "<< saldo << endl;
        cout << "................" << endl;
    }
    pausar();
    fclose(p);
    return false;
}
