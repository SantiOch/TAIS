
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int nDrones, nPilas9V, nPilas1V, horasVuelo;

  priority_queue<int> pilas9V;
  priority_queue<int> pilas1V;
  unordered_multiset<int> almacen9V;
  unordered_multiset<int> almacen1V;
  
  cin >> nDrones;
  
  if (!cin) return false;
  
  cin >> nPilas9V >> nPilas1V;
  
  for (int i = 0; i < nPilas9V; i++) {
    cin >> horasVuelo;
    pilas9V.push(horasVuelo);
  }
  
  for (int i = 0; i < nPilas1V; i++) {
    cin >> horasVuelo;
    pilas1V.push(horasVuelo);
  }
  
  if (pilas1V.size() == 0 || pilas9V.size() == 0) return true;
  
  while (pilas1V.size() > 0 && pilas9V.size() > 0) {
    
    int horasTotales = 0;
    
    for(int i = 0; i < nDrones; i++) {
      if (pilas1V.size() > 0 && pilas9V.size() > 0){
        
        int pila1 = pilas1V.top();
        int pila9 = pilas9V.top();
        
        pilas9V.pop();
        pilas1V.pop();
        
        if(pila1 == pila9) {
          horasTotales += pila1;
        } else if (pila1 > pila9) {
          horasTotales += pila9;
          almacen1V.insert((pila1 - pila9));
        } else {
          horasTotales += pila1;
          almacen9V.insert((pila9 - pila1));
        }
      }
    }
    
    for(auto it = almacen1V.begin(); it != almacen1V.end(); it++) {
      pilas1V.push(*it);
    }
    
    for(auto it = almacen9V.begin(); it != almacen9V.end(); it++) {
      pilas9V.push(*it);
    }
    
    almacen1V.clear();
    almacen9V.clear();
    
    cout << horasTotales << " ";
  }
  
  cout << "\n";
  
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
