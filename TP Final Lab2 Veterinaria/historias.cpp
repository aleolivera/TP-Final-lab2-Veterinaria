#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "historias.h"
#include "fecha.h"
#include "funcionesGlobales.h"

/// SETs
void Historia::setIDHistoria(int ID){
    IDHistoria=ID;
}
void Historia::setDNICliente(int DNI){
    DNICliente=DNI;
}
void Historia::setFechaIngreso(){
    fechaIngreso.setFechaActual();
}
void Historia::setFechaModificacion(){
    fechaModificacion=obtenerFechaActual();
}
void Historia::setFechaVisita(int d, int m, int a){     ///no se si esta bien
    fechaVisita.setFecha(d,m,a);
}
void Historia::setNombreMascota(const char*cadena){
   strcpy(nombreMascota,cadena);
}
void Historia::setAnamnesis(){
    char cadena[300];
    cin.getline(cadena,300);
    if(cadena[0]=='\0'){
       strcpy(anamnesis,"NO SE REALIZO NINGUN INGRESO POR TECLADO.");
    }
    else{
        strcpy(anamnesis,cadena);
    }
}
void Historia::setControl(bool valor){
    control=valor;
}
void Historia::setFechaControl(int d, int m, int a){
    fechaControl.setFecha(d,m,a);
}
void Historia::setIDarancel(int ID){
    IDArancel=ID;
}


///GETs
int Historia::getIDHistoria(){
    return IDHistoria;
}
int Historia::getDNICliente(){
    return DNICliente;
}
Fecha Historia::getFechaIngreso(){
    return fechaIngreso;
}
Fecha Historia::getFechaVisita(){
    return fechaVisita;
}
const char* Historia::getNombreMascota(){
    return nombreMascota;
}
bool Historia::getControl(){
    return control;
}
Fecha Historia::getFechaControl(){
    return fechaControl;
}
Fecha Historia::getFechaModificacion(){
    return fechaModificacion;
}
int Historia::getIDarancel(){
    return IDArancel;
}
const char * Historia::getAnamnesis(){
    return anamnesis;
}


