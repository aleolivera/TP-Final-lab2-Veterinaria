#include "funcionesGlobales.h"
#include <ctime>
#include "visuales.h"

///VALIDACIONES
int compararFechas(Fecha fechaUno, Fecha fechaDos)  ///Devuelve 0 si son iguales, 1 si la primera es anterior a la segunda, o 2 si la segunda es anterior a la primera
{

    if((fechaUno.getAnio()-fechaDos.getAnio())<0)
    {
        return 1;
    }
    else if((fechaUno.getAnio()-fechaDos.getAnio())>0)
    {
        return 2;
    }
    if((fechaUno.getMes()-fechaDos.getMes())<0)
    {
        return 1;
    }
    else if((fechaUno.getMes()-fechaDos.getMes())>0)
    {
        return 2;
    }
    if((fechaUno.getDia()-fechaDos.getDia())<0)
    {
        return 1;
    }
    else if((fechaUno.getDia()-fechaDos.getDia())>0)
    {
        return 2;
    }
    return 0;

}
Fecha obtenerFechaActual()          ///LLamas a la funcion  te devuelve un objeto de clase Fecha con dia mes y anio
{
    Fecha reg;
    time_t timestamp;
    timestamp=time(NULL); //asigna a timestamp el tiempo actual
    tm *p;
    p = localtime(&timestamp);
    int dia = p->tm_mday;
    int mes = p->tm_mon+1;
    int anio= p->tm_year +1900;
    reg.setFecha(dia,mes,anio);
    return reg;
}
bool validarFebrero(int dia,int anio)
{
    if ((anio%400==0) || (!anio%100==0 && anio%4==0))
    {
        if(dia>0 && dia<30)
        {
            return true;
        }
        else if (dia>0 && dia<29)
        {
            return true;
        }
    }
    return false;
}
bool validarBisiesto(int dia, int mes, int anio)
{
    Fecha aux;
    aux.setFechaActual();
    if (((anio>aux.getAnio())||(anio<=aux.getAnio()&&mes>aux.getMes())||(anio<=aux.getAnio()&&mes<=aux.getMes()&&dia>aux.getDia())) || (mes>12))
    {
        return true;
    }
    return false;
}
bool validarFecha(int dia,int mes,int anio)         ///Valida que la fecha se ingrese bien usando "validarFebrero()" y "validarFebrero"
{
//    if(validarBisiesto(dia,mes,anio))
//    {
//        return false;
//    }
    if (mes==2 && validarFebrero(dia,anio))
    {
        return false;
    }
    if (mes<8 && mes%2!=0)
    {
        if (dia<0&&dia>31)
        {
            return false;
        }
    }
    else if(mes<8 && dia<0&&dia>30)
    {
        return false;
    }
    if(mes%2!=0)
    {
        if(dia<0&&dia>30)
        {
            return false;
        }
        else if(dia<0&&dia>31)
        {
            return false;
        }
    }
    return true;
}
int buscarCaracter(const char*cadena,char caracter)
{
    int i=0;
    int con=0;
    while(cadena[i]!='\0')
    {
        if(cadena[i]==caracter)
        {
            con++;
        }
        i++;
    }
    return con;
}
bool ultimoCaracteresArroba (const char*cadena)
{
    int i=strlen(cadena);
    if(cadena[i-1]=='@')
    {
        return true;
    }
    return false;
}
bool buscarRepContiguos(const char*cadena,char caracter)
{
    int i=0;
    while (cadena[i]!='\0')
    {
        if(cadena[i]==caracter && cadena[i+1]==caracter)
        {
            return true;
        }
        i++;
    }
    return false;
}
char buscarUltCaracter(const char*cadena)
{
    int i=strlen(cadena);
    return cadena[i-1];
}
int contarSimbolos(const char*cadena)
{
    int con=0;
    int i=0;
    while(cadena[i]!='\0')
    {
        if(cadena[i]<'.' || (cadena[i]>'.' && cadena[i]<'0') || (cadena[i]>'9' && cadena[i]<'@') || (cadena[i]>'Z' && cadena[i]<'_') || (cadena[i]>'_' && cadena[i]<'a') || cadena[i]> 'z')
        {
            con++;
        }
        i++;
    }
    return con;
}
int validarMail(const char* cadena)     ///Usa la 5 funciones dde arriba para validar el mail como en el TP LARA
{
    int espacios;
    if(contarSimbolos(cadena)>0)
    {
        return 5;
    }
    espacios=buscarCaracter(cadena,' ');
    if (espacios>0)
    {
        return 4;
    }
    if(cadena[0]=='.'||cadena[0]=='@')
    {
        return 1;
    }
    if(buscarCaracter(cadena,'@')!=1||ultimoCaracteresArroba(cadena))
    {
        return 2;
    }
    if(buscarCaracter(cadena,'.')<1||buscarRepContiguos(cadena,'.')||buscarUltCaracter(cadena)=='.')
    {
        return 3;
    }
    return 0;
}
bool validarTipoDePago(char tipoPago)
{
    if(tipoPago=='e'||tipoPago=='E'|| tipoPago=='t'|| tipoPago=='T'|| tipoPago=='d'|| tipoPago=='D'|| tipoPago=='c'|| tipoPago=='C')
    {
        return true;
    }
    return false;
}
bool validarNombres(const char* cadena)     ///True = a-z o A-Z , false=cualquier otra cosa
{
    int i=0;
    while(cadena[i]!= '\0'){
        if((cadena[i]>0 && cadena[i]<65)||(cadena[i]>90 && cadena[i]<97)||(cadena[i]>122)){
            return false;
        }
        i++;
    }
    return true;
}
bool cad_vacia(char *cad)
{
    if(cad[0] == '\0')
    {
        return true;
    }
    return false;
}
void listardueno(int IDcliente)
{
    Cliente reg;
    system("cls");
    reg.LeerDiscoDeCliente(IDcliente-1);

    cout<<" -----DATOS DEL DUENO----- "<<endl;
    reg.mostrarCliente();
    cout<<endl;

}
const char* tipoDePagoACadena(char tipoPago){
    switch(tipoPago){
    case 'e':
    case 'E': return "EFECTIVO";
        break;
    case 't':
    case 'T':return "TARJETA DE CREDITO";
        break;
    case 'd':
    case 'D':return "DEBITO";
        break;
    case 'c':
    case 'C':return "CUENTA CORRIENTE";
        break;
    }
    return "INDEFINIDO";
}
void listarTiposDeVisita(){
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if (p==NULL) return;
    int i=1;
    cout <<"                       ";
    while(fread(&reg,sizeof (TipoVisita),1,p)==1){
        cout<<i <<"- "<<reg.getNombreTipoVisita();
        i++;
        if(i%4==0){
            cout << endl;
            cout<<"                       ";
        }
        else{
            cout << " | ";
        }

    }
    cout << endl;
    fclose(p);
    return;
}
void listarMascotasConIDCliente(int ID){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if (p==NULL) return;
    cout <<"                SUS MASCOTAS:";
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(reg.getIDCliente()==ID&&reg.getVivo()){
            cout << reg.getNombre()<< " | ";
        }
    }
    fclose(p);
    return;
}

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVOS
int asignarIDHistoria()     ///Le pone solo el ID de manera secuencial
{
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return 1;
    }
    if(fread(&reg,sizeof (Historia),1,p)==0)  ///tal vez deberia preguntar si !=1
    {
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (Historia),2);
        fread(&reg,sizeof (Historia),1,p);
        fclose(p);
        return reg.getIDHistoria()+1;
    }
}
int asignarIDarancel()      ///Le pone solo el ID de manera secuencial
{
    Arancel reg;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return 1;
    }
    if(fread(&reg,sizeof (Arancel),1,p)==0)
    {
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (Arancel),2);
        fread(&reg,sizeof (Arancel),1,p);
        fclose(p);
        return reg.getIDArancel()+1;
    }
}
int asignarIDTipoVisita()      ///Le pone solo el ID de manera secuencial
{
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL)
    {
        return 1;
    }
    if(fread(&reg,sizeof (TipoVisita),1,p)==0)
    {
        fclose(p);
        return 1;
    }
    else
    {
        fseek(p,-sizeof (TipoVisita),2);
        fread(&reg,sizeof (TipoVisita),1,p);
        fclose(p);
        return reg.getIDTipoVisita()+1;
    }
}
bool validarIDcliente(int ID)  ///Busca el ID en ARCHIVOCLIENTES y devuelve true si lo encuentra
{
    Cliente aux;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
        return false;
    while(fread(&aux,sizeof (Cliente),1,p)==1)
    {
        if(ID==aux.getIDCliente())
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool validarIDarancel(int ID){
    Arancel aux;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
        return false;
    while(fread(&aux,sizeof (Arancel),1,p)==1)
    {
        if(ID==aux.getIDArancel())
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool validarMascotaConCliente(const char*nombre,int ID){
    Mascotas regMascotas;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&regMascotas,sizeof (Mascotas),1,p)==1){
        if(regMascotas.getIDCliente()==ID&&strcmp(regMascotas.getNombre(),nombre)==0){
            fclose(p);
            return true;
        }
    }
    return false;
}
bool validarIDTipoVisita(int ID){
    TipoVisita aux;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL)
        return false;
    while(fread(&aux,sizeof (TipoVisita),1,p)==1)
    {
        if(ID==aux.getIDTipoVisita())
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
int buscarIDClienteEnHistorias(int IDHistoria){
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL) return -1;
    while(fread(&reg,sizeof (Historia),1,p)==1){
        if(IDHistoria==reg.getIDHistoria()){
            fclose(p);
            return reg.getIDCliente();
        }
    }
    fclose(p);
    return -1;
}
int cantidadRegistrosHistorias()    ///Devuelve la cantidad de registros en ARCHIVOHISTORIAS
{
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Historia);
}
int cantidadRegistrosClientes()     ///Devuelve la cantidad de registros en ARCHIVOCLIENTES
{
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Cliente);
}
int cantidadRegistrosMascotas()     ///Devuelve la cantidad de registros en ARCHIVOMASCOTAS
{
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Mascotas);
}
int cantidadRegistrosArancel()     ///Devuelve la cantidad de registros en ARCHIVOARANCELES
{
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Arancel);
}
int cantidadRegistrosTipoVisita(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (TipoVisita);
}
bool cargarVecHistorias(Historia*vec,int tam)  ///Le mandas un vector de clase HISTORIA y su tamanio y te lo carga todo
{
    Historia reg;
    int i=0;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Historia),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecClientes(Cliente*vec,int tam)     ///Le mandas un vector de clase CLIENTES y su tamanio y te lo carga todo
{
    Cliente reg;
    int i=0;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Cliente),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecMascotas(Mascotas*vec,int tam)    ///Le mandas un vector de clase MASCOTAS y su tamanio y te lo carga todo
{
    Mascotas reg;
    int i=0;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Mascotas),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecArancel(Arancel*vec,int tam)    ///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
{
    Arancel reg;
    int i=0;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (Arancel),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecTipoVisita(TipoVisita*vec,int tam)    ///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
{
    TipoVisita reg;
    int i=0;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL)
    {
        return false;
    }
    while(fread(&reg,sizeof (TipoVisita),1,p)==1 && i<tam)
    {
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}

///SECCIONES DEL PROGRAMA
///CLIENTES
///Para resolver las consignas del MENU CLIENTES


void menuClientes(){
    ///Para resolver las consignas del MENU CLIENTES
    limpiar();
    pantallaClientes();
    int op;
    cin >>op;
    limpiar();
    Cliente reg;
    switch(op)
    {
    case 1:
    {
        system("cls");
        reg.listarClietes();
        system("pause");
    }
    break;
    case 2:
    {
        system("cls");
        reg.modificar_Cliente();
        system("pause");
    }
    break;
    case 3:
    {
        ///LISTAR VISITAS
    }
    break;
    case 0:{
        reg.mostrarTodoElArchivo();
    } break;
    }

}


///MASCOTAS
///Para resolver las consignas del MENU MASCOTAS


void menuMascotas(){
    limpiar();
    pantallaMascotas();
    int op;
    cin >>op;
    limpiar();
    Mascotas reg;
    switch(op)
    {
    case 1:
    {
        system("cls");
        reg.listar_Mascotas();
        system("pause");
    }
    break;
    case 2:
    {
        system("cls");
        reg.modificar_mascota();
        system("pause");
    }
    break;
    case 4:
    {
        system("cls");
//        Mascotas reg;
//        Cliente p;
        int op;
        cout<<endl;
        cout<<" 1-Registrar nuevo dueno "<<endl;
        cout<<" 2-Dueno ya existente  "<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 1:
        {
            Mascotas re;
            Cliente reg;
            char nombre[20];
            if(reg.cargarCliente())
            {
                if(reg.gurdarClienteEnDisco())
                {
                    cout<<" El nuevo cliente fue registrado "<<endl;
                    system("pause");
                    cin.ignore();
                    cout<<" Nombre de la mascota que desa transferir :";
                    cin.getline(nombre,20);
                    cin.ignore();
                    int pos;
                    pos=re.buscarMascotaXNombre(nombre);
                    re.setIDcliente(reg.getIDCliente());
                    if(re.sobrescribir_mascota(pos))
                    {
                        cout<<" Transferencia completada "<<endl;

                    }
                    else
                    {
                        cout<<" No se pudo transferir "<<endl;
                    }
                }
            }
        }
        break;
        case 2:
        {
             int dni;
            char nombre[20];
            Cliente reg;
            Mascotas re;
            cout<<" Ingrese el DNI del nuevo duenio :";
            cin>>dni;
            cin.ignore();
            cout<<" Nombre de la mascota que desa transferir :";
            cin.getline(nombre,20);
            cin.ignore();
            int pos=0;
            pos=reg.buscarClienteXDni(dni);
            reg.LeerDiscoDeCliente(pos);
            int posmascota=re.buscarMascotaXNombre(nombre);
            re.setIDcliente(reg.getIDCliente());
            if(re.sobrescribir_mascota(posmascota))
            {
                cout<<" Transferencia completada "<<endl;
            }
        }
        break;
        }
    }
    break;
        case 0:
            Mascotas reg;
            reg.mostrarTodoElArchivo();
    }
}
void menuIngresoPaciente(){
    limpiar();
    pantallaAgregar();
    int op;
    cin >>op;
    limpiar();
    switch(op)
    {
    case 1:
    {
        system("cls");
        Cliente reg;
        Mascotas re;
        if(reg.cargarCliente())
        {
            if(reg.gurdarClienteEnDisco())
            {
                cout<<" El nuevo cliente fue registrado "<<endl;
                system("pause");
                re.setIDcliente(reg.getIDCliente());
                if(re.Cargar_Mascota())
                {
                    if(re.gurdar_Mascota_EnDisco())
                    {
                        cout<<" La mascota fue registrada "<<endl;
                        system("pause");
                    }
                }
            }
        }
    }
    break;
    case 2:
    {
        int dni;
        Cliente reg;
        Mascotas p;
        int pos_cliente,ID_cliente;
        system("cls");
        cout<<" Ingrese el DNI del cliente ya existente "<<endl;
        cin>>dni;

        pos_cliente=reg.buscarClienteXDni(dni);
        if(pos_cliente!=(-1)){
            ID_cliente=reg.buscraID_Cliente(pos_cliente);
            listardueno(ID_cliente);
            p.setIDcliente(reg.getIDCliente());
            if(p.Cargar_Mascota()){
                if(p.gurdar_Mascota_EnDisco()){
                    cout<<" La mascota fue registrada "<<endl;
//                    system("pause");
                }
            }
        }
        else
            cout<<" no existe el cliente "<<endl;
        system("pause");
    }
    break;
    case 3:
    {
        ///LISTAR VISITAS
    }
    break;
    case 0:{
        Cliente reg;
        reg.mostrarTodoElArchivo();
    } break;
    }

}



