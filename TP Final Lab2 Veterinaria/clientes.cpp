#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "funcionesGlobales.h"

using namespace std;

///GETs
int Cliente::getIDCliente(){
    return IDCliente;
}
int Cliente::getDNICliente(){
    return DNICliente;
}
const char* Cliente::getNombreCliente(){
    return nombreCliente;
}
const char* Cliente::getApellido(){
    return apellido;
}
const char* Cliente::getDomicilio(){
    return domicilio;
}
int Cliente::getTelefono(){
    return telefono;
}
const char* Cliente::getEmail(){
    return email;
}
float Cliente::getSaldo(){
    return saldo;
}

///SETs
void Cliente::setIDCliente(int ID){
    IDCliente=ID;
}
void Cliente::setDNICliente(int DNI){
    DNICliente=DNI;
}
void Cliente::setNombreCliente(const char* cadena){
    strcpy(nombreCliente,cadena);
}
void Cliente::setApellido(const char* cadena){
    strcpy(apellido,cadena);
}
void Cliente::setDomicilio(const char* cadena){
    strcpy(domicilio,cadena);
}
void Cliente::setTelefono(int t){
    telefono=t;
}
void Cliente::setEmail(const char* cadena){
    strcpy(email,cadena);
}
void Cliente::setSaldo(float importe){
    saldo=importe;
}

///DISCO        NECESITABA PONER COMO DEUDOR A UN CLIENTE DESDE ARANCELES
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
    fseek(p,(pos*sizeof (Cliente)),0);
    if(fread(this,sizeof (Cliente),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Cliente::modificarCliente(int pos){
    FILE*p=fopen(ARCHIVOCLIENTES,"rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,(pos*sizeof (Cliente)),0);
    if(fwrite(this,sizeof (Cliente),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

///GLOBALES
int asignarIDCliente(){///Le pone solo el ID de manera secuencial
    Cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return 1;
    }
    if(fread(&reg,sizeof (Cliente),1,p)==0)  ///tal vez deberia preguntar si !=1
    {
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (Cliente),2);
        fread(&reg,sizeof (Cliente),1,p);
        fclose(p);
        return reg.getIDCliente()+1;
    }
}
int cantidadRegistrosClientes(){    ///Devuelve la cantidad de registros en ARCHIVOCLIENTES
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Cliente);
}
bool cargarVecClientes(Cliente*vec,int tam){///Le mandas un vector de clase CLIENTES y su tamanio y te lo carga todo
    Cliente reg;
    int i=0;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Cliente),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
void verCliente(Cliente regCliente){
    cout << "               ID: " << regCliente.getIDCliente()<< endl;
    cout << "           NOMBRE: " << regCliente.getNombreCliente()<< endl;
    cout << "         APELLIDO: "<< regCliente.getApellido()<<endl;
    cout << "        DIRECCION: "<< regCliente.getDomicilio()<<endl;
    cout << "         TELEFONO: "<< regCliente.getTelefono()<<endl;
    cout << "            @MAIL: "<< regCliente.getEmail()<<endl;
    listarMascotasConDNICliente(regCliente.getDNICliente());
    cout << endl;
    pausar();
}

///CLIENTES
///Para resolver las consignas del MENU CLIENTES
bool mostrarCliente(){
    Cliente regCliente;
    int DNI,pos;
    cout << "MOSTRAR CLIENTE" << endl<< endl;
    cout << "       INGRESE DNI: ";
    cin>>DNI;
    pos=buscarClientePorDNI(DNI);
    if(pos==-1){
        errorEnteroInvalido(DNI,", NO SE ENCUENTRA EN LE ARCHIVO");
        return false;
    }
    regCliente.leerCliente(pos);
    verCliente(regCliente);
    return true;
}
bool mostrarTodosClientes(){
    Cliente*vecClientes;
    int cantClientes=cantidadRegistrosClientes();
    if(cantClientes==-1){
        error("NO SE ENCUENTRAR REGISTROS");
        return false;
    }

    vecClientes=new Cliente [cantClientes];
    if(vecClientes==NULL){
        error("ERROR EN LA ASIGNACION DE MEMORIA");
        return false;
    }

    if(!cargarVecClientes(vecClientes,cantClientes)){
        error("NO SE PUDIERON CARGAR LOS REGISTROS");
        delete(vecClientes);
        return false;
    }
    cout << "LISTADO DE CLIENTES"<< endl<< endl;
    for(int i=0;i<cantClientes;i++){
        cout << "               ID: " << vecClientes[i].getIDCliente()<< endl;
        cout << "              DNI: " << vecClientes[i].getDNICliente()<< endl;
        cout << "           NOMBRE: " << vecClientes[i].getNombreCliente()<< endl;
        cout << "         APELLIDO: "<< vecClientes[i].getApellido()<<endl;
        listarMascotasConDNICliente(vecClientes[i].getDNICliente());
        cout << "------------------------------------"<< endl;
    }
    pausar();
    delete(vecClientes);
    return true;
}
bool modificarClientes(){
    Cliente regCliente;
    int pos,DNI,validar;
    char cadena[30];
    char cadena2[50];
    cout<< "MODIFICAR CLIENTE" << endl << endl;
    cout << "       INGRESE DNI: ";
    cin>> DNI;
    pos=buscarClientePorDNI(DNI);
    if(pos==-1){
        errorEnteroInvalido(DNI,", NO SE ENCUENTRA ESTE DNI EN EL ARCHIVO");
        return false;
    }
    regCliente.leerCliente(pos);
    verCliente(regCliente);
    cout << "-----------------------------------------------" << endl;
    cout << "                MODIFICAR " << endl<<endl;
    cout << "        DOMICILIO: ";
    cin.ignore();
    cin.getline(cadena2,50);
    if (!validarNombresConEspacios(cadena2)){
        errorCadenaInvalida(cadena2,"ES UN INGRESO INVALIDO");
        return false;
    }
    regCliente.setDomicilio(cadena2);

    cout << "         TELEFONO: ";
    cin>>DNI;
    regCliente.setTelefono(DNI);

    cout << "            @MAIL: ";
    cin.ignore();
    cin.getline(cadena,30);
    if(validarMail(cadena)!=0){
        errorCadenaInvalida(cadena,"ES UN CORREO INVALIDO");
        return false;
    }
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regCliente.modificarCliente(pos)){
            error("ERROR EN EL GUARDADO");
            return false;
        }
    }
    else if(validar==0){
        volviendoMenu();
        return false;
    }
    else{
        errorIngresoInvalido();
        return false;
    }
    return true;
}
