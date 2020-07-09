#ifndef TIPOVISITA_H_INCLUDED
#define TIPOVISITA_H_INCLUDED

#include "fecha.h"
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

#endif // TIPOVISITA_H_INCLUDED
