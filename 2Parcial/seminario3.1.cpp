#include <iostream>
#include <set>
#include <map>
using namespace std;
// namespace std;


class Profesor{
    public:
        void imparte(Grupo* g) { Imp.insert(g);}
    private:
        set<Grupo*> Imp;
};


class Grupo{
    public:

    private:
        Profesor* prof;
        Asignatura* asig;
};

class Asignatura{
    public:

    private:
        set<Grupo*> Imp;
         map<Alumno*, Grupo*> asigGrupo;
};

class Alumno{
    public:
        void matriculado_en(Asignatura* a, Grupo* g) { asigGrupo[a] = g;}
    private:
        map<Asignatura*, Grupo*> asigGrupo;
};

class Alumno_Asignatura{
    public:
        void matriculado_en(Alumno* a, Asignatura* asig, Grupo* g) { AlumAsig[a] = make_pair(asig, g)}
        set<std::pair<Asignatura*,Grupo*>> matriculados(Alumno* a) { return AlumAsig[a];}
    private:
     map<Alumno*, set<std::pair<Asignatura*,Grupo*>>> AlumAsig;
     map<Asignatura*, set<std::pair<Alumno*,Grupo*>>> AsigAlim;

};

struct x { int x;}
struct c: public x{ int c;}
