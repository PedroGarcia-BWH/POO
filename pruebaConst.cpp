#include <iostream>
#include <cmath>


class A{
    public:
        double sqt() const {
            //a = 3; // esto no funcionaria
            int b = 0; //funcionaria ya que dentro del ambito

            b= 3; // funciona tbn

            b = a; // funciona tbn

            b--; //funciona
        return sqrt(2. * 1. + 1. * 1.); } // esto si
    private:
    int a;
};



int main(){
    A a;
    std::cout << a.sqt();
}