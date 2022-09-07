#include <iostream>
#include <map>
#include <utility>
class Alumno;
class Asignatura;
class Grupo;

class matriculadoEn{
    public:
        typedef   std::map<Alumno*,std::map<Asignatura*,Grupo*>> AlumAsig;
        typedef   std::map<Asignatura*,std::map<Alumno*,Grupo*>> AsigAlum;
        void asocia(Alumno& Alum, Asignatura& Asig, Grupo& grupo){
            alumasig[&Alum].insert(std::make_pair(&Asig, &grupo));
        }
        void asocia(Asignatura& Asig ,Alumno& Alum, Grupo& grupo){
            asocia(Alum, Asig, grupo);
        }
        const std::map<Asignatura*,Grupo*>& matriculados(Alumno& alum) const{
            typename AlumAsig::const_iterator i = alumasig.find(&alum);
            if(i != alumasig.end()) return std::map<Asignatura*,Grupo*>();
            else return i->second;
        }
        const std::map<Alumno*,Grupo*>& matriculados(Asignatura& asig) const{
             typename AsigAlum::const_iterator i = asigalum.find(&asig);
            if(i != asigalum.end()) return std::map<Alumno*,Grupo*>();
            else return i->second;
        }
    private:
        AlumAsig alumasig;
        AsigAlum asigalum;
};

class A{
    protected: 
        int a = 1;
};
// public == protected 
class B: private A{
    B() {std::cout << a; }       
};

