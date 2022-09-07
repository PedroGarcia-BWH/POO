#include <iostream>

using namespace std;

class capa{
    public:
        capa(unsigned x, unsigned y, char icono): x_(x), y_(y), icono(icono), activada_(true) {
            cuadricula_ = new char*[x];
            for(unsigned i = 0; i<x; i++){
                cuadricula_[i] = new char[y];
                for(unsigned j = 0; j<y; j++){
                     cuadricula_[i][j] = ' ';
                }
            }
        }
        ~capa();
        capa(unsigned x, unsigned y, char icono, bool activada, char** cuadricula):x_(x), y_(y), icono(icono), activada_(activada),
            cuadricula_(cuadricula) {}
        void desactivar() noexcept { activada_ = false;}
        void activar() noexcept{activada_ = true;}

        char Icono() const { return icono;}
        bool activada()const {return activada_;}
        bool ocupada(unsigned x, unsigned y) const{
            if(x > x_ || y > y_ ) throw out_of_range("Coordenada fuera de rango");
            
            return cuadricula_[x][y] == icono;   
        }

        void agrega_elemento(unsigned x, unsigned y){
            if(x > x_ || y > y_ ) throw out_of_range("Coordenada fuera de rango");
            cuadricula_[x][y] = icono; 
        }
    private:
    unsigned x_, y_;
    char icono;
    bool activada_;
    char** cuadricula_;

};

capa::~capa(){
    for(unsigned i = 0; i<x_; i++){
        delete cuadricula_[i];  
    }
    delete cuadricula_;
}


class mapa{
    public:
        mapa(unsigned x, unsigned y): x_(x), y_(y){}
    private:
        unsigned x_, y_;
        string cadena;
};

//ej4
class EmpleadoLocalidad{
    public:
        EmpleadoLocalidad(int dep, int telefono): departamento(dep), telefono(telefono) {}
    private:
        int departamento;
        int telefono;
};

class Empleado{
    public:
        Empleado(int n_empleado, string nombre, string apellidos, string f_alta): 
        n_empleado(n_empleado), nombre(nombre), apellidos(apellidos), f_alta(f_alta) {}
    private:
        int n_empleado;
        string nombre, apellidos;
        string f_alta;
};

class EmpleadoConCartera{
    public:
        EmpleadoConCartera(int clientes, int horas): clientes(clientes), horas(horas) {}
    private:
        int clientes;
        int horas;
};


class Tecnico: public EmpleadoLocalidad, public Empleado, public EmpleadoConCartera{
    public:
        Tecnico(int dep, int telefono, int n_empleado, string nombre, string apellidos, string f_alta,
         int clientes, int horas, int nivel): EmpleadoLocalidad(dep, telefono),
         Empleado(n_empleado,nombre,apellidos,f_alta), EmpleadoConCartera(clientes,horas),
         nivel(nivel) {}
    private:
        int nivel;
};


