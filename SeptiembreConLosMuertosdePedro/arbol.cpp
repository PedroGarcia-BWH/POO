template <class T>
class arbolPropio;
template<class T>
class arbol{
public:
arbol();
arbol(const T& r);
arbol(const T& r, const arbol& sai, const arbol& sad);
~arbol();
bool vacio() const{ return !a; }
const T& raiz() const{
return a->raiz();
}
const arbol& subarbolIzquierdo()const{
return a->subarbolIzquierdo();
}
const arbol& subarbolDerecho() const{
return a->subarbolDerecho();
}
// ...
void inserta(const T& e);
~arbol();
private:
arbolPropio<T>∗ a;
arbol& subarbolIzquierdo(){ return a->subarbolIzquierdo(); }
arbol& subarbolDerecho(){ return a->subarbolDerecho(); }
};
template <class T>
class arbolPropio{
public:
arbolPropio(const T& r);
arbolPropio(const T& r, const arbol<T>& sai,
const arbol<T>& sad);
T& raiz(){ return r; }
arbol<T>& subarbolIzquierdo(){ return sai; }
arbol<T>& subarbolDerecho(){ return sad; }
private:
T r;
arbol<T> sai, sad;
};


template <typename T>
arbol<T>::arbol(){}

template <typename T>
arbol<T>::arbol(const T& r): a(new arbolPropio<T>(r)){}

template <typename T>
arbol<T>::arbol(const T& r,  const arbol& sai, const arbol& sad):
 a(new arbolPropio<T>(r,sai,sad)){}

template <typename T>
arbol<T>::~arbol(){
    delete a;
}

