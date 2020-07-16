#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "clientes.h"
#include "mascotas.h"
#include "visuales.h"
#include "funcionesGlobales.h"
#include "windows.h"
#include "marcos.h"

using namespace std;

void pantallaPrincipal(){
    cout << " ===================================================== "<< endl;
    cout << "|                   VETERINARIA                       |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|        1) INGRESO PACIENTE                          |"<< endl;
    cout << "|        2) HISTORIA CLINICA                          |"<< endl;
    cout << "|        3) CLIENTES                                  |"<< endl;
    cout << "|        4) MASCOTAS                                  |"<< endl;
    cout << "|        5) ARANCELES         /|_/|        /|___/|    |"<< endl;
    cout << "|        6) ADMINISTRACION    (0_0)         (0_o)     |"<< endl;
    cout << "|        7) CONFIGURACION    ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaAgregar(){
    cout<<" ======================================================== "<<endl;
    cout<<"|                     AGREGAR                            |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|        1) AGREGAR MASCOTA Y CLIENTE                    |"<<endl;
    cout<<"|        2) AGREGAR MASCOTA (CLIENTE EXISTENTE)          |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|         0)VOLVER                                       |"<<endl;
    cout<<" ======================================================== "<<endl;
}
void pantallaHistorias(){
    cout << " ===================================================== "<< endl;
    cout << "|                 HISTORIA CLINICA                    |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) INGRESO DE NUEVA VISITA                      |"<< endl;
    cout << "|     2) MOSTRAR ENTRADA DE HISTORIA CLINICA (ID)     |"<< endl;
    cout << "|     3) MOSTRAR HISTORIA CLINICA                     |"<< endl;
    cout << "|     4) MODIFICAR HISTORIA   /|_/|        /|___/|    |"<< endl;
    cout << "|     5) CONTROLES PENDIENTES (0_0)         (0_o)     |"<< endl;
    cout << "|     6) CONTROLES AUSENTES  ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaMascotas(){
    cout << " ===================================================== "<< endl;
    cout << "|                    MASCOTAS                         |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|     1) MOSTRAR MASCOTAS                             |"<< endl;
    cout << "|     2) MODIFICAR MASCOTAS   /|_/|        /|___/|    |"<< endl;
    cout << "|     3) LISTAR VISITAS       (0_0)         (0_o)     |"<< endl;
    cout << "|     4) TRANSFERIR MASCOTA  ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaClientes(){
    system("cls");
    cout << " ===================================================== "<< endl;
    cout << "|                    CLIENTES                         |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|     1) MOSTRAR CLIENTES                             |"<< endl;
    cout << "|     2) MOSTRAR TODOS LOS CLIENTES                   |"<< endl;
    cout << "|     3) MODIFICAR CLIENTES   /|_/|        /|___/|    |"<< endl;
    cout << "|                             (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaAranceles(){
    cout << " ===================================================== "<< endl;
    cout << "|                    ARANCELES                        |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) NUEVO ARANCEL                                |"<< endl;
    cout << "|     2) MOSTRAR ARANCELES DEL DIA                    |"<< endl;
    cout << "|     3) MODIFICAR ARANCEL    /|_/|        /|___/|    |"<< endl;
    cout << "|     4) ARANCELES POR VISITA (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaAdministracion(){
    cout << " ===================================================== "<< endl;
    cout << "|                   ADMINISTRACION                    |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|       1) MOSTRAR LISTA DE PRECIOS                   |"<< endl;
    cout << "|       2) MODIFICAR IMPORTES                         |"<< endl;
    cout << "|       3) NUEVO SERVICIO                             |"<< endl;
    cout << "|       4) ALTA Y BAJA DE SERVICIOS                   |"<< endl;
    cout << "|       5) LISTAR POR FECHA     /|_/|        /|___/|  |"<< endl;
    cout << "|       6) MOSTRAR DEUDORES     (0_0)         (0_o)   |"<< endl;
    cout << "|       7) COMISIONES          ==(Y)==         (V)    |"<< endl;
    cout << "|-----------------------------(u)---(u)----oOo--U--oOo|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaConfiguracion(){
    cout << " ===================================================== "<< endl;
    cout << "|                CONFIGURACION                        |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) REALIZAR BACKUP DEL SISTEMA                  |"<< endl;
    cout << "|     2) RESTAURAR ARCHIVOS BACKUP                    |"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|                             /|_/|        /|___/|    |"<< endl;
    cout << "|                             (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) VOLVER                          |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void limpiar(){
    system("cls");
//    cin.ignore();
}
void pausar(){
    system("pause");
}
void colorPantalla(int texto,int fondo){
    int x;
    x=fondo*16+texto;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
///0 = Negro
///1= Azul
///2= Verde
///3= Aguamarina
///4= Rojo
///5= Púrpura
///6= Amarillo
///7= Blanco
///8= Gris
///9= Azul Claro
///A= Verde Claro
///B= Aguamarina Claro
///C= Rojo Claro
///D= Púrpura Claro
///E= Amarillo Claro
///F= Blanco Brillante
}

///ERRORES
void error(const char* mensaje){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "           " << mensaje << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorCadenaInvalida(const char* cadena,const char* mensaje){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "       '"<< cadena <<"' " << mensaje << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorEnteroInvalido(int numero,const char* mensaje){
    limpiar();
//    colorPantalla(15,4);
    system("color 4F");
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "       '"<< numero <<"' " << mensaje << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorFloatInvalido(float numero,const char* mensaje){
    limpiar();
//    colorPantalla(15,4);
    system("color 4F");
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "       '"<< numero <<"' " << mensaje << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}

void errorFechaInvalida(){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "              ERROR: FECHA INVALIDA." << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorArchivo(){
    limpiar();
//    colorPantalla(15,4);
    system("color 4F");
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "         ERROR: NO SE PUDO ABRIR EL ARCHIVO." << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorIngresoInvalido(){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "               ERROR: INGRESO INVALIDO." << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void volviendoMenu(){
    limpiar();
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "                  VOLVIENDO AL MENU..." << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void guardadoExitoso(){
    limpiar();
    system("color 2F");
//    colorPantalla(15,2);
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "                  GUARDADO EXITOSO." << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorRegistro(){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "       NO SE ENCUENTRA EL REGISTRO EN EL ARCHIVO."  << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorAsignacionMemoria(){
    limpiar();
//    colorPantalla(15,4);
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "                NO HAY MEMORIA SUFICIENTE"  << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorCargarRegistros(){
    limpiar();
    system("color 4F");
    gotoxy(0,4);
//    colorPantalla(15,4);
    cout << " =====================================================" << endl<< endl;
    cout << "      NO SE PUDIERON CARGAR EL/LOS REGISTRO/S."  << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
void errorGuardado(){
    limpiar();
    system("color 4F");
//    colorPantalla(15,4);
    gotoxy(0,4);
    cout << " =====================================================" << endl<< endl;
    cout << "            NO SE PUDO GUARDAR EL ARCHIVO."  << endl << endl;
    cout << " =====================================================" << endl;
    pausar();
}
