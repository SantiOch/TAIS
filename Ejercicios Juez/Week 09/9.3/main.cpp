
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

// función que resuelve el problema
int resolver(vector<int> & pilas, int umbral) {
  
  sort(pilas.begin(), pilas.end());
  int ok = 0, i = 0, j = pilas.size() - 1;
  
  while (i < j) {
    if (pilas[i] + pilas[j] >= umbral) { //si vale descarto las 2 pilas
      ++i; --j;
      ++ok;
    }
    else { //si no vale, solo descarto la pila de menor valor
      ++i;
    }
  }
  return ok;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  
  // leer los datos de la entrada
  int n, umbral, pila;
  cin >> n >> umbral;
  vector<int> pilas;
  while (n > 0) {
    cin >> pila;
    pilas.push_back(pila);
    n--;
  }
  cout << resolver(pilas, umbral) << '\n';
  // escribir solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
