#include <iostream>
#include <string>

using namespace std;
class empleado{
    public:
        empleado(int nEmpleado, string nombre, string apellidos, string fechaAlta):
        nEmpleado(nEmpleado), nombre(nombre), apellidos(apellidos), fechaAlta(fechaAlta) {}

        
    private:
        int nEmpleado;
        string nombre;
        string apellidos;
        string fechaAlta;
};

class infoGestorTenico: public empleado{
    public:
        infoGestorTenico(int nEmpleado, string nombre, string apellidos, string fechaAlta, int nClientesAtendidos, int nHoras):
        empleado(nEmpleado, nombre,  apellidos, fechaAlta), nClientesAtendidos(nClientesAtendidos), nHoras(nHoras) {}
    private:
        int nClientesAtendidos;
        int nHoras;
};

class infoTenicoDirectivo: public empleado{
    public:
        infoTenicoDirectivo(int nEmpleado, string nombre, string apellidos, string fechaAlta, int telefono, string departamento):
        empleado(nEmpleado, nombre,  apellidos, fechaAlta), nClientesAtendidos(nClientesAtendidos), departamento(departamento) {}
    private:
        int nClientesAtendidos;
        string departamento;
};

class gestor: public infoGestorTenico{
    public:
        gestor(int nEmpleado, string nombre, string apellidos, string fechaAlta, int nClientesAtendidos, int nHoras, string perfil):
         infoGestorTenico(nEmpleado, nombre,  apellidos, fechaAlta, nClientesAtendidos, nHoras), perfil(perfil) {}
    private:
        string perfil;
};

class tecnico: public infoGestorTenico, public infoTenicoDirectivo{
    public:
        tecnico(int nEmpleado, string nombre, string apellidos, string fechaAlta, int nClientesAtendidos, int nHoras, int telefono, string departamento,  string nivel):
         infoGestorTenico(nEmpleado, nombre,  apellidos, fechaAlta, nClientesAtendidos, nHoras),  infoTenicoDirectivo(nEmpleado,nombre, apellidos, fechaAlta, telefono,departamento), nivel(nivel) {}
    private:
        string nivel;
};


class directivo: public infoTenicoDirectivo{
    public:
        directivo(int nEmpleado, string nombre, string apellidos, string fechaAlta, int telefono, string departamento, string cargo):
         infoTenicoDirectivo(nEmpleado, nombre,  apellidos, fechaAlta,  telefono, departamento), cargo(cargo) {}
    private:
        string cargo;
};
