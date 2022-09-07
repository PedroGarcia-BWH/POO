#include <iostream>
#include <map>
#include <fstream>
#include <utility>
#include <iterator>
using namespace std;
class Diccionario{
    public:
        explicit Diccionario(string nom = string());
        int entradas() const;
        void introduce(string c, string v);
        string traduccion(string c) const;
        pair<string,string>  operator[](int i); 

    private:
        map<string, string> dic; 
};

Diccionario::Diccionario(string filename ){

    if(!filename.empty())
    {
        ifstream file(filename);
        string line, token, token2;

        while(std::getline(file, line))
        {
            token = line.substr(0, line.find(' '));
            token2 = line.substr(line.find(' ')+1, line.size());
            dic[token] = token2;
        }
        file.close();
    }
}

int Diccionario::entradas() const{
    return dic.size();
}

string Diccionario::traduccion(string c) const{
    if(dic.find(c) != dic.end()) return dic.find(c)->second;
    else return string();
}

pair<string,string> Diccionario::operator[](int i){
    if(i < 0 || i > dic.size()) return make_pair<string,string>(string(),string());
    
    typename map<string,string>::iterator it = advance(dic.begin(), i);
    return make_pair<string,string>(*it, it->second);

}
 