#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T1, class T2> class par{
    public:
        par(const T1& x = T1(), const T2& y = T2()): prime(x), segun(y) {}
        T1 primero() const {return prime;}
        T1& primero() const {return prime;}
        T2 segundo() const {return segun;}
        T2& segundo() const {return segun;}
    protected:
        T1 prime;
        T2 segun;
};

template <class T1, class T2>
ostream& operator <<(ostream& os, const par<T1,T2>& P){
    os<< P.primero() << P.segundo() << endl;
    return os;
}

 
template <class T1, class T2>class racional: public par<T1, T2>{
    public:
        racional(const T1& x = T1(), const T2& y = T2()): par(x,y); {}
    private:


};


//funcion rellena
template <typename iterator, typename valor>
iterator rellena(iterator it, size_t n, valor v){
    for(auto i = it ; i < i+n ; i++){
        *i = v;
    }

    if(n > 0 ) return it+n;
    else return it;
}

int main(){
    vector<string> v(16);
    rellena(v.begin(), v.size(), "----------------");
    for(auto i : v){
        cout <<  "\"" << i <<"\""<< " "  << endl;
    }
}