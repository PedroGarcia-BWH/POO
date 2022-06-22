#include <iostream>
#include <string>
#include <map>
using namespace std;

class operador{
    public:
        typedef map<string, llamada*> llamadas;
        void recibir(llamada& llamada) {
            mamadas[llamada.codigito()] = &llamada;
        }
        llamadas atendidas() const {return mamadas;}
    private:
        llamadas mamadas;

};

class llamada{
    public:
        llamada(string codigo, string fecha,string  horaInicio, double duracion):
            codigo(codigo), fecha(fecha), horaInicio(horaInicio), duracion(duracion) {}
        void asignar(operador& oper) { 
            op = &oper;
        }
        const operador& asistente() const { return *op;}
        string codigito() {return codigo;}
    private:
        string codigo, fecha, horaInicio;
        double duracion;
        operador* op;
};