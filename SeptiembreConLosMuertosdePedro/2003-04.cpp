#include <iostream>

using namespace std;

class Cadena{
    public:
        explicit Cadena(unsigned int n = 0): n(n), pc(new char[n+1]) {
            for(int i = 0; i < n; i++){
                pc[i] = ' ';
            }

            pc[n] = '\0';
        }

        Cadena(const char* c){
            char aux = c[0];
            while( aux != '\0'){
                n++;
                aux = c[n];
            }

            pc = new char[n+1];

            char aux = c[0];
            int i = 0;
            while( aux != '\0'){
                pc[i] = c[i];
                i++;
                aux = c[i];
            }

             pc[n] = '\0';
        }

        Cadena operator =(const Cadena& c){
            Cadena n(c.pc);
            return n;
        } 

        char operator[](int i) const{
            if(i < 0 || i > n +1 ) throw AccesoIndebido();
            return pc[i];
        }

        char& operator[](int i){
            if(i < 0 || i > n +1 ) throw AccesoIndebido();
            return pc[i];
        }

        class AccesoIndebido{};

        ostream& operator <<(ostream& os) {}
    private:
        char* pc;
        unsigned int n;
};

template <typename iterator>
bool ordenado(iterator begin, iterator end){
    for(auto i = begin +1; i != end ; i++){
        if(*i < *(i -1)) return false
    }

    return true;
}

template <typename iterator, typename T>
bool ordenado(iterator begin, iterator end, T func){
    for(auto i = begin +1; i != end ; i++){
        if(func(i, i-1)) return false
    }

    return true;
}


struct funcion{
    public:
        bool operator()(int a, int b){
            return a < b;
        }
};

int main(){
    int v[6] = {1,2,3,4,5,6};
    funcion f;
    int a, b;
    cout << ordenado(&v[0], &v[5], f);
}
