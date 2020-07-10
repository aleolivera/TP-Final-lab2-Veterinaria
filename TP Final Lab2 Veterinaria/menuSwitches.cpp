#include "menuSwitches.h"

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
        pausar();
    }
    break;
    case 2:
    {
        system("cls");
        reg.modificar_Cliente();
        pausar();
    }
    break;
    case 3:
    {
        if(listarVisitasClientes()){
            volviendoMenu();
        }
        else{
            errorArchivo();
        }
    }
    break;
    case 0:{
//        reg.mostrarTodoElArchivo();
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
//        system("pause");
    }
    break;
    case 2:
    {
        system("cls");
        reg.modificar_mascota();
//        system("pause");
    }
    break;
    case 3:
    {
        system("cls");
        listarVisitasMascotas();
//        system("pause");
    }
    break;
    case 4:
    {
        system("cls");
//        Mascotas reg;
//        Cliente p;
        int op;
        cout<< "TRANSFERENCIA DE MASCOTA" <<endl;
        cout<<" 1- TRANSFERIR A NUEVO CLIENTE "<<endl;
        cout<<" 2- CLIENTE YA INGRESADO "<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 1:
        {
            Mascotas re;
            Cliente reg;
            char nombre[20];
            int ID;
            if(reg.cargarCliente())
            {
                if(reg.gurdarClienteEnDisco())
                {
                    cout<<"EL NUEVO CLIENTE FUE REGISTRADO."<<endl;
                    system("pause");
                    cin.ignore();
                    cout<<"NOMBRE DE LA MASCOTA A TRANSFERIR: ";
                    cin.getline(nombre,20);
                    cin.ignore();
                    cout<<"           ID DEL DUENIO ANTERIOR: ";
                    cin >> ID;
                    int pos;
                    pos=re.buscarMascotaXNombreID(nombre,ID);
                    if(pos==-1){
                        limpiar();
                        cout << "NO HUBO COINCIDENCIAS" << endl;
                    }
                    re.setIDcliente(reg.getIDCliente());

                    if(re.sobrescribir_mascota(pos))
                    {
                        limpiar();
                        cout<<"TRANSFERENCIA COMPLETADA"<<endl;

                    }
                    else
                    {
                        limpiar();
                        cout<<"NO SE PUDO TRANSFERIR"<<endl;
                    }
                }
            }
        }
        break;
        case 2:
        {
             int dni,ID;
            char nombre[20];
            Cliente reg;
            Mascotas re;
            cout<<" INGRESE EL DNI DEL NUEVO DUENIO:";
            cin>>dni;
            cin.ignore();
            cout<<"            NOMBRE DE LA MASCOTA:";
            cin.getline(nombre,20);
//            cin.ignore();
            int pos=0;
            pos=reg.buscarClienteXDni(dni);
            reg.LeerDiscoDeCliente(pos);
            cout<<"           ID DEL DUENIO ANTERIOR: ";
            cin >> ID;
            int posmascota;
            posmascota=re.buscarMascotaXNombreID(nombre,ID);
            if(pos==-1){
                cout << "NO HUBO COINCIDENCIAS" << endl;
                pausar();
            }
            re.setIDcliente(reg.getIDCliente());
            if(re.sobrescribir_mascota(posmascota))
            {
                cout<<"TRANSFERENCIA COMPLETADA"<<endl;
                pausar();
            }
        }
        break;
        }
    }
    break;
        case 0:
