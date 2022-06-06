#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
//suponemos que < esta sobrecargado
template <typename iterator>
bool ordenado(iterator begin, iterator end){
    if(begin == end) return true;
    for(auto it = begin ; it != end-1; it++){
        if(*it > *(it+1)) return false;
    }

    return true;
}

//parte 2 tenemos que hacer con  funcion lambda
template <typename iterator, typename tipo>
bool ordenado(iterator begin, iterator end, bool (*f)(tipo, tipo)){ // el bool este es miami MIARARLO CON JUANMA COMO SE HACE
    if(begin == end) return true;
    for(auto it = begin ; it != end-1; it++){
        if(f(*it, *(it+1))) return false;
    }

    return true;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8};
    cout << ordenado<vector<int>::iterator, int>(v.begin(), v.end(), [](int t1, int t2) -> bool{return t1 > t2;}) << endl;

    /*vector<int> v ;
     std::ifstream file("datos.dat");
        std::string line;

        while(getline(file, line))
        {
            for(auto it = line.begin(); it != line.end();it++){
                if(*it != ' ') v.push_back(*it);
            }
        }

        cout << ordenado(v.begin(), v.end()) << endl;*/
}