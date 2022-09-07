#include <iostream>
#include <map>
#include <set>
using namespace std;
class A{
    public:
        typedef std::map<int,C*> Cc;
        void asocia(int c1,  C& cc){ 
            //c.insert(pair<int, C*>(c1,&cc));
            c[c1] = &cc;
        }

        const Cc& asociados() const { return c;}
    private:
        Cc c;
};


class C{
    public:
        C(const B& b): b(b) {}
        void asocia (const B& b_) { b = b_;}
        const B& asociado() const { return b;}
    private:
        B b;
};

class B {
    public:
         typedef std::set<D*> Dd;
         void asocia (D& b_) { d.insert(&b_)}
        const Dd& asociado() const { return d;}
    private:
        Dd d;
};

class D { 
    public:
        
    private:

};


class rel4{
    public:
        typedef std::map<C*, std::set<D*>> cd;
        typedef std::map<D*, C*> dc;
        void asocia(C& c, D& d){
            CD[&c].insert(&d);
            DC[&d] = &c;
        }
        void asocia(D& d, C& c){
            asocia(c,d);
        }
        std::set<D*> asociados(C& c) const {
            if( CD.find(&c) != CD.end()) return (CD.find(&c))->second;
            set<D*> d;
            return d;
        }
        const C& asociados(D& d) const {
            
            if( DC.find(&d) != DC.end()) return (DC.find(&d))->second;
            B b;
            C c(b);
            return c;
        }
    private:
        cd CD;
        dc DC;
};