
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se resuelve con el TAD de colas de prioridad, en la que se usa la clase priority_queue de maximos.
 El coste de la funcion calcular_coste() es log(N log n)

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
long long int calcula_coste(priority_queue<long long int,vector<long long int>,greater<long long int>>cola){
   long long int coste=0, top1=0, top2= 0;
   while (cola.size() > 1){
      top1 = 0; top2 = 0;
      top1 += cola.top();
      cola.pop();
      top2 += cola.top();
      cola.pop();

      top1 += top2;  
      coste += top1;  
      cola.push(top1); 
   }

   return coste;
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int n;
   cin >>n;
   if (n==0)
      return false;

   long long int elem;
   priority_queue<long long int,vector<long long int>,greater<long long int>>cola;
   for (int i = 0; i < n; i++)
   {
      cin>>elem;
      cola.push(elem);
   }
   
   // resolver el caso posiblemente llamando top1 otras funciones
   long long int coste=calcula_coste(cola);
   // escribir la solución
   cout<<coste<<endl;
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
