#ifndef ARANCEL_H_INCLUDED
#define ARANCEL_H_INCLUDED
#include "fecha.h"

class Arancel{
    private:
        Fecha fechaArancel;
        int numArancel;
        int numHistoria;
        int IDTipoVisita;
        float totalArancel;
        char tipoPago;
        int porcentajeHonorario;
        bool abonado;
    public:

};

#endif // ARANCEL_H_INCLUDED
