#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "fecha.h"

const char ARCHIVOCLIENTES[20]="clientes.dat";
const char ARCHIVOCLIENTESBKP[20]="clientes.bkp";

class Cliente{
    private:
        int IDCliente;
        int DNICliente;
        char nombreCliente[30];
        char apellido[30]; ///TE LO CAMBIE!, ANTES DECIA "nombreApellido"
        char domicilio[50];
        int telefono;
        char email[30];
        float saldo;
    public:
        ///GETs
        int getIDCliente();
        int getDNICliente();
        const char* getNombreCliente();
        const char* getApellido();
        const char* getDomicilio();
        int getTelefono();
        const char* getEmail();
        float getSaldo();

        ///SETs
        void setIDCliente(int);
        void setDNICliente(int);
        void setNombreCliente(const char*);
        void setApellido(const char*);
        void setDomicilio(const char*);
        void setTelefono(int);
        void setEmail(const char*);
        void setSaldo(float);
        bool guardarCliente();
        bool leerCliente(int);
        bool modificarCliente(int);
};

///GLOBALES
int asignarIDCliente();
int cantidadRegistrosClientes();
bool cargarVecClientes(Cliente*,int);
void verCliente(Cliente);

///CLIENTES
///Para resolver las consignas del MENU CLIENTES
bool mostrarCliente();
bool mostrarTodosClientes();
bool modificarClientes();


#endif // CLIENTES_H_INCLUDED
