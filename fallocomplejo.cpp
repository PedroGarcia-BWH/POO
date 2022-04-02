#include <iostream>
#include <cmath>
using namespace std;
class Complejo {
    double real, imag;
    public:
    explicit Complejo (double r = 0., double i = 0.): real(r), i(imag) {} // si quitamos el explicit hay ambiguedad en el + // no funciona por tema de que esta al reves i y imag
    Complejo (const Complejo& c) {this = c;} // esta asignando a un puntero un objeto, ademas si asignaramos un puntero no seria una copia sino una referencia y por tanto se modifican los 2
    static void print() { cout << "(" << real << "," << imag << ")"; } // no se puede llamar a objetos no static en un metodo static
    operator double() const { return sqrt(real * real + imag * imag); }
};
Complejo operator +(const Complejo& c1, const Complejo& c2) { // no se puede llamar a los metodos privados
    c1.real += c2.real, c1.imag += c2.imag;
    return Complejo(c1.real, c1.imag);
}
Complejo& operator -(Complejo c1, Complejo c2) { // no se puede llamar a los metodos privados
    c1.real -= c2.real, c1.imag -= c2.imag;
    /*Complejo a(c1.real, c1.imag); 
    return  a;*/

    return Complejo (c1.real, c1.imag); // no se puede pasar este return cuando esta complejo& 
}
const Complejo operator *(Complejo& c1, Complejo& c2) { // no se puede llamar a los metodos privados
    return Complejo(c1.real * c2.real - c1.imag * c2.imag,
    c1.real * c2.imag + c2.real * c1.imag);
}
int main() {
Complejo a(3.), b(2., 2.), c = a + b, d = b + 3.; // el 3. no funciona pq tiene que ser explicit
double e = 3. + b; // si funciona pq no hacemos complejo complejo sino double double
cout << "a * b = ", (a * b).print();
}