//            Mascotas reg;
//            reg.mostrarTodoElArchivo();
            break;
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
                cout<<"EL NUEVO CLIENTE FUE REGISTRADO"<<endl;
                system("pause");
                re.setIDcliente(reg.getIDCliente());
                if(re.Cargar_Mascota())
                {
                    if(re.gurdar_Mascota_EnDisco())
                    {
                        cout<<"LA MASCOTA FUE REGISTRADA"<<endl;
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
        cout<<" INGRESO DE MASCOTA"<<endl << endl;
        cout<<" INGRESE EL DNI DEL CLIENTE REGISTRADO: ";
        cin>>dni;

        pos_cliente=reg.buscarClienteXDni(dni);
        if(pos_cliente!=(-1)){
            ID_cliente=reg.buscraID_Cliente(pos_cliente);
            listardueno(ID_cliente);
            p.setIDcliente(reg.getIDCliente());
            if(p.Cargar_Mascota()){
                if(p.gurdar_Mascota_EnDisco()){
                    cout<<" LA MASCOTA YA FUE REGISTRADA! "<<endl;
//                    system("pause");
                }
            }
        }
        else
            cout<<"CLIENTE INEXISTENTE"<<endl;
        system("pause");
    }
    break;
    case 3:
    {
        listarVisitasMascotas();
    }
    break;
    case 0:{
//        Cliente reg;
//        reg.mostrarTodoElArchivo();
    } break;
    }

}
void menuHistorias(){
    limpiar();
    pantallaHistorias();
    int op;
    cin >>op;
    limpiar();
    switch(op)
    {
    case 1:
        if(ingresoHistoria()){
            guardadoExitoso();
        }
        else{
            errorGuardado();
        }
        cin.get();
    break;
    case 2:
        if(mostrarEntradaHistoria()){
            volviendoMenu();
        }
        else{
            errorArchivo();
        }
        cin.get();
    break;
    case 3:
        if(mostrarHistoria()){
            volviendoMenu();
        }
        else{
            errorArchivo();
        }
    break;
    case 4:
        if(modificarHistoria()){
            guardadoExitoso();
        }
        else{
            errorGuardado();
        }
        cin.get();
    break;
    case 5:
        if(controlesPendientes()){
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();
    break;
    case 6:
        if(controlesAusentes()){
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();
    break;
    case 0:
    {
//        Historia reg;
//       reg.mostrarTodoElArchivo();
    } break;
    }
}
void menuAranceles(){
    limpiar();
    pantallaAranceles();
    int op;
    cin >>op;
    limpiar();
    switch(op){
        case 1:
            if(nuevoArancel()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
            cin.get();
            break;
        case 2:
            if(mostrarArancelesDelDia()){
                volviendoMenu();
            }
            else{
                errorArchivo();
            }
            cin.get();
            break;
        case 3:
            if(modificarArancel()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
            cin.get();
            break;
        case 4:
            if(mostrarArancelesPorVisita()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
            cin.get();
            break;
        case 0:
//            Arancel reg;
//            reg.mostrarTodoElArchivo();
            break;
    }
}
void menuAdministracion(){
    limpiar();
    pantallaAdministracion();
    int op;
    cin >>op;
    limpiar();
    switch(op){
    case 1:
        if(mostrarListaDePrecios()){
            volviendoMenu();
        }
        else{
            errorArchivo();
        }
        cin.get();
    break;
    case 2:
        if(modificarImportes())
        {
            guardadoExitoso();
        }
        else{
            errorGuardado();;
        }
        cin.get();
    break;
    case 3:
        if(nuevoServicio()){
            guardadoExitoso();
        }
        else{
            errorGuardado();;
        }
        cin.get();
    break;
    case 4:
        if(AltaBajaServicio()){
            guardadoExitoso();
        }
        else{
            errorGuardado();;
        }
//        cin.get();
    break;
    case 5:
        if(listarPorFecha()){
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();
    break;
    case 6:
        if(mostrarDeudores()){
            volviendoMenu();
        }
        else{
            errorRegistro();
        }
        cin.get();
    break;
    case 7:
        if(comisiones()){
            volviendoMenu();
        }
        else {
            errorRegistro();
        }
        cin.get();
    break;
    case 0:
//        TipoVisita reg;
//        reg.mostrarTodoElArchivo();
        break;
    }

}
void menuConfiguracion(){
    limpiar();
    pantallaConfiguracion();
    char cadena[3];
    int op;
    cin >>op;
    cin.ignore();
    limpiar();
    switch(op){
    case 1:
        cout << "BACKUP DE CLIENTES."<< endl <<endl;
        cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
        cin.getline(cadena,3);
        if(strcmp(cadena,"SI")==0|| strcmp(cadena,"si")==0){
            if(backupClientes()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
        }
        volviendoMenu();
        cin.get();
    break;
    case 2:
        cout << "BACKUP DE HISTORIAS MASCOTAS."<< endl <<endl;
        cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
        cin.getline(cadena,3);
        if(strcmp(cadena,"SI")==0|| strcmp(cadena,"si")==0){
            if(backupMascotas()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
        }
        volviendoMenu();
        cin.get();
    break;
    case 3:
         cout << "BACKUP DE HISTORIAS CLINICAS."<< endl <<endl;
        cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
        cin.getline(cadena,3);
        if(strcmp(cadena,"SI")==0|| strcmp(cadena,"si")==0){
            if(backupHistorias()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
        }
        volviendoMenu();
        cin.get();
    break;
    case 4:
        cout << "BACKUP DE LISTA DE PRECIOS."<< endl <<endl;
        cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
        cin.getline(cadena,3);
        if(strcmp(cadena,"SI")==0|| strcmp(cadena,"si")==0){
            if(backupTipoVisita()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
        }
        volviendoMenu();
        cin.get();
    break;
    case 5:
        cout << "BACKUP DE ARANCELES."<< endl <<endl;
        cout << "INGRESE 'SI' PARA CONFIRMAR LA OPERACION: ";
        cin.getline(cadena,3);
        if(strcmp(cadena,"SI")==0|| strcmp(cadena,"si")==0){
            if(backupAranceles()){
                guardadoExitoso();
            }
            else{
                errorGuardado();
            }
        }
        volviendoMenu();
        cin.get();
    break;
    case 0:
        break;
    }
}



