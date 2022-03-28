#include <iostream>
#include <cstring>
class Cadena {
    public:
        explicit Cadena(size_t n = 0);
        Cadena(const char* c);
        Cadena& operator =( const Cadena& cad) noexcept;
        const char& operator [](size_t i) const;
        char& operator [](size_t i);
        Cadena& operator +(const Cadena& cad) noexcept;
        friend std::ostream& operator << (std::ostream& os, const Cadena& c);
        class AccesoIndebido{

        };

    private:
        char* pc;
        size_t n;
};

Cadena::Cadena(size_t n): n(n), pc(new char [n+1]){
    for (int i = 0; i<n ; i++){
        pc[i] = ' ';
    }
    pc[n] = '\0';
}

Cadena::Cadena(const char* c): n(strlen(c)), pc(new char [n+1]) {
    /*for (int i = 0; i<n ; i++){
        pc[i] = c[i];
    }
    pc[n] = '\0';*/
    strcpy(pc,c);
}

//Si hace falta un operador de asignacion ya que tenemos memoria dinamica
Cadena& Cadena::operator = (const Cadena& cad) noexcept{
    if(n != cad.n){
        delete [] pc;
        n = cad.n;
        pc = new char[n + 1];
        strcpy(pc,cad.pc);
    }
    return *this;
}

const char& Cadena::operator [](size_t i) const{
    if(i<0 || i>n) throw AccesoIndebido();

    return pc[i];
}

char& Cadena::operator [](size_t i){
    if(i<0 || i>n) throw AccesoIndebido();

    return pc[i];
}

Cadena& Cadena::operator +(const Cadena& cad) noexcept{
    Cadena f(strcat(pc, cad.pc));
    return f;
}

std::ostream& operator << (std::ostream& os, const Cadena& c){
    for(int i=0; i<c.n; i++){
        os<<c.pc[i];
    }
    return os;
}


