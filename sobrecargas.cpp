#include <iostream>
#include <initializer_list>
class sobrecargas
{
private:
    /* data */
public:
    sobrecargas(/* args */);

    void argudoMaricon(const std::initializer_list<int>&) {std::cout<<"Argudo maricon";}
    ~sobrecargas();
};

sobrecargas::sobrecargas(/* args */)
{
}

sobrecargas::~sobrecargas()
{
}

int main(){
    sobrecargas a;
    std::initializer_list<int> b = {1,2,3,4,5};
    a.argudoMaricon(b);
}
