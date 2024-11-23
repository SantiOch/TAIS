
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
#include <queue>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct tCofre
{
   int cantidad;
   int profundidad;
};

pair<int,deque<tCofre>>cazaTesoros(vector<tCofre> const& cofres, int n, int t){
   Matriz<int> matriz(n+1,t+1,0);
   int oroTotal = 0;
   deque<tCofre> cofresSol;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=t;j++)
      {
         if(cofres[i-1].profundidad*3<=j)
         {
            matriz[i][j]=max(matriz[i-1][j],matriz[i-1][j-cofres[i-1].profundidad*3]+cofres[i-1].cantidad);
         }
         else
         {
            matriz[i][j]=matriz[i-1][j];
         }
      }
   }
   oroTotal=matriz[n][t];
   int i=n;
   int j=t;
   while(i>0 && j>0)
   {
      if(matriz[i][j]!=matriz[i-1][j])
      {
         cofresSol.push_front(cofres[i-1]);
         j-=cofres[i-1].profundidad*3;
      }
      i--;
   }
   return {oroTotal,cofresSol};
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n,t;
   cin>>t;
   if (!std::cin)  // fin de la entrada
      return false;
   cin>>n;
   vector<tCofre> cofres(n);
   // resolver el caso posiblemente llamando a otras funciones
   for(int i=0;i<n;i++)
   {
      cin>>cofres[i].profundidad;
      cin>>cofres[i].cantidad;
   }
   auto sol=cazaTesoros(cofres,n,t);
   deque<tCofre> cofresSol = sol.second;
   int oro = sol.first;
   // escribir la solución
   cout<<oro<<"\n";
   cout<<cofresSol.size()<<"\n";
   for(int i=0;i<cofresSol.size();i++)
   {
      cout<<cofresSol[i].profundidad<<" "<<cofresSol[i].cantidad<<"\n";
   }
   cout<<"---\n";
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