///DISCO
bool Historia::guardarHistoria(){
    FILE*p=fopen(ARCHIVOHISTORIAS,"ab");
    if(p==NULL){
        return false;
    }
    this->fechaIngreso.setFechaActual();
    if(fwrite(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Historia::leerHistoria(int pos){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p,(pos*sizeof (Historia)),0);
    if(fread(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool Historia::modificarHistoria(int pos){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb+");
    if(p==NULL){
        return false;
    }
    this->fechaModificacion.setFechaActual();
    fseek(p,(pos*sizeof (Historia)),0);
    if(fwrite(this,sizeof (Historia),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;

}

///GLOBALES
int asignarIDHistoria(){///Le pone solo el ID de manera secuencial
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return 1;
    }
    if(fread(&reg,sizeof (Historia),1,p)==0){ ///tal vez deberia preguntar si !=1
        fclose(p);
        return 1;
    }
    else{
        fseek(p,-sizeof (Historia),2);
        fread(&reg,sizeof (Historia),1,p);
        fclose(p);
        return reg.getIDHistoria()+1;
    }
}
int cantidadRegistrosHistorias(){   ///Devuelve la cantidad de registros en ARCHIVOHISTORIAS
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Historia);
}
bool cargarVecHistorias(Historia*vec,int tam){///Le mandas un vector de clase HISTORIA y su tamanio y te lo carga todo
    Historia reg;
    int i=0;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Historia),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
int buscarDNIClienteEnHistorias(int IDHistoria){
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL) return -1;
    while(fread(&reg,sizeof (Historia),1,p)==1){
        if(IDHistoria==reg.getIDHistoria()){
            fclose(p);
            return reg.getDNICliente();
        }
    }
    fclose(p);
    return -1;
}
void verVisita(Historia regHistoria, Cliente regCliente){
    cout << endl<< "FECHA: ";
    regHistoria.getFechaVisita().mostrarFecha();
    cout << "          MASCOTA: " << regHistoria.getNombreMascota() << endl;
    cout << "CLIENTE: " << regCliente.getApellido() << ", " << regCliente.getNombreCliente() << endl << endl << endl;
    cout <<"ANAMNESIS: " << regHistoria.getAnamnesis() << endl;
    if(regHistoria.getControl()){
        cout << endl << "REQUIERE CONTROL LA FECHA: ";
        regHistoria.getFechaControl().mostrarFecha();
    }
    cout <<endl <<"-----------------------------------" << endl;
    pausar();
}

///HISTORIAS
///Para resolver las consignas del MENU HISTORIA
bool ingresoHistoria(){
    Historia reg;
    int dia,mes,anio,valor,validar;
    char cadena[20];
    reg.setIDHistoria(asignarIDHistoria());     ///Aca se asigna solo ID de manera secuencial
    reg.setFechaIngreso();                      ///Aca se asigna automaticamente la fecha del HOY
    reg.setFechaModificacion();
    cout << "INGRESO DE HISTORIAS CLINICAS" << endl << endl;
    cout << "                          ID: "<< reg.getIDHistoria() << "        FECHA ACTUAL: ";
    reg.getFechaIngreso().mostrarFecha();
    cout<<endl;
    cout << "FECHA DE LA VISITA(DD/MM/AA) "<< endl;
    cout << "                         DIA: ";
    cin >> dia;
    cout << "                         MES: ";
    cin >> mes;
    cout << "                        ANIO: ";
    cin >> anio;
    reg.setFechaVisita(dia,mes,anio);
    if (!validarFecha(dia,mes,anio)||compararFechas(reg.getFechaVisita(),obtenerFechaActual())==2){
        errorFechaInvalida();
        return false;
    }

    cout << "             DNI DEL CLIENTE: ";
    cin >> valor;
    if(!validarDNICliente(valor)){
        errorIngresoInvalido();
        return false;
    }
    reg.setDNICliente(valor);                ///Aca se ingresa el ID del cliente en el registro tras validarlo en disco
    listarMascotasConDNICliente(valor);
    cout << endl << "        NOMBRE DE LA MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    if(!validarMascotaConCliente(cadena,reg.getDNICliente())){
        errorIngresoInvalido();
        return false;
    }
    reg.setNombreMascota(cadena);           ///Aca se ingresa el nombre de la mascota

    cout << endl;
    cout << "                  ANAMNESIS: ";
    reg.setAnamnesis();                     ///Aca la Anamnesis (detalles de la visita)

    cout << "VISITA DE CONTROL? 'SI' o 'NO' : ";
    validar=preguntarSIoNO();
    if(validar==1){
        cout << "INGRESE LA FECHA DEL CONTROL(DD/MM/AA)"<< endl;
        cout << "                         DIA: ";
        cin >> dia;
        cout << "                         MES: ";
        cin >> mes;
        cout << "                        ANIO: ";
        cin >> anio;
        cin.ignore();
        reg.setFechaControl(dia,mes,anio);
        if (!validarFecha(dia,mes,anio)||compararFechas(reg.getFechaControl(),obtenerFechaActual())==1){  ///Se valida que no se ingrese 42/9/2500 o 29/2 si no es anio biciesto y que la fecha del control no sea en le pasado
            errorFechaInvalida();
            return false;
        }
        reg.setControl(true);                ///al ingresar SI o NO se cambia el estado del booleano
    }
    else if(validar==0){
        reg.setControl(false);
        reg.setFechaControl(0,0,0);
    }
    else{
        errorIngresoInvalido();
        return false;
    }

    reg.setIDarancel(-1);   ///CUANDO HAGO EL ARANCEL LE ASIGNO SU NUMERO
    ///EL CAMPO QUE RESTA ES 'int IDArancel' QUE SE CARGA CON EL ARANCEL

    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!reg.guardarHistoria()){
            error("NO SE PUDO GUARDAR LA VISITA");
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
bool mostrarEntradaHistoria(){
    Historia regHistoria;
    Cliente regCliente;
    int ID;
    int pos;
    cout << "ENTRADA DE HISTORIA CLINICA." << endl;
    cout << "HISTORIA CLINICA ID: ";
    cin >> ID;
    pos=buscarHistoria(ID);
    if(pos==-1){
        errorEnteroInvalido(ID,", NO SE ENCUENTRA EN LE REGISTRO.");
        return false;
    }
    regHistoria.leerHistoria(pos);
    pos=buscarClientePorDNI(regHistoria.getDNICliente());
    if(pos==-1){
        errorEnteroInvalido(pos, ", NO ES UN DNI VALIDO.");
        return false;
    }
    regCliente.leerCliente(pos);
    verVisita(regHistoria,regCliente);
    return true;
}
bool mostrarHistoria(){
    Mascotas*vecMascotas;
    Historia*vecHistoria; ///para encontrar las entradas correspondientes a la historia clinica
    Cliente*vecClientes;    ///para encontrar con el ID del paciente el apellido que coincida con el del reg mascota
    int DNI=-1;              ///para comprar el ID entre los registros
    char nombreMascota[20];
    char apellidoCliente[30];
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();
    int cantMascotas=cantidadRegistrosMascotas();
    bool encontrado=false;

    vecHistoria=new Historia[cantHistorias];
    vecMascotas=new Mascotas[cantMascotas];
    vecClientes=new Cliente [cantClientes];

    if(vecHistoria==NULL||vecClientes==NULL||vecMascotas==NULL){
        errorAsignacionMemoria();
        delete(vecHistoria);
        delete(vecMascotas);
        delete(vecClientes);
        return false;
    }

    ///CARGO LOS VECTORES
    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!cargarVecClientes(vecClientes,cantClientes)||!cargarVecMascotas(vecMascotas,cantMascotas)){
        errorCargarRegistros();
        delete(vecClientes);
        delete(vecMascotas);
        delete(vecHistoria);
        return false;
    }

    cout << "MOSTRAR HISTORIA CLINICA." << endl << endl;
    cout << "       NOMBRE DE MASCOTA: ";                     ///PIDO nombreMascota (clase mascota)
    cin.ignore();
    cin.getline(nombreMascota,20);
    for(int i=0;i<cantMascotas;i++){                    ///MUESTRO LOS POSIBLES DUENIOS DE ESA MASCOTA
        if(strcmp(nombreMascota,vecMascotas[i].getNombreMascota())==0)
            for(int j=0;j<cantidadRegistrosClientes();j++){
                if(vecMascotas[i].getDNICliente()==vecClientes[j].getDNICliente()){
                    cout << "                 DUENIOS: " << vecClientes[i].getApellido()<< " | ";
                    encontrado=true;
                }
            }
    }
    cout << endl;
    if(!encontrado){
        cout << "NO HUBO COINCIDENCIAS"<< endl;
        pausar();
        return false;
    }

    cout << "    APELLIDO DEL CLIENTE: ";                    ///PIDO apellido (clase cliente)
    cin.getline(apellidoCliente,30);

    for(int i=0; i<cantHistorias; i++)          ///El problema es que puede haber mas de un cliente con el mismo apellido
    {
        if(strcmp(nombreMascota,vecHistoria[i].getNombreMascota())==0)          ///Recorro el vecHistoria hasta encontrar el nombre de mascota ingresado
        {
            for(int j=0; j<cantClientes; j++)       ///ahora vuelvo a recorrer pero el vecCliente hasta que coincida del apellido ingresado con el del REG
            {
                if((vecHistoria[i].getDNICliente() == vecClientes[j].getDNICliente())&&(strcmp(apellidoCliente,vecClientes[j].getApellido())==0)){
                    DNI=vecHistoria[i].getDNICliente();   ///al poder tener varios clientes con el mismo apellido, asi se puede obtener el ID correcto
                }
            }
        }
    }
    if(DNI==-1){
        cout << "NO HAY COINCIDENCIAS";
        cin.get();
        return false;
    }
    for (int i=0; i<cantHistorias; i++)
    {
        if(vecHistoria[i].getDNICliente()==DNI)   ///con el ID obtenido mostramos los atributos que corresponden
        {

            cout << endl << "    ID DE HISTORIA: " << vecHistoria[i].getIDHistoria()<< endl;
            cout << "   FECHA DE VISITA: ";
            vecHistoria[i].getFechaVisita().mostrarFecha();
            cout << endl;
            cout << "         ANAMNESIS: " << vecHistoria[i].getAnamnesis() << endl;
            cout << "      ---------------      " << endl;
        }
    }
    delete(vecHistoria);      ///tal vez necesite un DESTRUCTOR
    delete(vecClientes);
    delete(vecMascotas);
    pausar();
    return true;
}
bool modificarHistoria(){
    Historia regHistoria;
    Cliente regCliente;
    int ID,dia,mes,anio,validar;
    int posHistoria,posCliente;
    cout << "MODIFICAR HISTORIA." << endl<<endl;
    cout << " ID ENTRADA DE HISTORIA: ";
    cin>> ID;
    cin.ignore();
    posHistoria=buscarHistoria(ID);         ///PIDO EL ID, abro el archivo, busco esa entrada en particular y la leo
    if(posHistoria==-1){
        errorRegistro();
        return false;
    }
    regHistoria.leerHistoria(posHistoria);
    posCliente=buscarClientePorDNI(regHistoria.getDNICliente());
    if(posCliente==-1){
        errorEnteroInvalido(regHistoria.getDNICliente(),", NO SE ENCUENTRA EN EL ARCHIVO.");
        return false;
    }
    regCliente.leerCliente(posCliente);
    verVisita(regHistoria,regCliente);

//                                /// MUESTRA LO ANTERIOR
//    cout << "           FECHA VISITA: ";
//    regHistoria.getFechaVisita().mostrarFecha();
//    cout << "                 NOMBRE: " << regHistoria.getNombreMascota()<< endl;
//    cout << "              ANAMNESIS: " << regHistoria.getAnamnesis()<< endl;
//    cout << "                   -------------------------------------------------------" << endl;

                                /// EDITA ATRIBUTOS
    cout << "        NUEVA ANAMNESIS: ";              ///Despues se editan los Atributos de a uno.
    regHistoria.setAnamnesis();
    cout << "REQUIERE VISITA DE CONTROL?"<< endl;
    cout << "   INGRESE: 'SI' o 'NO': ";
    validar=preguntarSIoNO();
    if(validar==1){
        cout << "INGRESE LA FECHA DEL CONTROL(DD/MM/AA)"<< endl;
        cout << "                         DIA: ";
        cin >> dia;
        cout << "                         MES: ";
        cin >> mes;
        cout << "                        ANIO: ";
        cin >> anio;
        cin.ignore();
        regHistoria.setFechaControl(dia,mes,anio);
        if (!validarFecha(dia,mes,anio)||compararFechas(regHistoria.getFechaControl(),obtenerFechaActual())==1)  ///Se valida que no se ingrese 42/9/2500 o 29/2 si no es anio biciesto y que la fecha del control no sea en le pasado
        {
            errorFechaInvalida();
            return false;
        }
        regHistoria.setControl(true);
    }
    else if(validar==0){
        regHistoria.setControl(false);
        regHistoria.setFechaControl(0,0,0);
    }
    else{
        errorIngresoInvalido();
        return false;
    }

//    cin.ignore();

    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regHistoria.modificarHistoria(posHistoria)){
            error("NO SE PUDO GUARDAR LA VISITA");
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
bool controlesPendientes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    if(vecHistoria==NULL)
    {
        errorAsignacionMemoria();
        return false;
    }
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL)
    {
        errorAsignacionMemoria();
        delete(vecHistoria);
        return false;
    }

    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!(cargarVecClientes(vecCliente,cantClientes)))
    {
        errorCargarRegistros();
        delete(vecCliente);
        delete(vecHistoria);
        return false;
    }
    cout << "VISITAS DE CONTROL PENDIENTES." << endl << endl;
    for(int i=0; i<cantHistorias; i++)  ///Recorro el vecHistorias para encontrar las "control=true"
    {
        if(vecHistoria[i].getControl()&&compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==2)
        {
            cout << "       NOMBRE DE MASCOTA: " << vecHistoria[i].getNombreMascota();
            cout << "     FECHA: ";
            vecHistoria[i].getFechaControl().mostrarFecha();
            cout << endl;
            for(int j=0; j<cantClientes; j++)       ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
            {
                if(vecHistoria[i].getDNICliente()==vecCliente[j].getDNICliente())
                {
                    cout << "                APELLIDO: " << vecCliente[j].getApellido();    ///y ahora con el ID del cliente del reg de esa historia, ubico al cliente en el vec.
                    cout << "     TELEFONO: " << vecCliente[j].getTelefono() << endl;
                        ///asi accedo a sus atributos y muestro lo que necesito
                }
            }
            cout <<"--------------------------------------------------" <<endl;
        }
    }
    cout << "ESAS SON LAS ENTRADAS HASTA LA FECHA." << endl;
    pausar();
    delete(vecHistoria);
    delete(vecCliente);
    return true;
}
bool controlesAusentes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL||vecHistoria==NULL){
        errorAsignacionMemoria();
        delete (vecCliente);
        delete(vecHistoria);
        return false;
    }
    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!(cargarVecClientes(vecCliente,cantClientes))){
        errorCargarRegistros();
        delete(vecCliente);
        delete(vecHistoria);
        return false;
    }

    for(int i=0; i<cantHistorias; i++)  ///Recorro el vecHistorias para encontrar las "control=true" y que la fecha de contro no haya pasado
    {
        if(vecHistoria[i].getControl() && compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==1){
            cout << "       NOMBRE DE MASCOTA: " << vecHistoria[i].getNombreMascota();
            cout << "     FECHA: ";
            vecHistoria[i].getFechaControl().mostrarFecha();
            cout << endl;
            for(int j=0; j<cantClientes; j++)       ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
            {
                if(vecHistoria[i].getDNICliente()==vecCliente[j].getDNICliente()){
                    cout << "                APELLIDO: " << vecCliente[j].getApellido();    ///y ahora con el ID del cliente del reg de esa historia, ubico al cliente en el vec.
                    cout << "     TELEFONO: " << vecCliente[j].getTelefono() << endl;
                        ///asi accedo a sus atributos y muestro lo que necesito
                }
            }
            cout <<"--------------------------------------------------" <<endl;
        }
    }
    cout << "ESAS ENTRADAS HASTA LA FECHA." << endl;
    pausar();
    delete(vecHistoria);
    delete(vecCliente);
    return true;
}







