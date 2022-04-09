#include <iostream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

template <typename T>
ostream& operator <<(ostream& os, const vector<set<T>>& vConjuntos){

    for(vector<set<T>>::const_iterator it= vConjuntos.begin() ; it != vConjuntos.end() ; i++){
        os << copy((*it)->begin(), (*it)->end(), os.begin());
    }

    return os;
}

int main(){
    /*ifstream fich("datos.txt");
    string cad;
    vector<set<int>> vector;
    int e;
    while(getline(fich,cad)){
        set<int> conjunto;
        
        while()
        
        conjunto.insert(e);
    }*/

    cout << vector;

}