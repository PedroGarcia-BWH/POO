#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Elipse{
    public:
        Elipse(double radioX, double radioY): radioX(radioX),
        radioY(radioY){}
        double radio_X() const {return radioX;}
        double radio_Y() const {return radioY;}
        void escala(double e, double u) { radioX *= e; radioY *= u;}

    private:
    double radioX, radioY;

};

class Circunferencia: public Elipse{
    public:
        Circunferencia(double r): Elipse(r,r){}
        void escala(double e){Elipse::escala(e,e);}
        double radio() const { return radio_X();}

        
    private:

};



class Vehiculo{
    public:
     Vehiculo(string fecha): fecha(fecha) {}
     string fabricacion() const { return fecha;}
     virtual void imprimirDatos() const = 0;
    private:
     string fecha;
};


class turismo: public Vehiculo{
    public:
        turismo(string fecha, int pasajeros): Vehiculo(fecha), pasajeros(pasajeros){}
        int pasajerosMax() const { return pasajeros;}
        void imprimirDatos() const{}
    private:
        int pasajeros;
};  

class camion: public Vehiculo{
    public:
        camion(string fecha, int peso): Vehiculo(fecha), peso(peso){}
        int pesoMax() const { return peso;}
        void imprimirDatos() const{}
    private:
        int peso;
};


//como nos pide de los dos tipos no tendremos en cuenta si hay mas tipos
void clasificar(const vector<Vehiculo*>& v, vector<turismo*>& t, vector<camion*>& c){
for(auto it = v.begin(); it != v.end(); it++){
        if(turismo* turismoAux = dynamic_cast<turismo*>(*it)){
            t.push_back(turismoAux);
        }else if(camion* camionAux = dynamic_cast<camion*>(*it)){
            c.push_back(camionAux);
        }
    }
}
    
    
template <class T1, class T2>
std::ostream& operator << (std::ostream& os,const Par<T1,T2>& P){
    os<< P.primero();
    os << P.segundo();
    return os;
}

class racional{
    public:

    private:
        Par<int, int> p;
};

class intrumento{
    virtual string tipo() const { return "instrumento";}
};

class Cuerda: public Instrumento{
    public:
    Cuerda(string nom); Intrumento(nom) {}
    string tipo() const{return "cuerda" }
    private:

};

class D{
    C c;
}

D::f()
//modificar un static dentro de una fun static
//no puedes  modificar una variable no estatic dentro de una fun static
//se puede llamar a una funcion static sin tener nigun objeto inicializado
// se puede llamar una variable static sin tener ningun objeto inicializado