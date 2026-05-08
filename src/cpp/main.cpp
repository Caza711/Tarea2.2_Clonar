#include <iostream>
#include <queue>
using namespace std;

// Nodo del arbol binario
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// Raiz -> Izquierda -> Derecha
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// Izquierda -> Raiz -> Derecha (orden ascendente en BST)
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
    // Nodos base del repositorio
    Nodo* raiz = new Nodo(50);
    raiz->izquierda = new Nodo(30);
    raiz->derecha   = new Nodo(70);
    raiz->izquierda->izquierda = new Nodo(20);
    raiz->izquierda->derecha   = new Nodo(40);
    raiz->derecha->izquierda   = new Nodo(60);
    raiz->derecha->derecha     = new Nodo(80);

    // Nodos nuevos agregados (6 nodos)
    raiz->izquierda->izquierda->izquierda        = new Nodo(10);
    raiz->izquierda->izquierda->derecha          = new Nodo(25);
    raiz->izquierda->izquierda->derecha->derecha = new Nodo(28);
    raiz->derecha->izquierda->derecha            = new Nodo(65);
    raiz->derecha->derecha->derecha              = new Nodo(90);
    raiz->derecha->derecha->derecha->derecha     = new Nodo(95);

    cout << "=== RECORRIDOS DE ARBOLES BINARIOS - UTA ===" << endl;

    cout << "Preorden  : "; preorden(raiz);
    cout << "\nInorden   : "; inorden(raiz);
    cout << "\nPostorden : "; postorden(raiz);
    cout << "\nBFS       : "; bfs(raiz);
    cout << endl;

    return 0;
}
