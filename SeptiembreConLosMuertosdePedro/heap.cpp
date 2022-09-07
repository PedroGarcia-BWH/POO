#include <iostream>
#include <vector>
using namespace std;

template <class T>
class monticulo{
    public:
        monticulo();
        monticulo(const vector<T>&)
        void inserta(const T& e){
            m.push_back(e);
            push_heap(m.begin(), m.end());
            sort_heap(m.begin(), m.end());
        }
        void elimina(){
            pop_heap(m.begin(), m.end());
            m.pop_back();
        }
        const vector<T>& ordenacion() const{
            return m;
        }

        operator const vector<T>&(){
            return m;
        }
        ostream& operator <<(ostream& os){
            for(auto i=m.begin(); i != m.end();i++){
                os<< *i;
            }
            return os;
        }
    private:
    vector<T> m;
};


template <class T>
monticulo<T>::monticulo(){
    make_heap(m.begin(), m.end());
}

template <class T>
monticulo<T>::monticulo(const vector<T>& e): m(e){
    make_heap(m.begin(), m.end());
    sort_heap(m.begin(), m.end());
}

