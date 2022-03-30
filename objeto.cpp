#include <iostream>

using namespace std;

class Objeto
{
    public:
    Objeto(char const *nombre): nombre (nombre) {
    cout << "Constructor de Objeto para " << nombre << endl;
    }
    ~Objeto() {
    cout << "Destructor de Objeto para " << nombre << endl;
    }
    void lanzamiento() {
    Objeto* o = new Objeto("‘objeto local de lanzamiento()’");

    cout << "M´etodo lanzamiento() para " << nombre << endl;
    throw o;
    }
    void saludo() {
    cout << "Hola de parte de " << nombre << endl;
    }
    private:
    char const *nombre ;
};

//se puede hacer asi el objeto o(con new), o pasarlo por valor siendo una variable y listo. // EL NEW FUNCIONA YA QUE NO TENEMOS UN DELETE Y ESO NO LO HACE EL COMPILADOR
int main()
{
    Objeto o("‘objeto de main()’");
    try {
    o.lanzamiento();
    }
    catch(Objeto* o) {
    cout << "Excepcion capturada" << endl;
    o->saludo();
}
}
