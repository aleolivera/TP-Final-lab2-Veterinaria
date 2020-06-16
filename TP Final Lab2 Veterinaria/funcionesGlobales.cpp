#include "funcionesGlobales.h"
#include <ctime>

///VALIDACIONES
int compararFechas(Fecha fechaUno, Fecha fechaDos){ ///Devuelve 0 si son iguales, 1 si la primera es anterior a la segunda, o 2 si la segunda es anterior a la primera

    if((fechaUno.getAnio()-fechaDos.getAnio())<0){
        return 1;
    }
    else if((fechaUno.getAnio()-fechaDos.getAnio())>0){
        return 2;
    }
    if((fechaUno.getMes()-fechaDos.getMes())<0){
        return 1;
    }
    else if((fechaUno.getMes()-fechaDos.getMes())>0){
        return 2;
    }
    if((fechaUno.getDia()-fechaDos.getDia())<0){
        return 1;
    }
    else if((fechaUno.getDia()-fechaDos.getDia())>0){
        return 2;
    }
    return 0;

}
Fecha obtenerFechaActual(){         ///LLamas a la funcion  te devuelve un objeto de clase Fecha con dia mes y anio
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
        if ((anio%400==0) || (!anio%100==0 && anio%4==0)){
        if(dia>0 && dia<30){
            return true;
        }
        else if (dia>0 && dia<29){
                return true;
            }
    }
    return false;
}
bool validarBisiesto(int dia, int mes, int anio){
    Fecha aux;
    aux.setFechaActual();
    if (((anio>aux.getAnio())||(anio<=aux.getAnio()&&mes>aux.getMes())||(anio<=aux.getAnio()&&mes<=aux.getMes()&&dia>aux.getDia())) || (mes>12)){
        return true;
    }
    return false;
}
bool validarFecha(int dia,int mes,int anio){        ///Valida que la fecha se ingrese bien usando "validarFebrero()" y "validarFebrero"
    if(validarBisiesto(dia,mes,anio)){
        return false;
    }
    if (mes==2 && !validarFebrero(dia,anio)){
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
    while(cadena[i]!='\0'){
        if(cadena[i]==caracter){
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
    while (cadena[i]!='\0'){
        if(cadena[i]==caracter && cadena[i+1]==caracter){
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
    while(cadena[i]!='\0'){
        if(cadena[i]<'.' || (cadena[i]>'.' && cadena[i]<'0') || (cadena[i]>'9' && cadena[i]<'@') || (cadena[i]>'Z' && cadena[i]<'_') || (cadena[i]>'_' && cadena[i]<'a') || cadena[i]> 'z'){
            con++;
        }
        i++;
    }
    return con;
}
int validarMail(const char* cadena){    ///Usa la 5 funciones dde arriba para validar el mail como en el TP LARA
    int espacios;
    if(contarSimbolos(cadena)>0){
        return 5;
    }
    espacios=buscarCaracter(cadena,' ');
    if (espacios>0){
        return 4;
    }
    if(cadena[0]=='.'||cadena[0]=='@')
    {
        return 1;
    }
    if(buscarCaracter(cadena,'@')!=1||ultimoCaracteresArroba(cadena)){
        return 2;
    }
    if(buscarCaracter(cadena,'.')<1||buscarRepContiguos(cadena,'.')||buscarUltCaracter(cadena)=='.'){
        return 3;
    }
    return 0;
}
bool validarTipoDePago(char tipoPago){
    if(!(tipoPago=='e'||tipoPago=='E'|| tipoPago=='t'|| tipoPago=='T'|| tipoPago=='d'|| tipoPago=='D'|| tipoPago=='c'|| tipoPago=='C')){
       return true;
    }
    return false;
}
bool validarNombres(const char* cadena){    ///True = a-z o A-Z , false=cualquier otra cosa
    int i;
    while(cadena[i]!= '\0'){
        if((cadena[i]>0 && cadena[i]<65)||(cadena[i]>90 && cadena[i]<97)||(cadena[i]>122)) return false;
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

///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVOS
int asignarIDHistoria(){    ///Le pone solo el ID de manera secuencial
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    if(fread(&reg,sizeof (Historia),1,p)==0){ ///tal vez deberia preguntar si !=1
        fclose(p);
        return 1;
        }
    else{
        fseek(p,-sizeof (Historia),2);
        fread(&reg,sizeof (Historia),1,p);
        fclose(p);
        return reg.getIDHistoria()+1;
    }
}
int asignarIDarancel(){     ///Le pone solo el ID de manera secuencial
    Arancel reg;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return -1;
    }
    if(fread(&reg,sizeof (Arancel),1,p)==0){
        fclose(p);
        return 1;
        }
    else{
        fseek(p,sizeof (Arancel),2);
        fread(&reg,-sizeof (Arancel),1,p);
        fclose(p);
        return reg.getIDArancel()+1;
    }
}
int asignarIDTipoVisita(){     ///Le pone solo el ID de manera secuencial
    TipoVisita reg;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return -1;
    }
    if(fread(&reg,sizeof (TipoVisita),1,p)==0){
        fclose(p);
        return 1;
    }
    else{
        fseek(p,-sizeof (TipoVisita),2);
        fread(&reg,sizeof (TipoVisita),1,p);
        fclose(p);
        return reg.getIDTipoVisita()+1;
    }
}
bool validarIDcliente(int ID){ ///Busca el ID en ARCHIVOCLIENTES y devuelve true si lo encuentra
    Cliente aux;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL) return false;
    while(fread(&aux,sizeof (Cliente),1,p)==1){
        if(ID==aux.getIDCliente()){
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
    if(p==NULL) return false;
    while(fread(&aux,sizeof (Arancel),1,p)==1){
        if(ID==aux.getIDArancel()){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool validarIDTipoVisita(int ID){
    TipoVisita aux;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL) return false;
    while(fread(&aux,sizeof (TipoVisita),1,p)==1){
        if(ID==aux.getIDTipoVisita()){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
int cantidadRegistrosHistorias(){   ///Devuelve la cantidad de registros en ARCHIVOHISTORIAS
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Historia);
}
int cantidadRegistrosClientes(){    ///Devuelve la cantidad de registros en ARCHIVOCLIENTES
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Cliente);
}
int cantidadRegistrosMascotas(){    ///Devuelve la cantidad de registros en ARCHIVOMASCOTAS
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Mascotas);
}
int cantidadRegistrosArancel(){    ///Devuelve la cantidad de registros en ARCHIVOARANCELES
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Arancel);
}
int cantidadRegistrosTipoVisita(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (TipoVisita);
}

bool cargarVecHistorias(Historia*vec,int tam){ ///Le mandas un vector de clase HISTORIA y su tamanio y te lo carga todo
    Historia reg;
    int i=0;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Historia),1,p)==1 && i<tam){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecClientes(Cliente*vec,int tam){    ///Le mandas un vector de clase CLIENTES y su tamanio y te lo carga todo
    Cliente reg;
    int i=0;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Cliente),1,p)==1 && i<tam){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecMascotas(Mascotas*vec,int tam){   ///Le mandas un vector de clase MASCOTAS y su tamanio y te lo carga todo
    Mascotas reg;
    int i=0;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Mascotas),1,p)==1 && i<tam){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecArancel(Arancel*vec,int tam){   ///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
    Arancel reg;
    int i=0;
    FILE*p=fopen(ARCHIVOARANCELES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Arancel),1,p)==1 && i<tam){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecTipoVisita(TipoVisita*vec,int tam){   ///Le mandas un vector de clase ARANCEL y su tamanio y te lo carga todo
    TipoVisita reg;
    int i=0;
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (TipoVisita),1,p)==1 && i<tam){
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

}


///MASCOTAS
///Para resolver las consignas del MENU MASCOTAS
void menuMascotas(){


}
void menuIngresoPaciente(){

}


///HISTORIAS
///Para resolver las consignas del MENU HISTORIA
bool ingresoHistoria(){
    Historia reg;
    int dia,mes,anio,valor;
    char cadena[20];
    reg.setIDHistoria(asignarIDHistoria());     ///Aca se asigna solo ID de manera secuencial
    reg.setFechaIngreso();                      ///Aca se asigna automaticamente la fecha del HOY
    ///EL ATRIBUTO 'Fecha fechaModificacion' LO ASIGNA EL CONSTRUCTOR EN ESTA ETAPA
    cout << "INGRESO DE HISTORIAS CLINICAS" << endl << endl;
    cout << "FECHA DE LA VISITA(DD/MM/AA):"<< endl;
    cin >> dia >> mes >> anio;
    if (!validarFecha(dia,mes,anio)){
        return false;
    }
    reg.setFechaVisita(dia,mes,anio);       ///Aca de ingresa la fecha de visita tras validarla

    cout << "ID DEL CLIENTE: ";
    cin >> valor;
    if(validarIDcliente(valor)){
        return false;
    }
    reg.setIDCliente(valor);                ///Aca se ingresa el ID del cliente en el registro tras validarlo en disco

    cout << endl << "NOMBRE DE LA MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    reg.setNombreMascota(cadena);           ///Aca se ingresa el nombre de la mascota

    cout << "ANAMNESIS: ";
    cin.ignore();
    reg.setAnamnesis();                     ///Aca la Anamnesis (detalles de la visita)

    cout << "REQUIERE VOLVER A CONTROL?: ";
    cin.ignore();
    cin.getline(cadena,2);
    if(strcmp(cadena,"SI")||strcmp(cadena,"si")){
        reg.setControl(true);                ///al ingresar SI o NO se cambia el estado del booleano
    }
    else if(strcmp(cadena,"NO")||strcmp(cadena,"no")){
        reg.setControl(false);
    }
    else{
        cout << "'" <<cadena << "' " << " NO ES UN INGRESO VALIDO." << endl;
        cin.get();
        return false;
    }
    if(reg.getControl()){
        cout << "INGRESE LA FECHA DEL CONTROL(DD/MM/AA):"<< endl;
        cin >> dia >> mes >> anio;
        if (!validarFecha(dia,mes,anio)){ ///Se valida que no se ingrese 42/9/2500 o 29/2 si no es anio biciesto
                return false;
            }
        reg.setFechaControl(dia,mes,anio); ///Se valida que la fecha del control no sea en le pasado
        if(compararFechas(reg.getFechaControl(),obtenerFechaActual())==2){
            return false;
        }
    }
    ///EL CAMPO QUE RESTA ES 'int IDArancel' QUE SE CARGA CON EL ARANCEL
    if(!reg.guardarHistoria()){
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
    if(pos==-1){
        return false;
    }
    reg.leerHistoria(pos);          ///se busca la posicion del registro por ID
    reg.mostrarFechaModificacion(); ///Despues se muestran los registros de a uno
    reg.mostrarNombreMascota();
    reg.mostrarAnamnesis();
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
    if(vecHistoria==NULL){
        return false;
    }
    vecClientes=new Cliente [cantidadRegistrosClientes()];
    if(vecHistoria==NULL){
        free(vecHistoria);
        return false;
    }
    char nombreMascota[20];
    char apellidoCliente[30];
    cin.ignore();                       ///PIDO nombreMascota (clase mascota)
    cin.getline(nombreMascota,20);
    cin.ignore();                       ///PIDO apellido (clase cliente)
    cin.getline(apellidoCliente,30);

    tam1=cantidadRegistrosHistorias();
    tam2=cantidadRegistrosMascotas();


    ///CARGO LOS VECTORES
    if(!cargarVecHistorias(vecHistoria,tam1)||(cargarVecClientes(vecClientes,tam2))){
        free(vecClientes);
        free(vecHistoria);
        return false;
    }
    for(int i=0;i<tam1;i++){           ///El problema es que puede haber mas de un cliente con el mismo apellido
        vecHistoria[i].getNombreMascota(aux);
        if(strcmp(nombreMascota,aux)==0){         ///Recorro el vecHistoria hasta encontrar el nombre de mascota ingresado
            for(int j=0;j<tam2;j++){
                vecClientes[j].getApellido(aux);    ///ahora vuuelvo a recorrer pero el vecCliente hasta que coincida del apellido ingresado con el del REG
                if((vecHistoria[i].getIDCliente() == vecClientes[j].getIDCliente())&&(strcmp(apellidoCliente,aux))){
                    ID=vecHistoria[i].getIDCliente();   ///al poder tener varios clientes con el mismo apellido, asi se puede obtener el ID correcto
                }
            }
        }
    }
    if(ID==-1) return false;

    cout << "NOMBRE DE MASCOTA: " << nombreMascota << endl;
    cout << "APELLIDO DEL CLIENTE: " << apellidoCliente << endl;
    for (int i=0;i<tam1;i++){
        if(vecHistoria[i].getIDCliente()==ID){  ///con el ID obtenido mostramos los atributos que corresponden
            vecHistoria[i].mostrarIDHistoria();
            vecHistoria[i].mostrarFechaVisita();
            vecHistoria[i].mostrarAnamnesis();
            cout << endl;
            cout << "      ---------------      " << endl;
        }
    }
    free(vecHistoria);      ///tal vez necesite un DESTRUCTOR
    free(vecClientes);
    return true;
}
bool modificarHistoria(){
    Historia reg;
    int ID,dia,mes,anio;
    int pos;
    char cad[3];
    cout << "MODIFICAR HISTORIA: ";
    cout << "ID ENTRADA DE HISTORIA: ";
    cin>> ID;
    cout <<endl;
    pos=reg.buscarHistoria(ID);         ///PIDO EL ID, abro el archivo, busco esa entrada en particular y la leo
    if(pos==-1) return false;
    reg.leerHistoria(pos);

    cout << "ANAMNESIS: ";              ///Despues se editan los Atributos de a uno.
    reg.setAnamnesis();
    cout << "REQUIERE VISITA DE CONTROL?"<< endl;
    cout << "INGRESE: 'SI' o 'NO': ";
    cin >> cad;
    if(strcmp(cad,"SI")==0||strcmp(cad,"si")==0){
        reg.setControl(true);
        cout << "FECHA DE CONTROL (DD/MM/AA): " << endl;
        cin >> dia;
        cin >> mes;
        cin >> anio;
        if(!validarFecha(dia,mes,anio)){
        return false;
        }
        reg.setFechaControl(dia,mes,anio);
    }
    else if(strcmp(cad,"NO")==0||strcmp(cad,"no")==0){
        reg.setControl(false);
        reg.setFechaControl(0,0,0);
    }
    reg.guardarHistoria();
    return true;
}
bool controlesPendientes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    if(vecHistoria==NULL){
        return false;
    }
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL){
        free(vecHistoria);
        return false;
    }

    if(!cargarVecHistorias(vecHistoria,cantHistorias)||(cargarVecClientes(vecCliente,cantClientes))){
        free(vecCliente);
        free(vecHistoria);
        return false;
    }

    for(int i=0;i<cantHistorias;i++){   ///Recorro el vecHistorias para encontrar las "control=true"
        if(vecHistoria[i].getControl()&&compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==1){
            vecHistoria[i].mostrarNombreMascota();
            cout << endl;
            vecHistoria[i].mostrarFechaControl();
            cout << endl;
            for(int j=0;j<cantClientes;j++){        ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
                if(vecHistoria[i].getIDCliente()==vecCliente[i].getIDCliente()){
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
    system("pause");
    free(vecHistoria);
    free(vecCliente);
    return true;
}
bool controlesAusentes(){
    Historia*vecHistoria;
    Cliente*vecCliente;
    int cantHistorias=cantidadRegistrosHistorias();
    int cantClientes=cantidadRegistrosClientes();

    vecHistoria=new Historia [cantHistorias]; ///CARGO LOS VECTORES CON TODOS LOS REG HISTORIAS
    if(vecHistoria==NULL){
        return false;
    }
    vecCliente=new Cliente[cantClientes];///CARGO LOS VECTORES CON TODOS LOS REG CLIENTES
    if(vecCliente==NULL){
        free(vecHistoria);
        return false;
    }
    if(!cargarVecHistorias(vecHistoria,cantHistorias)||(cargarVecClientes(vecCliente,cantClientes))){
        free(vecCliente);
        free(vecHistoria);
        return false;
    }

    for(int i=0;i<cantHistorias;i++){   ///Recorro el vecHistorias para encontrar las "control=true" y que la fecha de contro no haya pasado
        if(vecHistoria[i].getControl() && compararFechas(vecHistoria[i].getFechaControl(),obtenerFechaActual())==2){
            vecHistoria[i].mostrarNombreMascota();
            cout << endl;
            vecHistoria[i].mostrarFechaControl();
            cout << endl;
            for(int j=0;j<cantClientes;j++){        ///al encontrar uno, muestro el nombre de mascota, fecha de control en el mismo reg.
                if(vecHistoria[i].getIDCliente()==vecCliente[i].getIDCliente()){
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
    system("pause");
    free(vecHistoria);
    free(vecCliente);
    return true;
    return true;
}
void menuHistorias(){
    limpiar();
    pantallaHistorias();
    int op;
    cin >>op;
    limpiar();
    switch(op){
        case 1:{
            if(!ingresoHistoria()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }

        }break;
        case 2:{
            if(!mostrarEntradaHistoria()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }

        }break;
        case 3:{
            if(!mostrarHistoria()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
        }break;
        case 4:{
            if(!modificarHistoria()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
        }break;
        case 5:{
            if(!controlesPendientes()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }

        }break;
        case 6:{
            if(!controlesAusentes()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
        }break;
        case 0:{
        }break;
    }
}

///ARANCELES
///Para resolver las consignas del MENU ARANCELES
bool nuevoArancel(){  ///ME QUEDA RESOLVER EL TEMA DE DEUDORES
    Arancel regArancel;
    TipoVisita regTipoVisita;
    char tipoPago;
    int valor,pos;
    float total;
    regArancel.setFechaIngreso();
    regArancel.setIDArancel(asignarIDarancel());
    cout <<"INGRESO DE NUEVO ARANCEL." << endl << endl;
    cout << "FECHA DE ARANCEL: ";
    regArancel.mostrarFechaArancel();
    cout << endl << "ID ARANCEL: Nº ";
    regArancel.mostrarIDArancel();
    cout<< "ID DE HISTORIA: ";
    cin >> valor;
    ///ACA DEBERIA VALIDAR QUE ESTE EN EL DISCO
    regArancel.setIDHistoria(valor);
    cout << "TIPO DE VISITA: ";
    cin >> valor;
    ///ACA DEBERIA VALIDAR QUE ESTE EN EL DISCO
    regArancel.setIDTipoVisita(valor);

    pos=regTipoVisita.buscarTipoVisita(valor);
    if(pos==-1) return false;
    regTipoVisita.leerTipoVisita(pos);
    total=regTipoVisita.getImporte();
    ///TENDRIA QUE VALIDAR EL TOTAL
    regArancel.setTotalArancel(total);
    cout <<"TOTAL DEL ARANCEL: " << endl;
    regArancel.mostrarTotalArancel();


    cout <<"E: EFECTIVO / T:TARJ CREDITO / D: DEBITO / C: A CUENTA" << endl;
    cout <<"TIPO DE PAGO: " << endl;
    cin>> tipoPago;
    if(validarTipoDePago(tipoPago)){
       return false;
    }
    regArancel.setTipoPago(tipoPago);

    if(tipoPago=='c'||tipoPago=='C'){
        regArancel.setAbonado(false);
    }
    else{
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
    cout << "ARANCELES DEL DIA:";
    fechaDeHoy.mostrarFecha();
    cout << endl<< endl;
    int cantAranceles=cantidadRegistrosArancel();
    vec=new Arancel[cantAranceles];
    if(vec==NULL) return false;
    cargarVecArancel(vec,cantAranceles);
    for(int i=0;i<cantAranceles;i++){
        if(compararFechas(vec[i].getFechaArancel(),obtenerFechaActual())==0){
            cout<<"ID DE ARANCEL : ";
            vec[i].mostrarIDArancel();
            cout<< endl;
            cout<<"TIPO DE VISITA: ";
            vec[i].mostrarIDTipoVisita();
            cout<< endl;
            cout<<"TIPO DE PAGO  : ";
            vec[i].mostrarTipoPago();
            cout<< endl;
            cout<<"         TOTAL: ";
            vec[i].mostrarTotalArancel();
            cout<< endl<< endl;
        }
    }
    free(vec);
    return true;
}
bool modificarArancel(){
    limpiar();
    Arancel reg;
    int ID,pos;
    char tipoDePago;
    cout << "MODIFICAR ARANCEL."<< endl<< endl;
    cout << "INGRESE ID DE ARANCEL:"<< endl;
    cin >> ID;
    pos=reg.buscarArancel(ID);
    if (pos==-1) return false;
    reg.leerArancel(pos);
    cout << "  TIPO DE PAGO: ";
    cin >> tipoDePago;
    if(!validarTipoDePago(tipoDePago)) return false;
    reg.setTipoPago(tipoDePago);
    cout << endl;
    return true;
}
bool mostrarArancelesPorVisita(){
    Arancel reg;
    int ID,pos;
    cin >> ID;
    pos=reg.buscarArancel(ID);
    if (pos==-1) return false;
    reg.leerArancel(pos);
    cout << "TIPO DE VISITA: ";
    reg.mostrarIDTipoVisita();
    cout << endl;
    cout << "    ID ARANCEL: ";
    reg.mostrarIDArancel();
    cout << endl;
    cout << " TOTAL ARANDEL: ";
    reg.mostrarTotalArancel();
    cout << endl;
    cout << "  TIPO DE PAGO: ";
    reg.mostrarTipoPago();
    cout << endl;
    cout << "   ID HISTORIA: ";
    reg.mostrarIDHistoria();
    cout << endl<< endl;
    return true;
}

void menuAranceles(){
    limpiar();
    pantallaAranceles();
    int op;
    cin >>op;
    limpiar();
    switch(op){
        case 1:
            if(!nuevoArancel()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
            break;
        case 2:
            if(!mostrarArancelesDelDia()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
            break;
        case 3:
            if(!modificarArancel()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
            break;
        case 4:
            if(!mostrarArancelesPorVisita()){
                limpiar();
                cout << "ERROR" << endl;
                cin.get();
            }
            break;
        case 0:

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
    if(vec==NULL) return false;
    if(!cargarVecTipoVisita(vec,cantTipoVisita)) return false;
    for(int i=0;i<cantTipoVisita;i++){
        cout << "            ID: ";
        vec[i].mostrarIDTipoVisita();
        cout << endl;
        cout << "TIPO DE VISITA: ";
        vec[i].mostrarNombreTipoVisita();
        cout << endl;
        cout << "       IMPORTE: ";
        vec[i].mostrarImporte();
        cout <<"-." << endl;
        cout << "     HONORARIO: ";
        vec[i].mostrarPorcentajeHonorario();
        cout << "%."<< endl<< endl;
    }
    free(vec);
    return true;
}
bool modificarImportes(){
    limpiar();
    TipoVisita reg;
    int ID, pos;
    float importe;
    cout << "MODIFICAR IMPORTES" <<endl << endl;
    cout << "          INGRESE ID: ";
    cin >> ID;                              ///PIDO EL ID,
    pos=reg.buscarTipoVisita(ID);           ///BUSCO ESE REGISTRO EN ARCHIVOTIPOVISITAS
    if (pos==-1) return false;              ///VALIDO LA POSICION
    reg.leerTipoVisita(pos);                ///LEO REGISTRO

    cout << "             IMPORTE:" << endl;///MODIFICO LOS ATRIBUTOS Y LOS VALIDO
    cin >> importe;
    if(importe <0) return false;
    reg.setImporte(importe);

    cout << "PORCENTAJE HONORARIO:" << endl;
    cin >> ID;
    if(ID<1||ID>100) return false;
    reg.setPorcentajeHonorario(ID);

    reg.guardarTipoVisita();                ///GUARDO EL REGISTRO
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
    if(validarIDTipoVisita(ID)) return false;
    cout << "                  ID: ";
    reg.mostrarIDTipoVisita();
    cout << endl;
    cout << "              NOMBRE:";
    cin.ignore();
    cin.getline(cadena,15);                    ///PIDO LOS DEMAS ATRIBUTOS Y LOS VALIDO
    if (!validarNombres(cadena)){
        return false;
    }
    reg.setNombreTipoVisita(cadena);

    cout << "             IMPORTE:" << endl;
    cin >> importe;
    if(importe <0) return false;
    reg.setImporte(importe);

    cout << "PORCENTAJE HONORARIO:" << endl;
    cin >> ID;
    if(ID<1||ID>100) return false;
    reg.setPorcentajeHonorario(ID);

    reg.guardarTipoVisita();                ///GUARDO EL REGISTRO
    return true;
}
bool listarPorFecha(){
    limpiar();
    Arancel*vecArancel;
    Fecha inicio;
    Fecha fin;
    int d, m, a ,cantAranceles;
    float acu=0;

    cout << " LISTADO DE VISITAS POR FECHA" <<endl << endl;
    cout << " FECHA DE INICIO (DD/MM/AA): " << endl;        ///PIDO LAS FECHAS DE INICIO Y FIN DE BUSQUEDA
    cin >> d>> m >>a;
    inicio.setFecha(d,m,a);
    if(validarFecha(d,m,a) && compararFechas(inicio,obtenerFechaActual())>1) return false;
    cout << "     FECHA DE FIN (DD/MM/AA): " << endl;
    cin >> d>> m >>a;
    inicio.setFecha(d,m,a);
    if(validarFecha(d,m,a) && compararFechas(fin,obtenerFechaActual())<2) return false;

    cantAranceles=cantidadRegistrosArancel();
    vecArancel= new Arancel[cantAranceles];
    if(vecArancel==NULL) return false;

    if(!(cargarVecArancel(vecArancel,cantAranceles))) return false;

    for(int i=0;i<cantAranceles;i++){
        if((compararFechas(inicio,vecArancel[i].getFechaArancel())==1) && (compararFechas(vecArancel[i].getFechaArancel(),fin)==1)){
            vecArancel[i].mostrarFechaArancel();
            cout << endl;
            cout << "  TIPO DE VISITA: ";
            vecArancel[i].mostrarIDTipoVisita();
            cout << endl;
            cout << "         IMPORTE: $";
            vecArancel[i].mostrarTotalArancel();
            cout << endl << endl;
            acu+=vecArancel[i].getTotalArancel();
        }
    }
    cout << "EL TOTAL FACTURADO: $" << acu;
    cin.get();
    free(vecArancel);
    return true;
}
bool mostrarDeudores(){
    cout << "LISTADO DE DEUDORES:" << endl;

    return true;
}
void menuAdministracion(){

}

int buscarIDClientePorMascota(const char*){

}

///CONFIGURACION
///Para resolver las consignas del MENU CONFIGURACION

void menuConfiguracion(){

}

