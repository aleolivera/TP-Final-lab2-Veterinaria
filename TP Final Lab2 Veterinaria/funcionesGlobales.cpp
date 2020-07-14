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
    if(cadena[0]=='\0'){
        return false;
    }
    while(cadena[i]!= '\0'){
        if((cadena[i]>0 && cadena[i]<65)||(cadena[i]>90 && cadena[i]<97)||(cadena[i]>122)){
            return false;
        }
        i++;
    }
    return true;
}
bool validarNombresConEspacios(const char* cadena){///True = 0-9, a-z o A-Z , false=cualquier otra cosa
    int i=0;
    if(cadena[0]=='\0'){
        return false;
    }
    while(cadena[i]!= '\0'){
        if((cadena[i]>0 && cadena[i]<32)||(cadena[i]>32 && cadena[i]<48)||(cadena[i]>57 && cadena[i]<65)||(cadena[i]>90 && cadena[i]<97)||(cadena[i]>122)){
            return false;
        }
        i++;
    }

    return true;
}
bool validarSiNo(const char* cadena){ /// True= Si o NO , false=cualquier otra cosa
    if(strcmp("Si",cadena)==0||strcmp("SI",cadena)==0||strcmp("sI",cadena)==0||strcmp("si",cadena)==0||strcmp("NO",cadena)==0||strcmp("No",cadena)==0||strcmp("nO",cadena)==0||strcmp("no",cadena)==0){
        return true;
    }
    return false;
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
void listarMascotasConDNICliente(int DNI){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if (p==NULL){
        cout<<endl;
        return;
    }
    bool estado=false;
    int con=0;
    cout <<"       SUS MASCOTAS: ";
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(reg.getDNICliente()==DNI&&reg.getVivo()){
            con++;
            estado=true;
            cout << reg.getNombreMascota();
            if(con%3==0){
                cout << endl;
            }
            else{
                cout << " | ";
            }
        }
    }
    if(!estado){
        cout << "SIN MASCOTA REGISTRADA" << endl;
    }
    cout << endl;
    fclose(p);
}
void listarClientesEnMascotas(int DNI){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if (p==NULL) return;
    cout <<"         LISTA DE MASCOTAS: ";
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(DNI==reg.getDNICliente()){
            cout << reg.getNombreMascota()<< " | ";
        }
    }
    fclose(p);
    return;
}
int preguntarSIoNO(){ ///DEVUELVE 1=si, 0=no, 2=otra cosa.
    char cadena[3];
    cin.getline(cadena,3);
    if(!validarSiNo(cadena)){
        return 2;
    }
    if(strcmp("Si",cadena)==0||strcmp("SI",cadena)==0||strcmp("sI",cadena)==0||strcmp("si",cadena)==0){
        return 1;
    }
    else{
        return 0;
    }
}

