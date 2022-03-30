#include  <iostream>
#include <initializer_list>
using namespace std;

class MatrizDispersa{
    public:
        friend void intercambiar(MatrizDispersa& A, MatrizDispersa& B);
        inline double& valor(size_t indice) {return val[i].v;} //esto faltaria el out of range 
    private:
};
double MatrizDispersa::valor(size_t indice)const{
    if(indice>val.size()) throw out_of_range("Indice fuera de rango");
    return val[indice].v;
}

size_t MatrizDispersa::filas() const noexcept{
    return m;
}

size_t MatrizDispersa::columnas() const noexcept{
    return n;
}

size_t MatrizDispersa::n_valores() const no except{
    return val.size();
}

MatrizDispersa::MatrizDispersa(const initializer_list<terna>& l){
    initializer_list<terna>::iterator it;
    for(it= l.begin(); it != l.end()-1;it++){
        val.push_back((*it));
        it++;
    }
    it++
    if(it->v != 0) val.push_back(it);

    m = it->f;
    n = it->c;
}

int main(){ //suponemos que terna esta en public pq sino no se puede hacer
    MatrizDispersa a(5,4);
    a.asignar(3,0,18.2);
    //a.asignar().....;
    //o se podria hacer esto
    //Matriz dispersa a={terna(0,1,7.5),terna(2,0,18.2)} ...
    try{
        a.asignar(8,6,0);
    }catch(out_of_range& e){
        cout<<"El programa se ha interrumpida por el siguiente motivo: " << e.what() << endl;
    }
}
void intercambiar(MatrizDispersa& A, MatrizDispersa& B){

}
