
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// #include "" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool bfs(unordered_map<string,unordered_set<string>> &grafo,unordered_map<string,int>&distancias){
   string kevin_bacon="KevinBacon";
   if(grafo.find(kevin_bacon)==grafo.end())
      return false;
   else{
      queue<string> cola;
      unordered_map<string, bool> visitados;
      visitados[kevin_bacon] = true;
      distancias[kevin_bacon] = 0;
      cola.push(kevin_bacon);
      while (!cola.empty())
      {
         string actual = cola.front();
         cola.pop();
         for (auto nombre : grafo[actual])
         {
            if (visitados.find(nombre) == visitados.end())
            {
               distancias[nombre] = distancias[actual] + 1;
               visitados[nombre] = true;
               cola.push(nombre);
            }
         }
      }
      return true;
   }
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int p;
   cin>>p;
   if (!std::cin)  // fin de la entrada
      return false;
   unordered_map<string,unordered_set<string>>grafo;
   unordered_map<string,int>distancias;
   string pelicula,actor;
   int num_act;
   for (int i = 0; i < p; i++)
   {
      cin>>pelicula;
      cin>>num_act;
      distancias[pelicula]=-1;
      for (int j = 0; j < num_act; j++)
      {
         cin>>actor;
         grafo[pelicula].insert(actor);
         grafo[actor].insert(pelicula);
         distancias[actor]=-1;
      }
      
   }
   int N;
   cin>>N;

   // resolver el caso posiblemente llamando a otras funciones
   bool solucion=bfs(grafo,distancias);
   // escribir la solución
   int numero_bacon;
   for (int i = 0; i < N; i++)
   {
      cin>>actor;
      if(!solucion||distancias.find(actor)==distancias.end()||distancias[actor]==-1){
         cout << actor <<" INF\n";
      }else{
         numero_bacon = distancias[actor] / 2;
         cout << actor <<" " << numero_bacon << "\n";
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
