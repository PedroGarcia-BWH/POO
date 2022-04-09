#include <iostream>
#include <cstring>
using namespace std;
    class Libro {
    char* titulo;
    int paginas;
    public:
    Libro() : titulo (new char[1]), paginas (0) { *titulo = 0; }
    Libro(const char* t, int p) : paginas (p)
    {
    titulo = new char[strlen(t) + 1];
    strcpy(titulo , t);
    }

    Libro& operator ++();
    Libro operator ++(int);
    ~Libro() { delete [] titulo ; }
    void pagina(int p) { paginas = p; }
    int pagina() const { return paginas; }
    char* titulos() const { return titulo ; }
    };

   void mostrar(Libro l) noexcept
    { cout << l.titulos() << " tiene " << l.pagina() << " paginas" << endl; }

    Libro& Libro::operator ++(){
        paginas++;
        return *this;
    }

    Libro Libro::operator ++(int){
        Libro aux(*this);
        paginas ++;

        return aux;
    }

    int main()
    {
        Libro l1("Fundamentos de C++", 474),
        l2("Por Fin: C ISO", 224),
        l3;
        mostrar(l3);
        Libro l4(l2);
        l3 = l1;
        l3++;
        ++l3;
        mostrar(l1), mostrar(l2), mostrar(l3);mostrar(l4);
        cout << " Hola";
    }

    