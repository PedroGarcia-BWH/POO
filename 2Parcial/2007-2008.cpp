#include <iostream>
#include <set>
using namespace std;
class A {
    public:

    private:
};


class B: public A{
    public:

    private:
};

class E: public A{
    public:

    private:
};

class D{
    set<E*> e;
    set<B*> b;
};

class C{

};

class F: public C, public E{

};
