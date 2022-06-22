#include <iostream>


 using namespace std;

 /*class B{
  public:
        void f(){ cout<< "f() de B" << endl;}
        virtual void g() {cout << "g() de B "<< endl;}
        virtual void h()=0;
 protected:
        int b;
};

class D1:  public B{
    public:
          void f(){ cout << "f() de D1" << endl;}
          virtual void g(){ cout << "g() de D1" << endl;}
    protected:
          int d1;
};

class D2: virtual public B{
public:
void f(int){ cout << "f(" << d2 <<") de D2" << endl;}
virtual void h(){ cout << "h() de D2"<< endl; }
protected:
int d2;
};
class D3: public D1{
public:
 void g(){ cout << "g() de D3" << endl;}
 void h(){ cout << "h() de D3" << endl;}
private:
 int d3;
};

class D4: public D1, public D2{
private:
 int d4;
};

void f(B& b){
 cout << "f() externa" << endl;
 b.f();
 b.g();
 b.h();
}

int main(){
B b, *pB; //b no se puede decalar porque es abstracta FALLO
D1 d1; // no se puede declarar pq es abstracta FALLO
D2 d2; D3 d3; D4 d4;
f(b); f(d1); f(d2); f(d3); f(d4); 
d4.D1::f();
d4.f(5);
d4.f(3.5);
d4.g();

d4.h();
pB = new D4;
pB­->f();
pb­->D4::f(3);
pb­->g();
pB­->h();
delete pB;
}*/



//-------RESOLVIENDO LOS PROBLEMAS
 using namespace std;

 class B{
public:
void f(){ cout<< "f() de B" << endl;}
virtual void g() {cout << "g() de B "<< endl;}
 virtual void h() {cout << "h() de B "<< endl;}
 protected:
 int b;
};

class D1: virtual public B{
public:
 void f(){ cout << "f() de D1" << endl;}
 virtual void g(){ cout << "g() de D1" << endl;}
protected:
 int d1;
};

class D2: virtual public B{
public:
void f(int i){ cout << "f(" << i <<") de D2" << endl;}
virtual void h(){ cout << "h() de D2"<< endl; }
protected:
int d2;
};
class D3: public D1{
public:
 void g(){ cout << "g() de D3" << endl;}
 void h(){ cout << "h() de D3" << endl;}
private:
 int d3;
};

class D4: public D1, public D2{
    public:
        using D2::f; 
    private:
    int d4;
};

void f(B& b){
 cout << "f() externa" << endl;
 b.f();
 b.g();
 b.h();
}

int main(){
B b, *pB; 
D1 d1; 
D2 d2; D3 d3; D4 d4;
//f(b); f(d1); f(d2); f(d3); 
//f(d4); 
  /*d4.D1::f(); //d1
d4.f(5); // no funciona ambiugedad no puede mirar cuales parametros tiene, si queremos utilizar f()int debemos poner el using en la clase y sin parentesisi y en la parte publica
//d4.f(3.5); // no funciona sobrecarga aqui ni en la de arriba
d4.g(); //D1

d4.h(); //D2
*/

pB = new D4;
pB->f();
//pB->D4::f(3); //no tiene F D4 
pB->g();
pB->h();
delete pB;
}