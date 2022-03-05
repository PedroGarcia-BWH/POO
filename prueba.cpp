#include <iostream>
#include <exception>
#include <stdexcept>


class real{
    public:
        class invalida{
            public:
                invalida(const char *razon):e(razon) {}
                inline const char* porque() {return e;}
            private:
                const char *e;
        };
        real(int n_);
    private:
        int n;
};

real::real(int n_): n(n_){
    //if(n == 0) throw invalida("por la cara");
}

int main(){
    try{
        real(0);
    /*}catch(...){
        std::cout << "En catch(...)" <<std::endl; //no ejecuta la clase invalida
    }*/
    }catch(real::invalida& e){ //ejecuta la clase invalida
        std::cerr << e.porque() <<std::endl; //cerr igual que cout pero cerr ejecuta cout.flush()
    }
    /*}catch(exception& e){ //preguntar cuando vale
        std::cerr << e.what() <<std::endl; //
    }*/
    
}