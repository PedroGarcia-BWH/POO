#include <iostream>

//default dice para poder utilizar el metodo por defecto, si se pone dice 
//que utilize el de por defecto del compilador, poniendolo en la declaracion sirve para
//que se de cuetna(para nosotros) que no se nos ha olvidado el constrocutor de copia por ej.


//interna son para metodos que vayamos machacar modificar,
//cuando es una sobrcarga simetrica es mejor declararla externamente, ya que el primer elemento(this), no se puede convertir a otro elemento, por tanto para las simetricas es mejor dejarlas fuera.

matriz A = 3; //no se puede es implicito
matriz B = matriz(5);
matriz C(3);
B = 2; //lo hace
A = matriz(5);
B = static_cast<matriz>(4);