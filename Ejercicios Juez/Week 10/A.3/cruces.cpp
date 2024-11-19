
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

#ifndef DOMJUDGE
   //  #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   // #include "EnterosInf.h" // descomentar para juez
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
int numeroCaminosDistinos(vector<vector<int>>const & mapa,int n,int m){
	vector<int> res(m, 1);
	for (int i = 1; i < m; i++) {
		if (mapa[0][i]) res[i] = 0;
		else res[i] = res[i - 1];
	}
	
	for (int i = 1; i < n; i++) {
		if (mapa[i][0]) res[0] = 0;

		for (int j = 1; j < m; j++) {
			if (!mapa[i][j]) {
				res[j] = res[j] + res[j - 1];
			}
			else {
				res[j] = 0;
			}
		}
	}
	return res[m - 1];
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int n,m;
   cin >> n >> m;
   if (!std::cin)  // fin de la entrada
      return false;
   vector<vector<int>>mapa(n,vector<int>(m,0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         char c;
         cin>>c;
         if(c=='X')
            mapa[i][j]=1;
      }
      
   }
   
   // resolver el caso posiblemente llamando a otras funciones
   int sol = numeroCaminosDistinos(mapa,n,m);
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
