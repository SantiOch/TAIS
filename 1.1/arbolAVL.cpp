
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * Alex Guillermo Bonilla Taco
 *@ </authors> */

#include <iostream>
#include <fstream>

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

tuple<bool,bool,int> esAVL(BinTree<int>tree){
   if(tree.empty())return {true,true,0};
   else{
      auto[bal_left, avl_left ,height_left] = esAVL(tree.left());
      auto[bal_right, avl_right, height_right] = esAVL(tree.right());
      bool balanced = bal_left && bal_right && abs(height_left - height_right) <= 1;
      int height = 1+ max(height_left, height_right);
      int val=tree.root();
      bool avl_root=tree.left().root()<val && tree.right().root()>val;
      return {balanced, avl_root,height};
   }
}
tuple<bool,bool,int> esAVL(BinTree<string>tree){
      auto[bal_left, avl_left ,height_left] = esAVL(tree.left());
      auto[bal_right, avl_right, height_right] = esAVL(tree.right());
      bool balanced = bal_left && bal_right && abs(height_left - height_right) <= 1;
      int height = 1+ max(height_left, height_right);
      int val=tree.root();
      bool avl_root=tree.left().root()<val && tree.right().root()>val;
      return {balanced, avl_root,height};
}
bool resuelveCaso() {

   // leer los datos de la entrada

   if (!std::cin)  // fin de la entrada
      return false;
   int c;
   cin >> c;
   tuple<bool,bool,int> loes;
   if(c == 'N'){
      BinTree<int>tree= read_tree<int>(cin);
      loes=esAVL(tree);

   }
   else if(c=='P'){
      BinTree<string>tree= read_tree<string>(cin);
      loes=esAVL(tree);
   }
   // resolver el caso posiblemente llamando a otras funciones
   
   if()cout<<"SI"<<endl;
   else cout<<"NO"<<endl;
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
