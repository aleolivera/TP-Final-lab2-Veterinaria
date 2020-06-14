#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <string.h>

#include "fecha.h"
#include "arancel.h"
#include "clientes.h"
#include "historias.h"
#include "mascotas.h"
#include "tipoVisita.h"
#include "visuales.h"


///VALIDACIONES DE INGRESOS
bool validarFebrero(int,int);
bool validarBisiesto(int, int, int);
bool validarFecha(int,int,int);
int buscarCaracter(const char*,char);
bool ultimoCaracteresArroba (const char*);
bool buscarRepContiguos(const char*,char);
char buscarUltCaracter(const char*);
int contarSimbolos(const char*);
int validarMail(const char*);

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVO
int asignarIDHistoria();
int asignarIDarancel();
int buscarIDClientePorMascota(const char*);
int cantidadRegistrosHistorias();
int cantidadRegistrosClientes();
int cantidadRegistrosMascotas();
bool cargarVecHistorias(Historia*);
bool cargarVecClientes(Cliente*);
bool cargarVecMascotas(Mascotas*);

///SECCIONES DEL PROGRAMA
///CLIENTES

void menuClientes();
///MASCOTAS


void menuMascotas();
void menuIngresoPaciente();
///HISTORIAS
bool ingresoHistoria();
bool mostrarEntradaHistoria();
bool mostrarHistoria();
bool modificarHistotia();
void controlesPendientes();
void controlesAusentes();

void menuHistorias();
///ARANCELES

void menuAranceles();
///ADMINISTRACION

void menuAdministracion();
///CONFIGURACION

void menuConfiguracion();


#endif // FUNCIONESGLOBALES_H_INCLUDED
