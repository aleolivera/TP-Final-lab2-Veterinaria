#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

#include "fecha.h"

class mascota{
    private:
        char nombreMascota[20];
        int IDCliente;
        int edad;
        bool castrado;
        bool vacunado;
        char[10] especie;
        char[20] raza;
        char sexo;
        fecha fechaVacuna;
        bool vivo;
    public:

};

#endif // MASCOTAS_H_INCLUDED
