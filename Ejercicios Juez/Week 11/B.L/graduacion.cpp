
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>
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





vector<string> readWords() {
   vector<string> ret;
   
   string linea;
   getline(cin, linea);
   
   stringstream ss(linea);  
   string palabra;
   
   while (ss >> palabra) { // Extract word from the stream.
     ret.push_back(palabra);
   }
   return ret; 
}

int conciertos_rec(int i, int j, const vector<string>& v1,  const vector<string>& v2, Matriz<int>& m) {

   if(i == 0 || j == 0) return 0;
   
   if(m[i][j] != -1) return m[i][j];

   if(v1[i] == v2[j]) {
      m[i][j] = 1 + conciertos_rec(i - 1, j - 1, v1, v2, m);
   } else {
     m[i][j] = max(conciertos_rec(i - 1, j, v1, v2, m),conciertos_rec(i, j - 1, v1, v2, m));
   }
   return m[i][j];
}
int conciertos(const vector<string>& v1,  const vector<string>& v2, Matriz<int>& m) {

   for(int i = 1; i <= v1.size(); i++) {
      for (int j = 1; j <= v2.size(); j++) {
         if(v1[i-1] == v2[j-1]) {
            m[i][j] = m[i - 1][j - 1] + 1;
         }
         else {
            m[i][j] = max( m[i][j - 1], m[i - 1][j]);
         }
      }  
   }
   return m[v1.size()][v2.size()];
}



vector<string>recontruir(const vector<string> &v1,  const vector<string>& v2,const Matriz<int>&m){
   vector<string> sol;
   int i = v1.size();
   int j = v2.size();
   while(i > 0 && j > 0){
      if(v1[i-1] == v2[j-1]){
         sol.push_back(v1[i-1]);
         i--;
         j--;
      }else{
         if(m[i-1][j] > m[i][j-1]){
            i--;
         }else{
            j--;
         }
      }
   }

   return sol;
}

bool resuelveCaso() {

   vector<string> v1,v2;

   v1 = readWords();
   v2 = readWords();

   if (v1.size() == 0 && v2.size() == 0)  // fin de la entrada
      return false;
    // La línea que deseas dividir

   Matriz<int> m(v1.size() + 1, v2.size() + 1, 0);
   
   // cout << conciertos_rec(v1.size() - 1,v2.size()-1,v1,v2,m) << endl;
   conciertos(v1,v2,m);

   vector<string>sol = recontruir(v1,v2,m);
   
   if(sol.size()!=0){
      for (int i = sol.size()-1; i >=0; i--) {
         cout<<sol[i]<<" ";
      }
   }
      cout<<"\n";

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
