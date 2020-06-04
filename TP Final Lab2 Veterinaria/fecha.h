#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes,anio;

    public:
        void mostrarFecha(); //hace cout de las 3 variables
        void getFechaActual();// le pone la echa actual a una variable clase Fecha
        void cargarFecha(); // carga D/M/A con cin>>
        void cargarFecha(int, int, int); // carga D/M/A con 3 enteros
};

#endif // FECHA_H_INCLUDED
