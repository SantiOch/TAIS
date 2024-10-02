
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#include "IndexPQ.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Para resolver el problema se ha utilizado un unordered_map<string,unordered_set<string>> que representa un grafo no dirigido entre actores y peliculas,
 despues de leer los datos de entrada se recorre el grafo con un bfs desde el actor dado hasta encontrar a KevinBacon o hasta que no haya mas actores.
 Si KevinBacon no esta en el grafo se imprime INF, si se encuentra se imprime el numero de saltos que se han dado para llegar a KevinBacon.
 
 El coste de la solución es O(N * V) donde N es el numero de actores que se quieren buscar en el grafo y V es el numero de vertices del grafo.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct tema {
  string nombre;
  int numeroCitado;
  int ultimaVezCitado;
  
  bool operator<(const tema &otro) const {
    return numeroCitado > otro.numeroCitado || (numeroCitado == otro.numeroCitado && ultimaVezCitado > otro.ultimaVezCitado);
  }
};

void imprime(IndexPQ<tema> cola) {
  int contador = 1;
  while (!cola.empty() && contador <= 3 && cola.top().prioridad.numeroCitado != 0) {
    cout << contador << " " << cola.top().prioridad.nombre << "\n";
    cola.pop();
    contador++;
  }
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n;
  cin >> n;
  if (!std::cin)  // fin de la entrada
    return false;

  IndexPQ<tema> cola(n);
  unordered_map<string, pair<int, int>> nombresYNumeroCitas;
  string letras;
  string nombre;
  int posCola = 0;
  int num;
  for(int i = 0; i < n; i++) {
    cin >> letras;
    
    if (letras == "E") {
      cin >> nombre;
      cin >> num;

      pair<int, int> citas = nombresYNumeroCitas[nombre];
      int numeroCola = citas.first;
      int numeroCitas = citas.second;
      
      cola.update(numeroCola, { nombre, numeroCitas - num, i });
      
    } else if (letras == "C") {
      
      cin >> nombre;
      cin >> num;
      
      tema t(nombre, num, i);
      
      if (nombresYNumeroCitas.find(nombre) == nombresYNumeroCitas.end()) {
        nombresYNumeroCitas[nombre] = { posCola, num};
        cola.push(posCola++, t);
      } else {
        pair<int, int> cita = nombresYNumeroCitas[nombre];
        cita.second += num;
        t.numeroCitado = cita.second;
        cola.update(cita.first, t);
      }
    } else {
      imprime(cola);
      // Resolver
    }
  }
  cout << "---\n";

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
