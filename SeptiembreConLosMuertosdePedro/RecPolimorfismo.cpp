#include <iostream>
#include <string>

using namespace std;
/*class Mamifero{
public:
    Mamifero(string s) : nombre_(s) {}
    virtual void saludo() const{
    cout << "El nombre del animal es " << nombre() << " y es un " <<
    tipo() << endl; }
    virtual string tipo() const{ return "animal"; }
    string nombre() const{ return nombre_; }
    private:
    string nombre_;
};

class Gato: public Mamifero{
    public:
    Gato(string s): Mamifero(s) {}
    string tipo() const{
        return "Gato";
    }
};

int main(){
    Mamifero* mp = new Gato("Miai");
    mp->saludo();
    delete mp;
}*/

class Objeto{
    public:
    Objeto(char const *nombre): nombre_(nombre) {
    cout << "Constructor de Objeto para " << nombre_ << endl;
    }
    ~Objeto() {
    cout << "Destructor de Objeto para " << nombre_ << endl;
    }
    void lanzamiento() {
    Objeto o("'objeto local de lanzamiento()'");
    cout << "Metodo lanzamiento() para " << nombre_ << endl;
    throw &o;
    }
    void saludo() {
    cout << "Hola de parte de " << nombre_ << endl;
    }
    private:
    char const *nombre_;
};

int main() {
    Objeto o("'objeto de main()'");
    try { o.lanzamiento(); }
    catch(Objeto *o) {
    cout << "Excepción capturada" << endl;
    o->saludo();
    }
}
