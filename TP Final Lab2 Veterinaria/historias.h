#ifndef HISTORIAS_H_INCLUDED
#define HISTORIAS_H_INCLUDED
#include "fecha.h"

class Historia{
    private:
        int IDHistoria; ///se carga solo
        Fecha fechaIngreso; ///se carga solo
        Fecha fechaVisita;
        int IDCliente;
        char nombreMascota[20];
        char anamnesis [300];
        bool control; ///constructor =falso
        Fecha fechaControl;///constructor =0
        int numArancel; ///constructor =0
    public:
        Historia();
        ///      MOSTRAR
        void mostrarIDHistoria();
        void mostrarIDCliente();
        void mostrarFechaIngreso();
        void mostrarFechaVisita();
        void mostrarNombreMascota();
        void mostrarAnamnesis();
        void mostrarControl();
        void mostrarFechaControl();

///     SETs
        void setIDHistoria(int); /// no la hice, no se hacerla aun
        void setIDCliente(int);
        void setFechaIngreso(int,int,int); /// No se si esta bien
        void setFechaVisita(int,int,int); /// No se si esta bien
        void setNombreMascota(const char*cadena);
        void setAnamnesis(); /// la carga el usuario
        void setControl(bool);
        void setFechaControl(int,int,int);

///      GETs
        int getIDHistoria();
        int getIDCliente();
        Fecha getFechaIngreso();
        Fecha getFechaVisita();
        void getNombreMascota(char*);
        Fecha getFechaControl();

        ///DISCO
        int buscarHistoria(int);
        bool guardarHistoria();
        bool leerHistoria(int);
        int cantidadRegistros();

};


#endif // HISTORIAS_H_INCLUDED
