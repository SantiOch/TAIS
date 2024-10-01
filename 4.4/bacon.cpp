
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
 
 Para resolver el problema se ha utilizado un unordered_map<string,unordered_set<string>> que representa un grafo no dirigido entre actores y peliculas,
 despues de leer los datos de entrada se recorre el grafo con un bfs desde el actor dado hasta encontrar a KevinBacon o hasta que no haya mas actores.
 Si KevinBacon no esta en el grafo se imprime INF, si se encuentra se imprime el numero de saltos que se han dado para llegar a KevinBacon.

El coste de la solución es O(N * V) donde N es el numero de actores que se quieren buscar en el grafo y V es el numero de vertices del grafo.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int bfs(unordered_map<string,unordered_set<string>> &grafo,const string&actor){
   int res=-1;
   bool encontrado = false;
   if(actor == "KevinBacon"){
      res = 0;
      encontrado = true;
   }
   if(grafo.find("KevinBacon") == grafo.end()){
      encontrado = true;
   }
   queue<string>cola;
   unordered_map<string,int>distancias;
   unordered_map<string,bool>visitados;
   visitados[actor] = true;
   distancias[actor] = 0;
   cola.push(actor);
   while (!cola.empty()&&!encontrado)
   {
      string actual = cola.front();
      cola.pop();
      for (auto nombre : grafo[actual])
      {
         if(visitados.find(nombre) == visitados.end()){
            distancias[nombre] = distancias[actual] + 1;
            visitados[nombre] = true;
            cola.push(nombre);
            if(nombre == "KevinBacon"){
               encontrado = true;
               res = distancias[nombre]/2;
            }
         }
      }
   }
   return res;
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int p;
   cin>>p;
   if (!std::cin)  // fin de la entrada
      return false;
   unordered_map<string,unordered_set<string>>grafo;
   unordered_map<string,bool> visitados;
   string pelicula,actor;
   int num_act;
   for (int i = 0; i < p; i++)
   {
      cin>>pelicula;
      cin>>num_act;
      visitados[pelicula] = false;
      for (int j = 0; j < num_act; j++)
      {
         cin>>actor;
         grafo[pelicula].insert(actor);
         grafo[actor].insert(pelicula);
         visitados[actor] = false;
      }
      
   }
   int N;
   cin>>N;

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   int numero_bacon;
   for (int i = 0; i < N; i++)
   {
      cin>>actor;
      numero_bacon = bfs(grafo,actor);
      if(numero_bacon != -1){
         cout << actor <<" " << numero_bacon << "\n";
      }else{
         cout << actor <<" INF\n";
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
