
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

// #include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Para resolver el problema se ha creado una clase Manchas que recibe un mapa de manchas y calcula el número de manchas y el tamaño de la mancha más grande.
 Se ha implementado un algoritmo de búsqueda en profundidad (DFS) para recorrer las manchas y contar el número de manchas.
 El coste de la solución es O(F*C) siendo F el número de filas y C el número de columnas del mapa, ya que se recorre el mapa una vez y se recorre cada mancha una vez.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
using Mapa = vector<string>;

class Manchas
{
private:
   int F, C;
   vector<vector<bool>> visit;
   int num;
   int maxim;
   bool correcta(int i, int j)const{
      return 0<=i&&i<F&&0<=j&&j<C;
   }
   const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
   int dfs(Mapa const& mapa, int i, int j){
      visit[i][j]=true;
      int res=1;
      for(auto d:dirs){
         int ni=i+d.first, nj=j+d.second;
         if(correcta(ni,nj)&&!visit[ni][nj]&&mapa[ni][nj]=='#'){
            res+=dfs(mapa,ni,nj);
         }
      }
      return res;
   }
public:
   Manchas(Mapa const &mapa) : F(mapa.size()), C(mapa[0].size()), visit(F, vector<bool>(C, false)), num(0), maxim(0){
      for (int i = 0; i < F; ++i){
         for (int j = 0; j < C; ++j){
            if (!visit[i][j] && mapa[i][j] == '#'){
               num++;
               maxim = max(maxim, dfs(mapa, i, j));
            }
         }
      }
   }
   int numero()const{
      return num;
   };
   int maximo()const{
      return maxim;
   };
};



bool resuelveCaso() {

   // leer los datos de la entrada
   int F, C;
   cin >> F >> C;
   if (!std::cin)  // fin de la entrada
      return false;
   Mapa mapa(F);
   // resolver el caso posiblemente llamando a otras funciones
   for(string &s:mapa){
      cin >>s;
   }
   Manchas manchas(mapa);

   // escribir la solución
   cout << manchas.numero() << " " << manchas.maximo() << "\n";
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
