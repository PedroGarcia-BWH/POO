class racional{

    public:
        racional(int num = 0, int den = 1);

    private:
        int n,d;
        static int mdc(int,int);
};  


int main (){
    racional r(0,1);
    racional s;
    racional t{4,-8};
    racional u(3);
    racional v = 5;
    racional w = v;
    racional x{w};
    r = t;
    s = racional{9,6};
    v = -4;
}