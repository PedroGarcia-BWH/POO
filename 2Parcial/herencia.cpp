#include <iostream>
#include <string>
using namespace std;
class X {
public:
X(string s = "por omision") { cout << "Constructor de X: " << s << endl; }
};
class A {

public:
A() { cout << "Constructor de A" << endl; }
void f() { cout << "Metodo f() de A" << endl; }
int  x = 3;
};
class B: virtual public A {

public:
B() { cout << "Constructor de B" << endl; }
void f() { cout << "Metodo f() de B" << endl; }
int  x=2;
};
class C: virtual public A {

public:
C() { cout << "Constructor de C" << endl; }
void f() { cout << "Metodo f() de C" << endl; }
int x=1;
};
class D: public B, public C {

public:
D() { cout << "Constructor de D" << endl; }
int x=0;
};


int main(){
    D d;
    
    d.B::f();
    d.C::f();
    d.A::f();
    d.B::A::f();
    d.C::A::f();

    cout << d.x << endl;
    cout << d.B::x << endl;
    cout << d.C::x << endl;
    cout << d.A::x << endl;
}