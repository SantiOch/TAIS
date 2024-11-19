
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
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
bool esValida(int pos, int n) {
    return pos >= 0 && pos < n;
}
pair<int,int>maximaPuntuacion(const vector<vector<int>>& tablero, int n) {
    int maxPunt, colIni;
    vector<int>res(n);
    int puntIzq, puntArr, puntDer;
    for (int i = 0; i < n; i++)
    {
        int ultiPunt=0;
        for (int j = 0; j < n; j++)
        {
            esValida(j - 1, n) ? puntIzq = ultiPunt : puntIzq = 0;
            puntIzq=ultiPunt;
            puntArr=res[j];
            esValida(j + 1, n) ? puntDer = res[j + 1] : puntDer = 0;
            ultiPunt = res[j];
            res[j] = tablero[i][j] + max(puntIzq, max(puntArr, puntDer));

        }
        
    }
    colIni = 0; maxPunt = res[0];
    for (int i = 1; i < n; i++)
    {
        if (res[i] > maxPunt) {
            maxPunt = res[i];
            colIni = i;
        }
    }
    return { maxPunt, colIni+1 };
}
bool resuelveCaso() {

   // leer los datos de la entrada
    int n;
    cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
    vector<vector<int>> tablero(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tablero[i][j];
    auto sol = maximaPuntuacion(tablero, n);
   // resolver el caso posiblemente llamando a otras funciones
    cout << sol.first << " " << sol.second << "\n";
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
