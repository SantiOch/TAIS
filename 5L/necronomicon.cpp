
/*@ <authors>
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

   Para resolver el problema contruimos un grafo dirigido con la plantilla Digrafo.h, dependiendo de la operacion
   ponemos las aristas y añadimos un vertice mas para marcarnos el final. Despues creamos un objeto de la clase necronomicon que
   recibe el grafo y hace una busqueda en profundidad para ver si hay un ciclo y si llegamos a visitar el ultimo vertice. 
   Si llegamos al final y hay un ciclo imprimimos "A VECES", si llegamos al final y no hay ciclo imprimimos "SIEMPRE" y 
   si no llegamos al final imprimimos "NUNCA".
   Los vertices del grafo representan las instrucciones y las aristas representan los saltos que se pueden hacer entre instrucciones.

   El coste de la solucion es O(V+A) donde V es el numero de vertices y A el numero de aristas. Ya que recorremos todos los vertices
   y aristas del grafo en la busqueda en profundidad, y hacemos operaciones de coste constante.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Necronomicon {
private:
   vector<bool> visitados;
   vector<bool> enPila;
   bool cicloDetectado;
public:
   Necronomicon(Digrafo const & grafo) : visitados(grafo.V(), false), enPila(grafo.V(), false), cicloDetectado(false) {
      dfs(grafo, 0);
   };

   bool finalLlegado() {
      return visitados[visitados.size() - 1];
   }
   bool huboCiclo() {
      return cicloDetectado;
   }
   void dfs(Digrafo const & grafo, int verticeActual) {
      visitados[verticeActual] = true;
      enPila[verticeActual] = true;
      for (int adyacente : grafo.ady(verticeActual)) {
         if (!visitados[adyacente]) {
            dfs(grafo, adyacente);
         } else if (enPila[adyacente]) {
            cicloDetectado = true;
         }
      }
      enPila[verticeActual] = false;
   }
};

bool resuelveCaso() {

   // leer los datos de la entrada
   int l;
   cin>> l; // Tamaño del grafo
   if (!std::cin)  // fin de la entrada
      return false;
   Digrafo g(l + 1); // Lo hacemos uno mas grande para marcar el final
   char op;
   int n;
   for (int i = 0; i < l; i++) { // Iteramos y vamos añadiendo las aristas
      cin >> op;
      
      if(op =='J'){ // Si es J ponemos una arista la instruccion a la que salta
         cin >> n;
         g.ponArista(i, n - 1);
      } else if(op =='C') { // Si es C ponemos dos aristas, una a la siguiente instruccion y otra al final
         cin >> n;
         g.ponArista(i, i + 1);
         g.ponArista(i, n - 1);
      } else { // Si es A ponemos una arista a la siguiente instruccion
         g.ponArista(i, i + 1);
      }
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   Necronomicon necro(g); // Creamos el objeto necronomicon
   
   // escribir la solución
   if(necro.finalLlegado()) { // Ha llegado al final
      cout << (necro.huboCiclo() ? "A VECES\n" : "SIEMPRE\n"); // Si hay ciclo o no
   }
   else cout << "NUNCA\n";  // Si no llegamos al final
   
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
