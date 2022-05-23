#include <iostream>
#include <set>
class A{

};

class C{
    private:
        int c1;
        A* a;
        B b;
        std::set<D*> d;
};

class B{
    private:
        C* c;
};

class D{
    private:
        C* c;
        B* b;
};
//preguntar a pedro esto
//preguntar a pedro diapositiva discord pq es un  map siendo 0...1 cuando se podria poner un puntero
//preguntar en la captura de pantalla en al rel4 por ej cuando es necesario realizar una clase de asociacion y cuando solo añadir los atributos a cada clase