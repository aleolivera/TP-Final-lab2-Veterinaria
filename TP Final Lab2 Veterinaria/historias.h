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
        int IDCliente;
        char nombreMascota[20];
        char anamnesis [300];
        bool control;
        Fecha fechaControl;
        int IDArancel;
    public:
        ///      MOSTRAR

        void mostrarFechaIngreso();
        void mostrarFechaModificacion();
        void mostrarFechaVisita();
        void mostrarAnamnesis();
        void mostrarFechaControl();

///     SETs
        void setIDHistoria(int); /// no la hice, no se hacerla aun
        void setIDCliente(int);
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
        int getIDCliente();
        Fecha getFechaIngreso();
        Fecha getFechaModificacion();
        Fecha getFechaVisita();
        const char*getNombreMascota();
        bool getControl();
        Fecha getFechaControl();
        int getIDarancel();

        ///DISCO
        int buscarHistoria(int);
        bool guardarHistoria();
        bool leerHistoria(int);
        bool modificarHistoria(int);
//        bool mostrarTodoElArchivo();

//        ///CONSTRUCTOR
//        Historia(){
//            fechaModificacion.setFechaActual();
//            fechaControl.setFecha(0,0,0);
//            IDArancel=0;
//        }

};


#endif // HISTORIAS_H_INCLUDED
