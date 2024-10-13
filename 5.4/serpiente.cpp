
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


/*@ <answer>

Para resolver el problema construimos un grafo dirigido con los extremos que se dan por entrada, metiendolos en un unordered_map. 
Despues, simulamos un recorrido bfs desde el inicio del tablero hasta llegar a su casilla_final que es n*n, en cada iteracion,
se comprobara si tenemos un salto hacia otra casilla para actualizar la posicion y meterla en la cola si no hemos pasado aun por ella.
Tambien comprobamos si hemos llegado a la casilla_final y retormamos la distancia acumulada hasta el momento, es decir, los movimientos
que llevamos en total.

El coste de la funcion resolvver() es de O(n), siendo n el numero total de casillas que tiene el tablero, en el peor de los casos
si no tuviese ningun salto. Todas las demas operaciones relacionadas con el unordered_map son O(1) por la teoria.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


int resolver(unordered_map<int,int>&g,int n, int k) {
   int sol=-1;
   int casilla_final = n * n;
   vector<int> dist(n * n + 1, 0);
   queue<int> cola;
   cola.push(1);
   while (!cola.empty()){
      int casilla_actual = cola.front();
      cola.pop();
      int avance=1;
      while (avance <= k && casilla_actual + avance <= casilla_final){
         int casilla_nueva = casilla_actual + avance;
         if(g.count(casilla_nueva)){
            casilla_nueva = g[casilla_nueva];
         }
         if(dist[casilla_nueva]==0){
            dist[casilla_nueva] = dist[casilla_actual] + 1;
            if (casilla_nueva == casilla_final){
               return dist[casilla_nueva];
            }
            cola.push(casilla_nueva);
         }
         avance++;
      }
   }
   return-1;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n,k,s,e;
   cin >> n >> k >> s >> e;
   if (n == 0 && k == 0 && s == 0 && e == 0)
      return false;
   int v, w;
   unordered_map<int,int>g;
   for (int  i = 0; i < s+e; i++)
   {
      cin >> v >> w;
      g[v] = w;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int sol = resolver(g, n, k);
   // escribir la solución
   cout << sol << '\n';
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
