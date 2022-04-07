#include <iostream>
#include <valarray>

using namespace std;

class A{
    public:
        A (int i): val(i) {}
        A(valarray<int> val): val(val) {}
        void mostrar(){
            val[1] = 10;
            for (int i = 0 ; i< val.size();i++){
                cout << val[i] << endl;
            }
        }
    private:
    valarray<int> val;
};

int main(){
    A a(1), b(2);
    
    b.mostrar();

}