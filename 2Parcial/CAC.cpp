#include <string>
#include <map>
#include <pair>
using namespace std;


/*class llamada{
    
};

class  operador{

};

struct InfoOperadorLLamada{
    string fecha;
    string hInicio;
    double duracion;
};
        

class OperadorLLamada{
    public:
        void recibir(operador& oper_,llamada& lam, InfoOperadorLLamada& info);
        void asignar(llamada& lam, operador& oper_, InfoOperadorLLamada& info);
        map<llamada*,InfoOperadorLLamada*> llamadas(operador& oper_) const ;
        map<operador*,InfoOperadorLLamada*> asistente(llamada& lam) const;      
    private:
        typedef map<operador*,map<llamada*,InfoOperadorLLamada*>> operadores;
        typedef map<llamada*,map<operador*,InfoOperadorLLamada*>> lamadas;

        operadores oper;
        lamadas llam;
};

void OperadorLLamada::recibir(operador& oper_,llamada& lam, InfoOperadorLLamada& info){
    oper[&oper_].insert(make_pair(&lam, &info));
    llam[&lam].insert(make_pair(&oper_, &info));
}

void OperadorLLamada::asignar(llamada& lam, operador& oper_, InfoOperadorLLamada& info){
    recibir(oper_, lam, info);
}

 map<llamada*,InfoOperadorLLamada*> OperadorLLamada::llamadas(operador& oper_){
    operadores::const_iterator i = oper.find(&oper);
    if(i != oper.end()) return i->second;
    
    else{
        map<llamada*,InfoOperadorLLamada*> vacio;
        return vacio;
        
        }
     
 }

  map<operador*,InfoOperadorLLamada*> OperadorLLamada::asistente(llamada& lam) const{
      lamadas::const_iterator i = llam.find(&lam);
      if(i != llam.end()) return i->second;
      else{
          map<operador*,InfoOperadorLLamada*> vacio;
            return vacio;
      }
      
  } */

///CALIFICADA
class llamada{
    public:
    llamada(string codigo_, string fecha, string hInicio, double duracion): codigo_(codigo_), fecha(fecha), hInicio(hInicio), duracion(duracion) {}
    const operador& asistente() const {return *oper;}
    void asignar(operador& oper_) {oper = &oper_;}
    string codigo() {return codigo_;}

    private:
    operador* oper;
    string codigo_;
    string fecha;
    string hInicio;
    double duracion;
};


class operador{
    public:
        typedef map<string,llamada*> CalificadorLlamada;
        void recibir(llamada& lam){
            llamadas[lam.codigo()] = &lam;
        }
       
        CalificadorLlamada atendidas() const {
            return llamadas;
        }
         
    private:
        CalificadorLlamada llamadas;
};



