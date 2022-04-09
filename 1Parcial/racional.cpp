#include <iostream>

class racional{

    public:
        racional(int num = 0, int den = 1);
        racional inv(const racional& r);
        friend racional operator + (const racional& a, const racional& b);
        friend racional operator - (const racional& a, const racional& b);
        friend racional operator * (const racional& a, const racional& b);
        friend racional operator / (const racional& a, const racional& b);
        friend racional operator + (const racional& a);
        friend racional operator - (const racional& a);
        friend bool  operator == (const racional& a, const racional& b);
        friend bool  operator != (const racional& a, const racional& b);
        friend bool  operator < (const racional& a, const racional& b);
        friend bool  operator <= (const racional& a, const racional& b);
        friend bool  operator > (const racional& a, const racional& b);
        friend bool  operator >= (const racional& a, const racional& b);

    private:
        int n,d;
        static int mdc(int,int);
};  

racional::racional(int num , int den){
    if(den == 0) throw std::invalid_argument("Error, denominador es 0");
     
    num = num / mcd(num,den);
    dem = dem / mcd(num,den);
}

int main (){
    racional r(0,1);
    racional s;
    racional t{4,-8};
    racional u(3);
    racional v = 5;
    racional w = v;
    racional x{w};
    r = t;
    s = racional{9,6};
    v = -4;
}
