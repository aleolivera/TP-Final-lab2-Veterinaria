#ifndef ARANCEL_H_INCLUDED
#define ARANCEL_H_INCLUDED
#include "fecha.h"

const char ARCHIVOARANCELES[20]="aranceles.dat";
const char ARCHIVOARANCELESBKP[20]="aranceles.bkp";

class Arancel{
    private:
        Fecha fechaArancel;
        int IDArancel;
        int IDHistoria;
        int IDTipoVisita;
        float totalArancel;
        char tipoPago;
        int porcentajeHonorario;
        bool abonado;
    public:
        ///MOSTRAR
        void mostrarIDArancel();
        void mostrarIDHistoria();
        void mostrarIDTipoVisita();
        void mostrarTotalArancel();
        void mostrarTipoPago();
        void mostrarPorcentajeHonorario();
        void mostrarAbonado();

        ///GETs
        int getIDArancel();
        int getIDHistoria();
        int getIDTipoVisita();
        float getTotalArancel();
        char getTipoPago();
        int getPorcentajeHonorario();
        bool getAbonado();

        ///SETs
        void setIDArancel(int);
        void setIDHistoria(int);
        void setIDTipoVisita(int);
        void setTotalArancel(float);
        void setTipoPago(char);
        void setPorcentajeHonorario(int);
        void setAbonado(bool);

        ///DISCO
        int buscarArancel(int);
        bool guardarArancel();
        bool leerArancel(int);
//        int cantidadRegistros();
};

#endif // ARANCEL_H_INCLUDED
