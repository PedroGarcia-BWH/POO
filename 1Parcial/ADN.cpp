#include <iostream>
#include <cstring>

class ADN{
    public: 
        ADN();
        ADN(const char* c);
        friend ADN operator +(const ADN& A, const ADN& B);
    private:
        char* c;
        size_t n;
        ADN(const char* c, size_t n);
};

ADN::ADN():n(0), c(nullptr){}

ADN::ADN(const char* c, size_t n):n(n), c(new char[n+1]){
    for(size_t i = 0; i<n;i++){
        this->c[i] = c[i];
    }
}

ADN::ADN(const char* c):n(strlen(c)),c(new char[strlen(c)]){
    for(size_t i = 0; i<n;i++){
        //if(c[i] == "A" )
        this->c[i] = c[i];
    }
}

ADN operator + (const ADN& A, const ADN& B){
    ADN C(A.c,A.n + B.n);
    memcpy(C.c + A.n, B.c, sizeof(char));

    return C; 
}

int main(){
    const char* const s = "GA";
    ADN a(s), b(a);
    //b[0] = C;

    ADN((a + ADN c("TTA") + b)).mostrar();
}