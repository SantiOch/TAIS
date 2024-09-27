
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El problema se resuelve con dos colas de prioridad, una de maximos que almacenaran las edades menores a la mediana y 
 uno de minimos que almacenara las edades mayores de la mediana. La mediana sera el resultado que se mostrara por pantalla, 
 y siempre se encontrara en la cola con tamaño mayor y siempre las dos colas tendran como maximo una diferencia de tamaño de 1,
 si en algun momento en cada pareja de entrada se tiene mas nodos de diferencia, se traspasara de sus tops de una cola o otra, 
 tantas veces como fuese necesario hasta que vuelvan a tener la diferencia maxima de 1.

 El coste de resuelveCaso() es O(K log n), siendo K el numero total de parejas de aves y log n, el coste de la funcion push()
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

   // leer los datos de la entrada
   int edad, parejas;

   cin >> edad >> parejas;

   if (edad == 0 && parejas == 0)
      return false;

   priority_queue<int> mini;
   priority_queue<int,vector<int>, greater<int>> maxi;
   
   maxi.push(edad);

   for (int i = 0; i < parejas; i++) { //O(k log n)
      int p1, p2, medio;
      cin >> p1 >> p2;
      medio = maxi.top(); //O(1)
      if(p1 < medio)
         mini.push(p1); //O(log n)
      else maxi.push(p1); //O(log n)
      
      if(p2 < medio)
         mini.push(p2);
      else maxi.push(p2);
     
     int tamMaxi, tamMini;
     tamMaxi = maxi.size(); //O(1)
     tamMini = mini.size(); //O(1)
      
     while(abs(tamMaxi - tamMini) > 1) {  //O(1*log n)
         int topDeLaColaQueToque;
         if (maxi.size() > mini.size()) {
            topDeLaColaQueToque = maxi.top();
            maxi.pop(); //O(1)
            mini.push(topDeLaColaQueToque);  //O(log n)
         } else {
            topDeLaColaQueToque = mini.top();
            mini.pop(); //O(1)
            maxi.push(topDeLaColaQueToque);
         }
         tamMaxi = maxi.size();
         tamMini = mini.size();
      }
      // escribir la solución
      int mostrar = (maxi.size() > mini.size()) ? maxi.top(): mini.top();
      cout << mostrar << " ";
   }
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
