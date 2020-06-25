#ifndef TIPOVISITA_H_INCLUDED
#define TIPOVISITA_H_INCLUDED

#include "fecha.h"
const char ARCHIVOTIPOVISITA[20]="tipovisita.dat";
const char ARCHIVOTIPOVISITABKP[20]="tipovisita.bkp";


class TipoVisita{
    private:
        int IDTipoVisita;
        char nombreTipoVisita[15];
        float importe;
        float porcentajeHonorario;
    public:
        ///MOSTRAR
        void mostrarIDTipoVisita();
        void mostrarNombreTipoVisita();
        void mostrarImporte();
        void mostrarPorcentajeHonorario();

        ///SETs
        void setIDTipoVisita(int);
        void setNombreTipoVisita(const char*);
        void setImporte(float);
        void setPorcentajeHonorario(int);

        ///GETs
        int getIDTipoVisita();
        void getNombreTipoVisita(char*);
        float getImporte();
        int getPorcentajeHonorario();

        ///DISCO
        int buscarTipoVisita(int);
        bool guardarTipoVisita();
        bool leerTipoVisita(int);
//        int cantidadRegistros();
        bool modificarTipoVisita(int);
};

#endif // TIPOVISITA_H_INCLUDED
