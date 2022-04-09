#include <iostream>
#include <vector>
using namespace std;

class Libro2 {
string titulo_; int pags_;
public:
Libro2(string t, int p=0): titulo_(t), pags_(p) {};
Libro2(const char* c) {};
// ...
};

int main(){
    vector<Libro2> lib3;
    Libro2 lib2 = 5;
}
//mirar si string t lo hace por defecto el compilador de asignacion por defecto

