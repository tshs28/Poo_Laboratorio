#include <iostream>
using namespace std;

class SerVivo {
protected:
    string nombre;
    int edad;
public:
    SerVivo(string n, int e) : nombre(n), edad(e) {}
    virtual void emitirSonido() {
        cout << nombre << " emite un sonido." << endl;
    }
};

class Perro : public SerVivo {
public:
    Perro(string n, int e) : SerVivo(n, e) {}
    void emitirSonido() override {
        cout << nombre << " ladra: Gua Gua!" << endl;
    }
};

class Vehiculo {
private:
    string marca;
    int velocidad;
public:
    Vehiculo(string m, int v) : marca(m), velocidad(v) {}
    void acelerar() {
        velocidad += 20;
        cout << "El vehículo " << marca << " ahora va a " << velocidad << " km/h." << endl;
    }
};

class Humano {
private:
    string nombre;
    int edad;
public:
    Humano(string n, int e) : nombre(n), edad(e) {}
    void presentarse() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    Perro miPerro("Polizon", 3);
    miPerro.emitirSonido();

    Vehiculo miMoto("Yamaha", 80);
    miMoto.acelerar();

    Humano persona2("Sebas", 19);
    persona2.presentarse();

    return 0;
}
