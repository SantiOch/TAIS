
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
 
 La solución se basa en el uso de una cola de prioridad indexada (IndexPQ) para gestionar los temas y sus citas. 
 Cada tema se almacena en un mapa (unordered_map) que permite acceder rápidamente a los datos de cada tema y su posicion en la cola para cuando
 se necesite cambiar la prioridad.
 
 El coste de las operaciones de añadir y eliminar citas es O(log n), donde n es el número de temas en la cola de prioridad.
 Imprimir por pantalla tiene un coste constante para cada uno de los tres temas más citados, más el coste de restaurar la cola, 
 que es O(log n) por cada tema restaurado, ya que la insercion en una cola de prioridad es logarítmica respecto al numero de elementos.
  
@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Tema {
   string nombre;
   int numeroCitado;
   int ultimaVezCitado;

   Tema(string nom = "", int n = 0, int u = 0): nombre(nom), numeroCitado(n), ultimaVezCitado(u) { }
   
   bool operator<(const Tema &otro) const {
      return numeroCitado > otro.numeroCitado || (numeroCitado == otro.numeroCitado && ultimaVezCitado > otro.ultimaVezCitado);
   }
};

struct DatosTema {
   int posicionCola;
   int numCitas;
};

void imprime(IndexPQ<Tema> &cola) {
   int contador = 1;
   vector<pair<int, Tema>> perdidos;
   while (!cola.empty() && contador <= 3 && cola.top().prioridad.numeroCitado != 0) {
      auto t = cola.top();
      cout << contador << " " << t.prioridad.nombre << "\n";
      perdidos.push_back( {t.elem, t.prioridad} );
      cola.pop();
      contador++;
   }
   for(const auto& t: perdidos) {
      cola.push(t.first, t.second);
   }
}

bool resuelveCaso() {
    int numOperaciones;
    cin >> numOperaciones;
    if (!cin) return false;

    IndexPQ<Tema> cola(numOperaciones);
    unordered_map<string, DatosTema> mapaTemas;
    string comando, nombreTema;
    int numCitas, posicionCola = 0;

    for (int i = 0; i < numOperaciones; i++) {
         cin >> comando;
         if (comando == "E") {
            cin >> nombreTema >> numCitas;
             auto& datosTema = mapaTemas[nombreTema];
             datosTema.numCitas -= numCitas;
             cola.update(datosTema.posicionCola, {nombreTema, datosTema.numCitas});
         } else if (comando == "C") {
            cin >> nombreTema >> numCitas;
             Tema nuevoTema(nombreTema, numCitas, i);
             if (mapaTemas.find(nombreTema) == mapaTemas.end()) {
                  mapaTemas[nombreTema] = {posicionCola, numCitas};
                  cola.push(posicionCola++, nuevoTema);
             } else {
                  auto& datosTema = mapaTemas[nombreTema];
                  datosTema.numCitas += numCitas;
                  nuevoTema.numeroCitado = datosTema.numCitas;
                  cola.update(datosTema.posicionCola, nuevoTema);
             }
         } else {
             imprime(cola);
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
