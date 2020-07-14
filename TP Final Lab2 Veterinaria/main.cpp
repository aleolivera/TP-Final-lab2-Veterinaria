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
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL) return -1;
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        verMascota(reg);
        }
    pausar();
    fclose(p);

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
