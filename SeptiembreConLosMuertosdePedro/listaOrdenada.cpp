#include <iostream>
#include <list>
#include <algorithm>
class ListaOrdenada{
    public:
        size_t contar(double e) const;
    private:
        std::list<double> lista;
};

size_t ListaOrdenada::contar(double e) const{
    return std::count_if(lista.cbegin(), lista.cend(), [](double d1, double d2)->bool{return d1 == d2;});
}