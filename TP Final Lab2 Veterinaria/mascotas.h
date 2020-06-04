#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

#include "fecha.h"

class mascotas{
    private:
        char nombreMascota[20];
        int IDCliente;
        int edad;
        bool castrado;
        bool vacunado;
        char especie [10];
        char raza [20];
        char sexo;
        Fecha fechaVacuna;
        bool vivo;
    public:

};

#endif // MASCOTAS_H_INCLUDED
