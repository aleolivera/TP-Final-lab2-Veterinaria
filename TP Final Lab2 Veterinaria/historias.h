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
        char amnesis [300];
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
        void mostrarAmnesis();
        void mostrarControl();
        void mostrarFechaControl();

///      CARGA
        void cargarIDHistoria(); /// no la hice, no se hacerla aun
        void cargarIDCliente();
        void cargarFechaIngreso(); /// se pone sola la fecha que se creo la historia (fecha actual de ese dia)
        void cargarFechaVisita(); /// la carga el usuario
        void cargarNombreMascota(); /// la carga el usuario
        void cargarAmnesis(); /// la carga el usuario
        void cargarControl(); /// la carga el usuario
        void cargarFechaControl(); /// la carga el usuario
        void cargarNuevaHistoria(); ///carga toda  la historia clinica llamando a los demas metodos

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
