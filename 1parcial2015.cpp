#include <iostream>

class Vector{
    public:
        explicit Vector(size_t n_, double num = 0);
        Vector(const std::initializer_list<double>& l);
        Vector(const Vector& v);
        Vector(Vector&& v);
        double at(int i) const;
        double& at(int i);

        ~Vector();

    private:
        size_t n;
        double* datos;
};

Vector::Vector(size_t n_, double num): n(n_), datos(new double[n]){
    for(int i=0; i<n;i++){
        datos[i] = num;    
    }
}

Vector::Vector(const Vector& v): n(v.n), datos(new double[n]){
    for(int i=0; i<n;i++){
        datos[i] = v.datos[i];   
    }
}

Vector::Vector(Vector&& v): n(v.n), datos(new double[n]){
    for(int i=0; i<n;i++){
        datos[i] = v.datos[i];   
    }
    v.~Vector(); //llamamos al destructor
}

double Vector::at(int i) const {
    if(i<0 || i>=n ) throw std::out_of_range("Vector::at, índice fuera de rango");

    return datos[i];

}

double& Vector::at(int i){
     if(i<0 || i>=n ) throw std::out_of_range("Vector::at, índice fuera de rango");

     return datos[i];
}


Vector::~Vector(){
    delete[] datos;
}

Vector::Vector(const std::initializer_list<double>& l): n(l.size()), datos(new double[n]){
    std::initializer_list<double>::iterator it = l.begin();

    int i = 0;
    while(it != l.end()){
        datos[i] = *it;
        it++;
        i++;
    }
}

int main(){
    Vector v1(5, 1.2);
    Vector v2(4); //v2={0, 0, 0, 0}
    Vector v5={1,2.5,3}; //v5={1,2.5,3}

    const Vector v6={1,2,3,4,5,6};
    Vector v7(6);
    try{
    v7.at(0)=v6.at(9);
    }catch (std::out_of_range& e){
    std::cout << e.what() << std::endl;
    }
}




