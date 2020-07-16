#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
#include "mascotas.h"
#include "funcionesGlobales.h"
#include "visuales.h"

///GETS
int Mascotas::getIDmascota(){
    return IDmascota;
}
const char* Mascotas::getNombreMascota(){
    return nombreMascota;
}
int Mascotas::getDNICliente(){
    return DNICliente;
}
int Mascotas::getAnios(){
    return anios;
}
bool Mascotas::getCastrado(){
    return castrado;
}
bool Mascotas::getVacunado(){
    return vacunado;
}
const char* Mascotas::getEspecie(){
    return especie;
}
const char* Mascotas::getRaza(){
    return raza;
}
char Mascotas::getSexo(){
    return sexo;
}
Fecha Mascotas::getFechaVacuna(){
    return fechaVacuna;
}
bool Mascotas::getVivo(){
    return vivo;
}

///SET
void Mascotas::setIDMascota(int ID){
    IDmascota=ID;
}
void Mascotas::setNombreMascota(const char* cadena){
    strcpy(nombreMascota,cadena);
}
void Mascotas::setDNICliente(int DNI){
    DNICliente=DNI;
}
void Mascotas::setAnios(int a){
    anios=a;
}
void Mascotas::setCastrado(bool estado){
    castrado=estado;
}
void Mascotas::setVacunado(bool estado){
    vacunado=estado;
}
void Mascotas::setEspecie(const char* cadena){
    strcpy(especie,cadena);
}
void Mascotas::setRaza(const char* cadena){
    strcpy(raza,cadena);
}
void Mascotas::setSexo(char caracter){
    sexo=caracter;
}
//void Mascotas::setFechaVacuna(int d,int m,int a){
//    fechaVacuna.setFecha(int d,int m,int a);
//}
void Mascotas::setVivo(bool estado){
    vivo=estado;
}
///DISCO
bool Mascotas::guardarMascota(){
    FILE*p=fopen(ARCHIVOMASCOTAS,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (Mascotas),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
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
bool Mascotas::modificarMascota(int pos){
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,(pos*sizeof (Mascotas)),0);
    if(fwrite(this,sizeof (Mascotas),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

///GLOBALES
int asignarIDMascota(){///Le pone solo el ID de manera secuencial
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return 1;
    }
    if(fread(&reg,sizeof (Mascotas),1,p)==0){
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (Mascotas),2);
        fread(&reg,sizeof (Mascotas),1,p);
        fclose(p);
        return reg.getIDmascota()+1;
    }
}
int cantidadRegistrosMascotas(){    ///Devuelve la cantidad de registros en ARCHIVOMASCOTAS
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Mascotas);
}
bool cargarVecMascotas(Mascotas*vec,int tam){///Le mandas un vector de clase MASCOTAS y su tamanio y te lo carga todo
    Mascotas reg;
    int i=0;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Mascotas),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
void verMascota(Mascotas regMascota){
    cout<<"       ID MASCOTA: " << regMascota.getIDmascota() << endl;
    cout<<"             EDAD: "<<regMascota.getAnios() <<" ANIOS."<< endl;
    cout<<"          ESPECIE: "<< regMascota.getEspecie()<< endl;
    cout<<"             RAZA: "<< regMascota.getRaza()<< endl;
    cout<<"             SEXO: ";
    if(regMascota.getSexo()=='m'||regMascota.getSexo()=='M'){
        cout << "MACHO"<< endl;
    }
    else{
        cout << "HEMBRA" << endl;
    }
     cout<<"           ESTADO: ";
    if(regMascota.getCastrado()){
        cout<<"CASTRADO";
    }
    else{
        cout<<"SIN CASTRAR";
    }
    cout << " | ";
    if(regMascota.getVacunado()){
        cout<<"VACUNADO" << endl;
    }
    else{
        cout<<"SIN VACUNAR" << endl;
    }
}

///MASCOTAS
///Para resolver las consignas del MENU MASCOTA
bool mostrarMascotas(){
    Mascotas regMascota;
    int pos,DNI;
    char cadena[20];

    cout << "======================================================"<< endl;
    cout << "                    MOSTRAR MASCOTA" << endl;
    cout << "------------------------------------------------------"<< endl;
    cout<<"  DNI DEL CLIENTE: ";
    cin>>DNI;
    pos=buscarMascotaPorDNI(DNI);
    if(pos==-1){
        errorEnteroInvalido(DNI,"ES UN DNI INVALIDO, O NO POSEE MASCOTA REGISTRADA");
        return false;
    }
    cout<<"         MASCOTAS: ";
    listarMascotasConDNICliente(DNI);
    cout << "------------------------------------------------------"<< endl;

    cout<<"NOMBRE DE MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    pos=buscarMascotaPorDNIyNombre(DNI,cadena);
    if(pos==-1){
        errorCadenaInvalida(cadena,", NO SE ENCUENTRA EN EL ARCHIVO");
        return false;
    }
    regMascota.leerMascota(pos);
    verMascota(regMascota);
    cout << "======================================================"<< endl;
    pausar();
    return true;
}
bool modificarMascotas(){
    Mascotas regMascota;
    int pos,DNI, validar;
    char cadena[20];
    char caracter;
    cout << "======================================================"<< endl;
    cout << "                    MODIFICAR MASCOTA" << endl;
    cout << "------------------------------------------------------"<< endl;
    cout << "  DNI DEL CLIENTE: ";
    cin>>DNI;
    pos=buscarMascotaPorDNI(DNI);
    if(pos==-1){
        errorEnteroInvalido(DNI,"ES UN DNI INVALIDO");
        return false;
    }
    cout<< "          MASCOTAS: ";
    listarMascotasConDNICliente(DNI);
    cout << endl;
    cout<<"  NOMBRE DE MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    pos=buscarMascotaPorDNIyNombre(DNI,cadena);
    if(pos==-1){
        errorEnteroInvalido(DNI,"EL NOMBRE INGRESADO NO SE ENCUENTRA EN LE ARCHIVO");
        return false;
    }
    regMascota.leerMascota(pos);
    verMascota(regMascota);
    cout << "------------------------------------------------------"<< endl;
    cout <<"                    MODIFICAR" << endl;
    cout << "         NOMBRE: ";
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN NOMBRE VALIDO PARA UNA MASCOTA");
    }
    regMascota.setNombreMascota(cadena);

    cout << "        ESPECIE: ";
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regMascota.setEspecie(cadena);

    cout << "CASTRADO  'SI'|'NO': ";

    validar=preguntarSIoNO();
    if(validar==1){
        regMascota.setCastrado(true);
    }
    else if(validar==0){
        regMascota.setCastrado(false);
    }
    else{
        error("INGRESO INVALIDO");
        return false;
    }

    cout << "VACUNADO  'SI'|'NO': ";
    validar=preguntarSIoNO();
    if(validar==1){
        regMascota.setVacunado(true);
    }
    else if(validar==0){
        regMascota.setVacunado(false);
    }
    else{
        error("INGRESO INVALIDO");
        return false;
    }

    cout << "SEXO Macho= 'M'| Hembra= 'H': ";
    cin>> caracter;
    if(caracter=='H'||caracter=='h'){
        regMascota.setSexo(caracter);
    }
    else if(caracter=='M'||caracter!='m'){
        regMascota.setSexo(caracter);
    }
    else{
        errorIngresoInvalido();
        return false;
    }

    cout << "SIGUE DE ALTA  'SI'|'NO': ";
    cin.ignore();
    validar=preguntarSIoNO();
    if(validar==1){
        regMascota.setVivo(true);
    }
    else if(validar==0){
        regMascota.setVivo(false);
    }
    else{
        error("INGRESO INVALIDO");
    }
    cout << "------------------------------------------------------"<< endl;
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO: ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regMascota.modificarMascota(pos)){
            error("NO SE PUDO GUARDAR LA MASCOTA");
            return false;
        }
        return true;
    }
    else if(validar==0){
        volviendoMenu();
        return false;
    }
    else{
        error("INGRESO INVALIDO");
        return false;
    }

}
bool listarVisitas(){
    Historia*vecHistorias;
    char cadena[20];
    int DNI;
    bool encontrado=false;
    int cantHistorias=cantidadRegistrosHistorias();
    if(cantHistorias==-1){
        errorArchivo();
        return false;
    }

    cout << "======================================================"<< endl;
    cout << "                    LISTAR VISITAS" << endl;
    cout << "------------------------------------------------------"<< endl;
    cout << "     DNI DE CLIENTE: ";
    cin>> DNI;
    cin.ignore();
    if(!validarDNICliente(DNI)){
        errorIngresoInvalido();
        return false;
    }
    listarMascotasConDNICliente(DNI);
    cout << endl;
    cout << "   NOMBRE DE MASCOTA: ";
    cin.getline(cadena,20);
    if(cadena[0]=='\0'){
        errorIngresoInvalido();
        return false;
    }

    vecHistorias=new Historia [cantHistorias];
    if(vecHistorias==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecHistorias(vecHistorias,cantHistorias)){
        delete(vecHistorias);
        return false;
    }

    for(int i=0;i<cantHistorias;i++){
        if(strcmp(cadena,vecHistorias[i].getNombreMascota())==0 && vecHistorias[i].getDNICliente()==DNI){
            cout << "------------------------------------------------------"<<endl;
            cout << "FECHA VISITA: ";
            vecHistorias[i].getFechaVisita().mostrarFecha();
            cout << "      ID DE VISITA: " << vecHistorias[i].getIDHistoria() << endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "NO HUBO COINCIDENCIAS" << endl;
    }
    cout << "======================================================"<< endl;
    pausar();
    delete(vecHistorias);
    return true;
}
bool transferirMascotas(){
    Cliente regCliente;
    Mascotas regMascota;
    int posMascota,posCliente,DNI,validar;
    char cadena[20];
    cout << "======================================================"<< endl;
    cout << "                    TRANSFERIR MASCOTA" << endl;
    cout << "------------------------------------------------------"<< endl;
    cout<<"DNI DUENIO ACTUAL: ";
    cin>>DNI;
    posMascota=buscarMascotaPorDNI(DNI);
    if(posMascota==-1){
        errorEnteroInvalido(DNI,"ES UN DNI INVALIDO");
        return false;
    }
    cout<<"         MASCOTAS: ";
    listarMascotasConDNICliente(DNI);

    cout<<"NOMBRE DE MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    posMascota=buscarMascotaPorDNIyNombre(DNI,cadena);
    if(posMascota==-1){
        errorEnteroInvalido(DNI,"EL NOMBRE INGRESADO NO SE ENCUENTRA EN LE ARCHIVO");
        return false;
    }
    regMascota.leerMascota(posMascota);
    verMascota(regMascota);
    cout << "------------------------------------------------------"<< endl;
    cout <<"                        TRANSFERIR A:" << endl;
    cout << "       DNI NUEVO DUENIO: ";
    cin>>DNI;
    cin.ignore();
    posCliente=buscarClientePorDNI(DNI);
    regCliente.leerCliente(posCliente);
    if(posCliente==-1){
        cout << DNI << ", ES UN DNI INVALIDO, O NO SE ENCUENTRA REGISTRADO"<< endl;
        cout << "¿DESEA REGISTRARLO AHORA?:";
        validar=preguntarSIoNO();
        if(validar==1){
            limpiar();
            if(!ingresarCliente()){
                error("NO SE PUDO INGRESAR EL CLIENTE");
                return false;
            }
            regCliente=ultimoCliente();
        }
        else if(validar==0){
            volviendoMenu();
            return false;
        }
        else{
            error("NO ES UN INGRESO VALIDO");
            return false;
        }
    }
    limpiar();
    cout << "======================================================"<< endl;
    cout << "                    TRANSFERIR MASCOTA" << endl;
    cout << "------------------------------------------------------"<< endl<< endl;
    cout << "                MASCOTA: "<< regMascota.getIDmascota()<< endl;
    cout << "NOMBRE DEL NUEVO DUENIO: "<< regCliente.getNombreCliente() << endl;
    cout << "               APELLIDO: "<< regCliente.getApellido() << endl;
    cout << "                    DNI: "<< regCliente.getDNICliente() << endl;
    cout << "DESEA COMPLETAR LA TRANSFERENCIA? SI | NO: ";
    validar=preguntarSIoNO();
    if(validar==1){
        regMascota.setDNICliente(regCliente.getDNICliente());
        if(!regMascota.modificarMascota(posMascota)){
            error("NO SE PUDO GUARDAR EL REGISTRO");
            return false;
        }
    }
    else if(validar==0){
        volviendoMenu();
        return false;
    }
    else{
        error("NO ES UN INGRESO VALIDO");
        return false;
    }
    return true;
}

