#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "fecha.h"

class cliente{
    private:
        int IDCliente;
        char nombreCliente[30];
        char nombreApellido[30];
        char nombreDomicilio[50];
        int Telefono;
        char email[30];
        bool deudor;
        fecha fechaDeuda;
    public:


};

#endif // CLIENTES_H_INCLUDED
