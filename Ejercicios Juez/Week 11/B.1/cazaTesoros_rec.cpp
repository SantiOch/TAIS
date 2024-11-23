
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
   El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de cofres y T la profundidad maxima que se puede alcanzar.
   Siendo N == i y T==j en la recurrencia, para la forma general.
   
   *Definicion
   Tesoros(N,T)=Tesoro(i,j) === cantidad maxima de oro que se puede obtener con los cofres de 1 a i con limitacion de profundidad maxima j

   *Casos base
   Tesoros(0,j)=0
   Tesoros(i,0)=0

   *Casos recursivos
   Tesoros(i,j)=|Tesoro(i-1,j)                                                                        si cofres[i-1].profundidad*3>j
                |max(Tesoros(i-1,j),Tesoros(i-1,j-cofres[i-1].profundidad*3)+cofres[i-1].cantidad)    si cofres[i-1].profundidad*3<=j

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

int tesoros(vector<tCofre> const& cofres,Matriz<int>&matriz, int i, int j){
   if( i==0 || j==0 ||matriz[i][j]!=0 ){
      return matriz[i][j];
   }else{
      if(cofres[i-1].profundidad*3>j)
      {
         matriz[i][j]=tesoros(cofres,matriz,i-1,j);
      }
      else
      {
         matriz[i][j] = max(tesoros(cofres, matriz, i - 1, j), tesoros(cofres, matriz, i - 1, j - cofres[i - 1].profundidad * 3) + cofres[i - 1].cantidad);
      }
   }
   return matriz[i][j];
}
pair<int,deque<tCofre>>cazaTesoros(vector<tCofre> const& cofres, int n, int t){
   Matriz<int> matriz(n+1,t+1,0);
   int oroTotal = 0;
   deque<tCofre> cofresSol;
   oroTotal=tesoros(cofres,matriz,n,t);
   int i=n,j=t;
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
