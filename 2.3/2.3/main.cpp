//
//  main.cpp
//  2.3
//
//  Created by Santi Ochoa on 9/20/24.
//


/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 ALEX GUILLERMO BONILLA TACO
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct caja {
  int num;
  int tiempo = 0;
};

bool operator<(const caja &c1, const caja &c2) {
  return c1.tiempo < c2.tiempo || (c1.tiempo == c2.tiempo && c1.num < c2.num);
}

bool resuelveCaso() {

   // leer los datos de la entrada
  int numCaj;
  int numCli;
    
  cin >> numCaj >> numCli;

  if (numCaj == 0 && numCli == 0) return false;
  
  PriorityQueue<caja> cajas;

  for(int i = 1; i <= numCaj; i++) {
    caja c = caja(i);
    cajas.push(c);
  }
  
  for(int i = 0; i < numCli; i++) {
    int clienteActual;
    cin >> clienteActual;
    
    caja actual = cajas.top();
    actual.tiempo += clienteActual;
    cajas.pop();
    cajas.push(actual);
  }
  
  cout << cajas.top().num << endl;
   // resolver el caso posiblemente llamando a otras funciones

   // escribir la solución

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
