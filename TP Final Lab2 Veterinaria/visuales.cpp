#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "clientes.h"
#include "mascotas.h"
#include "visuales.h"
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
            }
        }
        if(re.Cargar_Mascota())
        {
            if(re.gurdar_Mascota_EnDisco())
            {
                cout<<" La mascota fue registrada "<<endl;
                system("pause");
            }
        }
    }
    break;
    case 2:
    {
        char nombre[30];
        char apellido[30];
        Cliente reg;
        int pos_cliente,ID_cliente;
        system("cls");
        cout<<" Ingresar cliente ya existente "<<endl;
        cout<<" Nombre  :";
        cin.getline(nombre,30);
        cout<<" Apellido :";
        cin.getline(apellido,30);
        pos_cliente=reg.buscarCliente(nombre,apellido);
        if(pos_cliente!=1)
        {
            ID_cliente=reg.buscraID_Cliente(pos_cliente);
        }
        else
            cout<<" no existe el cliente "<<endl;

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
    case 1:{
        system("cls");
        Mascotas reg;
        reg.listar_Mascotas();
        system("pause");
        }break;
    case 2: {
        system("cls");
        Mascotas reg;
        reg.modificar_mascota();
        system("pause");
     }break;
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
    cout << "|     5)                     ==(Y)==         (V)      |"<< endl;
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
    cout << "|       3) INGRESAR ITEM        /|_/|        /|___/|  |"<< endl;
    cout << "|       4) LISTAR POR FECHA     (0_0)         (0_o)   |"<< endl;
    cout << "|       5) MOSTRAR DEUDORES    ==(Y)==         (V)    |"<< endl;
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
    cout << "|     3) BACKUP HISTORIAS     /|_/|        /|___/|    |"<< endl;
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
    cin.ignore();
}
