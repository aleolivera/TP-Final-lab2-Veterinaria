#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "fecha.h"

const char ARCHIVOCLIENTES[20]="clientes.dat";
const char ARCHIVOCLIENTESBKP[20]="clientes.bkp";

class Cliente{
    private:
        int IDCliente;
        char nombreCliente[30];
        char apellido[30]; ///TE LO CAMBIE!, ANTES DECIA "nombreApellido"
        char domicilio[50];
        int Telefono;
        char email[30];
        bool deudor;
        Fecha fechaDeuda;
    public:
        bool cargarCliente();
        bool gurdarClienteEnDisco();
        bool LeerDiscoDeCliente(int);
        void mostrarCliente();
        int buscarCliente(char*,char*);
        void listarClietes();
        ///GETs
        int getIDCliente();
        void getApellido(char*);
};

#endif // CLIENTES_H_INCLUDED