///HISTORIAS
///Para resolver las consignas del MENU HISTORIA
bool ingresoHistoria(){
    Historia reg;
    int dia,mes,anio,valor;
    char cadena[20];
    char cadena2[3];
    reg.setIDHistoria(asignarIDHistoria());     ///Aca se asigna solo ID de manera secuencial
    reg.setFechaIngreso();                      ///Aca se asigna automaticamente la fecha del HOY
    reg.setFechaModificacion();
    cout << "INGRESO DE HISTORIAS CLINICAS" << endl << endl;
    cout << "                          ID: "<< reg.getIDHistoria() << endl;
    cout << "FECHA DE LA VISITA(DD/MM/AA): "<< endl;
    cout << "                         DIA: ";
    cin >> dia;
    cout << "                         MES: ";
    cin >> mes;
    cout << "                        ANIO: ";
    cin >> anio;
    reg.setFechaVisita(dia,mes,anio);
    if (!validarFecha(dia,mes,anio)||compararFechas(reg.getFechaVisita(),obtenerFechaActual())==2)
    {
        errorFechaInvalida();
        return false;
    }

    cout << "              ID DEL CLIENTE: ";
    cin >> valor;
    if(!validarIDcliente(valor))
    {
        errorIngresoInvalido();
        return false;
    }
    reg.setIDCliente(valor);                ///Aca se ingresa el ID del cliente en el registro tras validarlo en disco
    listarMascotasConIDCliente(valor);
    cout << endl << "        NOMBRE DE LA MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    if(!validarMascotaConCliente(cadena,reg.getIDCliente())){
        errorIngresoInvalido();
        return false;
    }
    reg.setNombreMascota(cadena);           ///Aca se ingresa el nombre de la mascota

    cout << endl;
    cout << "                  ANAMNESIS: ";
