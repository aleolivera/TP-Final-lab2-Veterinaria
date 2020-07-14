#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <ctime>
#include "funcionesGlobales.h"
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
bool validarNombres(const char*);
bool validarNombresConEspacios(const char*);
bool validarDomicilio(const char*);
bool validarSiNo(const char*);
const char* tipoDePagoACadena(char);
int listarTiposDeVisita(int);
void listarMascotasConDNICliente(int);
void listarClientesConIDMascotas(int);
int preguntarSIoNO();

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVO
bool validarTipoVisita(const char*);
bool validarDNICliente(int);
bool validarIDarancel(int);
bool validarMascotaConCliente(const char*,int);
bool validarIDTipoVisita(int);


///BUSCAR
int buscarArancel(int);
int buscarHistoria(int);
int buscarTipoVisita(int);
int buscarMascotaPorDNI(int DNI);
int buscarMascotaPorDNIyNombre(int DNI,const char*nombre);
Cliente ultimoCliente();
int buscarClientePorDNI(int DNI);


///SECCIONES DEL PROGRAMA
///INGRESOS PACIENTES
bool ingresarCliente();
bool ingresarMascota();
bool ingresarSoloMascota();
bool AgregarPacienteYCliente();


///CLIENTES
bool listarVisitasClientes();


///CONFIGURACION
bool restaurarSistema();
bool realizarBKP();
bool backupHistorias();
bool backupClientes();
bool backupTipoVisita();
bool backupMascotas();
bool backupAranceles();
void menuConfiguracion();


#endif // FUNCIONESGLOBALES_H_INCLUDED
