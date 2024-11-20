
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

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "EnterosInf.h" // descomentar para juez
#endif
   /*@ <answer>
	j representa la puntuación a obtener
	i representa el conjunto de las puntuaciones de 1 a i

	num_dardos(0, j) = INF con j > 0
	num_dardos(i, 0) = 0
	num_dardos(i, j) = | num_dardos(i-1, j) si puntuaciones[i] > j
				          | min(num_dardos(i-1, j), num_dardos(i, j - puntuaciones[i]) + 1)
    @ </answer> */

   // ================================================================
   // Escribe el código completo de tu solución aquí debajo
   // ================================================================
   //@ <answer>
   vector<int> num_dardos(const vector<int> &puntuaciones, int n, int s)
   {
      vector<EntInf> v(s + 1, Infinito);
      vector<int> sol;
      v[0] = 0;

      for (int i = 1; i <= n; i++)
      {
         for (int j = puntuaciones[i]; j <= s; j = j + 1)
         {
            v[j] = min(v[j], v[j - puntuaciones[i]] + 1);
         }
      }
      if (v[s] != Infinito)
      {
         int j = s;
         for (int i = n; i > 0; i--)
         {
            if (j - puntuaciones[i] >= 0 && v[j] == v[j - puntuaciones[i]] + 1)
            {
               sol.push_back(puntuaciones[i]);
               j -= puntuaciones[i];
               i++;
            }
         }
      }
      return sol;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int s,n;
   cin>>s>>n;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<int>puntuaciones(n+1);
   vector<int>sol;
   for (int i = 1; i <= n; i++)
   {
      cin>>puntuaciones[i];
   }
   sol=num_dardos(puntuaciones,n,s);
   // resolver el caso posiblemente llamando a otras funciones
   if(sol.size()==0)
      cout<<"Imposible\n";
   else
   {
      cout<<sol.size()<<":";
      for (int i = 0; i < sol.size(); i++)
      {
         cout<<" "<<sol[i];
      }
      cout<<"\n";
   }
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
