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
        int IDmascota;
        char nombreMascota[20];
        int DNICliente;  ///UN SET = GET DE IDCLIENTE CLIENTE
        int anios;
        bool castrado;
        bool vacunado;
        char especie [20];
        char raza [20];
        char sexo;
        Fecha fechaVacuna;
        bool vivo;
    public:
        ///GETS
        int getIDmascota();
        const char* getNombreMascota();
        int getDNICliente();
        int getAnios();
        bool getCastrado();
        bool getVacunado();
        const char* getEspecie();
        const char* getRaza();
        char getSexo();
        Fecha getFechaVacuna();
        bool getVivo();

        ///SET
        void setIDMascota(int);
        void setNombreMascota(const char*);
        void setDNICliente(int);
        void setAnios(int );
        void setCastrado(bool);
        void setVacunado(bool);
        void setEspecie(const char*);
        void setRaza(const char*);
        void setSexo(char);
        void setVivo(bool);
        ///DISCO
        bool guardarMascota();
        bool leerMascota(int);
        bool modificarMascota(int);
};


///GLOBALES
int asignarIDMascota();
int cantidadRegistrosMascotas();
bool cargarVecMascotas(Mascotas*,int);
void verMascota(Mascotas regMascota);

///MASCOTAS
///Para resolver las consignas del MENU MASCOTA
bool mostrarMascotas();
bool modificarMascotas();
bool listarVisitas();
bool transferirMascotas();



#endif // MASCOTAS_H_INCLUDED
