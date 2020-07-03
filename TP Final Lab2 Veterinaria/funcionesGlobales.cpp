#include "funcionesGlobales.h"

///VALIDACIONES
int compararFechas(Fecha fechaUno, Fecha fechaDos){ /// 0=son iguales, 1=la primera es anterior a la segunda, o 2=la segunda es anterior a la primera

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
Fecha obtenerFechaActual(){///LLamas a la funcion  te devuelve un objeto de clase Fecha con dia mes y anio
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
bool validarFebrero(int dia,int anio){
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
bool validarBisiesto(int dia, int mes, int anio){
    Fecha aux;
    aux.setFechaActual();
    if (((anio>aux.getAnio())||(anio<=aux.getAnio()&&mes>aux.getMes())||(anio<=aux.getAnio()&&mes<=aux.getMes()&&dia>aux.getDia())) || (mes>12))
    {
        return true;
    }
    return false;
}
bool validarFecha(int dia,int mes,int anio){///Valida que la fecha se ingrese bien usando "validarFebrero()" y "validarFebrero"
//    if(validarBisiesto(dia,mes,anio))
//    {
//        return false;
//    }
    if(mes>12||dia>31){
        return false;
    }
    if (mes==2 && validarFebrero(dia,anio)){
        return false;
    }
    if (mes<8 && mes%2!=0){
        if (dia<0&&dia>31){
            return false;
        }
    }
    else if(mes<8 && dia<0&&dia>30){
        return false;
    }
    if(mes%2!=0){
        if(dia<0&&dia>30){
            return false;
        }
        else if(dia<0&&dia>31){
            return false;
        }
    }
    return true;
}
int buscarCaracter(const char*cadena,char caracter){
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
bool ultimoCaracteresArroba (const char*cadena){
    int i=strlen(cadena);
    if(cadena[i-1]=='@')
    {
        return true;
    }
    return false;
}
bool buscarRepContiguos(const char*cadena,char caracter){
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
char buscarUltCaracter(const char*cadena){
    int i=strlen(cadena);
    return cadena[i-1];
}
int contarSimbolos(const char*cadena){
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
int validarMail(const char* cadena){///Usa la 5 funciones dde arriba para validar el mail como en el TP LARA
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
bool validarTipoDePago(char tipoPago){
    if(tipoPago=='e'||tipoPago=='E'|| tipoPago=='t'|| tipoPago=='T'|| tipoPago=='d'|| tipoPago=='D'|| tipoPago=='c'|| tipoPago=='C')
    {
        return true;
    }
    return false;
}
bool validarNombres(const char* cadena){///True = a-z o A-Z , false=cualquier otra cosa
    int i=0;
    while(cadena[i]!= '\0'){
        if((cadena[i]>0 && cadena[i]<65)||(cadena[i]>90 && cadena[i]<97)||(cadena[i]>122)){
            return false;
        }
        i++;
    }
    return true;
}
bool cad_vacia(char *cad){
    if(cad[0] == '\0')
    {
        return true;
    }
    return false;
}
void listardueno(int IDcliente){
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
int listarTiposDeVisita(int op){///parametro 0=muestra Inactivos, 1=activos, 2=todos || retornos -1=no hay registros , 1=hay registros
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if (p==NULL){
        errorArchivo();
        return -1;
    }
    int i=0;
    int con=0;
    cout <<"                       ";
    switch(op){
        case 0:
            while(fread(&reg,sizeof (TipoVisita),1,p)==1){
                i++;
                if(!reg.getEstado()){
                    con++;
                    cout<<i <<"- "<<reg.getNombreTipoVisita();
                    if(con%3==0){
                        cout << endl;
                        cout<<"                       ";
                    }
                    else{
                        cout << " | ";
                    }
                }
            }
            break;
        case 1:
            while(fread(&reg,sizeof (TipoVisita),1,p)==1){
                i++;
                if(reg.getEstado()){
                    con++;
                    cout<<i <<"- "<<reg.getNombreTipoVisita();
                    if(con%3==0){
                        cout << endl;
                        cout<<"                       ";
                    }
                    else{
                        cout << " | ";
                    }
                }
            }
            break;
        case 2:
            while(fread(&reg,sizeof (TipoVisita),1,p)==1){
                con++;
                i++;
                cout<<i <<"- "<<reg.getNombreTipoVisita();
                if(con%3==0){
                    cout << endl;
                    cout<<"                       ";
                }
                else{
                    cout << " | ";
                }
            }
            break;
    }
    cout << endl;
    fclose(p);
    if(i==0){
        return -1;
    }
    return 1;
}
void listarMascotasConIDCliente(int ID){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if (p==NULL) return;
    cout <<"                SUS MASCOTAS: ";
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(reg.getIDCliente()==ID&&reg.getVivo()){
            cout << reg.getNombre()<< " | ";
        }
    }
    fclose(p);
    return;
}
void listarClientesConIDMascotas(int ID){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if (p==NULL) return;
    cout <<"         LISTA DE MASCOTAS: ";
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(ID==reg.getIDCliente()){
            cout << reg.getNombre()<< " | ";
        }
    }
    fclose(p);
    return;
}

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVOS
int asignarIDHistoria(){///Le pone solo el ID de manera secuencial
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
int asignarIDarancel(){///Le pone solo el ID de manera secuencial
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
int asignarIDTipoVisita(){///Le pone solo el ID de manera secuencial
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
bool validarTipoVisita(const char*nombre){
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return false;
    }
    if(!validarNombres(nombre)){
        return false;
    }
    while(fread(&reg,sizeof (TipoVisita),1,p)==1){
        if(strcmp(reg.getNombreTipoVisita(),nombre)==0){
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
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
bool validarIDcliente(int ID){///Busca el ID en ARCHIVOCLIENTES y devuelve true si lo encuentra
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
int cantidadRegistrosHistorias(){   ///Devuelve la cantidad de registros en ARCHIVOHISTORIAS
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Historia);
}
int cantidadRegistrosClientes(){    ///Devuelve la cantidad de registros en ARCHIVOCLIENTES
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Cliente);
}
int cantidadRegistrosMascotas(){    ///Devuelve la cantidad de registros en ARCHIVOMASCOTAS
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Mascotas);
}
int cantidadRegistrosArancel(){ ///Devuelve la cantidad de registros en ARCHIVOARANCELES
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
bool cargarVecHistorias(Historia*vec,int tam){///Le mandas un vector de clase HISTORIA y su tamanio y te lo carga todo
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
bool cargarVecClientes(Cliente*vec,int tam){///Le mandas un vector de clase CLIENTES y su tamanio y te lo carga todo
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
bool cargarVecMascotas(Mascotas*vec,int tam){///Le mandas un vector de clase MASCOTAS y su tamanio y te lo carga todo
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
bool cargarVecArancel(Arancel*vec,int tam){///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
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
bool cargarVecTipoVisita(TipoVisita*vec,int tam){///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
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
bool listarVisitasClientes(){
    Historia*vecHistorias;
    char cadena[20];
    int ID;
    bool encontrado=false;
    int cantHistorias=cantidadRegistrosHistorias();
    if(cantHistorias==-1){
        errorArchivo();
        return false;
    }

    cout << "LISTAR VISITAS" << endl << endl;
    cout << "       ID DE CLIENTE: ";
    cin>> ID;
    cin.ignore();
    if(!validarIDcliente(ID)){
        errorIngresoInvalido();
        return false;
    }
    listarMascotasConIDCliente(ID);
    cout << endl;
    cout << "   NOMBRE DE MASCOTA: ";
    cin.getline(cadena,20);
    if(cadena[0]=='\0'){
        errorIngresoInvalido();
        return false;
    }

    vecHistorias=new Historia [cantHistorias];
    if(vecHistorias==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecHistorias(vecHistorias,cantHistorias)){
        delete(vecHistorias);
        return false;
    }

    for(int i=0;i<cantHistorias;i++){
        if(strcmp(cadena,vecHistorias[i].getNombreMascota())==0 && vecHistorias[i].getIDCliente()==ID){
            cout << "FECHA VISITA: ";
            vecHistorias[i].mostrarFechaVisita();
            cout << "      ID DE VISITA: " << ID << endl;
            cout << "--------------------------------------------" << endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "NO HUBO COINCIDENCIAS" << endl;
    }
    pausar();
    delete(vecHistorias);
    return true;
}

///MASCOTAS
bool listarVisitasMascotas(){
    Historia*vecHistorias;
    char cadena[20];
    int ID;
    bool encontrado=false;
    int cantHistorias=cantidadRegistrosHistorias();
    if(cantHistorias==-1){
        errorArchivo();
        return false;
    }

    cout << "LISTAR VISITAS" << endl << endl;
    cout << "       ID DE CLIENTE: ";
    cin>> ID;
    cin.ignore();
    if(!validarIDcliente(ID)){
        errorIngresoInvalido();
        return false;
    }
    listarMascotasConIDCliente(ID);
    cout << endl;
    cout << "   NOMBRE DE MASCOTA: ";
    cin.getline(cadena,20);
    if(cadena[0]=='\0'){
        errorIngresoInvalido();
        return false;
    }

    vecHistorias=new Historia [cantHistorias];
    if(vecHistorias==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecHistorias(vecHistorias,cantHistorias)){
        delete(vecHistorias);
        return false;
    }

    for(int i=0;i<cantHistorias;i++){
        if(strcmp(cadena,vecHistorias[i].getNombreMascota())==0 && vecHistorias[i].getIDCliente()==ID){
            cout << "FECHA VISITA: ";
            vecHistorias[i].mostrarFechaVisita();
            cout << "      ID DE VISITA: " << ID << endl;
            cout << "--------------------------------------------" << endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "NO HUBO COINCIDENCIAS" << endl;
    }
    pausar();
    delete(vecHistorias);
    return true;
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
    cout << "FECHA DE LA VISITA(DD/MM/AA) "<< endl;
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
    if(!validarIDcliente(valor)){
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
    reg.setAnamnesis();                     ///Aca la Anamnesis (detalles de la visita)

    cout << "VISITA DE CONTROL? 'SI' o 'NO' : ";
    cin.getline(cadena2,3);
    if(strcmp(cadena2,"SI")==0||strcmp(cadena2,"si")==0)
    {
        cout << "INGRESE LA FECHA DEL CONTROL(DD/MM/AA)"<< endl;
        cout << "                         DIA: ";
        cin >> dia;
        cout << "                         MES: ";
        cin >> mes;
        cout << "                        ANIO: ";
        cin >> anio;
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
    cout << "ENTRADA DE HISTORIA CLINICA." << endl;
    cout << "HISTORIA CLINICA ID: ";
    cin >> ID;
    pos=reg.buscarHistoria(ID);
    if(pos==-1){
        errorRegistro();
        return false;
    }

    reg.mostrarFechaVisita(); ///Despues se muestran los registros de a uno
    cout << "                 " << reg.getNombreMascota() << endl<< endl;
    cout <<"ANAMNESIS: " << endl;
    reg.mostrarAnamnesis();
    cout << endl;
    pausar();
    return true;
}
bool mostrarHistoria(){
    Mascotas*vecMascotas;
    Historia*vecHistoria; ///para encontrar las entradas correspondientes a la historia clinica
    Cliente*vecClientes;    ///para encontrar con el ID del paciente el apellido que coincida con el del reg mascota
    int ID=-1;              ///para comprar el ID entre los registros
    char nombreMascota[20];
    char apellidoCliente[30];
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();
    int cantMascotas=cantidadRegistrosMascotas();
    bool encontrado=false;

    vecHistoria=new Historia[cantHistorias];
    vecMascotas=new Mascotas[cantMascotas];
    vecClientes=new Cliente [cantClientes];

    if(vecHistoria==NULL||vecClientes==NULL||vecMascotas==NULL){
        errorAsignacionMemoria();
        delete(vecHistoria);
        delete(vecMascotas);
        delete(vecClientes);
        return false;
    }

    ///CARGO LOS VECTORES
    if(!cargarVecHistorias(vecHistoria,cantHistorias)||!cargarVecClientes(vecClientes,cantClientes)||!cargarVecMascotas(vecMascotas,cantMascotas)){
        errorCargarRegistros();
        delete(vecClientes);
        delete(vecMascotas);
        delete(vecHistoria);
        return false;
    }

    cout << "MOSTRAR HISTORIA CLINICA." << endl << endl;
    cout << "       NOMBRE DE MASCOTA: ";                     ///PIDO nombreMascota (clase mascota)
    cin.ignore();
    cin.getline(nombreMascota,20);
    for(int i=0;i<cantMascotas;i++){                    ///MUESTRO LOS POSIBLES DUENIOS DE ESA MASCOTA
        if(strcmp(nombreMascota,vecMascotas[i].getNombre())==0)
            for(int j=0;j<cantidadRegistrosClientes();j++){
                if(vecMascotas[i].getIDCliente()==vecClientes[j].getIDCliente()){
                    cout << "                 DUENIOS: " << vecClientes[i].getApellido()<< " | ";
                    encontrado=true;
                }
            }
    }
    cout << endl;
    if(!encontrado){
        cout << "NO HUBO COINCIDENCIAS"<< endl;
        pausar();
        return false;
    }

    cout << "    APELLIDO DEL CLIENTE: ";                    ///PIDO apellido (clase cliente)
    cin.getline(apellidoCliente,30);

    for(int i=0; i<cantHistorias; i++)          ///El problema es que puede haber mas de un cliente con el mismo apellido
    {
        if(strcmp(nombreMascota,vecHistoria[i].getNombreMascota())==0)          ///Recorro el vecHistoria hasta encontrar el nombre de mascota ingresado
        {
            for(int j=0; j<cantClientes; j++)       ///ahora vuelvo a recorrer pero el vecCliente hasta que coincida del apellido ingresado con el del REG
            {
                if((vecHistoria[i].getIDCliente() == vecClientes[j].getIDCliente())&&(strcmp(apellidoCliente,vecClientes[j].getApellido())==0)){
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
    for (int i=0; i<cantHistorias; i++)
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
    delete(vecMascotas);
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

    listarTiposDeVisita(1);
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
    cout <<"         TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita();
    cout <<"      TOTAL DEL ARANCEL: $";
    regArancel.mostrarTotalArancel();

    cout <<"           E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cout <<"           TIPO DE PAGO: ";
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
    int ID,anio;
    float acu=0;
    cout << "ARANCELES POR TIPO DE VISITA ANUAL"<< endl<< endl;
    listarTiposDeVisita(2);
    cout << endl;
    cout << "INGRESE EL TIPO DE VISITA: ";
    cin >> ID;
    cout << "                     ANIO: ";
    cin >> anio;
    if (anio<100) anio+=2000;
    cout << endl;
    for(int i=0;i<cantTipoVisita;i++){
        if(vecTipoVisita[i].getIDTipoVisita()==ID){
            for (int j=0;j<cantAranceles;j++){
                if(vecArancel[j].getIDTipoVisita()==ID && vecArancel[j].getFechaArancel().getAnio()==anio){
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
        cout << "TIPO DE VISITA: " << vec[i].getNombreTipoVisita() << endl;
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
    cout << "MODIFICAR IMPORTES" <<endl << endl;
    listarTiposDeVisita(1);
    cout << endl << endl<< "           INGRESE ID: ";
    cin >> ID;                              ///PIDO EL ID,
    pos=reg.buscarTipoVisita(ID);           ///BUSCO ESE REGISTRO EN ARCHIVOTIPOVISITAS
    if (pos==-1 || !reg.getEstado()){                           ///VALIDO LA POSICION
        errorRegistro();
        return false;
    }
    cout << "NOMBRE TIPO DE VISITA: ";
    cout << reg.getNombreTipoVisita() << endl;
    cout << "              IMPORTE: $";///MODIFICO LOS ATRIBUTOS Y LOS VALIDO
    cin >> importe;
    if(importe <0){
        errorIngresoInvalido();
        return false;
    }
    reg.setImporte(importe);

    cout << " PORCENTAJE HONORARIO: %";
    cin >> ID;
    if(ID<1||ID>100){
        errorIngresoInvalido();
        return false;
    }
    reg.setPorcentajeHonorario(ID);
    if(!reg.modificarTipoVisita(pos)){
        errorArchivo();
        return false;
    }                ///GUARDO EL REGISTRO
    return true;
}
bool nuevoServicio(){
    limpiar();
    TipoVisita reg;
    int ID;
    float importe;
    char cadena[30];
    cout << " INGRESAR TIPO DE VISITA" <<endl << endl;
    ID=asignarIDTipoVisita();                  ///EL ID SE ASIGNA SECUENCIALMENTE
    if(validarIDTipoVisita(ID)){
        errorRegistro();
        return false;
    }
    reg.setIDTipoVisita(ID);
    cout << "                  ID: " << reg.getIDTipoVisita()<< endl;
    cout << "              NOMBRE: ";        ///PIDO LOS DEMAS ATRIBUTOS Y LOS VALIDO
    cin.ignore();
    cin.getline(cadena,30);
    if (!validarTipoVisita(cadena) && ID!=1){
        errorIngresoInvalido();
        cout << "PUEDE QUE ESE SERVICIO ESTE DADO DE BAJA" << endl;
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
    reg.setEstado(true);
    reg.guardarTipoVisita();                ///GUARDO EL REGISTRO
    return true;
}
bool AltaBajaServicio(){
    limpiar();
    TipoVisita regTipoVisita;
    int ID,pos;
    char cadena[3];
    cout << " ALTA Y BAJA DE TIPO DE VISITA" <<endl << endl;
    cout << "   SERVICIOS EN BAJA:" << endl;
    listarTiposDeVisita(0);
    cout << endl;
    cout << "   SERVICIOS EN ALTA:" << endl;
    listarTiposDeVisita(1);
    cout << endl<< endl << "   TIPO DE VISITA ID: ";
    cin >> ID;
    pos=regTipoVisita.buscarTipoVisita(ID);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    cin.ignore();
    if(regTipoVisita.getEstado()){
        cout << " ESTA SEGURO QUE DESEA DAR DE BAJA?"<< endl;
        cout << "                       'SI' o 'NO':";
        cin.getline(cadena,3);
        if(strcmp(cadena,"si")==0||strcmp(cadena,"SI")==0){
            cout << "ENTRO AL SI DE BAJA:"<< cadena << endl;
            pausar();
            regTipoVisita.setEstado(false);
        }
        else if (strcmp(cadena,"no")==0||strcmp(cadena,"NO")==0){
            cout << "ENTRO AL NO DE BAJA:"<< cadena << endl;
            pausar();
            volviendoMenu();
            return false;
        }
        else{
            cout << "ENTRO AL ERROR DE BAJA:"<< cadena << endl;
            pausar();
            errorIngresoInvalido();
            return false;
        }
    }
    else{
        cout << " ESTA SEGURO QUE DESEA DAR DE ALTA?"<< endl;
        cout << "                       'SI' o 'NO':";
        cin.getline(cadena,3);
        if(strcmp(cadena,"si")==0||strcmp(cadena,"SI")==0){
            cout << "ENTRO AL SI DE ALTA:"<< cadena << endl;
            pausar();
            regTipoVisita.setEstado(true);
        }
        else if (strcmp(cadena,"no")==0||strcmp(cadena,"NO")==0){
            cout << "ENTRO AL NO DE ALTA:"<< cadena << endl;
            pausar();
            volviendoMenu();
            return false;
        }
        else{
            cout << "ENTRO AL ERROR DE ALTA:"<< cadena << endl;
            pausar();
            errorIngresoInvalido();
            return false;
        }
    }
    if(!regTipoVisita.modificarTipoVisita(pos)){
        errorArchivo();
        return false;
    }
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
            cout << "      APELLIDO: " << vecClientes[i].getApellido();
            cout << "      TELEFONO: " << vecClientes[i].getTelefono() << endl <<endl;
            cout << "                ARANCELES" << endl;
            cout << "---------------------------" << endl;                                    ///LUEGO BUSCO LOS ARANCELES INPAGOS QUE COICIDAN CON ESE CLIENTE
            for(int j=0;j<cantAranceles;j++){
                if(!(vecArancel[j].getAbonado()) && vecClientes[i].getIDCliente()==vecArancel[j].getIDCliente()){

                    cout << "         FECHA: ";
                    vecArancel[j].mostrarFechaArancel();           ///SI ENCUENTRO MUESTRO LOS DATOS DE ESE ARANCEL Y ACUMULO EL TOTAL $.
                    cout << endl << "    ID ARANCEL: " << vecArancel[j].getIDArancel() << endl;
                    cout << "         TOTAL: $" << vecArancel[j].getTotalArancel() << endl;
                     cout << "---------------------------" << endl;
                    acu+=vecArancel[j].getTotalArancel();
                }

            }
            cout << "----------------------------" << endl;
            cout << "  SALDO DEUDOR: $" << acu << endl;               ///AHORA MUESTRO EL TOTAL ACUMULADO DE LOS ARANCELES INPAGOS
            cout << "===================================================" << endl;
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
    cout << "              TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita()<< endl << endl;

    for(int i=0;i<cantAranceles;i++){
        if(vecArancel[i].getIDTipoVisita()==ID && (compararFechas(aux,vecArancel[i].getFechaArancel())==1 || compararFechas(aux,vecArancel[i].getFechaArancel())==0)){
            cout << "FECHA: ";
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
