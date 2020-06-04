#ifndef HISTORIAS_H_INCLUDED
#define HISTORIAS_H_INCLUDED
#include "fecha.h"

class historia{
    private:
        int IDHistoria;
        fecha ingreso;
        fecha fechaVisita;
        int IDCliente;
        char nombreMascota[20];
        char amnesis [200];
        bool control; //constructor =falso
        fecha control;//constructor =0
        int numArancel; //constructor =0
    public:

};


#endif // HISTORIAS_H_INCLUDED
