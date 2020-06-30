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
    system("cls");
    int op;
    cout<<" ======================================================== "<<endl;
    cout<<"|                     AGREGAR                            |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|        1) AGREGAR MASCOTA Y CLIENTE                    |"<<endl;
    cout<<"|        2) AGREGAR MASCOTA (CLIENTE EXISTENTE)          |"<<endl;
    cout<<"|--------------------------------------------------------|"<<endl;
    cout<<"|         0)SALIR                                        |"<<endl;
    cout<<" ======================================================== "<<endl;

    cin>>op;
    cin.ignore();
    switch(op)
    {
    case 1:
    {
        system("cls");
        Cliente reg;
        Mascotas re;
        if(reg.cargarCliente())
        {
            if(reg.gurdarClienteEnDisco())
            {
                cout<<" El nuevo cliente fue registrado "<<endl;
                system("pause");

        re.setIDcliente(reg.getIDCliente());
        if(re.Cargar_Mascota())
        {
            if(re.gurdar_Mascota_EnDisco())
            {
                cout<<" La mascota fue registrada "<<endl;
                system("pause");
            }
        }
    }}}
    break;
    case 2:
    {
        int dni;
        Cliente reg;
        Mascotas p;
        int pos_cliente,ID_cliente;
        system("cls");
        cout<<" Ingrese el DNI del cliente ya existente "<<endl;
        cin>>dni;

        pos_cliente=reg.buscarClienteXDni(dni);
        if(pos_cliente!=-1)
        {
            ID_cliente=reg.buscraID_Cliente(pos_cliente);
            listardueno(ID_cliente);
            p.setIDcliente(ID_cliente);
            if(p.Cargar_Mascota())
                if(p.gurdar_Mascota_EnDisco())
                    cout<<" La mascota fue registrada "<<endl;
            system("pause");
        }
        else
            cout<<" no existe el cliente "<<endl;
        system("pause");

    }
    break;
    }
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
    system("cls");
    int op;
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
    cin>>op;
    cin.ignore();
    switch(op)
    {
    case 1:
    {
        system("cls");
        Mascotas reg;
        reg.listar_Mascotas();
        system("pause");
    }
    break;
    case 2:
    {
        system("cls");
        Mascotas reg;
        reg.modificar_mascota();
        system("pause");
    }
    break;
    case 4:
    {
        system("cls");
        Mascotas reg;
        Cliente p;
        int op;
        cout<<endl;
        cout<<" 1-Registrar nuevo dueno "<<endl;
        cout<<" 2-Dueno ya existente  "<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 1:
        {
            Mascotas re;
            Cliente reg;
            char nombre[20];
            if(reg.cargarCliente())
            {
                if(reg.gurdarClienteEnDisco())
                {
                    cout<<" El nuevo cliente fue registrado "<<endl;
                    system("pause");
                    cin.ignore();
                    cout<<" Nombre de la mascota que desa transferir :";
                    cin.getline(nombre,20);
                    cin.ignore();
                    int pos;
                    pos=re.buscarMascotaXNombre(nombre);
                    re.setIDcliente(reg.getIDCliente());
                    if(re.sobrescribir_mascota(pos))
                    {
                        cout<<" Transferencia completada "<<endl;

                    }
                    else
                    {
                        cout<<" No se pudo transferir "<<endl;
                    }
                }
            }
        }
        break;
        case 2:
        {
             int dni;
            char nombre[20];
            Cliente reg;
            Mascotas re;
            cout<<" Ingrese el DNI del nuevo duenio :";
            cin>>dni;
            cin.ignore();
            cout<<" Nombre de la mascota que desa transferir :";
            cin.getline(nombre,20);
            cin.ignore();
            int pos=0;
            pos=reg.buscarClienteXDni(dni);
            reg.LeerDiscoDeCliente(pos);
            int posmascota=re.buscarMascotaXNombre(nombre);
            re.setIDcliente(reg.getIDCliente());
            if(re.sobrescribir_mascota(posmascota))
            {
                cout<<" Transferencia completada "<<endl;
            }
        }
        break;
        }
    }
    break;
    }

}
void pantallaClientes()
{
    system("cls");
    int op;
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

    cin>>op;
    cin.ignore();
    switch(op)
    {
    case 1:
    {
        Cliente reg;
        system("cls");
        reg.listarClietes();
        system("pause");
    }
    break;
    case 2:
    {
        Cliente reg;
        system("cls");
        reg.modificar_Cliente();
        system("pause");
    }
    break;
    }
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
    cout << "|       3) INGRESAR ITEM                              |"<< endl;
    cout << "|       4) LISTAR POR FECHA     /|_/|        /|___/|  |"<< endl;
    cout << "|       5) MOSTRAR DEUDORES     (0_0)         (0_o)   |"<< endl;
    cout << "|       6) COMISIONES          ==(Y)==         (V)    |"<< endl;
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
