#include "funcionesGlobales.h"

///VALIDACIONES
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
bool validarFecha(int dia,int mes,int anio){
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
int validarMail(const char* cadena){
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



///VALIDACIONES CON ARCHIVOS Y BUSQUEDAS EN ARCHIVOS
int asignarIDHistoria(){
    Historia reg;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    if(fread(&reg,sizeof (Historia),1,p)==0){
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
int asignarIDarancel(){
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
        fseek(p,-sizeof (Arancel),2);
        fread(&reg,sizeof (Arancel),1,p);
        fclose(p);
        return reg.getIDArancel()+1;
    }
}
bool validarIDcliente(int ID){
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
int cantidadRegistrosHistorias(){
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Historia);
}
int cantidadRegistrosClientes(){
     FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Cliente);
}
int cantidadRegistrosMascotas(){
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (Mascotas);
}
bool cargarVecHistorias(Historia*vec){
    Historia reg;
    int i=0;
    FILE*p=fopen(ARCHIVOHISTORIAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Historia),1,p)==1){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecClientes(Cliente*vec){
    Cliente reg;
    int i=0;
    FILE*p=fopen(ARCHIVOCLIENTES,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Cliente),1,p)==1){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}
bool cargarVecMascotas(Mascotas*vec){
    Mascotas reg;
    int i=0;
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Mascotas),1,p)==1){
        vec[i]=reg;
        i++;
    }
    fclose(p);
    return true;
}

///SECCIONES DEL PROGRAMA
///CLIENTES



void menuClientes(){

}
///MASCOTAS

void menuMascotas(){

}
void menuIngresoPaciente(){

}
///HISTORIAS
bool ingresoHistoria(){
    Historia reg;
    int dia,mes,anio,valor;
    char cadena[20];
    reg.setIDHistoria(asignarIDHistoria());
    reg.setFechaIngreso();
    ///EL ATRIBUTO 'Fecha fechaModificacion' LO ASIGNA EL CONSTRUCTOR EN ESTA ETAPA

    cout << "INGRESE LA FECHA DE LA VISITA(DD/MM/AA):"<< endl;
    cin >> dia >> mes >> anio;
    if (!validarFecha(dia,mes,anio)){
        return false;
    }
    reg.setFechaVisita(dia,mes,anio);

    cout << "ID DEL CLIENTE: ";
    cin >> valor;
    if(validarIDcliente(valor)){
        return false;
    }
    reg.setIDCliente(valor);

    cout << "NOMBRE DE LA MASCOTA: ";
    cin.ignore();
    cin.getline(cadena,20);
    reg.setNombreMascota(cadena);

    cout << "ANAMNESIS: ";
    cin.ignore();
    reg.setAnamnesis();

    cout << "REQUIERE VOLVER A CONTROL?: ";
    cin.ignore();
    cin.getline(cadena,2);
    if(strcmp(cadena,"SI")||strcmp(cadena,"si")){
        reg.setControl(true);
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
        if (!validarFecha(dia,mes,anio)){ ///TENDRIA QUE VALIDAR ADEMAS QUE LA FECHA NO SEA MENOR A LA DE HOY
                return false;
            }
        reg.setFechaControl(dia,mes,anio);
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
    reg.leerHistoria(pos);
    reg.mostrarFechaModificacion();
    reg.mostrarNombreMascota();
    reg.mostrarAnamnesis();
    return true;
}
bool mostrarHistoria(){
    Historia*vecHistoria;
    Mascotas*vecMascota;
    Cliente*vecClientes;
    char aux[30];
    int ID=-1;
    int tam1;
    int tam2;
    vecHistoria=new Historia[cantidadRegistrosHistorias()];
    if(vecHistoria==NULL){
        return false;
    }
    vecMascota=new Mascotas [cantidadRegistrosMascotas()];
    if(vecHistoria==NULL){
        free(vecHistoria);
        return false;
    }
    vecClientes=new Cliente [cantidadRegistrosClientes()];
    if(vecHistoria==NULL){
        free(vecMascota);
        free(vecHistoria);
        return false;
    }
    char nombreMascota[20];
    char apellidoCliente[30];
    cin.ignore();
    cin.getline(nombreMascota,20);
    cin.ignore();
    cin.getline(apellidoCliente,30);

    tam1=cantidadRegistrosHistorias();
    tam2=cantidadRegistrosMascotas();

    if(!cargarVecHistorias(vecHistoria)||(!cargarVecMascotas(vecMascota))||(cargarVecClientes(vecClientes))){
        free(vecClientes);
        free(vecMascota);
        free(vecHistoria);
        return false;
    }
    for(int i=0;i<tam1;i++){
        vecHistoria[i].getNombreMascota(aux);
        if(strcmp(nombreMascota,aux)==0){
            for(int j=0;j<tam2;j++){
                vecClientes[j].getApellido(aux);
                if((vecHistoria[i].getIDCliente() == vecClientes[j].getIDCliente())&&(strcmp(apellidoCliente,aux))){
                    ID=vecHistoria[i].getIDCliente();
                }
            }
        }
    }
    if(ID==-1) return false;

    cout << "NOMBRE DE MASCOTA: " << nombreMascota << endl;
    cout << "APELLIDO DEL CLIENTE: " << apellidoCliente << endl;
    for (int i=0;i<tam1;i++){
        if(vecHistoria[i].getIDCliente()==ID){
            vecHistoria[i].mostrarIDHistoria();
            vecHistoria[i].mostrarFechaVisita();
            vecHistoria[i].mostrarAnamnesis();
            cout << endl;
            cout << "      ---------------      " << endl;
        }
    }
    free(vecHistoria);
    free(vecMascota);
    free(vecClientes);
    return true;
}

bool modificarHistoria(){

    return true;
}
void controlesPendientes(){

}
void controlesAusentes(){

}

void menuHistorias(){
    limpiar();
    pantallaHistorias();
    int op;
    cin >>op;
    switch(op){
        case 1:{
            ingresoHistoria();
        }break;
        case 2:{
            mostrarHistoria();
        }break;
        case 3:{
            modificarHistoria();
        }break;
        case 4:{
            controlesPendientes();
        }break;
        case 5:{
            controlesAusentes();
        }break;
        case 0:{


        }break;
    }
}
///ARANCELES


void menuAranceles(){

}
///ADMINISTRACION

void menuAdministracion(){

}
///CONFIGURACION

void menuConfiguracion(){

}