///BUSCAR
int buscarArancel(int ID){
    Arancel reg;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return -1;
    }
    int n;
    while(fread(&reg,sizeof (Arancel),1,p)==1){
        if(ID==reg.getIDArancel()){
            n=(ftell(p)/sizeof (Arancel));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}
int buscarHistoria(int ID){
    Historia reg;
    int n;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&reg,sizeof (Historia),1,p)==1){
        if(ID==reg.getIDHistoria()){
            n=(ftell(p)/sizeof (Historia));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}
int buscarTipoVisita(int ID){
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return -1;
    }
    int n;
    while(fread(&reg,sizeof (TipoVisita),1,p)==1){
        if(ID==reg.getIDTipoVisita()){
            n=(ftell(p)/sizeof (TipoVisita));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}
int buscarMascotaPorDNI(int DNI){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL) return -1;
    int n;
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(DNI==reg.getDNICliente()){
            n=(ftell(p)/sizeof (Mascotas));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}
int buscarMascotaPorDNIyNombre(int DNI,const char*nombre){
    Mascotas reg;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL) return -1;
    int n;
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        if(DNI==reg.getDNICliente()&&strcmp(reg.getNombreMascota(),nombre)==0){
            n=(ftell(p)/sizeof (Mascotas));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}
Cliente ultimoCliente(){ ///DEVUELVE EL REGISTRO ENTRO DEL ULTIMO CLIENTE
    Cliente aux;
    aux.setDNICliente(-1);
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
        return aux;
    fseek(p,-sizeof (Cliente),2);
    if(fread(&aux,sizeof (Cliente),1,p)==1){
        return aux;
    }
    fclose(p);
    return aux;
}
int buscarClientePorDNI(int DNI){
    Cliente reg;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL) return -1;
    int n;
    while(fread(&reg,sizeof (Cliente),1,p)==1){
        if(DNI==reg.getDNICliente()){
            n=(ftell(p)/sizeof (Cliente));
            fclose(p);
            return n-1;
        }
    }
    fclose(p);
    return -1;
}

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVOS
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
bool validarDNICliente(int DNI){///Busca el ID en ARCHIVOCLIENTES y devuelve true si lo encuentra
    Cliente aux;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL)
        return false;
    if(DNI<1||DNI>99999999){
        return false;
    }
    while(fread(&aux,sizeof (Cliente),1,p)==1)
    {
        if(DNI==aux.getDNICliente())
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
bool validarMascotaConCliente(const char*nombre,int DNI){
    Mascotas regMascotas;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&regMascotas,sizeof (Mascotas),1,p)==1){
        if(regMascotas.getDNICliente()==DNI&&strcmp(regMascotas.getNombreMascota(),nombre)==0){
            fclose(p);
            return true;
        }
    }
    return false;
}


