
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int numPeliculas(map<int,int>&peliculas){
   int total=0;
   int tiempo=0;
   auto it=peliculas.begin();
   if(it!=peliculas.end()){
      tiempo=it->first+it->second;
      total++;
   }
   while (it!=peliculas.end())
   {
      if(it->first>=tiempo){
      total++;
      tiempo=   

      }
   }
   
   
   return total;
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int n;
   cin>>n;
   if (n==0)
      return false;
   map<int,int>peliculas;
   int h,m,t,comienzo;
   char c;
   for (int i = 0; i < n; i++)
   {
      cin>>h;
      cin>>c;
      cin>>m>>t;
      comienzo=h*60+m;
      t+=10;
      auto p=peliculas.find(comienzo);
      if(p!=peliculas.end()){
         if(p->second>t)
         peliculas[comienzo]=t;
      }else peliculas[comienzo]=t;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int sol=numPeliculas(peliculas);
   // escribir la solución
   cout<<sol<<"\n";
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
