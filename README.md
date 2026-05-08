# Tarea 2.2 – Recorridos de Árboles Binarios

**Universidad Técnica de Ambato**  
**Facultad de Ingeniería en Sistemas, Electrónica e Industrial**  
**Carrera:** Ingeniería de Software  
**Asignatura:** Estructura de Datos  
**Ciclo:** Enero – Julio 2026

---

## Integrantes

| Nombre | Rol |
|--------|-----|
| Nombre Apellido | Implementación |
| Nombre Apellido | Documentación |
| Nombre Apellido | Pruebas |

---

## Descripción

Implementación de los cuatro recorridos de árboles binarios en C++, partiendo del código base del repositorio docente y extendido con 6 nodos nuevos. Se aplica el caso de uso al Proyecto Final del grupo.

---

## Estructura del repositorio

```
tarea2_2_recorridos_arboles_uta/
├── src/
│   └── main.cpp
├── ejercicios/
│   ├── ejercicio1.cpp
│   ├── ejercicio2.cpp
│   ├── ejercicio3.cpp
│   ├── ejercicio4.cpp
│   └── ejercicio5.cpp
├── capturas/
│   └── consola.png
└── README.md
```

---

## Árbol construido

```
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
      /  \     \      \
    10   25    65      90
          \              \
          28              95
```

- **Nodos base:** 50, 30, 70, 20, 40, 60, 80  
- **Nodos nuevos:** 10, 25, 28, 65, 90, 95

---

## Recorridos

| Recorrido | Resultado |
|-----------|-----------|
| Preorden  | 50 30 20 10 25 28 40 70 60 65 80 90 95 |
| Inorden   | 10 20 25 28 30 40 50 60 65 70 80 90 95 |
| Postorden | 10 28 25 20 40 30 65 60 95 90 80 70 50 |
| BFS       | 50 30 70 20 40 60 80 10 25 65 90 28 95 |

---

## Compilación y ejecución

```bash
g++ src/main.cpp -o recorridos
./recorridos
```

Requiere g++ con soporte C++11 o superior.

---

## Caso de aplicación – Proyecto Final

El árbol modela el plan de estudios de Ingeniería de Software. Cada nodo representa una materia identificada por su código. Los recorridos permiten:

- **Preorden:** exportar materias respetando la jerarquía de prerrequisitos.
- **Inorden:** listar materias en orden ascendente de código (orden de malla).
- **Postorden:** identificar materias sin dependientes para cerrar créditos.
- **BFS:** agrupar materias por semestre (nivel del árbol).

---

## Ejercicios resueltos

| Archivo | Descripción |
|---------|-------------|
| `ejercicio1.cpp` | 4 recorridos del árbol base |
| `ejercicio2.cpp` | Árbol ampliado con nodos 1, 3, 18 y 25 |
| `ejercicio3.cpp` | Función para contar nodos totales |
| `ejercicio4.cpp` | Función para contar hojas |
| `ejercicio5.cpp` | Árbol de módulos del sistema web (Proyecto Final) |

---

## Uso de IA

Se utilizó Claude (Anthropic) como apoyo para generación de código comentado, adaptación del caso real y redacción de documentación. Todo el código fue compilado y verificado por el grupo antes de la entrega.