///CLIENTES
bool listarVisitasClientes(){
    Historia*vecHistorias;
    char cadena[20];
    int DNI;
    bool encontrado=false;
    int cantHistorias=cantidadRegistrosHistorias();
    if(cantHistorias==-1){
        error("NO HAY REGISTROS DE HISTORIAS CLINICAS");
        return false;
    }
    vecHistorias=new Historia [cantHistorias];
    if(vecHistorias==NULL){
        errorAsignacionMemoria();
        return false;
    }
    if(!cargarVecHistorias(vecHistorias,cantHistorias)){
        errorCargarRegistros();
        delete(vecHistorias);
        return false;
    }

    cout << "LISTAR VISITAS" << endl << endl;
    cout << "       DNI DE CLIENTE: ";
    cin>> DNI;
    cin.ignore();
    if(validarDNICliente(DNI)){
        errorIngresoInvalido();
        return false;
    }
    listarMascotasConDNICliente(DNI);
    cout << endl;
    cout << "   NOMBRE DE MASCOTA: ";
    cin.getline(cadena,20);
    if(cadena[0]=='\0'){
        errorIngresoInvalido();
        return false;
    }

    for(int i=0;i<cantHistorias;i++){
        if(strcmp(cadena,vecHistorias[i].getNombreMascota())==0 && vecHistorias[i].getDNICliente()==DNI){
            cout << "FECHA VISITA: ";
            vecHistorias[i].getFechaVisita().mostrarFecha();
            cout << "      ID DE VISITA: " << vecHistorias[i].getIDHistoria()<< endl;
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

///INGRESOS PACIENTES
bool ingresarCliente(){
    Cliente regCliente;
    int DNI;
    char cadena[30];
    char cadena2[50];
    cout << "INGRESO DE CLIENTE" << endl << endl;
    regCliente.setIDCliente(asignarIDCliente());
    cout << "            ID: " << regCliente.getIDCliente() << endl;
    cout << "           DNI: ";
    cin >> DNI;
    if(validarDNICliente(DNI)){
        error("EL DNI YA HA SIDO INGRESADO, O EL INGRESO ESINVALIDO");
        return false;
    }
    regCliente.setDNICliente(DNI);

    cout << "        NOMBRE: ";
    cin.ignore();
    cin.getline(cadena,30);
    if (!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regCliente.setNombreCliente(cadena);

    cout << "      APELLIDO: ";
    cin.getline(cadena,30);
    if (!validarNombres(cadena)){
        errorCadenaInvalida(cadena,", NO ES UN INGRESO VALIDO");
        return false;
    }
    regCliente.setApellido(cadena);

    cout << "     DOMICILIO: ";
    cin.getline(cadena2,50);
    if (!validarNombresConEspacios(cadena2)){
        errorCadenaInvalida(cadena2,"ES UN INGRESO INVALIDO");
        return false;
    }
    regCliente.setDomicilio(cadena2);

    cout << "      TELEFONO: ";
    cin>>DNI;
    if(DNI<0){
        errorEnteroInvalido(DNI,", NO ES UN TELEFONO VALIDO");
        return false;
    }
    regCliente.setTelefono(DNI);

    cout << "         @MAIL: ";
    cin.ignore();
    cin.getline(cadena,30);
    if(validarMail(cadena)!=0){
        errorCadenaInvalida(cadena,"ES UN CORREO INVALIDO");
        return false;
    }
    regCliente.setEmail(cadena);
    regCliente.setSaldo(0);
    cout <<"-------------------------------------" << endl;

    if(!regCliente.guardarCliente()){
        error("NO SE PUDO GUARDAR EL ARCHIVO.");
        return false;
    }
    return true;
}
bool ingresarMascota(){
    int valor,validar;
//    int dia,mes,anio;
    char cadena [20];
    char cadena3 [3];
    char caracter;

    Mascotas regMascota;
    Cliente regCliente;
    regCliente=ultimoCliente();
    if(regCliente.getDNICliente()==-1){
        error("NO SE ENCONTRO ESE DNI");
        return false;
    }
    regMascota.setIDMascota(asignarIDMascota());
    regMascota.setDNICliente(regCliente.getDNICliente());
    cout << "INGRESO DE MASCOTA" << endl<< endl;
    cout << "         ID MASCOTA: " << regMascota.getIDmascota();
    cout << "                DNI: " << regMascota.getDNICliente();
    cout << endl;
    cout << "             NOMBRE: ";
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN NOMBRE VALIDO PARA UNA MASCOTA");
        return false;
    }
    regMascota.setNombreMascota(cadena);

    cout << "       EDAD (ANIOS): ";
    cin>> valor;
    if(valor>30||valor<0){
        errorEnteroInvalido(valor,"NO ES UN INGRESO VALIDO.");;
        return false;
    }
    regMascota.setAnios(valor);

    cout << "CASTRADO  'SI'|'NO': ";
    cin.ignore();
    cin.getline(cadena3,3);
    if(!validarSiNo(cadena3)){
        errorCadenaInvalida(cadena3,"NO ES UN INGRESO VALIDO");
        return false;
    }
    if(strcmp("Si",cadena3)==0||strcmp("SI",cadena3)==0||strcmp("sI",cadena3)==0||strcmp("si",cadena3)==0){
        regMascota.setCastrado(true);
    }
    else{
        regMascota.setCastrado(false);
    }

    cout << "VACUNADO  'SI'|'NO': ";
    cin.getline(cadena3,3);
    if(!validarSiNo(cadena3)){
        errorCadenaInvalida(cadena3,"NO ES UN INGRESO VALIDO");
    }
    if(strcmp("Si",cadena3)==0||strcmp("SI",cadena3)==0||strcmp("sI",cadena3)==0||strcmp("si",cadena3)==0){
        regMascota.setVacunado(true);
    }
    else{
        regMascota.setVacunado(false);
    }
    cout << "            ESPECIE: ";
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regMascota.setEspecie(cadena);

    cout << "               RAZA: ";
    cin.getline(cadena,20);
    if(!validarNombresConEspacios(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regMascota.setRaza(cadena);

    cout << "Macho='M'| Hembra='H': ";
    cin>> caracter;
    if(caracter=='H'||caracter=='h'){
        regMascota.setSexo(caracter);
    }
    else if(caracter=='M'||caracter!='m'){
        regMascota.setSexo(caracter);
    }
    else{
        errorIngresoInvalido();
        return false;
    }

//    cout << "   FECHA VACUNACION " <<endl;
//    cout << "                DIA: ";
//    cin>> dia;
//    cout << "                MES: ";
//    cin>> mes;
//    cout << "               ANIO: ";
//    cin>> anio;
//    regMascota.getFechaVacuna().setFecha(dia,mes,anio);
//    if(!validarFecha(dia,mes,anio)||compararFechas(regMascota.getFechaVacuna(),obtenerFechaActual())==2){
//        error("LA FECHA INGRESADA NO ES VALIDA.");
//        return false;
//    }
    regMascota.getFechaVacuna().setFecha(1,1,1); ///BORRAR AL DESCOMENTAR
    regMascota.setVivo(true);

    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    cin.ignore();
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regMascota.guardarMascota()){
            error("NO SE PUDO GUARDAR LA MASCOTA");
            return false;
        }
    }
    else if(validar==0){
        volviendoMenu();
        return false;
    }
    else{
        errorIngresoInvalido();
        return false;
    }
    return true;
}
bool ingresarSoloMascota(){
    int pos,valor,validar;
//    int dia,mes,anio;
    char cadena [20];
    char cadena3 [3];
    char caracter;

    Mascotas regMascota;
    Cliente regCliente;

    regMascota.setIDMascota(asignarIDMascota());
    regMascota.setDNICliente(regCliente.getDNICliente());
    cout << "INGRESO DE MASCOTA" << endl<< endl;
    cout << "        INGRESE DNI: ";
    cin >> valor;
    pos=buscarClientePorDNI(valor);
    if(pos==-1){
        errorEnteroInvalido(valor,",NO SE ENCUENTRA EN EL ARCHIVO");
        return false;
    }
    regCliente.leerCliente(pos);
    regMascota.setDNICliente(regCliente.getDNICliente());
    cout << " NOMBRE DEL CLIENTE: " << regCliente.getNombreCliente() << endl;
    cout << "           APELLIDO: " << regCliente.getApellido()<< endl;
    listarMascotasConDNICliente(valor);
    cout << "---------------------------------------" << endl;
    cout << "         ID MASCOTA: " << regMascota.getIDmascota()<< endl;
    cout << "             NOMBRE: ";
    cin.ignore();
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN NOMBRE VALIDO PARA UNA MASCOTA");
        return false;
    }
    regMascota.setNombreMascota(cadena);

    cout << "       EDAD (ANIOS): ";
    cin>> valor;
    if(valor>30||valor<0){
        errorEnteroInvalido(valor,"NO ES UN INGRESO VALIDO.");
        return false;
    }
    regMascota.setAnios(valor);

    cout << "CASTRADO  'SI'|'NO': ";
    cin.ignore();
    cin.getline(cadena3,3);
    if(!validarSiNo(cadena3)){
        errorCadenaInvalida(cadena3,"NO ES UN INGRESO VALIDO");
        return false;
    }
    if(strcmp("Si",cadena3)==0||strcmp("SI",cadena3)==0||strcmp("sI",cadena3)==0||strcmp("si",cadena3)==0){
        regMascota.setCastrado(true);
    }
    else{
        regMascota.setCastrado(false);
    }

    cout << "VACUNADO  'SI'|'NO': ";
    cin.getline(cadena3,3);
    if(!validarSiNo(cadena3)){
        errorCadenaInvalida(cadena3,"NO ES UN INGRESO VALIDO");
    }
    if(strcmp("Si",cadena3)==0||strcmp("SI",cadena3)==0||strcmp("sI",cadena3)==0||strcmp("si",cadena3)==0){
        regMascota.setVacunado(true);
    }
    else{
        regMascota.setVacunado(false);
    }
    cout << "            ESPECIE: ";
    cin.getline(cadena,20);
    if(!validarNombres(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regMascota.setEspecie(cadena);

    cout << "               RAZA: ";
    cin.getline(cadena,20);
    if(!validarNombresConEspacios(cadena)){
        errorCadenaInvalida(cadena,"NO ES UN INGRESO VALIDO");
        return false;
    }
    regMascota.setRaza(cadena);

    cout << "Macho='M'| Hembra='H': ";
    cin>> caracter;
    if(caracter=='H'||caracter=='h'){
        regMascota.setSexo(caracter);
    }
    else if(caracter=='M'||caracter!='m'){
        regMascota.setSexo(caracter);
    }
    else{
        errorIngresoInvalido();
        return false;
    }

//    cout << "   FECHA VACUNACION " <<endl;
//    cout << "                DIA: ";
//    cin>> dia;
//    cout << "                MES: ";
//    cin>> mes;
//    cout << "               ANIO: ";
//    cin>> anio;
//    regMascota.getFechaVacuna().setFecha(dia,mes,anio);
//    if(!validarFecha(dia,mes,anio)||compararFechas(regMascota.getFechaVacuna(),obtenerFechaActual())==2){
//        error("LA FECHA INGRESADA NO ES VALIDA.");
//        return false;
//    }
    regMascota.getFechaVacuna().setFecha(1,1,1);
    regMascota.setVivo(true);

    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    cin.ignore();
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regMascota.guardarMascota()){
            error("NO SE PUDO GUARDAR LA MASCOTA");
            return false;
        }
    }
    else if(validar==0){
        volviendoMenu();
        return false;
    }
    else{
        errorIngresoInvalido();
        return false;
    }
    return true;
}
bool AgregarPacienteYCliente(){
    limpiar();
    cout << "INGRESO DE CLIENTE Y PACIENTE"<< endl<< endl;
    if(!ingresarCliente()){
        error("NO SE PUDO CARGAR EL CLIENTE");
        return false;
    }
    if(!ingresarMascota()){
        error("NO SE PUDO INGRESAR LA MASCOTA");
        return false;
    }
    return true;
}


///CONFIGURACION
///Para resolver las consignas del MENU CONFIGURACION
bool restaurarHistorias(){
    Historia reg;
    FILE*pArchivo=fopen(ARCHIVOHISTORIASBKP,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOHISTORIAS,"wb");
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
bool restaurarClientes(){
    Cliente reg;
    FILE*pArchivo=fopen(ARCHIVOCLIENTESBKP,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOCLIENTES,"wb");
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
bool restaurarMascotas(){
    Mascotas reg;
    FILE*pArchivo=fopen(ARCHIVOMASCOTASBKP,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOMASCOTAS,"wb");
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
bool restaurarAranceles(){
    Arancel reg;
    FILE*pArchivo=fopen(ARCHIVOARANCELESBKP,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOARANCELES,"wb");
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
bool restaurarVisita(){
    Arancel reg;
    FILE*pArchivo=fopen(ARCHIVOTIPOVISITABKP,"rb");
    if(pArchivo==NULL) return false;

    FILE*pBackup=fopen(ARCHIVOTIPOVISITA,"wb");
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
bool restaurarSistema(){
    int validar;
    cout << "RESTAURAR SISTEMA"<< endl <<endl;
    cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!restaurarClientes()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'CLIENTES'");
            return false;
        }
        if(!restaurarMascotas()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'MASCOTAS'");
            return false;
        }
        if(!restaurarHistorias()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'HISTORIAS'");
            return false;
        }
        if(!restaurarVisita()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'TIPOVISITA'");
            return false;
        }
        if(!restaurarAranceles()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'ARANCELES'");
            return false;
        }
    }
    else{
        volviendoMenu();
        return false;
    }
    return true;
}
bool realizarBKP(){
    int validar;
    cout << "BACKUP DE CLIENTES."<< endl <<endl;
    cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!backupClientes()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'CLIENTES'");
            return false;
        }
        if(!backupMascotas()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'MASCOTAS'");
            return false;
        }
        if(!backupHistorias()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'HISTORIAS'");
            return false;
        }
        if(!backupTipoVisita()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'TIPOVISITA'");
            return false;
        }
        if(!backupAranceles()){
            error("ERROR EN EL GUARDADO DEL REGISTRO 'ARANCELES'");
            return false;
        }
    }
    else{
        volviendoMenu();
        return false;
    }
    return true;
}
