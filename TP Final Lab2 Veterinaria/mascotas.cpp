#include "mascotas.h"







///GETS
int Mascotas::getIDCliente(){
    return IDCliente;
}
void Mascotas::getNombre(char*cadena){
    strcpy(cadena,nombreMascota);
}
///DISCO


bool Mascotas::leerMascota(int pos){
    FILE*p=fopen(ARCHIVOMASCOTAS,"rb");
    if(p==NULL){
        return false;
    }
    fseek(p, pos*sizeof (Mascotas),0);
    if(fread(this,sizeof (Mascotas),1,p)==1){
        fclose(p);
        return true;
    }
    else{
        fclose(p);
        return false;
    }
}

