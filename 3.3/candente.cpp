
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
 
@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct tema {
  string nombre;
  int numeroCitado;
  int ultimaVezCitado;
  tema(string nom="",int n=0,int u=0):nombre(nom), numeroCitado(n),ultimaVezCitado(u){}
  bool operator<(const tema &otro) const {
    return numeroCitado > otro.numeroCitado || (numeroCitado == otro.numeroCitado && ultimaVezCitado > otro.ultimaVezCitado);
  }
};

void imprime(IndexPQ<tema> &cola) {
  int contador = 1;
  vector<pair<int,tema>> perdidos;
  while (!cola.empty() && contador <= 3 && cola.top().prioridad.numeroCitado != 0) {
    auto t = cola.top();
    cout << contador << " " << t.prioridad.nombre << "\n";
    perdidos.push_back({t.elem, t.prioridad});
    cola.pop();
    contador++;
  }
  for(const auto& t: perdidos) {
    cola.push(t.first, t.second);
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
        pair<int, int> &cita = nombresYNumeroCitas[nombre];
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
