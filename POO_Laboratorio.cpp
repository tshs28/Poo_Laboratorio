#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto {
public:
    int codigo;
    string nombre;
    double precio;
    int stock;

    Producto(int c, string n, double p, int s) : codigo(c), nombre(n), precio(p), stock(s) {}
};

class Inventario {
private:
    vector<Producto> productos;

public:
    void agregarProducto(int codigo, string nombre, double precio, int stock) {
        Producto nuevoProducto(codigo, nombre, precio, stock);
        productos.push_back(nuevoProducto);
    }

    void mostrarInventario() {
        if (productos.empty()) {
            cout << "No hay productos en el inventario." << endl;
            return;
        }
        for (const auto& producto : productos) {
            cout << "Código: " << producto.codigo << ", Nombre: " << producto.nombre
                << ", Precio: $" << producto.precio << ", Stock: " << producto.stock << endl;
        }
    }

    Producto* buscarProducto(int codigo) {
        for (auto& producto : productos) {
            if (producto.codigo == codigo) {
                return &producto;
            }
        }
        return nullptr;
    }

    void actualizarStock(int codigo, int nuevoStock) {
        Producto* producto = buscarProducto(codigo);
        if (producto) {
            producto->stock = nuevoStock;
            cout << "El stock ha sido actualizado." << endl;
        }
        else {
            cout << "Producto no encontrado." << endl;
        }
    }

    double calcularValorTotal() {
        double valorTotal = 0;
        for (const auto& producto : productos) {
            valorTotal += producto.precio * producto.stock;
        }
        return valorTotal;
    }
};

void mostrarMenu() {
    cout << "Sistema de Inventario" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Mostrar inventario" << endl;
    cout << "3. Buscar producto por código" << endl;
    cout << "4. Actualizar stock" << endl;
    cout << "5. Calcular valor total" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    Inventario inventario;
    int opcion, codigo, stock;
    string nombre;
    double precio;

    while (true) {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese código del producto: ";
            cin >> codigo;
            cout << "Ingrese nombre del producto: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese precio del producto: ";
            cin >> precio;
            cout << "Ingrese stock del producto: ";
            cin >> stock;
            inventario.agregarProducto(codigo, nombre, precio, stock);
            break;
        case 2:
            inventario.mostrarInventario();
            break;
        case 3:
            cout << "Ingrese código del producto: ";
            cin >> codigo;
            if (Producto* producto = inventario.buscarProducto(codigo)) {
                cout << "Código: " << producto->codigo << ", Nombre: " << producto->nombre
                    << ", Precio: $" << producto->precio << ", Stock: " << producto->stock << endl;
            }
            else {
                cout << "Producto no encontrado." << endl;
            }
            break;
        case 4:
            cout << "Ingrese código del producto: ";
            cin >> codigo;
            cout << "Ingrese nuevo stock: ";
            cin >> stock;
            inventario.actualizarStock(codigo, stock);
            break;
        case 5:
            cout << "El valor total del inventario es: $" << inventario.calcularValorTotal() << endl;
            break;
        case 6:
            return 0;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}
