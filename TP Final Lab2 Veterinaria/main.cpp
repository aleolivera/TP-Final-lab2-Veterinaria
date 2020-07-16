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
#include "menuSwitches.h"
#include "funcionesGlobales.h"

using namespace std;

int main()
{
//    Arancel reg;
//    FILE*p=fopen(ARCHIVOARANCELES,"rb");
//    if(p==NULL) return -1;
//    while(fread(&reg,sizeof reg,1,p)==1){
//        cout << reg.getIDArancel() << endl;
//        verArancel(reg);
//    }
//    pausar();

    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL) return -1;
    while(fread(&reg,sizeof reg,1,p)==1){
        cout << reg.getIDTipoVisita() << endl;
        cout << reg.getNombreTipoVisita() << endl;
    }
    pausar();

    int op;
    bool salir=false;
    while(!salir){
        system("cls");
//        colorPantalla(10,0);
        system("color 0A");
        pantallaPrincipal();
        cin>>op;
        cin.ignore();
        switch(op){
            case 1:
                    menuAgregar();
                break;
            case 2:
                    menuHistorias();
                break;
            case 3:
                    menuClientes();
                break;
            case 4:
                    menuMascotas();
                break;
            case 5:
                    menuAranceles();
                break;
            case 6:
                    menuAdministracion();
                break;
            case 7:
                    menuConfiguracion();
                break;
            case 0:
                    salir=true;
                break;

        }
    }
    return 0;
}
