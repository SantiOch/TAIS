
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
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

 Para comprobar que es un arbol AVL, veo si las ramas izquierdas que nacen de todos los nodos cumplen que
 el menores estricto y tods las ramas derechas cumplen que son mayores estricto.
 El arbol vacio se concidera AVL.
 Ademas se comprueba recursivamente a traves de la variable bool balanced que este equilibrado recursivamente,
 comprobando que la diferencia de las alturas de sus ramas no supere en 1.
 El coste en tiempo del metodo esAVL es O(n),puesto que tienen que recorrer  todos los nodos hijos.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
template<typename T>

tuple<bool, bool, int, T, T> esAVL(const BinTree<T> &tree){
  
  if(tree.empty()) return { true, true, 0, T(), T()};
  
  auto [bal_left, avl_left, height_left, maxIzq, minIzq] = esAVL(tree.left());//O(N/2)
  auto [bal_right, avl_right, height_right, maxDer, minDer] = esAVL(tree.right());//O(N/2)
  
  bool balanced = bal_left && bal_right && abs(height_left - height_right) <= 1;
  bool avl_root = true;
  
  int height = 1 + max(height_left, height_right);

  T val = tree.root();
  T maxVal;
  T minVal;
  
  bool emptyLeft = tree.left().empty();
  bool emptyRight = tree.right().empty();
  
  if(emptyLeft) minVal = val;
  else minVal = minIzq;
  
  if(emptyRight) maxVal = val;
  else maxVal = maxDer;
  
  if(!emptyLeft && maxIzq >= val) avl_root = false;
  if(!emptyRight && minDer <= val) avl_root = false;
  if(!avl_left || !avl_right) avl_root = false;
  
  return { balanced, avl_root, height, maxVal, minVal };
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  char c;
  cin >> c;
  
  // fin de la entrada
  if (!std::cin) return false;
  
  // numero
  if(c == 'N') {
    
    BinTree<int> tree = read_tree<int>(cin);
    auto [bal, avl, height, izq, der] = esAVL(tree);
   
    if(avl && bal) cout << "SI" << endl;
    else cout << "NO" <<endl;
  }
  // palabras
  else if(c == 'P'){
   
    BinTree<string> tree = read_tree<string>(cin);
    auto [bal, avl, height, izq, der] = esAVL(tree);//O(N)
  
    if(avl && bal) cout << "SI" << endl;
    else cout << "NO" <<endl;
  }
  
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
