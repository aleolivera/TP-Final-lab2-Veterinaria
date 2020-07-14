#include "menuSwitches.h"

void menuAgregar(){
    limpiar();
    pantallaAgregar();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(AgregarPacienteYCliente()){
            guardadoExitoso();
        }
    break;
    case 2:
        if(ingresarSoloMascota()){
            guardadoExitoso();
        }
    break;
    case 0:
        break;
    }
}
void menuClientes(){
    limpiar();
    pantallaClientes();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(mostrarCliente()){
            volviendoMenu();
        }
    break;
    case 2:
        if(mostrarTodosClientes()){
            volviendoMenu();
        }
    break;
    case 3:
        if(modificarClientes()){
            guardadoExitoso();
        }
    break;
    case 0:
        break;
    }
}
void menuMascotas(){
    limpiar();
    pantallaMascotas();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(mostrarMascotas()){
            volviendoMenu();
        }
    break;
    case 2:
        if(modificarMascotas()){
            guardadoExitoso();
        }
    break;
    case 3:
        if(listarVisitas()){
            volviendoMenu();
        }
    break;
    case 4:
        if(transferirMascotas()){
            guardadoExitoso();
        }
    break;
    case 0:
        break;
    }
}
void menuHistorias(){
    limpiar();
    pantallaHistorias();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(ingresoHistoria()){
            guardadoExitoso();
        }
    break;
    case 2:
        if(mostrarEntradaHistoria()){
            volviendoMenu();
        }
    break;
    case 3:
        if(mostrarHistoria()){
            volviendoMenu();
        }
    break;
    case 4:
        if(modificarHistoria()){
            guardadoExitoso();
        }
    break;
    case 5:
        if(controlesPendientes()){
            volviendoMenu();
        }
    break;
    case 6:
        if(controlesAusentes()){
            volviendoMenu();
        }
    break;
    case 0:
        break;
    }
}
void menuAranceles(){
    limpiar();
    pantallaAranceles();
    int op;
    cin >>op;
    limpiar();
    switch(op){
        case 1:
            if(nuevoArancel()){
                guardadoExitoso();
            }
            break;
        case 2:
            if(mostrarArancelesDelDia()){
                volviendoMenu();
            }
            break;
        case 3:
            if(modificarArancel()){
                guardadoExitoso();
            }
            break;
        case 4:
            if(mostrarArancelesPorVisita()){
                volviendoMenu();
            }
            break;
        case 0:

            break;
    }
}
void menuAdministracion(){
    limpiar();
    pantallaAdministracion();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(mostrarListaDePrecios()){
            volviendoMenu();
        }
    break;
    case 2:
        if(modificarImportes()){
            guardadoExitoso();
        }
    break;
    case 3:
        if(nuevoServicio()){
            guardadoExitoso();
        }
    break;
    case 4:
        if(AltaBajaServicio()){
            guardadoExitoso();
        }
    break;
    case 5:
        if(listarPorFecha()){
            volviendoMenu();
        }
    break;
    case 6:
        if(mostrarDeudores()){
            volviendoMenu();
        }
    break;
    case 7:
        if(comisiones()){
            volviendoMenu();
        }
    break;
    case 0:

        break;
    }

}
void menuConfiguracion(){
    limpiar();
    pantallaConfiguracion();
    int op;
    cin >>op;
    cin.ignore();
    limpiar();
    switch(op){
    case 1:
        if(realizarBKP()){
            guardadoExitoso();
        }
    break;
    case 2:
        if(restaurarSistema()){
            guardadoExitoso();
            cout << "SISTEMA RESTAURADO."<< endl;
            pausar();
        }
    break;
    case 0:
        break;
    }
}



