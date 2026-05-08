#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Nodo {
    string dato;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(string v) : dato(v), izquierda(nullptr), derecha(nullptr) {}
};

// Preorden: util para mostrar el menu principal (raiz primero)
void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << endl;
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// Postorden: procesa modulos internos (hojas) antes que el padre
void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << endl;
}

// BFS: muestra modulos nivel por nivel (por semestre/capa)
void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    int nivel = 0;
    while (!cola.empty()) {
        int tam = cola.size();
        cout << "  Nivel " << nivel << ": ";
        for (int i = 0; i < tam; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            cout << actual->dato;
            if (i < tam - 1) cout << ", ";
            if (actual->izquierda != nullptr) cola.push(actual->izquierda);
            if (actual->derecha   != nullptr) cola.push(actual->derecha);
        }
        cout << endl;
        nivel++;
    }
}

int main() {
    //         Sistema Web
    //        /           \
    //   Usuarios       Inventario
    //    /    \          /      \
    // Registrar Buscar Productos Reportes

    Nodo* raiz = new Nodo("Sistema Web");
    raiz->izquierda = new Nodo("Usuarios");
    raiz->derecha   = new Nodo("Inventario");
    raiz->izquierda->izquierda = new Nodo("Registrar");
    raiz->izquierda->derecha   = new Nodo("Buscar");
    raiz->derecha->izquierda   = new Nodo("Productos");
    raiz->derecha->derecha     = new Nodo("Reportes");

    cout << "=== Ejercicio 5: Sistema Web - Proyecto Final ===" << endl;

    cout << "\n1. Menu principal (Preorden - raiz primero):" << endl;
    preorden(raiz);

    cout << "\n2. Modulos internos primero (Postorden - hojas primero):" << endl;
    postorden(raiz);

    cout << "\n3. Modulos por nivel (BFS - capa por capa):" << endl;
    bfs(raiz);

    return 0;
}
