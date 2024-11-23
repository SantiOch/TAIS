
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>

   El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de caracteres de la palabra.
   Siendo N == j en la recurrencia, para la forma general.
   Siendo i  el inicio de la palabra en la recurrencia, para la foma general.
   Por lo tanto, i el inicio de la subpalabra y j el final de la subpalabra.

   *Definicion
   Aibofobia(i,j)=Aibofobia(i+1,j-1) === cantidad minima de caracteres que se deben añadir para que la palabra final sea un palindromo
   *Casos base
   Aibofobia(i,j)=0 si i==j //intervalo cerrado
   Aibofobia(i,j)=0 si i+1==j //intervalo abierto

   *Casos recursivos
   Aibofobia(i,j)=|Aibofobia(i+1,j-1) si palabra[i]==palabra[j]
                  |1+min(Aibofobia(i+1,j),Aibofobia(i,j-1)) si palabra[i]!=palabra[j]

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int aibo(string palabra,Matriz<int>& matriz,int i,int j){
   if(matriz[i][j]!=-1){
      return matriz[i][j];
   }
   else{
      if (i == j || i > j)
         matriz[i][j]=0;
      else if(palabra[i]==palabra[j]){
         matriz[i][j]=aibo(palabra,matriz,i+1,j-1);
      }else{
         matriz[i][j]=1+min(aibo(palabra,matriz,i+1,j),aibo(palabra,matriz,i,j-1));
      }
      return matriz[i][j];
   }
}
void recontruyePalabra(string palabra,Matriz<int>& matriz,int i,int j, string &sol){
	if (i > j) return;

	if (palabra[i] == palabra[j]) {
		sol.push_back(palabra[i]);
		recontruyePalabra(palabra, matriz, i + 1, j - 1, sol);
		if(i != j)
			sol.push_back( palabra[j] );
	}
	else if (matriz[i][j] == matriz[i][j - 1] + 1) {
		sol.push_back(palabra[j]);
		recontruyePalabra(palabra, matriz, i, j - 1, sol);
		sol.push_back(palabra[j]);
	}
	else {
		sol.push_back(palabra[i]);
		recontruyePalabra(palabra, matriz, i + 1, j, sol);
		sol.push_back(palabra[i]);
	}
}
pair<int,string> aibofobia(string palabra,int n){
   Matriz<int> matriz(n+1,n+1,-1);
   int minCaracteres = 0;
   string palabraFinal;
   minCaracteres=aibo(palabra,matriz,0,n-1);
   if(minCaracteres>0){
      recontruyePalabra(palabra,matriz,0,n-1,palabraFinal);
   }else
      palabraFinal=palabra;
   return {minCaracteres,palabraFinal};

}
bool resuelveCaso() {

   // leer los datos de la entrada
   string palabra;
   cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;
   // resolver el caso posiblemente llamando a otras funciones
   auto sol= aibofobia(palabra,palabra.size());

   // escribir la solución
   cout << sol.first << " "<<sol.second<< "\n";
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
