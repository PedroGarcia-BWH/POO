#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class monticulo{
    public:
        monticulo();
        monticulo(const vector<T>&);
        void insertar(const T& elem);
        void eliminar();
        operator const vector<T>*();
        friend ostream& operator << (ostream&, const monticulo<T>&); 
    private:
        vector<T> pila;
        size_t n;
};

template <typename T>
monticulo<T>::monticulo(): pila(vector<T>()), n(0) {}

template <typename T>
monticulo<T>::monticulo(const vector<T>& v): pila(v), n(v.size()) {
    make_heap(pila.begin(), pila.end());  
}

template <typename T>
void monticulo<T>::insertar(const T& elem){
    pila.push_back(elem);
    push_heap(pila.begin(), pila.end());
    n++;
}

template<typename T>
void monticulo<T>::eliminar(){
    if(n != 0){
        pop_heap(pila.begin(), pila.end());
        pila.pop_back();    
        n--;
    }
}

template <typename T>
monticulo<T>::operator const vector<T>*(){
    return &pila;
}
template<typename T>
ostream& operator << (ostream& os , const monticulo<T>& m){
    for(auto it : m.pila){
        os << it;
    }
}