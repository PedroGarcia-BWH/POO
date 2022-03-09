#include <iostream>
class A{

};
class complejo{
    public:
   complejo(double r=0, double i=0): r(r), i(i) {} // si ponemos explicit la linea 25(i2 = -1) y la 26(x=-3.5) no funcionan pq tiene que ser de esta forma
    complejo(const complejo& c);   //funciona solo con estos constructores

    inline double real() const { return r;} 
    inline double imag() const { return i;} 
    double& real() {return r;} //ejercicio 2
    double& imag() {return i;}
    friend bool operator == (const complejo& n1, const complejo& n2);
    const complejo& operator -();

    complejo& operator = (const A& a) {}
    complejo& operator = (const complejo& a) {}

    private:
    double r,i;
};

complejo::complejo(const complejo& c){
    r = c.r;
    i = c.i;
}

 complejo operator *(const complejo& n1, const complejo& n2){
    complejo result;
    result.real() = n1.real() * n2.real();
    result.imag() = n1.imag() * n2.imag();
    return result;
}

const complejo& complejo::operator -(){ //funcionar funciona pero no es lo mas ideal pq da warning pq estamos pasando la variable local como const
    complejo result(-r,-i);
    return result;
}

complejo operator -(const complejo& n){
    complejo result(-n.real(),-n.imag());
    return result;
}

bool operator == (const complejo& n1, const complejo& n2){
    if(n1.real() == n2.real() && n1.imag() == n2.imag()) return true;
    else return false;
}


int main(){
    /*complejo v(1.);
    complejo w;
    complejo x(2,-1.2);
    complejo y(x);
    complejo z=y; //preguntar pq funciona con el constructor de copia
    complejo i2 = -1; //preguntar en seminario pq esto funciona sin asignacion
    x= -3.5;*/ //ejercicio 1
    complejo z;
    complejo x(2,-1.2);
    z.real() = 1;
    z.imag() = 1;
    z = x*x;
    //complejo i,d;
    z = x = complejo(3,2);
    if(z == complejo(3,2)) std::cout << "carlos le gustan las pichas" << std::endl;

    //ejercio 3, para este ejercicio en el constructor r no tiene por omision
    complejo* p = new complejo(10); //lo haria 
    complejo* q = new complejo[10]; //no lo haria pq no hay constructor por defecto por lo tanto daria error, debe de estar entonces int i(mirar enunciado) como int i = 0 y ya funcionaria
    //linea 7.
    A a;
    //a = *p; no funciuna pq el this apunta a la clase A y como no existe el operator = entonces peta 
    *p = a; // p* es el complejo no la direccion de memoria por tanto funciona pq llame al operator = (const A&)
    //p = a; // esto no funciona pq no es un comlejo es un puntero(direccion de memoria)
    std::cout << z.real() << std::endl;
}

