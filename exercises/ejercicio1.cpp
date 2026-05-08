#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int v) : dato(v), izquierda(nullptr), derecha(nullptr) {}
};

// Raiz -> Izquierda -> Derecha
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// Izquierda -> Raiz -> Derecha
void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

// Izquierda -> Derecha -> Raiz
void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

// Recorrido por niveles usando cola
void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";
        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha   != nullptr) cola.push(actual->derecha);
    }
}

int main() {
    //       10
    //      /  \
    //     5    15
    //    / \   / \
    //   2   7 12  20

    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha   = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    cout << "=== Ejercicio 1: Recorridos del arbol ===" << endl;
    cout << "Preorden  : "; preorden(raiz);
    cout << "\nInorden   : "; inorden(raiz);
    cout << "\nPostorden : "; postorden(raiz);
    cout << "\nBFS       : "; bfs(raiz);
    cout << endl;

    return 0;
}
