#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes,anio;

    public:
        void mostrarFecha(); //hace cout de las 3 variables
        ///GETs
        int getDia();
        int getMes();
        int getAnio();
        ///SETs
        void setFecha(int, int, int); // carga D/M/A con 3 enteros
        void setFechaActual();// le pone la echa actual a una variable clase Fecha
};

#endif // FECHA_H_INCLUDED
