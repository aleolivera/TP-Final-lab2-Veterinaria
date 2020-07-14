#ifndef VISUALES_H_INCLUDED
#define VISUALES_H_INCLUDED

void pantallaPrincipal();
void pantallaHistorias();
void pantallaMascotas();
void pantallaClientes();
void pantallaAranceles();
void pantallaAdministracion();
void pantallaConfiguracion();
void pantallaAgregar();
void limpiar();
void pausar();
void error(const char*);
void errorCadenaInvalida(const char*,const char*);
void errorEnteroInvalido(int,const char*);
void errorFloatInvalido(float,const char*);
void errorArchivo();
void errorFechaInvalida();
void errorIngresoInvalido();
void volviendoMenu();
void guardadoExitoso();
void errorRegistro();
void errorAsignacionMemoria();
void errorCargarRegistros();
void errorGuardado();
void colorPantalla(int,int);

#endif // VISUALES_H_INCLUDED
