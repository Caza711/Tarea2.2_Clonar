#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int v) : dato(v), izquierda(nullptr), derecha(nullptr) {}
};

// Cuenta todos los nodos del arbol recursivamente
int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha   = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    cout << "=== Ejercicio 3: Contar nodos ===" << endl;
    cout << "Total de nodos: " << contarNodos(raiz) << endl;

    return 0;
}
