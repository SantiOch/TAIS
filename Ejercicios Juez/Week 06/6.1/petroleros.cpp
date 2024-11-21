
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
using namespace std;

 #include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Para resolver el problema, se crea un conjunto disjunto con los datos de entrada que almacenara la informacion de las manchas de petroleo.
 Cada vez que se encuentra una mancha de petroleo en los datos de entrada, se recorre los contiguos de la mancha actual, comprobando si 
 alguno de ellos pertenece a un conjutno ya existente, si es asi se unen los conjuntos y se actualiza el tamaño maximo si es necesario.
 De la misma forma, en cada caso de consulta se recorre los contiguos de la mancha actual con la funcion recorrer_contiguos, y se imprime el tamaño maximo.

 El coste de recorrer los contiguos de una mancha es constante, ya que como mucho se recorreran 9 casillas, y el coste de unir dos conjuntos es log(n),
 por lo tanto el coste total de la solucion es O(n log*(n)), siendo n los elentos de entrada.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool es_valida(int i, int j, int f, int c){
   return i>=0 && i<f && j>=0 && j<c;
}

void recorrer_contiguos(int a, int b, int f, int c, ConjuntosDisjuntos&manchas,unordered_set<int>&representantes,int &tam){
   bool es_nuevo=true;
   for (int i = a-1; i <= a+1; i++)
   {
      for(int j = b-1; j <= b+1; j++)
      {
         if(es_valida(i, j, f, c))
         {
            int r=manchas.buscar(i*c+j);
            if(representantes.count(r)!=0){
               es_nuevo=false;
               manchas.unir(a*c+b, r);
               tam=max(manchas.cardinal(r),tam);
            }
         }
      }
   }
   if (es_nuevo)
   {
      representantes.insert(a * c + b);
   }
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int f, c;
   cin >> f >> c;
   if (!std::cin)  // fin de la entrada
      return false;
   ConjuntosDisjuntos manchas(f*c);
   unordered_set<int>representantes;
   char casilla;
   int tam_maximo=0;
   for (int i = 0; i < f; i++)
   {
      for (int j = 0; j < c; j++)
      {
         cin >> casilla;
         if(casilla=='#')
         {
            if(tam_maximo==0){
               tam_maximo=1;
            }
            recorrer_contiguos(i, j, f, c, manchas, representantes, tam_maximo);
         }
      }
      
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int n;
   cin >> n;
   cout << tam_maximo << ' ';
   for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      if (tam_maximo == 0)
      {
         tam_maximo = 1;
      }
      recorrer_contiguos(a-1, b-1, f, c, manchas, representantes, tam_maximo);
      cout << tam_maximo << ' ';
   }
   cout << '\n';
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
