
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

#include "Digrafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {
  
  // leer los datos de la entrada
  int nodos;
  int aristas;
  cin >> nodos;
  
  if (!cin)  // fin de la entrada
    return false;
  
//  Digrafo g(nodos);
  
  vector<vector<bool>> matriz(nodos, vector<bool>(nodos, false));
  
  cin >> aristas;
  
  for (int i = 0; i < aristas; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    matriz[n1][n2] = true;
  }
  
//  Digrafo inverso = g.inverso();

  bool sumidero = true;
  int numSumidero = 0;
  
  for (int i = 1; i < nodos; i++) {
    if (matriz[numSumidero][i]) numSumidero = i;
  }
  
  for(int i = 0; i < nodos; i++) {
    if (i != numSumidero){
      if (!matriz[i][numSumidero]) sumidero = false;
      if (matriz[numSumidero][i]) sumidero = false;
    }
  }
  
//  for (int i = 0; i < nodos; i++) {
//    auto gradoSalida = g.ady(i).size();
//    auto gradoEntrada = inverso.ady(i).size();
//    if (gradoEntrada == g.V() - 1 && gradoSalida == 0) {
//      sumidero = true;
//      numSumidero = i;
//      break;
//    }
//  }
  
  // Esribir solucion
  if (sumidero) {
    cout << "SI " << numSumidero << "\n";
  } else {
    cout << "NO\n";
  }

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
