#ifndef TIPOVISITA_H_INCLUDED
#define TIPOVISITA_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "visuales.h"
#include "fecha.h"
#include "funcionesGlobales.h"

const char ARCHIVOTIPOVISITA[20]="tipovisita.dat";
const char ARCHIVOTIPOVISITABKP[20]="tipovisita.bkp";


class TipoVisita{
    private:
        int IDTipoVisita;
        char nombreTipoVisita[30];
        float importe;
        float porcentajeHonorario;
        bool estado;
    public:

        ///SETs
        void setIDTipoVisita(int);
        void setNombreTipoVisita(const char*);
        void setImporte(float);
        void setPorcentajeHonorario(int);
        void setEstado(bool);

        ///GETs
        int getIDTipoVisita();
        const char*getNombreTipoVisita();
        float getImporte();
        int getPorcentajeHonorario();
        bool getEstado();

        ///DISCO
        int buscarTipoVisita(int);
        bool guardarTipoVisita();
        bool leerTipoVisita(int);
        bool modificarTipoVisita(int);
        bool mostrarTodoElArchivo();
};

///GLOBALES
int asignarIDTipoVisita();///Le pone solo el ID de manera secuencial
int cantidadRegistrosTipoVisita();
bool cargarVecTipoVisita(TipoVisita*,int);

///ADMINISTRACION
///Para resolver las consignas del MENU ADMINISTRACION
bool mostrarListaDePrecios();
bool modificarImportes();
bool nuevoServicio();
bool AltaBajaServicio();
bool listarPorFecha();
bool mostrarDeudores();
bool comisiones();


#endif // TIPOVISITA_H_INCLUDED
