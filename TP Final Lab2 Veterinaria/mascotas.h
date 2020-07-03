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
        int IDCliente;  ///UN SET = GET DE IDCLIENTE CLIENTE
        int anios;
        bool castrado;
        bool vacunado;
        char especie [10];
        char raza [20];
        char sexo;
        Fecha fechaVacuna;
        bool vivo;
    public:
        bool Cargar_Mascota();
        void mostrar_Mascota(); ///INDIVIDUAL
        void listar_Mascotas(); ///MUESTRA TODOS LOS REGISTROS
        void mostrarDatosDelDueno(int );
        ///GETs
        int getIDCliente();
        const char* getNombre();
        bool getVivo();
        ///SETs
        void setIDcliente(int id){ IDCliente=id;}
        ///DISCO
        bool leerMascota(int);
        bool gurdar_Mascota_EnDisco();
        int buscarMascotaXNombre(char*);
        int buscarMascotaXNombreID(const char*,int);
        bool modificar_mascota();
        bool sobrescribir_mascota(int);
        bool mostrarTodoElArchivo();
};

#endif // MASCOTAS_H_INCLUDED
