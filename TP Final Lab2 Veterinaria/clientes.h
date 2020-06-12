#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "fecha.h"

class Cliente{
    private:
        int IDCliente;
        char nombreCliente[30];
        char nombreApellido[30];
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
};

#endif // CLIENTES_H_INCLUDED
