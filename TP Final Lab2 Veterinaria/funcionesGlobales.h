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
int compararFechas(Fecha, Fecha);
Fecha obtenerFechaActual();
bool validarFebrero(int,int);
bool validarBisiesto(int, int, int);
bool validarFecha(int,int,int);
int buscarCaracter(const char*,char);
bool ultimoCaracteresArroba (const char*);
bool buscarRepContiguos(const char*,char);
char buscarUltCaracter(const char*);
int contarSimbolos(const char*);
int validarMail(const char*);
bool validarTipoDePago(char);

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVO
int asignarIDHistoria();
int asignarIDarancel();
bool validarIDcliente(int);
bool validarIDarancel(int);
bool validarIDTipoVisita(int);
int buscarIDClientePorMascota(const char*);
int cantidadRegistrosHistorias();
int cantidadRegistrosClientes();
int cantidadRegistrosMascotas();
int cantidadRegistrosArancel();
int cantidadRegistrosTipoVisita();
bool cargarVecHistorias(Historia*,int);
bool cargarVecClientes(Cliente*,int);
bool cargarVecMascotas(Mascotas*,int);
bool cargarVecArancel(Arancel*,int);
bool cargarVecTipoVisita(TipoVisita*,int);

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
bool modificarHistoria();
bool controlesPendientes();
bool controlesAusentes();
void menuHistorias();

///ARANCELES
bool nuevoArancel();
bool modificarArancel();
bool mostrarArancelesDelDia();
bool mostrarArancelesPorVisita();
void menuAranceles();

///ADMINISTRACION
bool mostrarListaDePrecios();
bool modificarImportes();
bool ingresarItems();
bool listarPorFecha();
bool mostrarDeudores();
void menuAdministracion();

///CONFIGURACION

void menuConfiguracion();


#endif // FUNCIONESGLOBALES_H_INCLUDED
