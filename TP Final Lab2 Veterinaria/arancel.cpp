#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "fecha.h"
#include "arancel.h"
#include "visuales.h"
#include "funcionesGlobales.h"
///CONSTRUCTOR
//Arancel::Arancel(){
//    fechaArancel=obtenerFechaActual();
//    IDArancel=asignarIDarancel();
//}

///GETs
Fecha Arancel::getFechaArancel(){
    return fechaArancel;
}
int Arancel::getIDArancel(){
    return IDArancel;
}
int Arancel::getDNICliente(){
    return DNICliente;
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
void Arancel::setFechaArancel(){
    fechaArancel=obtenerFechaActual();
}
void Arancel::setIDArancel(int ID){
    IDArancel=ID;
}
void Arancel::setDNICliente(int DNI){
    DNICliente=DNI;
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
bool Arancel::guardarArancel(){         ///GUARDA EL REGISTRO EN EL ARCHIVO EN LA ULTIMA POSICION
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
bool Arancel::modificarArancel(int pos){ ///GUARDA EL REGISTRO EN EL ARCHIVO EN LA POSICION CORRESPONDIENTE A ESE ID
    FILE*p=fopen(ARCHIVOARANCELES,"rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,(pos*sizeof (Arancel)),0);
    if(fwrite(this,sizeof (Arancel),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

///GLOBALES
int buscarIDhistoriaEnAranceles(int IDHistoria){
    Arancel reg;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL) return -1;
    while(fread(&reg,sizeof (Arancel),1,p)==1){
        if(IDHistoria==reg.getIDHistoria()){
            fclose(p);
            return reg.getIDArancel();
        }
    }
    fclose(p);
    return -1;
}
int cantidadRegistrosArancel(){ ///Devuelve la cantidad de registros en ARCHIVOARANCELES
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Arancel);
}
bool cargarVecArancel(Arancel*vec,int tam){///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
    Arancel reg;
    int i=0;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Arancel),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
int asignarIDarancel(){///Le pone solo el ID de manera secuencial
    Arancel reg;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return 1;
    }
    if(fread(&reg,sizeof (Arancel),1,p)==0)
    {
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (Arancel),2);
        fread(&reg,sizeof (Arancel),1,p);
        fclose(p);
        return reg.getIDArancel()+1;
    }
}
void verArancel(Arancel regArancel){
    TipoVisita regTipoVisita;
    int pos=buscarTipoVisita(regArancel.getIDTipoVisita());
    if(pos==-1){
        return;
    }
    regTipoVisita.leerTipoVisita(pos);
    cout << "                  FECHA: ";
    regArancel.getFechaArancel().mostrarFecha();
    cout << endl;
    cout << "           TIPO DE PAGO: " << tipoDePagoACadena(regArancel.getTipoPago()) << endl;
    cout << "         TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita() << endl;
    cout << "                  TOTAL: " << regArancel.getTotalArancel() << endl;
}

///ARANCELES
///Para resolver las consignas del MENU ARANCELES
bool nuevoArancel(){
    Historia regHistoria;
    Arancel regArancel;
    TipoVisita regTipoVisita;
    Cliente regCliente;
    char tipoPago;
    int valor,pos,validar;
    float total;
    regArancel.setFechaArancel();
    regArancel.setIDArancel(asignarIDarancel());
    cout << "======================================================"<< endl;
    cout << "                  INGRESO DE NUEVO ARANCEL" << endl;
    cout << "------------------------------------------------------"<< endl;
    cout << "FECHA DE ARANCEL: ";
    regArancel.getFechaArancel().mostrarFecha();

    cout << "        ID ARANCEL: " << regArancel.getIDArancel();
    cout << endl;
    cout << "ID DE HISTORIA: ";
    cin >> valor;                           ///PIDO ID Y VALIDO SU PRESENCIA EN EL ARCHIVO HISTORIAS
    pos=buscarHistoria(valor);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regHistoria.leerHistoria(pos);
//    if (regHistoria.getIDarancel()!=-1){
//        cout << "A ESA HISTORIA LE FUE ASIGNADA EL ARANCEL ID " << regHistoria.getIDarancel()<< endl;
//        return false;
//    }
    regArancel.setIDHistoria(valor);

    valor=regHistoria.getDNICliente();
    cout<< "DNI DE CLIENTE: " << valor << endl;  ///ASIGNO AUTOMATICAMENTE ID Y VALIDO SU PRESENCIA EN EL ARCHIVOCLIENTES
    pos=buscarDNIClienteEnHistorias(regHistoria.getIDHistoria());
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regArancel.setDNICliente(valor);
    cout << endl;
    listarTiposDeVisita(1);
    cout << endl;
    cout<< "TIPO DE VISITA: ";             ///PIDO TIPO DE VISITA Y VALIDO SU PRESENCIA EN EL ARCHIVOTIPOVISITAS
    cin >> valor;
    pos=buscarTipoVisita(valor);
    if(pos==-1){
        errorRegistro();
        return false;           ///SI NO ESTA EN DISCO POS=-1 Y SALE
    }
    regTipoVisita.leerTipoVisita(pos);
    total=regTipoVisita.getImporte();   ///CARGO Y VALIDO EL IMPORTE DE LA VISITA SEGUN EL ARCHIVOTIPOVISITAS
    if(total<0){
        errorIngresoInvalido();
        return false;
    }
    regArancel.setIDTipoVisita(valor);
    regArancel.setTotalArancel(total);
    cout << "------------------------------------------------------"<< endl;
    cout << "TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita();
    cout << "        TOTAL: $" <<regArancel.getTotalArancel() << endl << endl;
    cout << "E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cout << "TIPO DE PAGO: ";
    cin>> tipoPago;
    cin.ignore();
    if(!validarTipoDePago(tipoPago))                                     ///VALIDA QUE SE INGRESEN 'E,T,D,C'
    {
        errorIngresoInvalido();
        return false;
    }
    regArancel.setTipoPago(tipoPago);

    if(tipoPago=='c'||tipoPago=='C')                                    ///EL PAGO QUEDA A CUENTA ENTONCES..
    {
        regArancel.setAbonado(false);                                   ///PONGO EL ARANCEL COMO IMPAGO
        pos=buscarClientePorDNI(regArancel.getDNICliente());
        if(pos==-1){
            errorRegistro();
            return false;
        }
        regCliente.leerCliente(pos);
        regCliente.setSaldo(regArancel.getTotalArancel()+regCliente.getSaldo()); ///BUSCO AL CLIENTE Y ACUMULO SU SALDO
        regCliente.modificarCliente(pos);
    }
    else
    {
        regArancel.setAbonado(true);
    }
    regArancel.setPorcentajeHonorario(regTipoVisita.getPorcentajeHonorario());

    cout << "------------------------------------------------------"<< endl;
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regArancel.guardarArancel()){
            error("NO SE PUDO GUARDAR EL ARANCEL");
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
bool mostrarArancelesDelDia(){
    Arancel*vec;
    Fecha fechaDeHoy;
    fechaDeHoy.setFechaActual();
    cout << "======================================================"<< endl;
    cout << "          MOSTRAR ARANCELES DEL DIA: ";
    fechaDeHoy.mostrarFecha();
    cout << endl;
    int cantAranceles=cantidadRegistrosArancel();
    vec=new Arancel[cantAranceles];
    if(vec==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecArancel(vec,cantAranceles)){
        errorCargarRegistros();
        delete(vec);
        return false;
    }
    bool estado=false;
    for(int i=0; i<cantAranceles; i++){
        if(compararFechas(vec[i].getFechaArancel(),obtenerFechaActual())==0){
            estado=true;
            cout <<"------------------------------------------------------"<< endl;
            cout <<" ID DE ARANCEL: "<< vec[i].getIDArancel()<< endl;
            cout <<"TIPO DE VISITA: "<< vec[i].getIDTipoVisita()<< endl;
            cout <<"  TIPO DE PAGO: "<< tipoDePagoACadena(vec[i].getTipoPago())<< endl;
            cout <<"         TOTAL: "<< vec[i].getTotalArancel()<< endl;

        }
    }
    if(!estado){
        cout << "NO HUBO VISITAS EL DIA DE HOY." << endl;
    }
    cout << "======================================================"<< endl;
    pausar();
    delete(vec);
    return true;
}
bool modificarArancel(){
    Arancel regArancel;
    Cliente regCliente;

    int ID,posArancel,posCliente,validar;
    char tipoPago;
    cout << "======================================================="<< endl;
    cout << "                    MODIFICAR ARANCEL" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "  INGRESE ID DE ARANCEL: ";
    cin >> ID;
    posArancel=buscarArancel(ID);
    if (posArancel==-1){
        errorRegistro();
        return false;
    }
    regArancel.leerArancel(posArancel);
    verArancel(regArancel);
    cout <<"-------------------------------------------------------"<<endl;
    cout <<"            INGRESE LA MODIFICACION" << endl;
    cout <<" E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cout <<"           TIPO DE PAGO: ";
    cin >> tipoPago;
    cin.ignore();
    if(!validarTipoDePago(tipoPago)){
        errorIngresoInvalido();
        return false;
    }
    regArancel.setTipoPago(tipoPago);
    posCliente=buscarClientePorDNI(regArancel.getDNICliente()); ///BUSCO AL CLIENTE
    if(posCliente==-1){
        errorRegistro();
        return false;
    }
    regCliente.leerCliente(posCliente);
    if(tipoPago=='c'||tipoPago=='C')                                 ///EL PAGO QUEDA A CUENTA ENTONCES..
    {
        if(regArancel.getAbonado()){                                ///SI EL ARANCEL ESTABA ABONADO, AHORA SE LO SUMO AL SALDO
            regCliente.setSaldo(regArancel.getTotalArancel()+regCliente.getSaldo());
        }
        regArancel.setAbonado(false);
    }
    else
    {
        if(!regArancel.getAbonado()){                                ///SI EL ARANCEL ESTABA ABONADO, AHORA SE LO SUMO AL SALDO

            regCliente.setSaldo(regCliente.getSaldo()-regArancel.getTotalArancel());
        }
        regArancel.setAbonado(true);
    }
    cout <<"-------------------------------------------------------"<<endl;
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regArancel.modificarArancel(posArancel) || !regCliente.modificarCliente(posCliente)){
            error("NO SE PUDO GUARDAR EL ARANCEL");
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
bool mostrarArancelesPorVisita(){
    Arancel *vecArancel;
    TipoVisita *vecTipoVisita;
    int cantAranceles=cantidadRegistrosArancel();
    int cantTipoVisita=cantidadRegistrosTipoVisita();
    vecArancel=new Arancel[cantidadRegistrosArancel()];
    vecTipoVisita=new TipoVisita [cantidadRegistrosTipoVisita()];

    if(vecArancel==NULL||vecTipoVisita==NULL){
        errorAsignacionMemoria();
        delete(vecArancel);
        delete(vecTipoVisita);
        return false;
    }

    if(!cargarVecArancel(vecArancel,cantAranceles)||!cargarVecTipoVisita(vecTipoVisita,cantTipoVisita)){
        errorCargarRegistros();
        delete(vecArancel);
        delete(vecTipoVisita);
        return false;

    }
    int ID,anio;
    float acu=0;
    cout << "======================================================"<< endl;
    cout << "          ARANCELES POR TIPO DE VISITA (ANUAL)" << endl;
    cout << "------------------------------------------------------"<< endl;
    listarTiposDeVisita(2);
    cout << "------------------------------------------------------"<< endl;
    cout << "INGRESE EL TIPO DE VISITA: ";
    cin >> ID;
    cout << "                     ANIO: ";
    cin >> anio;
    if (anio<100) anio+=2000;
    cout << endl;
    for(int i=0;i<cantTipoVisita;i++){
        if(vecTipoVisita[i].getIDTipoVisita()==ID){
            for (int j=0;j<cantAranceles;j++){
                if(vecArancel[j].getIDTipoVisita()==ID && vecArancel[j].getFechaArancel().getAnio()==anio){
                cout <<"            ID N " << vecArancel[j].getIDArancel()<<" | ";
                vecArancel[i].getFechaArancel().mostrarFecha();
                cout << " | $"<<vecArancel[j].getTotalArancel()<< endl;
                acu+=vecArancel[j].getTotalArancel();
                }
            }

        }
    }

    cout << "------------------------------------------------------"<< endl;
    cout << "                TOTAL: $" << acu << endl;
    cout << "======================================================"<< endl;
    cin.ignore();
    cin.get();
    return true;
}
