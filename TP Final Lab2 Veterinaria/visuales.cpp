#include <iostream>
using namespace std;

void pantallaPrincipal(){
    cout << " ===================================================== "<< endl;
    cout << "|                   VETERINARIA                       |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|        1) HISTORIA CLINICA                          |"<< endl;
    cout << "|        2) CLIENTES                                  |"<< endl;
    cout << "|        3) MASCOTAS                                  |"<< endl;
    cout << "|        4) ARANCELES         /|_/|        /|___/|    |"<< endl;
    cout << "|        5) ADMINISTRACION    (0_0)         (0_o)     |"<< endl;
    cout << "|        6) CONFIGURACION    ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaHistorias(){
    cout << " ===================================================== "<< endl;
    cout << "|                 HISTORIA CLINICA                    |"<< endl;
    cout << "|-----------------------------------------------------|"<< endl;
    cout << "|     1) INGRESO DE NUEVA VISITA                      |"<< endl;
    cout << "|     2) MOSTRAR HISTORIA CLINICA                     |"<< endl;
    cout << "|     3) MODIFICAR HISTORIA   /|_/|        /|___/|    |"<< endl;
    cout << "|     4) CONTROLES PENDIENTES (0_0)         (0_o)     |"<< endl;
    cout << "|     5) CONTROLES AUSENTES  ==(Y)==         (V)      |"<< endl;
    cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
    cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
    cout << " ===================================================== "<< endl;
    cout << "|                    DOCTOR CASA                      |"<< endl;
    cout << " ===================================================== "<< endl;
}
void pantallaMascotas(){
cout << " ===================================================== "<< endl;
cout << "|                    MASCOTAS                         |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|     1) INGRESO DE NUEVA MASCOTA                     |"<< endl;
cout << "|     2) MOSTRAR MASCOTAS(DUENO)                      |"<< endl;
cout << "|     3) MOSTRAR MASCOTAS(NOMBRE)                     |"<< endl;
cout << "|     3) MODIFICAR MASCOTAS   /|_/|        /|___/|    |"<< endl;
cout << "|     4) LISTAR VISITAS       (0_0)         (0_o)     |"<< endl;
cout << "|     5) TRANSFERIR MASCOTA  ==(Y)==         (V)      |"<< endl;
cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                    DOCTOR CASA                      |"<< endl;
cout << " ===================================================== "<< endl;

}
void pantallaClientes(){
cout << " ===================================================== "<< endl;
cout << "|                    CLIENTES                         |"<< endl;
cout << "|-----------------------------------------------------|"<< endl;
cout << "|     1) INGRESO DE NUEVO CLIENTE                     |"<< endl;
cout << "|     2) MOSTRAR CLIENTES                             |"<< endl;
cout << "|     3) MODIFICAR CLIENTES   /|_/|        /|___/|    |"<< endl;
cout << "|     4) LISTAR VISITAS       (0_0)         (0_o)     |"<< endl;
cout << "|     5)                     ==(Y)==         (V)      |"<< endl;
cout << "|---------------------------(u)---(u)----oOo--U--oOo--|"<< endl;
cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
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
cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
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
cout << "|       3) INGRESAR ITEM        /|_/|        /|___/|  |"<< endl;
cout << "|       4) LISTAR POR FECHA     (0_0)         (0_o)   |"<< endl;
cout << "|       5) MOSTRAR DEUDORES    ==(Y)==         (V)    |"<< endl;
cout << "|-----------------------------(u)---(u)----oOo--U--oOo|"<< endl;
cout << "|                  0) SALIR DEL PROGRAMA              |"<< endl;
cout << " ===================================================== "<< endl;
cout << "|                    DOCTOR CASA                      |"<< endl;
cout << " ===================================================== "<< endl;
}
void pantallaConfiguracion(){
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
