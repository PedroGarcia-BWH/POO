#include <set>

class A{};

class B: public A{
    void asociar(D& d_){ d.insert(&d_);}
    std::set<D*> asociados() const { return d;}
    private:
        std::set<D*> d;
};

class E: public A{
    E(D& d_){ d.insert(&d_);}
    void asociar(D& d_){ d.insert(&d_);}
    std::set<D*> asociados() const { return d;}
    private:
        std::set<D*> d;
};

class D{

    private:
        B* b;
};

class C{
    C(const D& d): d(d) {}
    const D& asociado() const {return d;}
    private:
        D d;
};

class F: public C, public F{
    
};
