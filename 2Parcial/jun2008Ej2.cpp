#include <set>

using namespace std;


class Asignatura{
    set <Grupo> g; 
    public:

};


class Grupo{
    Asignatura a; // esto lo ponemos para facilitar las cosas pero no haria falta ponerlo en la composicion
    set<Alumno*> alum;
    Profesor* prof;

    public:
        void añadirAlumno(Alumno& a) { alum.insert(&a);}
        set<Alumno*> AlumnosGrupo() { return alum;}
};

class Alumno{
    set<Grupo*> grup;
};

class Profesor{
    set<Grupo*> grup;
};