#include <iostream>

using namespace std;

class A{
    public:
    void f(){cout<< "F de A"<< endl;}
};

class B: virtual public A{
    public:
    void f(){cout<< "F de B"<< endl;}
};

class C:virtual public A{
    public:
    void f(){cout<< "F de C"<< endl;}};
   
class D:public B, public C {
    public:
    void f(){cout<< "F de D"<< endl;}
};

int main(){
    A *pa, a;
    B *pb, b;
    C *pc;
    D d, *pd;

    pb = &b;
    pc = (C*) pb; 
    cout << "hola2";
    pc->f();
}