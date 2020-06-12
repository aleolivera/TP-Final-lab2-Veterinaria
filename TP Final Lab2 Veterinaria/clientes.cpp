#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include "clientes.h"
const char ARCHIVOCLIENTES[20]="clientes.dat";
using namespace std;

/*int IDCliente;
        char nombreCliente[30];
        char nombreApellido[30];
        char domicilio[50];
        int Telefono;
        char email[30];
        bool deudor;
        Fecha fechaDeuda;*/
int buscarCliente(char*,char*);

bool Cliente::cargarCliente()
{
    int encontrado;
    cout<<" Nombre:";
    cin.getline(nombreCliente,30);
    cout<<" Apellido :";
    cin.getline(nombreApellido,30);
    encontrado=buscarCliente(nombreCliente,nombreApellido);  //////NO FUNCIONA (( NO DETECTA SI REPITE EL NOMBRE.
    if(encontrado==-1)
    {
        cout<<" Domicilio :";
        cin.getline(domicilio,30);
        cout<<" Telefono :";
        cin>>Telefono;
        cin.ignore();
        cout<<" Email :";
        cin.getline(email,30);
    }
    else{
        cout<<" El cliente "<<nombreApellido<<" "<<nombreCliente<<" esta registrado "<<endl;      //FALTA MOSTRAR CON QUE MASCOTA ESTA REGISTRADO.
        return false;
    }
        return true;
}

bool Cliente::gurdarClienteEnDisco()
{
    bool guardado;
    FILE *p;
    p=fopen(ARCHIVOCLIENTES,"ab");
    if(p==NULL)
    {
        return false;
    }
    guardado=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return guardado;
}

bool Cliente::LeerDiscoDeCliente(int pos)
{
    bool leido;
    FILE *p;
    p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        cout<<"No existe el archivo";
        return false;
    }
    fseek(p,pos*sizeof(Cliente),0);
    leido=fread(this,sizeof(Cliente),1,p);
    fclose(p);
    return leido;
}

int Cliente::buscarCliente(char*nombre,char*apellido)
{
    int pos=0;
    Cliente reg;
    while(reg.LeerDiscoDeCliente(pos)==1)
    {
        if(strcmp(nombre,reg.nombreCliente)==1&&strcmp(apellido,reg.nombreApellido)==1)
            return pos;
        pos++;
    }
    return -1;
}

void Cliente::mostrarCliente()
{
    cout<<" Nombre :"<<nombreCliente<<endl;
    cout<<" Apellido :"<<nombreApellido<<endl;
    cout<<" Domicilio :"<<domicilio<<endl;
    cout<<" Telefono :"<<Telefono<<endl;
    cout<<" Email :"<<email<<endl;
}

void Cliente::listarClietes()
{
    int pos=0;
    system("cls");
    while(LeerDiscoDeCliente(pos++)==1)
    {
        mostrarCliente();
    }
}
/*void listar_art()
	{
	Articulo reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
			{reg.Mostrar();
			system("pause>null");
			}
		}
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
	}*/
