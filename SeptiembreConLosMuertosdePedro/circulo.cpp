#include <iostream>
#include <cmath>

using namespace std;
class Forma{
    public:
        virtual double area() const = 0;
};

class Circulo: public Forma{
    public:
        Circulo(double d): diam(d){
            if(diam < 0) throw Radio_Negativo(diam);
        }
        virtual double area() const{
            return 3.14*pow(diam,2);
        }


        class Radio_Negativo{
            public:
            Radio_Negativo(double r):r(r){}
            double valor() const { return r;}
            private:
            double r;
        };
    private:
        double diam;
};

class Rectangulo: public Forma{
    public:
        Rectangulo(double d1, double d2): a(d1), l(d2){}
        virtual double area() const{
            return a*l;
        }
    private:
        double a,l;
};



class Cuadrado: public Rectangulo{
    public:
        Cuadrado(double d1): Rectangulo(d1,d1){}
    private:
};

int main(){
Circulo cir(1.0);
Cuadrado cua(2.0);
Forma * formas[] = {&cir, &cua};
for (int i=0;i<2;i++)
 cout << "Dl area de la figura " << (i+1) << "es: "
 << formas[i]->area();

try{
    Circulo cir1(-1);
}catch(Circulo::Radio_Negativo& e) {
        cerr << e.valor();
}
 
}
