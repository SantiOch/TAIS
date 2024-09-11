
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * Alex Guillermo Bonilla Taco TAIS009
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <memory>
#include <utility>  // Para la clase pair
#include <tuple>    // Para la clase tuple
using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
template<typename T>
tuple<bool,bool,int,T,T> esAVL(BinTree<T>tree){
   if(tree.empty())return {true,true,0,NULL,NULL};
   else{
      auto[bal_left, avl_left ,height_left,max_left,min_left] = esAVL(tree.left());
      auto[bal_right, avl_right, height_right,max_right,min_right] = esAVL(tree.right());
      bool balanced = bal_left && bal_right && abs(height_left - height_right) <= 1;
      int height = 1+ max(height_left, height_right);
      T val=tree.root();
      T min_val;
      T max_val;
      if(!tree.left().empty()){
         max_val=max(max_left,val);
         min_val=min(min_left,val);
         }else {
            min_val=val;
            max_val=val;
         }
      if(!tree.right().empty()){
         max_val=max(max_right,val);
         min_val=min(min_right,val);
      }     else {
            min_val=val;
            max_val=val;
         }
      bool avl_root=true;
      if(!tree.left().empty()&&max_val>val){
         avl_root=false;
      }
      if(!tree.right().empty()&&min_val<val){
         avl_root=false;
      }
      if(!avl_left||!avl_right)avl_root=false;
      return {balanced, avl_root,height,max_val,min_val};
   }
}

bool resuelveCaso() {

   // leer los datos de la entrada

   char c;
   cin >> c;
   if (!std::cin)  // fin de la entrada
      return false;
   tuple<bool,bool,int> loes;
   if(c == 'N'){
      BinTree<int>tree= read_tree<int>(cin);
      auto[bal, avl, height,max_val,min_val]=esAVL(tree);
   if(avl&&bal)cout<<"SI"<<endl;
   else cout<<"NO"<<endl;

   }
   else if(c=='P'){
      BinTree<string>tree= read_tree<string>(cin);
      auto[bal, avl, height,max_val,min_val]=esAVL(tree);
   if(avl&&bal)cout<<"SI"<<endl;
   else cout<<"NO"<<endl;
   }
   // resolver el caso posiblemente llamando a otras funciones
   
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
