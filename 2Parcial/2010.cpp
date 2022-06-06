#include <iostream>

using namespace std;

struct B{
   virtual void f() {cout << "f() de B" << endl;}
};

struct D:B{
   void f() {cout << "f() de D " << endl;}
};

void f(B b){
    cout << "f() externa" << endl; b.f();
}

int main(){
    B b;
    D d;
    f(b);
    f(d); // da igual si es virtual que como solo no es una referencia es un objeto nunca lo va a hacer
}



/*

    struct B{
   virtual void f() {cout << "f() de B" << endl;}
};

struct D:B{
   void f() {cout << "f() de D " << endl;}
};

    void f(B& b){
    cout << "f() externa" << endl; b.f();
    }

    int main(){
        B b;
        D d;
        f(b);
        f(d); // como es virtual funciona como mostrando d, si no fuera no lo hace
    }

*/

//PARA PUNTEROS ESTO
/*
void f ( B *b) { cout<< " f ( ) externa" << endl; b->f( ); } // NO FUNCIONA CON EL MAIN COMO TAL PQ NO HAY PUNTERO

int main(){
    B b;
    D d;
    f(&b);
    f(&d); // da igual si es virtual que como solo es una funcion de b siempre va a hacer b
}

*/

//EJERCICIO 2
class Punto{
    public:
        double x(){return x_;}
        double y() {return y_;}
    private:
        double x_;
        double y_;
};

class Cuadrilatero{
    public:
        Cuadrilatero(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        p1(p1), p2(p2), p3(p3), p4(p4) {}
        double perimetro();
        virtual void impresion() = 0; // no tiene sentido imprimir un cuadrilatero
    private:
        Punto p1,p2,p3,p4;
};

class Trapezoide: public Cuadrilatero{
    public:
        Trapezoide(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Cuadrilatero(p1,p2,p3,p4) {}
        void impresion() {}
    private:
};

class Paralelogramo: public Cuadrilatero{
    public:
        Paralelogramo(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Cuadrilatero(p1,p2,p3,p4) {}
        void impresion() {}
    private:
};

class Trapecio: public Cuadrilatero{
    public:
        Trapecio(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Cuadrilatero(p1,p2,p3,p4) {}
        void impresion() {}
    private:
};

class Rombo: virtual public Paralelogramo{
    public:
        Rombo(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Paralelogramo(p1,p2,p3,p4) {}
        void impresion() {}
    private:
};

class Rectangulo: virtual public Paralelogramo{
    public:
        Rectangulo(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Paralelogramo(p1,p2,p3,p4) {}
        void impresion() {}
    private:
}; 

class Cuadrado: virtual public Paralelogramo{
    public:
        Cuadrado(const Punto& p1,const  Punto& p2, const Punto& p3, const Punto& p4): 
        Paralelogramo(p1,p2,p3,p4) {}
        void impresion() {}
    private:
};