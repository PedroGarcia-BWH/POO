#include <iostream>
#include <map>

using namespace std;

class Diccionario{
    public:
        explicit Diccionario(string nom = "");
    private:
        map<string,string> dic;
};

Diccionario::Diccionario(s)