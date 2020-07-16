#ifndef HISTORIAS_H_INCLUDED
#define HISTORIAS_H_INCLUDED
#include "fecha.h"

const char ARCHIVOHISTORIAS[20]="historias.dat";
const char ARCHIVOHISTORIASBKP[20]="historias.bkp";

class Historia{
    private:
        int IDHistoria; ///se carga solo
        Fecha fechaIngreso; ///se carga solo
        Fecha fechaModificacion;
        Fecha fechaVisita;
        int DNICliente;
        char nombreMascota[20];
        char anamnesis [300];
        bool control;
        Fecha fechaControl;
        int IDArancel;
    public:
        ///     SETs
        void setIDHistoria(int); /// no la hice, no se hacerla aun
        void setDNICliente(int);
        void setFechaIngreso(); /// No se si esta bien
        void setFechaModificacion();
        void setFechaVisita(int,int,int); /// No se si esta bien
        void setNombreMascota(const char*cadena);
        void setAnamnesis(); /// la carga el usuario
        void setControl(bool);
        void setFechaControl(int,int,int);
        void setIDarancel(int);

///      GETs
        int getIDHistoria();
        int getDNICliente();
        Fecha getFechaIngreso();
        Fecha getFechaModificacion();
        Fecha getFechaVisita();
        const char*getNombreMascota();
        bool getControl();
        Fecha getFechaControl();
        int getIDarancel();
        const char*getAnamnesis();

        ///DISCO
        bool guardarHistoria();
        bool leerHistoria(int);
        bool modificarHistoria(int);
};

///GLOBALES
int asignarIDHistoria();
int cantidadRegistrosHistorias();
bool cargarVecHistorias(Historia*,int);
int buscarDNIClienteEnHistorias(int);
void verVisita(Historia);


///HISTORIAS
///Para resolver las consignas del MENU HISTORIA
bool ingresoHistoria();
bool mostrarEntradaHistoria();
bool mostrarHistoria();
bool modificarHistoria();
bool controlesPendientes();
bool controlesAusentes();
bool bajarControlesPendientes();
bool bajarControlesAusentes();





#endif // HISTORIAS_H_INCLUDED
