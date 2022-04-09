#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <valarray>
#include <initializer_list>
using std::valarray;
using std::slice;
using std::slice_array;
using std::initializer_list;

class matriz {
    public:
    // Constructores
    explicit matriz(size_t m = 1, size_t n = 1, double y = 0.0); // constructor por defecto 
    matriz(size_t m, size_t n, double f(size_t i, size_t j)); // constructor con constructor de double
    matriz(const initializer_list<valarray<double>>& l); // lista inicializadoras

    // Copia y movimiento (C++11)
    matriz(const matriz&) = default; // esto le decimos que utilice el que tiene el compilador por defecto
    matriz(matriz&&) = default; // esto le decimos que utilice el que tiene el compilador por defecto
    matriz& operator =(const matriz&) = default; // esto le decimos que utilice el que tiene el compilador por defecto
    matriz& operator =(matriz&&) = default; // esto le decimos que utilice el que tiene el compilador por defecto
    
    
    // Observadores
    size_t filas() const;
    size_t columnas() const;

    // sobrecargas Operadores de indización
    double operator ()(size_t i, size_t j) const;
    double& operator ()(size_t i, size_t j);
    valarray<double> operator [](size_t i) const;
    slice_array<double> operator [](size_t i);
    valarray<double> operator ()(size_t j) const;
    slice_array<double> operator ()(size_t j);

    // Asignación de valor constante
    matriz& operator =(double y);
    // Operadores de asignación compuesta
    matriz& operator +=(const matriz& a);
    matriz& operator -=(const matriz& a);
    matriz& operator *=(const matriz& a);
    matriz& operator *=(double y);
    // Matriz opuesta
    friend matriz operator -(const matriz& a);
    private:
    size_t m, n;
    valarray<double> x;
};

// Prototipos de operadores externos no amigos que trabajan con matrices.
const matriz& operator +(const matriz& a);
matriz operator +(const matriz& a, const matriz& b);
matriz operator -(const matriz& a, const matriz& b);
matriz operator *(const matriz& a, const matriz& b);
matriz operator *(double y, const matriz& a);
matriz operator *(const matriz& a, double y);
// Definiciones en línea .
// Notas:
//
// Este fichero contiene definiciones en línea de funciones y operadores
// relacionados con la clase matriz y se incluye en la cabecera "matriz .h"5 // Por lo tanto , no debe incluirse ni compilarse por separado.
// Constructor : matriz constante
inline matriz::matriz(size_t m, size_t n, double y):
m(m), n(n), x(y, m * n)
{}
// Dimensión.
inline size_t matriz::filas() const
{ return m; }
inline size_t matriz::columnas() const
{ return n; }
// Operadores de indización
// Selección de elemento
inline double matriz::operator ()(size_t i, size_t j) const
{ return x[i * n + j]; }
inline double& matriz::operator ()(size_t i, size_t j)
{ return x[i * n + j]; }
// Selección de fila .
inline valarray<double> matriz::operator [](size_t i) const
{ return x[slice(i * n, n, 1)]; }
inline slice_array<double> matriz::operator [](size_t i)
{ return x[slice(i * n, n, 1)]; }
// Selección de columna.
inline valarray<double> matriz::operator ()(size_t j) const
{ return x[slice(j, m, n)]; }
inline slice_array<double> matriz::operator ()(size_t j)
{ return x[slice(j, m, n)]; }
// Asignación de valor constante
inline matriz& matriz::operator =(double y)
{
    x = y;
    return *this;
}

// Operadores de auto−suma, auto−resta y auto− multiplicación .
inline matriz& matriz::operator +=(const matriz& a)
{
    x += a.x;
    return *this;
}
inline matriz& matriz::operator -=(const matriz& a)
{
    x -= a.x;
    return *this;
}
inline matriz& matriz::operator *=(const matriz& a)
{ return *this = *this * a; }

inline matriz& matriz::operator *=(double y)
{
    x *= y;
    return *this;
}
 // Operadores de signo .
inline const matriz& operator +(const matriz& a)
{ return a; }
inline matriz operator -(const matriz& a)
{
    matriz c(a);
    c.x = -c.x;
    return c;
}

// Operadores de suma y resta .
inline matriz operator +(const matriz& a, const matriz& b)
{ return matriz(a) += b; }
inline matriz operator -(const matriz& a, const matriz& b)
{ return matriz(a) -= b; }
// Operadores de producto por escalar
inline matriz operator *(double y, const matriz& a)
{ return matriz(a) *= y; }
inline matriz operator *(const matriz& a, double y)
{ return y * a; }

// Constructor : matriz definida por una función
matriz::matriz(size_t m, size_t n, double f(size_t i, size_t j)):
m(m), n(n), x(m * n)
{
    for (size_t i = 0; i < m; ++i)
    for (size_t j = 0; j < n; ++j)
    (*this)(i, j) = f(i, j);
}
// Constructor desde lista de filas de la matriz (C++11)
matriz::matriz(const initializer_list<valarray<double>>& l):
m(l.size()), n(l.begin()->size()), x(m * n)
{
auto it = l.begin();
for (size_t i = 0; i < m && it != l.end(); ++i, ++it)
(*this)[i] = *it;
}

// Operador de multiplicación
matriz operator *(const matriz& a, const matriz& b)
{
matriz c(a.filas(), b.columnas()); // Matriz nula
for (size_t i = 0; i < a.filas(); ++i)
for (size_t j = 0; j < b.columnas(); ++j)
c(i, j) = (a[i] * b(j)).sum();
return c;
}

#endif // MATRIZ_H_
