#include <iostream>

using namespace std;

class elipse{
    public:
        elipse(double radio_x, double radio_y): radioX(radioX), radioY(radioY) {}
        double radio_x() const {return radioX;}
        double radio_y() const {return radioY;}
        virtual void escala(double factor) { 
            radioX *= factor;
            radioY *= factor;
        }
        
            virtual void escala(double factorX, double factorY) { 
                    radioX *= factorX;
                    radioY *= factorY;
            }

    private:
        double radioX, radioY;
};


class circunferencia: protected elipse{
    public:
        circunferencia(double radio): elipse(radio,radio) {}
         virtual void escala(double factor) {
            cout << "Carlos ha ligado" << endl;
        }
        
    private:
};

/*class figuraPlana: public circunferencia {
    public:
        virtual void escala() = 0;
        virtual void dibujo() = 0;
};*/




int main(){
    //circunferencia c(1);
    //c.escala(1, 2);
    //double u = c.radio_x();
    elipse *c = new circunferencia(1);
    //c.escala(1,1);
}