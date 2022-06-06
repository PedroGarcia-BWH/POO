#include <iostream>
#include <set>
#include <map>

using namespace std;

class A{

};

class C{
    private:
        int c1;
        A* a;
        B b;
        std::set<D*> d;
};

class B{
    private:
        C* c;
};

class D{
    private:
        C* c;
        B* b;
};


//clase de asocicacion
class rel4{
    public:
        typedef map<C*, set<D*>> CaD;
        typedef map<D*,C*> DaC;

        void asocia(C& c, D& d){
            cad[&c].insert(&d);
            dac[&d] = &c;
        }
        void asocia(D& d, C& c){
            asocia(c,d);
        }

        set<D*> asociados(C& c) const { 
            typename std::map<C*, set<D*>>::const_iterator i = cad.find(&c);
            if( i != cad.end()) return i->second;

            return set<D*>(); 
            
            }
        const C* asociados(D& d) const { 
            typename std::map<D*, C*>::const_iterator i = dac.find(&d);
            if( i != dac.end()) return i->second;

            return nullptr;  
            }
    private:
        CaD cad;
        DaC dac;
};