//    cin.ignore();
    reg.setAnamnesis();                     ///Aca la Anamnesis (detalles de la visita)

    cout << "VISITA DE CONTROL? 'SI' o 'NO' :";
//    cin.ignore();
    cin.getline(cadena2,3);
//    cin.ignore();
    if(strcmp(cadena2,"SI")==0||strcmp(cadena2,"si")==0)
    {
        cout << "INGRESE LA FECHA DEL CONTROL(DD/MM/AA):"<< endl;
        cin >> dia >> mes >> anio;

        if (!validarFecha(dia,mes,anio)&&compararFechas(reg.getFechaControl(),obtenerFechaActual())==2)  ///Se valida que no se ingrese 42/9/2500 o 29/2 si no es anio biciesto y que la fecha del control no sea en le pasado
        {
            errorFechaInvalida();
            return false;
        }
        reg.setFechaControl(dia,mes,anio);
        reg.setControl(true);                ///al ingresar SI o NO se cambia el estado del booleano
    }
    else if(strcmp(cadena2,"NO")||strcmp(cadena2,"no")){
        reg.setControl(false);
        reg.setFechaControl(0,0,0);
    }
    else
    {
        cout << "'" <<cadena2 << "' " << " NO ES UN INGRESO VALIDO." << endl;
        cin.get();
        return false;
    }

    ///EL CAMPO QUE RESTA ES 'int IDArancel' QUE SE CARGA CON EL ARANCEL
    if(!reg.guardarHistoria())
    {
        errorArchivo();
        return false;
    }
    return true;
}
bool mostrarEntradaHistoria(){
    Historia reg;
    int ID;
    int pos;
    cout << "ID DE ENTRADA DE HISTORIA CLINICA." << endl;
    cin >> ID;
    pos=reg.buscarHistoria(ID);
    if(pos==-1)
    {
        errorRegistro();
        return false;
    }

    reg.mostrarFechaVisita(); ///Despues se muestran los registros de a uno
    cout << endl;
    reg.mostrarNombreMascota();
    cout << endl;
    reg.mostrarAnamnesis();
    cout << endl;
    pausar();
    return true;
}
bool mostrarHistoria(){
    Historia*vecHistoria; ///para encontrar las entradas correspondientes a la historia clinica
    Cliente*vecClientes;    ///para encontrar con el ID del paciente el apellido que coincida con el del reg mascota
    char aux[30];           ///para deposita el contenido de los GETS que devuelven cadenas
    int ID=-1;              ///para comprar el ID entre los registros
    int tam1;               ///para armar el vector y recorrer los ciclos
    int tam2;               ///para armar el vector y recorrer los ciclos
    vecHistoria=new Historia[cantidadRegistrosHistorias()];
    if(vecHistoria==NULL)
    {
        errorAsignacionMemoria();
        return false;
    }
    vecClientes=new Cliente [cantidadRegistrosClientes()];
    if(vecHistoria==NULL)
    {
        errorAsignacionMemoria();
        delete(vecHistoria);
        return false;
    }
    cout << "MOSTRAR HISTORIA CLINICA." << endl << endl;

    char nombreMascota[20];
    char apellidoCliente[30];
    cout << "       NOMBRE DE MASCOTA: ";                     ///PIDO nombreMascota (clase mascota)
    cin.ignore();
    cin.getline(nombreMascota,20);
    cout << "    APELLIDO DEL CLIENTE: ";                    ///PIDO apellido (clase cliente)
    cin.getline(apellidoCliente,30);

    tam1=cantidadRegistrosHistorias();
    tam2=cantidadRegistrosClientes();


    ///CARGO LOS VECTORES
    if(!cargarVecHistorias(vecHistoria,tam1)||!cargarVecClientes(vecClientes,tam2))
    {
        errorCargarRegistros();
        delete(vecClientes);
        delete(vecHistoria);
        return false;
    }
    for(int i=0; i<tam1; i++)          ///El problema es que puede haber mas de un cliente con el mismo apellido
    {
        vecHistoria[i].getNombreMascota(aux);
        if(strcmp(nombreMascota,aux)==0)          ///Recorro el vecHistoria hasta encontrar el nombre de mascota ingresado
        {
            for(int j=0; j<tam2; j++)       ///ahora vuelvo a recorrer pero el vecCliente hasta que coincida del apellido ingresado con el del REG
            {
                if((vecHistoria[i].getIDCliente() == vecClientes[j].getIDCliente())&&(strcmp(apellidoCliente,vecClientes[j].getApellido())))
                {
                    ID=vecHistoria[i].getIDCliente();   ///al poder tener varios clientes con el mismo apellido, asi se puede obtener el ID correcto
                }
            }
        }
    }
    if(ID==-1){
        cout << "NO HAY COINCIDENCIAS";
        cin.get();
        return false;
    }
    for (int i=0; i<tam1; i++)
    {
        if(vecHistoria[i].getIDCliente()==ID)   ///con el ID obtenido mostramos los atributos que corresponden
        {

            cout << endl << "    ID DE HISTORIA: " << vecHistoria[i].getIDHistoria()<< endl;
            cout << "   FECHA DE VISITA: ";
            vecHistoria[i].mostrarFechaVisita();
            cout << endl;
            cout << "         ANAMNESIS: ";
            vecHistoria[i].mostrarAnamnesis();
            cout << endl;
            cout << "      ---------------      " << endl;
        }
    }
    delete(vecHistoria);      ///tal vez necesite un DESTRUCTOR
    delete(vecClientes);
    pausar();
    return true;
}
bool modificarHistoria(){
    Historia reg;
    int ID,dia,mes,anio;
    int pos;
    char cad[3];
    cout << "MODIFICAR HISTORIA." << endl<<endl;
    cout << " ID ENTRADA DE HISTORIA: ";
    cin>> ID;
    pos=reg.buscarHistoria(ID);         ///PIDO EL ID, abro el archivo, busco esa entrada en particular y la leo
    if(pos==-1){
        errorRegistro();
        return false;
        }
    cin.ignore();
    cout << "              ANAMNESIS: ";              ///Despues se editan los Atributos de a uno.
    reg.setAnamnesis();
    cout << "REQUIERE VISITA DE CONTROL?"<< endl;
    cout << "   INGRESE: 'SI' o 'NO': ";
    cin >> cad;

    if(strcmp(cad,"SI")==0||strcmp(cad,"si")==0)
    {
        cout << "FECHA DE CONTROL (DD/MM/AA): " << endl;
        cin >> dia >> mes>> anio;
        if(!validarFecha(dia,mes,anio))
        {
            errorFechaInvalida();
            cout << dia << "/" << mes <<"/" << anio<< endl;
            pausar();
            return false;
        }
        reg.setControl(true);
        reg.setFechaControl(dia,mes,anio);
    }
    else if(strcmp(cad,"NO")==0||strcmp(cad,"no")==0)
    {
        reg.setControl(false);
        reg.setFechaControl(0,0,0);
    }
    cin.ignore();
    if(!reg.modificarHistoria(pos)){
        errorArchivo();
        return false;
    }
    return true;
}
bool controlesPendientes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    if(vecHistoria==NULL)
    {
        errorAsignacionMemoria();
        return false;
    }
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL)
    {
        errorAsignacionMemoria();
        delete(vecHistoria);
        return false;
    }

    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!(cargarVecClientes(vecCliente,cantClientes)))
    {
        errorCargarRegistros();
        delete(vecCliente);
        delete(vecHistoria);
        return false;
    }

    for(int i=0; i<cantHistorias; i++)  ///Recorro el vecHistorias para encontrar las "control=true"
    {
        if(vecHistoria[i].getControl()&&compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==2)
        {
            vecHistoria[i].mostrarNombreMascota();
            cout << endl;
            vecHistoria[i].mostrarFechaControl();
            cout << endl;
            for(int j=0; j<cantClientes; j++)       ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
            {
                if(vecHistoria[i].getIDCliente()==vecCliente[j].getIDCliente())
                {
                    vecCliente[j].mostrarTelefono();    ///y ahora con el ID del cliente del reg de esa historia, ubico al cliente en el vec.
                    cout << endl;
                    vecCliente[j].mostrarApellido();    ///asi accedo a sus atributos y muestro lo que necesito
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    cout << "ESAS SON LAS ENTRADAS HASTA LA FECHA." << endl;
    pausar();
    delete(vecHistoria);
    delete(vecCliente);
    return true;
}
bool controlesAusentes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL||vecHistoria==NULL)
    {
        errorAsignacionMemoria();
        delete (vecCliente);
        delete(vecHistoria);
        return false;
    }
    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!(cargarVecClientes(vecCliente,cantClientes)))
    {
        errorCargarRegistros();
        delete(vecCliente);
        delete(vecHistoria);
        return false;
    }

    for(int i=0; i<cantHistorias; i++)  ///Recorro el vecHistorias para encontrar las "control=true" y que la fecha de contro no haya pasado
    {
        if(vecHistoria[i].getControl() && compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==1)
        {
            vecHistoria[i].mostrarNombreMascota();
            cout << endl;
            vecHistoria[i].mostrarFechaControl();
            cout << endl;
            for(int j=0; j<cantClientes; j++)       ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
            {
                if(vecHistoria[i].getIDCliente()==vecCliente[j].getIDCliente())
                {
                    vecCliente[j].mostrarTelefono();    ///y ahora con el ID del cliente del reg de esa historia, ubico al cliente en el vec.
                    cout << endl;
                    vecCliente[j].mostrarApellido();    ///asi accedo a sus atributos y muestro lo que necesito
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    cout << "ESAS ENTRADAS HASTA LA FECHA." << endl;
    pausar();
    delete(vecHistoria);
    delete(vecCliente);
    return true;
}
void menuHistorias(){
    limpiar();
    pantallaHistorias();
    int op;
    cin >>op;
    limpiar();
    Historia reg;
    switch(op)
    {
    case 1:
    {
        if(ingresoHistoria())
        {
            guardadoExitoso();
            cin.get();
        }

    }
    break;
    case 2:
    {
        if(mostrarEntradaHistoria())
        {
            volviendoMenu();
            cin.get();
        }
    }
    break;
    case 3:
    {
        if(mostrarHistoria())
        {
            volviendoMenu();
            cin.get();
        }
    }
    break;
    case 4:
    {
        if(modificarHistoria())
        {
            guardadoExitoso();
            cin.get();
        }
    }
    break;
    case 5:
    {
        if(controlesPendientes())
        {
            volviendoMenu();
            cin.get();
        }

    }
    break;
    case 6:
    {
        if(controlesAusentes())
        {
            volviendoMenu();
            cin.get();
        }
    }
    break;
    case 0:
    {
       reg.mostrarTodoElArchivo();
    } break;
    }
}

///ARANCELES
///Para resolver las consignas del MENU ARANCELES
bool nuevoArancel(){
    Historia regHistoria;
    Arancel regArancel;
    TipoVisita regTipoVisita;
    Cliente regCliente;
    char tipoPago;
    int valor,pos;
    float total;
    regArancel.setFechaIngreso();
    regArancel.setIDArancel(asignarIDarancel());
    cout <<"INGRESO DE NUEVO ARANCEL." << endl << endl;
    cout << "       FECHA DE ARANCEL: ";
    regArancel.mostrarFechaArancel();
    cout << endl;

    cout << "             ID ARANCEL: " << regArancel.getIDArancel();
    cout << "         ID DE HISTORIA: ";
    cin >> valor;                           ///PIDO ID Y VALIDO SU PRESENCIA EN EL ARCHIVO HISTORIAS
    pos=regHistoria.buscarHistoria(valor);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regArancel.setIDHistoria(valor);

    valor=regHistoria.getIDCliente();
    cout<< "          ID DE CLIENTE: " << valor << endl;  ///ASIGNO AUTOMATICAMENTE ID Y VALIDO SU PRESENCIA EN EL ARCHIVOCLIENTES
    pos=buscarIDClienteEnHistorias(valor);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regArancel.setIDCliente(valor);

    listarTiposDeVisita();
    cout<< "         TIPO DE VISITA: ";             ///PIDO TIPO DE VISITA Y VALIDO SU PRESENCIA EN EL ARCHIVOTIPOVISITAS
    cin >> valor;
    pos=regTipoVisita.buscarTipoVisita(valor);
    if(pos==-1){
        errorRegistro();
        return false;           ///SI NO ESTA EN DISCO POS=-1 Y SALE
    }
    total=regTipoVisita.getImporte();   ///CARGO Y VALIDO EL IMPORTE DE LA VISITA SEGUN EL ARCHIVOTIPOVISITAS
    if(total<0){
        errorIngresoInvalido();
        return false;
    }
    regArancel.setIDTipoVisita(valor);
    regArancel.setTotalArancel(total);
    cout <<"         TIPO DE VISITA: ";
    regTipoVisita.mostrarNombreTipoVisita();
    cout <<"      TOTAL DEL ARANCEL: $";
    regArancel.mostrarTotalArancel();

    cout <<"           TIPO DE PAGO: " << endl;
    cout <<"E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cin>> tipoPago;
    if(!validarTipoDePago(tipoPago))                                     ///VALIDA QUE SE INGRESEN 'E,T,D,C'
    {
        errorIngresoInvalido();
        return false;
    }
    regArancel.setTipoPago(tipoPago);

    if(tipoPago=='c'||tipoPago=='C')                                    ///EL PAGO QUEDA A CUENTA ENTONCES..
    {
        regArancel.setAbonado(false);                                   ///PONGO EL ARANCEL COMO IMPAGO
        pos=regCliente.buscarClientePorID(regArancel.getIDCliente());
        if(pos==-1){
            errorRegistro();
            return false;
        }
        regCliente.setSaldo(regArancel.getTotalArancel()+regCliente.getSaldo()); ///BUSCO AL CLIENTE Y ACUMULO SU SALDO
        regCliente.modificarClienteDisco(pos);
    }
    else
    {
        regArancel.setAbonado(true);
    }
    regArancel.setPorcentajeHonorario(regTipoVisita.getPorcentajeHonorario());
    regArancel.guardarArancel();
    return true;
}
bool mostrarArancelesDelDia(){
    Arancel*vec;
    Fecha fechaDeHoy;
    fechaDeHoy.setFechaActual();
    cout << "ARANCELES DEL DIA: ";
    fechaDeHoy.mostrarFecha();
    cout << endl<< endl;
    int cantAranceles=cantidadRegistrosArancel();
    vec=new Arancel[cantAranceles];
    if(vec==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecArancel(vec,cantAranceles)){
        errorCargarRegistros();
        delete(vec);
        return false;
    }
    for(int i=0; i<cantAranceles; i++){
        if(compararFechas(vec[i].getFechaArancel(),obtenerFechaActual())==0){
            cout<<" ID DE ARANCEL: "<< vec[i].getIDArancel()<< endl;
            cout<<"TIPO DE VISITA: "<< vec[i].getIDTipoVisita()<< endl;
            cout<<"  TIPO DE PAGO: "<< tipoDePagoACadena(vec[i].getTipoPago())<< endl;
            cout<<"         TOTAL: "<< vec[i].getTotalArancel()<< endl;
            cout<<"----------------------------------" << endl;
        }
    }
    pausar();
    delete(vec);
    return true;
}
bool modificarArancel(){
    Arancel regArancel;
    Cliente regCliente;

    int ID,posArancel,posCliente;
    char tipoPago;
    cout << "MODIFICAR ARANCEL."<< endl<< endl;
    cout << "  INGRESE ID DE ARANCEL: ";
    cin >> ID;
    posArancel=regArancel.buscarArancel(ID);
    if (posArancel==-1){
        errorRegistro();
        return false;
    }
    cout << "                  FECHA: ";
    regArancel.mostrarFechaArancel();
    cout << endl;
    cout << "           TIPO DE PAGO: " << tipoDePagoACadena(regArancel.getTipoPago()) << endl;
    cout << "         TIPO DE VISITA: " << regArancel.getIDTipoVisita() << endl;
    cout << "                  TOTAL: " << regArancel.getTotalArancel() << endl;
    cout <<"E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cout << "           TIPO DE PAGO: ";
    cin >> tipoPago;
    if(!validarTipoDePago(tipoPago)){
        errorIngresoInvalido();
        return false;
    }
    regArancel.setTipoPago(tipoPago);
    posCliente=regCliente.buscarClientePorID(regArancel.getIDCliente()); ///BUSCO AL CLIENTE
    if(posCliente==-1){
        errorRegistro();
        return false;
    }
    if(tipoPago=='c'||tipoPago=='C')                                 ///EL PAGO QUEDA A CUENTA ENTONCES..
    {
        if(regArancel.getAbonado()){                                ///SI EL ARANCEL ESTABA ABONADO, AHORA SE LO SUMO AL SALDO
            regCliente.setSaldo(regArancel.getTotalArancel()+regCliente.getSaldo());
        }
        regArancel.setAbonado(false);
    }
    else
    {
        if(!regArancel.getAbonado()){                                ///SI EL ARANCEL ESTABA ABONADO, AHORA SE LO SUMO AL SALDO

            regCliente.setSaldo(regCliente.getSaldo()-regArancel.getTotalArancel());
        }
        regArancel.setAbonado(true);
    }
    if(!regArancel.modificarArancel(posArancel) || !regCliente.modificarClienteDisco(posCliente)){
        errorArchivo();
        return false;
    }
    return true;
}
bool mostrarArancelesPorVisita(){
    Arancel *vecArancel;
    TipoVisita *vecTipoVisita;
    int cantAranceles=cantidadRegistrosArancel();
    int cantTipoVisita=cantidadRegistrosTipoVisita();
    vecArancel=new Arancel[cantidadRegistrosArancel()];
    vecTipoVisita=new TipoVisita [cantidadRegistrosTipoVisita()];

    if(vecArancel==NULL||vecTipoVisita==NULL){
        errorAsignacionMemoria();
        delete(vecArancel);
        delete(vecTipoVisita);
        return false;
    }

    if(!cargarVecArancel(vecArancel,cantAranceles)||!cargarVecTipoVisita(vecTipoVisita,cantTipoVisita)){
        errorCargarRegistros();
        delete(vecArancel);
        delete(vecTipoVisita);
        return false;

    }
    int ID;
    float acu=0;
    cout << "ARANCELES POR TIPO DE VISITA"<< endl<< endl;
    listarTiposDeVisita();
    cout << endl;
    cout << "INGRESE EL TIPO DE VISITA: ";
    cin >> ID;
    cout << endl;
    for(int i=0;i<cantTipoVisita;i++){
        if(vecTipoVisita[i].getIDTipoVisita()==ID){
            for (int j=0;j<cantAranceles;j++){
                if(vecArancel[j].getIDTipoVisita()==ID){
                cout <<"ID N " << vecArancel[j].getIDArancel()<<" | "<< vecTipoVisita[i].getNombreTipoVisita()<< " | $"<<vecArancel[j].getTotalArancel()<< endl;
                acu+=vecArancel[j].getTotalArancel();
                }
            }

        }
    }
    cout << endl;
    cout << "        TOTAL: $" << acu << endl;
    cin.ignore();
    cin.get();
    return true;
}
void menuAranceles(){
    limpiar();
    pantallaAranceles();
    int op;
    cin >>op;
    limpiar();
    switch(op)
    {
    case 1:
        if(nuevoArancel())
        {
            guardadoExitoso();
            cin.get();
        }
        break;
    case 2:
        if(mostrarArancelesDelDia())
        {
            volviendoMenu();
            cin.get();
        }
        break;
    case 3:
        if(modificarArancel())
        {
            guardadoExitoso();
            cin.get();
        }
        break;
    case 4:
        if(mostrarArancelesPorVisita())
        {
            guardadoExitoso();
            cin.get();
        }
        break;
    case 0:
        Arancel reg;
        reg.mostrarTodoElArchivo();
        break;
    }
}

///ADMINISTRACION
///Para resolver las consignas del MENU ADMINISTRACION
bool mostrarListaDePrecios(){
    limpiar();
    cout << "LISTA DE PRECIOS" << endl<< endl;
    TipoVisita*vec;
    int cantTipoVisita=cantidadRegistrosTipoVisita();
    vec= new TipoVisita [cantTipoVisita];
    if(vec==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecTipoVisita(vec,cantTipoVisita)){
        errorCargarRegistros();
        return false;
    }
    for(int i=0; i<cantTipoVisita; i++)
    {
        cout << "            ID: "<< vec[i].getIDTipoVisita() << endl;
        cout << "TIPO DE VISITA: ";
        vec[i].mostrarNombreTipoVisita();
        cout << endl;
        cout << "       IMPORTE: $" << vec[i].getImporte() <<"-." << endl;
        cout << "     HONORARIO: " << vec[i].getPorcentajeHonorario() << "%."<< endl;
        cout << "----------------------------------" << endl;
    }
    pausar();
    delete(vec);
    return true;
}
bool modificarImportes(){
    limpiar();
    TipoVisita reg;
    int ID, pos;
    float importe;
    cout << "MODIFICAR IMPORTES." <<endl << endl;
    cout << "           INGRESE ID: ";
    cin >> ID;                              ///PIDO EL ID,
    pos=reg.buscarTipoVisita(ID);           ///BUSCO ESE REGISTRO EN ARCHIVOTIPOVISITAS
    if (pos==-1)
        return false;              ///VALIDO LA POSICION
    cout << "NOMBRE TIPO DE VISITA: ";
    reg.mostrarIDTipoVisita();
    cout << endl;
    cout << "              IMPORTE: $";///MODIFICO LOS ATRIBUTOS Y LOS VALIDO
    cin >> importe;
    if(importe <0)
        return false;
    reg.setImporte(importe);

    cout << " PORCENTAJE HONORARIO: %";
    cin >> ID;
    if(ID<1||ID>100) return false;
    reg.setPorcentajeHonorario(ID);

    reg.modificarTipoVisita(pos);                ///GUARDO EL REGISTRO
    return true;
}
bool ingresarItems(){
    limpiar();
    TipoVisita reg;
    int ID;
    float importe;
    char cadena[15];
    cout << " INGRESAR TIPO DE VISITA" <<endl << endl;
    ID=asignarIDTipoVisita();                  ///EL ID SE ASIGNA SECUENCIALMENTE
    if(validarIDTipoVisita(ID)){
        errorRegistro();
        return false;
    }
    reg.setIDTipoVisita(ID);
    cout << "                  ID: ";
    reg.mostrarIDTipoVisita();
    cout << endl;
    cout << "              NOMBRE:";        ///PIDO LOS DEMAS ATRIBUTOS Y LOS VALIDO
    cin.ignore();
    cin.getline(cadena,15);
    if (!validarNombres(cadena)){
        errorIngresoInvalido();
        return false;
    }
    reg.setNombreTipoVisita(cadena);

    cout << "             IMPORTE: $";
    cin >> importe;
    if(importe <0){
        cout << "EL IMPORTE NO PUEDE SER MENOR A $0-." << endl;
        cin.get();
        return false;
    }
    reg.setImporte(importe);

    cout << "PORCENTAJE HONORARIO: %";
    cin >> ID;
    if(ID<1||ID>100){
        errorIngresoInvalido();
        return false;
    }
    reg.setPorcentajeHonorario(ID);
    reg.guardarTipoVisita();                ///GUARDO EL REGISTRO
    return true;
}
bool listarPorFecha(){
    limpiar();
    Arancel*vecArancel;
    TipoVisita reg;
    Fecha inicio;
    Fecha fin;
    int d, m, a,cantAranceles;
    float acu=0;

    cout << " LISTADO DE VISITAS POR FECHA" <<endl << endl;
    cout << " FECHA DE INICIO (DD/MM/AA): " << endl;        ///PIDO LAS FECHAS DE INICIO Y FIN DE BUSQUEDA
    cout << "                        DIA: ";
    cin >> d;
    cout << "                        MES: ";
    cin >> m;
    cout << "                       ANIO: ";
    cin >> a;
    inicio.setFecha(d,m,a);
    if(!validarFecha(d,m,a) || compararFechas(inicio,obtenerFechaActual())>1){
        errorFechaInvalida();
        return false;
    }
    cout << "     FECHA DE FIN (DD/MM/AA): " << endl;
    cout << "                        DIA: ";
    cin >> d;
    cout << "                        MES: ";
    cin >> m;
    cout << "                       ANIO: ";
    cin >> a;
    fin.setFecha(d,m,a);
    if(!validarFecha(d,m,a) || compararFechas(inicio,fin)==2){
        errorFechaInvalida();
        return false;
    }

    cantAranceles=cantidadRegistrosArancel();
    vecArancel= new Arancel[cantAranceles];
    if(vecArancel==NULL){
        errorAsignacionMemoria();
        return false;
        }

    if(!(cargarVecArancel(vecArancel,cantAranceles))){
        errorCargarRegistros();
        return false;
        }

    for(int i=0; i<cantAranceles; i++)
    {
        if((compararFechas(inicio,vecArancel[i].getFechaArancel())<=1) && (compararFechas(vecArancel[i].getFechaArancel(),fin)<=1))
        {
            vecArancel[i].mostrarFechaArancel();
            cout << endl;
            if(reg.buscarTipoVisita(vecArancel[i].getIDTipoVisita())==-1){
                errorRegistro();
                return false;
            }
            cout << "  TIPO DE VISITA: " << reg.getNombreTipoVisita() << endl;
            cout << "         IMPORTE: $"<< vecArancel[i].getTotalArancel() << endl;
            cout << "-------------------------------" << endl;
            acu+=vecArancel[i].getTotalArancel();
        }
    }
    cout << "        EL TOTAL FACTURADO: $" << acu << endl;
    pausar();
    delete(vecArancel);
    return true;
}
bool mostrarDeudores(){
    Arancel*vecArancel;
    Cliente*vecClientes;
    float acu;
    bool deudores=false;

    int cantAranceles=cantidadRegistrosArancel();   ///CARGO VECTOR DE ARANCELES
    vecArancel= new Arancel [cantAranceles];
    if(vecArancel==NULL) return false;
    if(!cargarVecArancel(vecArancel,cantAranceles)) return false;

    int cantClientes=cantidadRegistrosClientes();   ///CARGO VECTOR DE CLIENTES
    vecClientes= new Cliente [cantClientes];
    if(vecClientes==NULL){
        delete(vecArancel);
        return false;
    }
    if(!cargarVecClientes(vecClientes,cantClientes)){
        delete (vecArancel);
        delete (vecClientes);
        return false;
    }

    cout << "LISTADO DE DEUDORES" << endl<< endl;
    for(int i=0;i<cantClientes;i++){            ///RECORRO LOS CLIENTES DE A UNO BUSCANDO DEUDORES
        acu=0;
        if(vecClientes[i].getSaldo()>0){         ///SI ENCUENTRO, MUESTRO SUS DATOS
            deudores=true;                          ///SI DEUDORES ES FALSE MUESTRO QUE NO HAY DEUDORES
            cout << "NOMBRE CLIENTE: "<< vecClientes[i].getNombreCliente() << endl;
            cout << "      APELLIDO: " << vecClientes[i].getApellido()<< endl;
            cout << "      TELEFONO: " << vecClientes[i].getTelefono() << endl;
                                                ///LUEGO BUSCO LOS ARANCELES INPAGOS QUE COICIDAN CON ESE CLIENTE
            for(int j=0;j<cantAranceles;j++){
                if(!(vecArancel[j].getAbonado()) && vecClientes[i].getIDCliente()==vecArancel[j].getIDCliente()){
                    cout << "         FECHA: ";
                    vecArancel[j].mostrarFechaArancel();           ///SI ENCUENTRO MUESTRO LOS DATOS DE ESE ARANCEL Y ACUMULO EL TOTAL $.
                    cout << endl << "    ID ARANCEL: " << vecArancel[j].getIDArancel() << endl;
                    cout << "         TOTAL: $" << vecArancel[j].getTotalArancel() << endl;
                }

            }
            cout << "  SALDO DEUDOR: $" << acu;               ///AHORA MUESTRO EL TOTAL ACUMULADO DE LOS ARANCELES INPAGOS
            cout << endl<< endl;
        }
    }
    if(!deudores){
        cout << "NO HAY CLIENTES CON SALDO DEUDOR." << endl;
    }
    system("pause");
    delete(vecArancel);
    delete(vecClientes);
    return true;
}
bool comisiones(){
    Arancel*vecArancel;
    TipoVisita regTipoVisita;
    Fecha aux;
    int dia, mes, anio, ID, cantAranceles;
    float acu=0;
    cout << "COMISIONES" << endl << endl;
    cout << "INGRESE DESDE QUE FECHA INICIAR LA BUSQUEDA (DD/MM/AA): " << endl;
    cout << "                         DIA: ";
    cin >> dia;
    cout << "                         MES: ";
    cin >> mes;
    cout << "                        ANIO: ";
    cin >> anio;
    aux.setFecha(dia,mes,anio);
    cout << "           ID TIPO DE VISITA: ";
    cin>> ID;
    cantAranceles=cantidadRegistrosArancel();
    vecArancel=new Arancel [cantAranceles];
    if(vecArancel==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecArancel(vecArancel,cantAranceles)){
        errorCargarRegistros();
        delete (vecArancel);
        return false;
    }

    regTipoVisita.buscarTipoVisita(ID);
    cout << "              TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita()<< endl;

    for(int i=0;i<cantAranceles;i++){
        if(vecArancel[i].getIDTipoVisita()==ID && (compararFechas(aux,vecArancel[i].getFechaArancel())==1 || compararFechas(aux,vecArancel[i].getFechaArancel())==0)){
            cout << "                       FECHA: ";
            vecArancel[i].getFechaArancel().mostrarFecha();
            cout << "            TOTAL DE ARANCEL: $"<< vecArancel[i].getTotalArancel()<< endl;
            acu+= (vecArancel[i].getTotalArancel() * vecArancel[i].getPorcentajeHonorario()/100);
        }
    }
    cout <<"---------------------------------------------"<<  endl;
    cout << "      PORCENTAJE DE COMISION: " <<regTipoVisita.getPorcentajeHonorario()<< "%." << endl;
    cout << "         TOTAL DE COMISIONES: $" <<acu << endl;
    system("pause");
    delete(vecArancel);
    return true;
}
void menuAdministracion(){
    limpiar();
    pantallaAdministracion();
    TipoVisita reg;
    int op;
    cin >>op;
    limpiar();
    switch(op)
    {
    case 1:
    {
        if(mostrarListaDePrecios())
        {
            volviendoMenu();
            cin.get();
        }

    }
    break;
    case 2:
    {
        if(modificarImportes())
        {
            guardadoExitoso();
        }
        else{
            errorRegistro();
        }
        cin.get();

    }
    break;
    case 3:
    {
        if(ingresarItems())
        {
            guardadoExitoso();
        }
        else{
            errorArchivo();
        }
        cin.get();
    }
    break;
    case 4:
    {
        if(listarPorFecha())
        {
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();
    }
    break;
    case 5:
    {
        if(mostrarDeudores())
        {
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();

    }
    break;
    case 6:
    {
        if(comisiones())
        {
            guardadoExitoso();

        }
        errorRegistro();
        cin.get();
    }
    break;
    case 0:
    {
        reg.mostrarTodoElArchivo();
    } break;
    }

}


///CONFIGURACION
///Para resolver las consignas del MENU CONFIGURACION

bool backupHistorias(){
    Historia reg;
    FILE*pArchivo=fopen(ARCHIVOHISTORIAS,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOHISTORIASBKP,"wb");
    if(pBackup==NULL){
        fclose(pArchivo);
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    fclose(pArchivo);
    fclose(pBackup);
    return true;
}
bool backupClientes(){
    Cliente reg;
    FILE*pArchivo=fopen(ARCHIVOCLIENTES,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOCLIENTESBKP,"wb");
    if(pBackup==NULL){
        fclose(pArchivo);
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    fclose(pArchivo);
    fclose(pBackup);
    return true;
}
bool backupMascotas(){
    Mascotas reg;
    FILE*pArchivo=fopen(ARCHIVOMASCOTAS,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOMASCOTASBKP,"wb");
    if(pBackup==NULL){
        fclose(pArchivo);
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    fclose(pArchivo);
    fclose(pBackup);
    return true;
}
bool backupAranceles(){
    Arancel reg;
    FILE*pArchivo=fopen(ARCHIVOARANCELES,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOARANCELESBKP,"wb");
    if(pBackup==NULL){
        fclose(pArchivo);
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    fclose(pArchivo);
    fclose(pBackup);
    return true;
}
bool backupTipoVisita(){
    Arancel reg;
    FILE*pArchivo=fopen(ARCHIVOTIPOVISITA,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOTIPOVISITABKP,"wb");
    if(pBackup==NULL){
        fclose(pArchivo);
        return false;
    }
    while(fread(&reg,sizeof reg,1,pArchivo)==1){
        fwrite(&reg,sizeof reg,1,pBackup);
    }
    fclose(pArchivo);
    fclose(pBackup);
    return true;
}
void menuConfiguracion(){
    limpiar();
    pantallaConfiguracion();
    int op;
    cin >>op;
    limpiar();
    switch(op)
    {
    case 1:
    {
        if(backupClientes())
        {
            guardadoExitoso();
            cin.get();
        }

    }
    break;
    case 2:
    {
        if(backupMascotas())
        {
            guardadoExitoso();
            cin.get();
        }

    }
    break;
    case 3:
    {
        if(backupHistorias())
        {
            guardadoExitoso();
            cin.get();
        }
    }
    break;
    case 4:
    {
        if(backupTipoVisita())
        {
            guardadoExitoso();
            cin.get();
        }
    }
    break;
    case 5:
    {
        if(backupAranceles())
        {
            guardadoExitoso();
            cin.get();
        }
    }
    break;
    case 0:
    {
    } break;
    }

}

