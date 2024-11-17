
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//  #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
//  #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
 #include "Matriz.h"  // descomentar para juez
 #include "EnterosInf.h"  // descomentar para juez

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct tCuerda
{
   int longitud;
   int coste;
};
bool posible(vector<tCuerda> const &cuerdas, int L){
   Matriz<bool> matriz(cuerdas.size() + 1, L + 1, false);
   matriz[0][0]=true;
   for (int i = 1; i <= cuerdas.size(); i++)
   {
      matriz[i][0] = true;
      for (int j = 1; j <= L; j++)
      {
         if(cuerdas[i-1].longitud>j){
            matriz[i][j]=matriz[i-1][j];
         }
         else
         {
            matriz[i][j] = matriz[i - 1][j] || matriz[i - 1][j - cuerdas[i - 1].longitud];
         }
         
      }
      
   }
   return matriz[cuerdas.size()][L];
}

int manerasTotales(vector<tCuerda> const &cuerdas, int L){
   Matriz<int> matriz(cuerdas.size() + 1, L + 1, 0);
   matriz[0][0]=1;
   for (int i = 1; i <= cuerdas.size(); i++)
   {
      matriz[i][0] = 1;
      for (int j = 1; j <= L; j++)
      {
         if(cuerdas[i-1].longitud>j){
            matriz[i][j]=matriz[i-1][j];
         }
         else
         {
            matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - cuerdas[i - 1].longitud];
         }
         
      }
      
   }
   return matriz[cuerdas.size()][L];
}

EntInf minimoCuerdas(vector<tCuerda> const &cuerdas, int L){
Matriz<EntInf> matriz(cuerdas.size() + 1, L + 1, Infinito);
   matriz[0][0]=0;
   for (int i = 1; i <= cuerdas.size(); i++)
   {
      matriz[i][0] = 0;
      for (int j = 1; j <= L; j++)
      {
         if(cuerdas[i-1].longitud>j){
            matriz[i][j]=matriz[i-1][j];
         }
         else
         {
            matriz[i][j] = min(matriz[i - 1][j], matriz[i][j - cuerdas[i - 1].longitud] + 1);
         }
         
      }
      
   }
   return matriz[cuerdas.size()][L];
}

EntInf minimoCoste(vector<tCuerda> const &cuerdas, int L){
Matriz<EntInf> matriz(cuerdas.size() + 1, L + 1, Infinito);
   matriz[0][0]=0;
   for (int i = 1; i <= cuerdas.size(); i++)
   {
      matriz[i][0] = 0;
      for (int j = 1; j <= L; j++)
      {
         if(cuerdas[i-1].longitud>j){
            matriz[i][j] = matriz[i - 1][j];
         }
         else
         {
            matriz[i][j] = min(matriz[i - 1][j], matriz[i-1][j - cuerdas[i - 1].longitud] + cuerdas[i-1].coste);
         }
         
      }
      
   }
   return matriz[cuerdas.size()][L];
}

tuple<bool, int, EntInf, EntInf> calcularCuerdas(vector<tCuerda> const &cuerdas, int L){
   auto loes=posible(cuerdas,L);
   if(loes){
      auto maneras = manerasTotales(cuerdas, L);
      auto cuerdasMin = minimoCuerdas(cuerdas, L);
      auto costeMin = minimoCoste(cuerdas, L);
      return {loes, maneras, cuerdasMin, costeMin};
   }
   else
      return{loes,0,0,0};
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int N,L;
   cin >> N >> L;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<tCuerda> cuerdas(N);
   for (size_t i = 0; i < N; i++)
   {
      cin >> cuerdas[i].longitud >> cuerdas[i].coste;
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   auto[posible,manerasTotales,minimoCuerdas,minimoCoste] = calcularCuerdas(cuerdas,L);
   // escribir la solución
   if (posible)
      cout << "SI " << manerasTotales << " " << minimoCuerdas << " " << minimoCoste << "\n";
   else
      cout << "NO" << "\n";
   
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
