#include <iostream>
#include <set>
#include <pair>
#include <map>
#include <string>
using namespace std;
class Capa{
    public:
        Capa( size_t m, size_t n, char icono):m(m), n(n), simbolo(icono), visible(true) {}
        char icono() const {return simbolo;}
        bool activada() const {return visible;}
        bool ocupada(size_t m, size_t n) const { return cuadricula.find(make_pair(m,n)).second;}
        void activa() {visible = true;}
        void desactiva() {visible = false;}
        void agregaElemento(size_t x, size_t y){
            if(x >= m || y >= n) throw out_of_range("Coordenadas fuera de rango");

            cuadricula.insert(make_pair(x,y));
        }
    
    private:
        size_t m, n;
        char simbolo;
        bool visible;
        set<pair<size_t,size_t>> cuadricula;
}


class Mapa{
    public:
        Mapa(size_t m, size_t n):m(m), n(n) {}
        void agregarCapa(string nombre, size_t m, size_t n, char icono){
            capas[nombre] = Capa(m,n,icono);
        }
        void agregaElemento(string nombre, size_t x, size_t y){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre].agregaElemento(x,y);
        }

        void activaCapa(string nombre){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre].activa();
        }

        void desactivaCapa(string nombre){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre].desactiva();
        }

        void representa(){
            //representacion del mapa
        }
            
    private:
        size_t m, n;
        map<string,Capa> capas;
};

//ejercicio 2
class Mapa{
    public:
        Mapa(size_t m, size_t n):m(m), n(n) {}
        void agregarCapa(string nombre, Capa& capa){
            capas[nombre] = &capa;
        }
        void agregaElemento(string nombre, size_t x, size_t y){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre]->agregaElemento(x,y);
        }

        void activaCapa(string nombre){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre]->activa();
        }

        void desactivaCapa(string nombre){
            if(capas.find(nombre) == capas.end()) throw invalid_argument("Capa no encontrada");

            capas[nombre]->desactiva();
        }

        void representa(){
            //representacion del mapa
        }
            
    private:
        size_t m, n;
        map<string,Capa*> capas;
};



class CapaAbstracta{
    public:
        CapaAbstracta( size_t m, size_t n,):m(m), n(n), visible(true) {}
        virtual char icono() const = 0;
        bool activada() const {return visible;}
        bool ocupada(size_t m, size_t n) const { return cuadricula.find(make_pair(m,n)).second;}
        void activa() {visible = true;}
        void desactiva() {visible = false;}
        void agregaElemento(size_t x, size_t y){
            if(x >= m || y >= n) throw out_of_range("Coordenadas fuera de rango");

            cuadricula.insert(make_pair(x,y));
        }
    
    private:
        size_t m, n;
        bool visible;
        set<pair<size_t,size_t>> cuadricula;
}

class CapaHospital: public CapaAbstracta{
    public:
        CapaHospital( size_t m, size_t n, char icono):CapaAbstracta(m,n), icono(icono) {}
        char icono() const {return icono;}
    private:
        char icono;
};

