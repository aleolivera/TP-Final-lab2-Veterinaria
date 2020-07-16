
#include "tipoVisita.h"

    ///SETs
void TipoVisita::setIDTipoVisita(int valor){
    IDTipoVisita = valor;
}
void TipoVisita::setNombreTipoVisita(const char*cadena){
        strcpy(nombreTipoVisita,cadena);
}
void TipoVisita::setImporte(float valor){
    importe=valor;
}
void TipoVisita::setPorcentajeHonorario(int valor){
    porcentajeHonorario=valor;
}
void TipoVisita::setEstado(bool e){
    estado=e;
}

    ///GETs
int TipoVisita::getIDTipoVisita(){
    return IDTipoVisita;
}
const char*TipoVisita::getNombreTipoVisita(){
    return nombreTipoVisita;
}
float TipoVisita::getImporte(){
    return importe;
}
int TipoVisita::getPorcentajeHonorario(){
    return porcentajeHonorario;
}
bool TipoVisita::getEstado(){
    return estado;
}

    ///DISCO
bool TipoVisita::guardarTipoVisita(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"ab");
    if(p==NULL){
        return false;
    }

    if(fwrite(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool TipoVisita::leerTipoVisita(int pos){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (TipoVisita),0);
    if(fread(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}
bool TipoVisita::modificarTipoVisita(int pos){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,(pos*sizeof (TipoVisita)),0);
    if(fwrite(this,sizeof (TipoVisita),1,p)==1){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

///GLOBALES
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
int cantidadRegistrosTipoVisita(){
    FILE*p=fopen(ARCHIVOTIPOVISITA,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2);
    return ftell(p)/sizeof (TipoVisita);
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
void verTipoVisita(TipoVisita regTipoVisita){
        cout << "                      ID: "<< regTipoVisita.getIDTipoVisita() << endl;
        cout << "          TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita() << endl;
        cout << "                 IMPORTE: $" << regTipoVisita.getImporte() <<"-." << endl;
        cout << "               HONORARIO: " << regTipoVisita.getPorcentajeHonorario() << "%."<< endl;
}

///ADMINISTRACION
///Para resolver las consignas del MENU ADMINISTRACION
bool mostrarListaDePrecios(){
    limpiar();
    cout << "======================================================"<< endl;
    cout << "                    LISTA DE PRECIOS" << endl;
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
    for(int i=0; i<cantTipoVisita; i++){
        cout << " ---------------------------------------------------- " <<endl;
        verTipoVisita(vec[i]);
    }
    cout << " ==================================================== "<< endl;
    pausar();
    delete(vec);
    return true;
}
bool modificarImportes(){
    limpiar();
    TipoVisita reg;
    int ID, pos, validar;
    float importe;
    cout << "======================================================"<< endl;
    cout << "                    MODIFICAR IMPORTES" << endl;
    cout << "------------------------------------------------------"<< endl;
    if(listarTiposDeVisita(1)==-1){
        error("NO SE ENCONTRARON SERVICIOS EN EL ARCHIVO");
        return false;
    }
    cout << "           INGRESE ID: ";
    cin >> ID;                              ///PIDO EL ID,
    cout << "------------------------------------------------------" << endl;
    pos=buscarTipoVisita(ID);           ///BUSCO ESE REGISTRO EN ARCHIVOTIPOVISITAS
    if (pos==-1){                           ///VALIDO LA POSICION
        errorRegistro();
        return false;
    }
    reg.leerTipoVisita(pos);
    verTipoVisita(reg);
    cout << "------------------------------------------------------" << endl;
    cout << "           INGRESO DE NUEVOS VALORES" <<endl << endl;
    cout << "NOMBRE TIPO DE VISITA: ";
    cout << reg.getNombreTipoVisita() << endl;
    if(!validarNombresConEspacios(reg.getNombreTipoVisita())){
        errorCadenaInvalida(reg.getNombreTipoVisita(),", NO ES UN INGRESO VALIDO");
        return false;
    }
    cout << "              IMPORTE: $";
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

    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    cin.ignore();
    validar=preguntarSIoNO();
    if(validar==1){
        if(!reg.modificarTipoVisita(pos)){
            error("NO SE HA PODIDO MODIFICAR EL REGISTRO");
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
bool nuevoServicio(){
    limpiar();
    TipoVisita reg;
    int ID,validar;
    float importe;
    char cadena[30];
    cout << "======================================================"<< endl;
    cout << "              INGRESAR NUEVO TIPO DE VISITA" << endl;
    cout << "------------------------------------------------------"<< endl;
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
    if(validarTipoVisita(cadena) || !validarNombresConEspacios(cadena)){
        errorIngresoInvalido();
        cout << "PUEDE QUE ESE SERVICIO ESTE DADO DE BAJA" << endl;
        pausar();
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
    cout << "------------------------------------------------------"<< endl;
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    cin.ignore();
    validar=preguntarSIoNO();
    if(validar==1){
        if(!reg.guardarTipoVisita()){
            error("NO SE HA PODIDO GUARDAR EL REGISTRO");
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
bool AltaBajaServicio(){
    limpiar();
    TipoVisita regTipoVisita;
    int ID,pos, validar;
    cout << "======================================================" << endl;
    cout << "             ALTA Y BAJA DE TIPO DE VISITAS" << endl;
    cout << "------------------------------------------------------" << endl<< endl;
    cout << "   SERVICIOS EN BAJA:" << endl;
    listarTiposDeVisita(0);
    cout << endl;
    cout << "   SERVICIOS EN ALTA:" << endl;
    listarTiposDeVisita(1);
    cout << "------------------------------------------------------" << endl;
    cout << endl << "   TIPO DE VISITA ID: ";
    cin >> ID;
    cin.ignore();
    pos=buscarTipoVisita(ID);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regTipoVisita.leerTipoVisita(pos);
    if(regTipoVisita.getEstado()){
        cout << " ESTA SEGURO QUE DESEA DAR DE BAJA?"<< endl;
        cout << "                         SI | NO: ";
        validar=preguntarSIoNO();
        if(validar==1){
            regTipoVisita.setEstado(false);
        }
        else if(validar==0){
            volviendoMenu();
            return false;
        }
        else{
            errorIngresoInvalido();
            return false;
        }
    }
    else{
        cout << " ESTA SEGURO QUE DESEA DAR DE ALTA?"<< endl;
        cout << "                         SI | NO: ";
        validar=preguntarSIoNO();
        if(validar==1){
            regTipoVisita.setEstado(true);
        }
        else if(validar==0){
            volviendoMenu();
            return false;
        }
        else{
            errorIngresoInvalido();
            return false;
        }
    }
    cout << "------------------------------------------------------" << endl;
    cout << "DESEA GUARDAR LOS CAMBIOS?  SI | NO : ";
    validar=preguntarSIoNO();
    if(validar==1){
        if(!regTipoVisita.modificarTipoVisita(pos)){
            error("NO SE HA PODIDO MODIFICAR EL REGISTRO");
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
bool listarPorFecha(){
    limpiar();
    Arancel*vecArancel;
    TipoVisita reg;
    Fecha inicio;
    Fecha fin;
    int d, m, a,cantAranceles;
    float acu=0;

    cout << "======================================================"<< endl;
    cout << "              LISTADO DE VISITAS POR FECHA" << endl;
    cout << "------------------------------------------------------"<< endl<< endl;
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
    int pos;
    for(int i=0; i<cantAranceles; i++)
    {
        if((compararFechas(inicio,vecArancel[i].getFechaArancel())<=1) && (compararFechas(vecArancel[i].getFechaArancel(),fin)<=1))
        {
            vecArancel[i].getFechaArancel().mostrarFecha();
            cout << endl;
            pos=0;
            while(reg.leerTipoVisita(pos++)){
                if(reg.getIDTipoVisita()==vecArancel[i].getIDTipoVisita()){
                    cout << "  TIPO DE VISITA: " << reg.getNombreTipoVisita() << endl;
                    cout << "         IMPORTE: $"<< vecArancel[i].getTotalArancel() << endl;
                    cout << "------------------------------------------------------"<< endl;
                    acu+=vecArancel[i].getTotalArancel();
                }
            }
//            if(reg.buscarTipoVisita(vecArancel[i].getIDTipoVisita())==-1){
//                errorRegistro();
//                return false;
//            }
//            cout << "  TIPO DE VISITA: " << reg.getNombreTipoVisita() << endl;
//            cout << "         IMPORTE: $"<< vecArancel[i].getTotalArancel() << endl;
//            cout << "-------------------------------" << endl;
//            acu+=vecArancel[i].getTotalArancel();
        }
    }
    cout << "        EL TOTAL FACTURADO: $" << acu << endl;
    cout << "======================================================"<< endl;
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

    cout << "======================================================"<< endl;
    cout << "                 LISTADO DE DEUDORES" << endl;
    cout << "------------------------------------------------------"<< endl;
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
                if(!(vecArancel[j].getAbonado()) && vecClientes[i].getDNICliente()==vecArancel[j].getDNICliente()){

                    cout << "         FECHA: ";
                    vecArancel[j].getFechaArancel().mostrarFecha();           ///SI ENCUENTRO MUESTRO LOS DATOS DE ESE ARANCEL Y ACUMULO EL TOTAL $.
                    cout << endl << "    ID ARANCEL: " << vecArancel[j].getIDArancel() << endl;
                    cout << "         TOTAL: $" << vecArancel[j].getTotalArancel() << endl;
                    cout << "---------------------------" << endl;
                    acu+=vecArancel[j].getTotalArancel();
                }

            }
            cout << "------------------------------------------------------"<< endl;
            cout << "  SALDO DEUDOR: $" << acu << endl;               ///AHORA MUESTRO EL TOTAL ACUMULADO DE LOS ARANCELES INPAGOS
            cout << "------------------------------------------------------"<< endl;
            cout << "======================================================" << endl;
        }
    }
    if(!deudores){
        cout << "------------------------------------------------------"<< endl<< endl;
        cout << "   NO HAY CLIENTES CON SALDO DEUDOR." << endl;
        cout << "======================================================"<< endl;
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
    int dia, mes, anio, ID, cantAranceles, pos;
    float acu=0;
    cout << "======================================================"<< endl;
    cout << "                    COMISIONES" << endl;
    cout << "------------------------------------------------------"<< endl<< endl;
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

    pos=buscarTipoVisita(ID);
    if(pos==-1){
        errorRegistro();
        return false;
    }
    regTipoVisita.leerTipoVisita(pos);

    cout << "              TIPO DE VISITA: " << regTipoVisita.getNombreTipoVisita()<< endl << endl;

    for(int i=0;i<cantAranceles;i++){
        if(vecArancel[i].getIDTipoVisita()==ID && (compararFechas(aux,vecArancel[i].getFechaArancel())==1 || compararFechas(aux,vecArancel[i].getFechaArancel())==0)){
            cout << "FECHA: ";
            vecArancel[i].getFechaArancel().mostrarFecha();
            cout << "   TOTAL DE ARANCEL: $"<< vecArancel[i].getTotalArancel()<< "  " << vecArancel[i].getPorcentajeHonorario()<< "%."<<endl;
            acu+= (vecArancel[i].getTotalArancel() * vecArancel[i].getPorcentajeHonorario()/100);
        }
    }
    cout << "------------------------------------------------------"<< endl;
//    cout << "      PORCENTAJE DE COMISION: " <<regTipoVisita.getPorcentajeHonorario()<< "%." << endl;
    cout << "         TOTAL DE COMISIONES: $" <<acu << endl;
    cout << "======================================================"<< endl;
    pausar();
    delete(vecArancel);
    return true;
}
