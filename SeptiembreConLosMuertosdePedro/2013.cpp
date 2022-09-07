#include <iostream>

using namespace std;

template<class T1, class T2> class par{
public:
par(): prime(T1()), segun(T2()) {}
par(const T1& x, const T2& y): prime(x), segun(y){}
T1 primero() const{return prime;}
T1& primero() {return prime;}
T2 segundo() const{return segun;}
T2& segundo() { return segun;}
private:
T1 prime;
T2 segun;
};

template <class T1, class T2>
ostream& operator << (ostream& os, const par<T1,T2>& P){
    os << P.primero() << " " << P.segundo() << endl;
    return os;
}

template<class T1, class T2>
class racional: public par<T1,T2>{
    public:
        racional(const T1& x, const T2& y): par<T1,T2>(x,y) {}
    private:
        
};

template<class T1, class T2>
racional<T1,T2> operator +(const racional<T1,T2>& r1, const racional<T1,T2>& r2){
    racional<T1, T2> r3(r1.primero()+ r2.primero(), r1.segundo()*r2.segundo());
    return r3;
}

class complejo: public par<double,double>{
    public:
        complejo(): par<double,double>() {}
        complejo(double c1, double c2): par<double,double>(c1,c2) {}
};



int main(){
    par<int,int> P(1,2);
    cout << P;
    racional<int, int> r1(1,2), r2(2,4);
    racional<int, int> r3(1,2);
    r3 = r1 + r2;
    complejo c1(1,2);
}