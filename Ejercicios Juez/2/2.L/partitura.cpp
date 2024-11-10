
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Grupo {
   int musicos;
   int nPartituras;
};

struct cmp {
   bool operator()(const Grupo &a, const Grupo &b) {
      return a.musicos * b.nPartituras < b.musicos * a.nPartituras;
   }
};

void calcula_partitura(priority_queue<Grupo, vector<Grupo>, cmp> &cola) { 
   Grupo top = cola.top();
   top.nPartituras++;
   cola.pop();
   cola.push(top);
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n,p;
   cin >> p >> n;
   if (!std::cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<Grupo,vector<Grupo>,cmp>cola;
   Grupo grupo;
   int num;
   for (int i = 0; i < n; i++){
      cin >> num;
      grupo.musicos = num;
      grupo.nPartituras = 1;
      cola.push(grupo);
   }
   p -= n;
   for (int i = 0; i < p; i++)  {
      calcula_partitura(cola);
;   }
   Grupo top = cola.top();
   // escribir la solución
   cout << ceil(double(top.musicos) / top.nPartituras);
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
