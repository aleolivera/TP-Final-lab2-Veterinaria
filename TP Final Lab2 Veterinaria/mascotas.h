#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>

#include "fecha.h"

const char ARCHIVOMASCOTAS[20]="mascotas.dat";
const char ARCHIVOMASCOTASBKP[20]="mascotas.bkp";

class Mascotas{
    private:
        char nombreMascota[20];
        int IDCliente;
        int edad;
        bool castrado;
        bool vacunado;
        char especie [10];
        char raza [20];
        char sexo[14];
        Fecha fechaVacuna;
        bool vivo;
    public:
        Mascotas();
        bool Cargar_Mascota();
        void mostrar_Mascota();
        void listar_Mascotas();
        ///GETs
        int getIDCliente();
        void getNombre(char*);

        ///DISCO
        bool leerMascota(int);
        bool gurdar_Mascota_EnDisco();
};

#endif // MASCOTAS_H_INCLUDED
