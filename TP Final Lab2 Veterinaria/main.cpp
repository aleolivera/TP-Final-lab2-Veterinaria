#include <iostream>
#include <cstdlib>
#include "visuales.h"
#include "fecha.h"
#include "clientes.h"

using namespace std;
///CONSTANTES DAT
const char ARCHIVOHISTORIAS[20]="historias.dat";
const char ARCHIVOCLIENTES[20]="clientes.dat";
const char ARCHIVOMASCOTAS[20]="mascotas.dat";
const char ARCHIVOARANCELES[20]="aranceles.dat";
const char ARCHIVOTIPOVISITA[20]="tipovisita.dat";

///CONSTANTES BKP
const char ARCHIVOHISTORIASBKP[20]="historias.bkp";
const char ARCHIVOCLIENTESBKP[20]="clientes.bkp";
const char ARCHIVOMASCOTASBKP[20]="mascotas.bkp";
const char ARCHIVOARANCELESBKP[20]="aranceles.bkp";
const char ARCHIVOTIPOVISITABKP[20]="tipovisita.bkp";

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
            pantallaAgregar();
        }
        break;
        case 3:
        {
            pantallaClientes();
        }break;
        }
    }
    return 0;
}
