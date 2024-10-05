
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
#include <climits>

using namespace std;

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

Para resolver el problema, se recorre el grafo de estados con un algoritmo de búsqueda en anchura (BFS) para encontrar el camino más corto entre el estado inicial y el estado final.
Para marcar que un vertice ha sido visitado se utiliza un vector de distancias, donde cada posición representa un estado y su valor la distancia al estado inicial, inicializando
todas a INT_MAX para que simule que aun no ha sido visitado.

El coste del metodo bfs es O(V), donde V es el número de vértices, teniendo en el caso peor que recorrer todos los nodos del grafo

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
const int MAX_DIGITOS = 10000; // Máximo 4 dígitos.
const int VALOR_MAXIMO = INT_MAX; // máximo valor que puede tener un int

int adyacente(int v, int i) {   
   switch (i){
   case 0:
      return (v + 1) % MAX_DIGITOS; 
   case 1:
      return (v * 2) % MAX_DIGITOS; 
   case 2:
      return v / 3; 
   }
}

int bfs(const int & ini, const int & fin) {    
   if (ini == fin)
      return 0;

   vector<int> distancia(MAX_DIGITOS, VALOR_MAXIMO); // El vector distancia tendrá un espacio MAX_DIGITOS, y cada valor del vector será VALOR_MAXIMO (infinito) para marcar como que aún no ha sido visitado.
   distancia[ini] = 0;                      
   queue<int> q;
   q.push(ini); 
   while (!q.empty()){
      int v = q.front();
      q.pop();
      for (int i = 0; i < 3; i++){
         int w = adyacente(v, i); // Se calcula el siguiente número adyacente por alguna de las operaciones según el valor de la i.
         if (distancia[w] == VALOR_MAXIMO){// Si w no ha sido visitado valor igual a int_max
            distancia[w] = distancia[v] + 1; // Se marca como visitado aumentando la distancia respecto al ini.
            if (w == fin)
               return distancia[w]; // Si resulta que hemos alcanzado el fin, se devuelve la distancia a la que se encuentra del ini.
            else
               q.push(w); 
         }
      }
   }
   return 0;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int ini,fin;
   cin >> ini >> fin;
   if (!cin)  // fin de la entrada
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   int pulsaciones=bfs(ini,fin);
   // escribir la solución
   cout << pulsaciones << "\n";
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
