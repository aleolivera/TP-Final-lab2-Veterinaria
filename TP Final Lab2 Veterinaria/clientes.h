#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "fecha.h"

const char ARCHIVOCLIENTES[20]="clientes.dat";
const char ARCHIVOCLIENTESBKP[20]="clientes.bkp";

class Cliente{
    private:
        int IDCliente;
        int dni;
        char nombreCliente[30];
        char apellido[30]; ///TE LO CAMBIE!, ANTES DECIA "nombreApellido"
        char domicilio[50];
        int Telefono;
        char email[30];
        float saldo;
    public:
        bool cargarCliente();
        bool gurdarClienteEnDisco();
        bool LeerDiscoDeCliente(int);
        void mostrarCliente();
        int buscarClienteXDni(int);
        void listarClietes();
        int cantidad_Clientes();
        int buscraID_Cliente(int);
        void modificar_Cliente();
        bool sobrescribir_Cliente(int);

        ///GETs
        int getIDCliente();
        float getSaldo();
        void getNombreCliente(char*);
        void getApellido(char*);
        int getTelefono();
        ///SETs
        void setSaldo(float);
        ///MOSTRAR solo cout de un solo atributo
        void mostrarTelefono();
        void mostrarApellido();
        ///DISCO        NECESITABA PONER COMO DEUDOR A UN CLIENTE DESDE ARANCELES
        int buscarClientePorID(int);
        bool guardarCliente();
        bool leerCliente(int);
        bool modificarClienteDisco(int);
        bool mostrarTodoElArchivo();
};

#endif // CLIENTES_H_INCLUDED
