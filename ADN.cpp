#include <iostream>

class ADN{
    public: 
        ADN();
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

