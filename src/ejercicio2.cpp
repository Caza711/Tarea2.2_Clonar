#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int v) : dato(v), izquierda(nullptr), derecha(nullptr) {}
};

void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

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
    //           10
    //          /  \
    //         5    15
    //        / \   / \
    //       2   7 12  20
    //      / \       /  \
    //     1   3     18   25

    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha   = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha   = new Nodo(7);
    raiz->derecha->izquierda   = new Nodo(12);
    raiz->derecha->derecha     = new Nodo(20);

    // Nodos nuevos: 1, 3, 18, 25
    raiz->izquierda->izquierda->izquierda = new Nodo(1);
    raiz->izquierda->izquierda->derecha   = new Nodo(3);
    raiz->derecha->derecha->izquierda     = new Nodo(18);
    raiz->derecha->derecha->derecha       = new Nodo(25);

    cout << "=== Ejercicio 2: Arbol con nodos 1, 3, 18 y 25 ===" << endl;
    cout << "Preorden  : "; preorden(raiz);
    cout << "\nInorden   : "; inorden(raiz);
    cout << "\nPostorden : "; postorden(raiz);
    cout << "\nBFS       : "; bfs(raiz);
    cout << endl;

    return 0;
}
