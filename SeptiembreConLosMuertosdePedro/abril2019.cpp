#include <iostream>

class racional{
    public: 
        racional(int n = 0, int d = 1);
        racional inv();

        friend racional operator +(const racional& r1, const racional& r2);
        friend racional operator -(const racional& r1, const racional& r2);
        friend racional operator *(const racional& r1, const racional& r2);
        friend racional operator /(const racional& r1, const racional& r2);


        racional operator +();
        racional operator -();

        friend bool operator ==(const racional& r1, const racional& r2);
        friend bool operator !=(const racional& r1, const racional& r2);
        friend bool operator <(const racional& r1, const racional& r2);
        friend bool operator <=(const racional& r1, const racional& r2);
        friend bool operator >(const racional& r1, const racional& r2);
        friend bool operator >=(const racional& r1, const racional& r2);
        private: 
            int n, d;
            static int mcd (int i, int n) {}
};

racional::racional(int n, int d): n(n/mcd(n,d)), d(d/mcd(n,d)){
    if(d == 0) throw std::invalid_argument("0 como denominador no se puede");

    if(d < 0) {
        d = -d;
        n = -n; 
    }
}

inline racional racional::inv(){
    if(n == 0) return racional();

    if(n < 0){
        return racional(-d, -n);
    }

    return racional (d,n);
}

inline racional racional::operator+(){
    return *this;
}

inline racional racional::operator-(){
    return racional(-n,d);  
}

racional operator-(const racional& r1, const racional& r2){
    int mcd = racional::mcd(r1.d, r2.d);
    return racional(r1.n*(mcd/r1.d) - r2.n*(mcd/r2.d), mcd);
}

racional operator*(const racional& r1, const racional& r2){
    return racional(r1.n * r2.n, r1.d * r2.d);
}

bool operator ==(const racional& r1, const racional& r2){
    if(r1.n == r2.n && r1.d == r2.d) return true;

    return false;
}

bool operator !=(const racional& r1, const racional& r2){
    return !(r1 == r2);
}


