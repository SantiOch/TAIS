
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class Navegador {
private:
    const int INFINITO = numeric_limits<int>::max();
    vector<int> distancias;
    DigrafoValorado<int> grafo;
    IndexPQ<int> colaPrioridad;
    vector<int> costesNodos;

    void relajarArista(AristaDirigida<int> arista) {
        int origen = arista.desde(), destino = arista.hasta();
        if (distancias[destino] > distancias[origen] + arista.valor() + costesNodos[destino]) {
            distancias[destino] = distancias[origen] + arista.valor() + costesNodos[destino];
            colaPrioridad.update(destino, distancias[destino]);
        }
    }

    void ejecutarDijkstra(int nodoOrigen) {
        distancias[nodoOrigen] = 0 + costesNodos[nodoOrigen];
        colaPrioridad.push(nodoOrigen, 0);
        while (!colaPrioridad.empty()) {
            int nodoActual = colaPrioridad.top().elem; 
            colaPrioridad.pop();
            for (auto arista : grafo.ady(nodoActual))
                relajarArista(arista);
        }
    }
  
public:
    Navegador(int numNodos) : grafo(numNodos), distancias(numNodos, INFINITO), colaPrioridad(numNodos), costesNodos(numNodos) {
        int coste, numAristas;
        for (int i = 0; i < numNodos; ++i) {
            cin >> coste;
            costesNodos[i] = coste;
        }
        cin >> numAristas;
        int origen, destino, valorArista;
        for (int i = 0; i < numAristas; ++i) {
            cin >> origen >> destino >> valorArista;
            grafo.ponArista({ origen - 1, destino - 1, valorArista });
        }
    }

    int obtenerMenorCoste() {
        ejecutarDijkstra(0);
        if (distancias[grafo.V() - 1] == INFINITO) return -1;
        return distancias[grafo.V() - 1];
    }
};

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
  
    Navegador navegador(n);
    int sol = navegador.obtenerMenorCoste();
    if (sol == -1) cout << "IMPOSIBLE\n";
    else cout << sol << '\n';
  
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
