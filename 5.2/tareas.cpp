
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

#include "Digrafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void dfs(const Digrafo& grafo, int tarea, vector<bool>& visitado, list<int>& tareasEnOrden, vector<bool>& enPila, bool& hayCiclo) {
  
  enPila[tarea] = true;
  visitado[tarea] = true;
  
  for (int adyacente : grafo.ady(tarea)) {
    if (hayCiclo) {
      return;
    }
    
    if (!visitado[adyacente]) {
      dfs(grafo, adyacente, visitado, tareasEnOrden, enPila, hayCiclo);
    } else if (enPila[adyacente]) {
      hayCiclo = true;
      return;
    }
  }
  
  tareasEnOrden.push_front(tarea);
  enPila[tarea] = false;
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int numTareas;
  int numRelaciones;
  
  cin >> numTareas >> numRelaciones;
  
  if (!cin)  // fin de la entrada
    return false;
  
  Digrafo grafo(numTareas);
  bool hayCiclo = false;
  vector<bool> visitado(numTareas, false);
  vector<bool> enPila(numTareas, false);
  list<int> tareasEnOrden;
  
  for (int i = 0; i < numRelaciones; i++) {
    int tareaA, tareaB;
    cin >> tareaA >> tareaB;
    grafo.ponArista(tareaA - 1, tareaB - 1);
  }
  
  for (int i = 0; i < numTareas; ++i) {
    if (!visitado[i]) dfs(grafo, i, visitado, tareasEnOrden, enPila, hayCiclo);
  }
  
  if (hayCiclo) cout << "Imposible";
  else for (int tarea: tareasEnOrden) cout << tarea + 1 << " ";
  cout << '\n';
  
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
