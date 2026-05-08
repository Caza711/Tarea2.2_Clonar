#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int v) : dato(v), izquierda(nullptr), derecha(nullptr) {}
};

// Un nodo es hoja si no tiene hijos
int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz->izquierda == nullptr && raiz->derecha == nullptr)
        return 1;
    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha   = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    cout << "=== Ejercicio 4: Contar hojas ===" << endl;
    cout << "Hojas del arbol: " << contarHojas(raiz) << endl;
    cout << "(Hojas: 2, 7, 12, 20)" << endl;

    return 0;
}
