
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
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "EnterosInf.h" // descomentar para juez
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>

   cine(i) = maximos minutos de peliculas que Dinamique podra ver en la maraton de cine
             considerando las peliculas de 0..i
   *Casos base:
      cine(0)=0;
   *Recurrencia:
   cine(i)= |cine(i-1)+ duracion(i) si ultimaDuracion < horaInici(i)
            |max(cine(i-x) + duracion(i), cine(i-1)) si i > 0

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct tPeli
{
   int inicio;
   int duracion;
   bool operator<(const tPeli&o)const{
      return inicio < o.inicio;
   }
};

int cine(Matriz<EntInf>&matriz,const vector<tPeli>&peliculas,int n){
   int total=0;
   matriz[0][0]=0;
   for (int i = 1; i < n+1; i++)
   {
      matriz[i][0] = 0;

      for (int j = 1; j < n+1; j++)
      {
         
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
   Matriz<EntInf>matriz(n+1,-1);
   vector<tPeli>peliculas(n);
      char c;
      int hora,minutos,duracion;
   for (int i = 0; i < n; i++)
   {
      cin >> hora;
      cin>>c;
      cin >>minutos;
      peliculas[i].inicio = hora * 60 + minutos;
      cin >> peliculas[i].duracion;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int sol = cine(matriz,peliculas,n);
   // escribir la solución
   cout << sol << "\n;";
   
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
