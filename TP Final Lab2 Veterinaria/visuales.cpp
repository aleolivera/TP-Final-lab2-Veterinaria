#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "clientes.h"
#include "mascotas.h"
#include "visuales.h"
#include "funcionesGlobales.h"
using namespace std;

void pantallaPrincipal()
{
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

void pantallaAgregar()
{
    cout<<" ======================================================== "<<endl;
    cout<<"|                     AGREGAR                            |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|        1) AGREGAR MASCOTA Y CLIENTE                    |"<<endl;
    cout<<"|        2) AGREGAR MASCOTA (CLIENTE EXISTENTE)          |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|         0)SALIR                                        |"<<endl;
    cout<<" ======================================================== "<<endl;
}

void pantallaHistorias()
{
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
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaMascotas()
{
    cout << " ===================================================== "<< endl;
    cout << "|                    MASCOTAS                         |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|     1) MOSTRAR MASCOTAS                             |"<< endl;
    cout << "|     2) MODIFICAR MASCOTAS   /|_/|        /|___/|    |"<< endl;
    cout << "|     3) LISTAR VISITAS       (0_0)         (0_o)     |"<< endl;
    cout << "|     4) TRANSFERIR MASCOTA  ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaClientes()
{
    system("cls");
    cout << " ===================================================== "<< endl;
    cout << "|                    CLIENTES                         |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|     1) MOSTRAR CLIENTES                             |"<< endl;
    cout << "|     2) MODIFICAR CLIENTES   /|_/|        /|___/|    |"<< endl;
    cout << "|     3) LISTAR VISITAS       (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaAranceles()
{
    cout << " ===================================================== "<< endl;
    cout << "|                    ARANCELES                        |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) NUEVO ARANCEL                                |"<< endl;
    cout << "|     2) MOSTRAR ARANCELES DEL DIA                    |"<< endl;
    cout << "|     3) MODIFICAR ARANCEL    /|_/|        /|___/|    |"<< endl;
    cout << "|     4) ARANCELES POR VISITA (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaAdministracion()
{
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
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaConfiguracion()
{
    cout << " ===================================================== "<< endl;
    cout << "|                CONFIGURACION                        |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) BACKUP CLIENTES                              |"<< endl;
    cout << "|     2) BACKUP MASCOTAS                              |"<< endl;
    cout << "|     3) BACKUP HISTORIAS                             |"<< endl;
    cout << "|     4) BACKUP LISTA DE PRECIOS                      |"<< endl;
    cout << "|     5) BACKUP ARANCELES     /|_/|        /|___/|    |"<< endl;
    cout << "|                             (0_0)         (0_o)     |"<< endl;
    cout << "|                            ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}

void limpiar()
{
    system("cls");
//    cin.ignore();
}
void pausar(){
    system("pause");
}
///ERRORES
void errorFechaInvalida(){
    limpiar();
    cout << "ERROR: FECHA INVALIDA." << endl;
    pausar();
}
void errorArchivo(){
    limpiar();
    cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO." << endl;
    pausar();
}
void errorIngresoInvalido(){
    limpiar();
    cout << "ERROR: INGRESO INVALIDO."<< endl;
    pausar();
}
void volviendoMenu(){
    limpiar();
    cout << "VOLVIENDO AL MENU..."<< endl;
    pausar();
}
void guardadoExitoso(){
    limpiar();
    cout << "GUARDADO EXITOSO." << endl;
    pausar();
}
void errorRegistro(){
    limpiar();
    cout << "NO SE ENCUENTRA EL REGISTRO EN EL ARCHIVO." << endl;
    pausar();
}
void errorAsignacionMemoria(){
    limpiar();
    cout << "NO HAY MEMORIA SUFICIENTE." << endl;
    pausar();
}
void errorCargarRegistros(){
    limpiar();
    cout << "NO SE PUDIERON CARGAR EL/LOS REGISTRO/S." << endl;
    pausar();
}
void errorGuardado(){
    limpiar();
    cout << "NO SE PUDO GUARDAR EL ARCHIVO." << endl;
    pausar();
}
