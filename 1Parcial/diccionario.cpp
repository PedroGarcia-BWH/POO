#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Diccionario{
    public:
        explicit Diccionario(string nom = "");
        inline size_t entradas() const { return dic.size();}
        inline void introduce(string pal1, string pal2) { dic[pal1] = pal2;}
        inline string traduccion(string pal1){ return dic[pal1];} 
        pair<string,string> operator [](size_t);
    private:
        map<string,string> dic;
};

Diccionario::Diccionario(string nom){
    fstream fich(nom);
    string cad;
    string pal1, pal2;
    
    while(!getline(fich, cad)){
        pal1 = cad.substr(0,cad.find(" "));
        pal2 =  cad.substr(cad.find(" ")+1, cad.size());

        dic[pal1] = pal2;
    }
}

pair<string,string> Diccionario::operator [](size_t n){
    map<string,string>::iterator it = dic.begin();

    size_t ind = 0;

    while(it != dic.end()){
        if (ind == n) return pair<string,string>(it->first, it->second);
        it++;
        ind++;
    }

    return pair<string,string>("", "");
}




