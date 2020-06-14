#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "fecha.h"
#include "arancel.h"
#include "clientes.h"
#include "historias.h"
#include "mascotas.h"
#include "tipoVisita.h"
#include "visuales.h"
#include "funcionesGlobales.h"

using namespace std;
/////CONSTANTES DAT      LAS COMENTE PORQ SE DECLARAN EN SUS RESPECTIVOS HEADER, PREGUNTO EN CLASE IGUAL PARA ESTAR SEGURO
//const char ARCHIVOHISTORIAS[20]="historias.dat";
//const char ARCHIVOCLIENTES[20]="clientes.dat";
//const char ARCHIVOMASCOTAS[20]="mascotas.dat";
//const char ARCHIVOARANCELES[20]="aranceles.dat";
//const char ARCHIVOTIPOVISITA[20]="tipovisita.dat";
//
/////CONSTANTES BKP
//const char ARCHIVOHISTORIASBKP[20]="historias.bkp";
//const char ARCHIVOCLIENTESBKP[20]="clientes.bkp";
//const char ARCHIVOMASCOTASBKP[20]="mascotas.bkp";
//const char ARCHIVOARANCELESBKP[20]="aranceles.bkp";
//const char ARCHIVOTIPOVISITABKP[20]="tipovisita.bkp";

int main()
{
    int op;
    bool salir=false;
    while(!salir)
    {

        pantallaPrincipal();
        cin>>op;
        switch(op)
        {
            case 1:
                {
                    menuIngresoPaciente();

                }
                break;
            case 2:
                {
                    menuHistorias();
                }
                break;
            case 3:
                {
//                    pantallaClientes();
                    menuClientes();
                }
                break;
            case 4:
                {
                    menuMascotas();
                }
                break;
            case 5:
                {
                    menuAranceles();
                }break;
            case 6:
                {
                    menuAdministracion();
                }break;
            case 7:
                {
                    menuConfiguracion();
                }break;
            case 0:
                {
                    salir=true;
                }break;

        }
    }
    return 0;
}
