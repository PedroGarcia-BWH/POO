#include <iostream>
using namespace std;
/*void mostrar(int i) { cout << i << "␣[entero]" << endl; }
void mostrar(float f) { cout << f << "␣[real]" << endl; }
int main()
{
    mostrar(2);
    mostrar(2.0f);// al poner solo 2.0 es un double y es ambiguo, hay que poner 2.0f
    mostrar('a');
}*/

/*void f(char);
void f(double);
void f(void *); // con esto entra todo menos lo constante por eso la line 21  no entra pq es un const char
int main()
{
f(0.0);
f(0);
f(0.0f);
char *g = "Hola"; 
f(g); // el puntero void no esta guardado la direccion por eso tenemos que meterlo en una varaible
}*/


struct B {
B() { std::cout << "Constructor␣de␣B\n"; }
~B() { std::cout << "Destructor␣de␣B\n"; }
 };
struct D: B {
D() { std::cout << "Constructor␣de␣D\n"; }
~D() { std::cout << "Destructor␣de␣D\n"; }
};
int main() {
B *pb = new D;
delete pb;
}
//¿Cambiaría algo si quitamos la palabra virtual del destructor de B?
// Si quitamos la palabra virtual llamariamos al destricutor de B
