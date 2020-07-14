#ifndef ARANCEL_H_INCLUDED
#define ARANCEL_H_INCLUDED
#include "fecha.h"
#include "visuales.h"
#include "clientes.h"
#include "historias.h"
#include "mascotas.h"
#include "tipoVisita.h"
#include "funcionesGlobales.h"

const char ARCHIVOARANCELES[20]="aranceles.dat";
const char ARCHIVOARANCELESBKP[20]="aranceles.bkp";

class Arancel{
    private:
        Fecha fechaArancel;
        int IDArancel;
        int DNICliente;
        int IDHistoria;
        int IDTipoVisita;
        float totalArancel;
        char tipoPago;
        int porcentajeHonorario;
        bool abonado;
    public:
        ///GETs
        Fecha getFechaArancel();
        int getIDArancel();
        int getDNICliente();
        int getIDHistoria();
        int getIDTipoVisita();
        float getTotalArancel();
        char getTipoPago();
        int getPorcentajeHonorario();
        bool getAbonado();

        ///SETs
        void setFechaArancel();
        void setIDArancel(int);
        void setDNICliente(int);
        void setIDHistoria(int);
        void setIDTipoVisita(int);
        void setTotalArancel(float);
        void setTipoPago(char);
        void setPorcentajeHonorario(int);
        void setAbonado(bool);

        ///DISCO
        bool guardarArancel();
        bool modificarArancel(int);
        bool leerArancel(int);
};

///GLOBALES
int cantidadRegistrosArancel();
bool cargarVecArancel(Arancel*,int);
int asignarIDarancel();
void verArancel(Arancel);

///ARANCELES
///Para resolver las consignas del MENU ARANCELES
bool nuevoArancel();
bool mostrarArancelesDelDia();
bool modificarArancel();
bool mostrarArancelesPorVisita();

#endif // ARANCEL_H_INCLUDED
