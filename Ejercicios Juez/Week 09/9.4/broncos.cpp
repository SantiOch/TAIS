
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

   Se puede resolver el problema de la siguiente manera:
   - Ordenamos los vectores de rivales y broncos.
   - Recorremos los vectores de rivales y broncos de manera simultánea.
   - Si el equipo rival es menor que el equipo bronco, sumamos la diferencia de puntos al total.
   - Si el equipo rival es mayor o igual que el equipo bronco, paramos el bucle.
   - Devolvemos el total de puntos.

   La complejidad de este algoritmo es O(2(n log n) + n) , siendo n el numero de partidos que juegan cada equipo. 
   El coste O(2(n log n)) es debido a la ordenación de los vectores de rivales y broncos, 
   y el coste O(n) es debido al bucle que itera n veces en el caso peor.
   El coste final despues de simplificar es O(n log n).
   
   Se ha resuelto con un algoritmo voraz, ya que en cada paso se toma la decisión óptima localmente, con la esperanza de que sea la decisión óptima globalmente.
   DEMOSTRACIÓN DE ALGORITMO VORAZ:
   - Supongamos que tenemos 4 equipos rivales y broncos, si ordenamos los equipos rivales de menor a mayor y los broncos de mayor a menor, 
   y los comparamos, podemos ver que el equipo bronco con mayor puntuación siempre ganará al equipo rival con menor puntuación.
   Por lo tanto, si sumamos la diferencia de puntos entre los equipos broncos y rivales, obtendremos la máxima puntuación posible.
   Por otro lado, si en alguna ocasión el equipo rival tiene más puntos que el equipo bronco, no se sumará nada a la puntuación total y se parará el bucle.
   porque las siguientes puntuaciones de los equipos rivales serán mayores o iguales a las puntuaciones de los equipos broncos.
   Por lo tanto, el algoritmo voraz es correcto y devuelve la puntuación máxima posible.


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int calcularPuntos(vector<int> &rivales, vector<int> &broncos) {
   int total = 0;
   sort(rivales.begin(), rivales.end());
   sort(broncos.begin(), broncos.end(), greater<int>());
   int i = 0;
   while (i < rivales.size()) {
      if (rivales[i] < broncos[i]) {
         total+=broncos[i]-rivales[i];
         i++;
      }
      else {
         break;
      }
   }
   return total;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n;
   cin >> n;
   if (n == 0)
      return false;
   vector<int> broncos(n);
   vector<int> rivales(n);
   for (int i = 0; i < n; i++) {
      cin >> rivales[i];
   }
   for (int i = 0; i < n; i++) {
      cin >> broncos[i];
   }
   // resolver el caso posiblemente llamando a otras funciones
   int sol= calcularPuntos(rivales, broncos);
   // escribir la solución
   cout << sol << "\n";
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
