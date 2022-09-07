
class A{
    public:
    A(int i): i(i){}
    A(A& a){}
    private:
    int i;
};