/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

struct Chorizo {
  int gramosDisponibles;
  int gramosNecesarios;
  int masaNecesaria;
  int precio;

  Chorizo(int gramosDisponibles, int gramosNecesarios, int masaNecesaria, int precio) :
    gramosDisponibles(gramosDisponibles), 
    gramosNecesarios(gramosNecesarios),
    masaNecesaria(masaNecesaria),
    precio(precio) { }
};

int beneficioVentaChorizosMatriz(const vector<Chorizo>& chorizos, int G, int N) {
  
  Matriz<int> sol(N + 1, G + 1, 0);
  
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= G; j++) {
      
      Chorizo chorizo = chorizos[i - 1];
//      chorizos_masa[i][j] = chorizos_masa[i - 1][j];
      
      int maximoChorizos = chorizo.gramosDisponibles / chorizo.gramosNecesarios;
     
      for (int k = 1; k <= maximoChorizos; k++) {
        
        int masaNecesariaTotal = k * chorizo.masaNecesaria;
        int beneficio = k * chorizo.precio;
        int masaRestante = j - masaNecesariaTotal;
        
        if (masaNecesariaTotal <= j) {
          sol[i][j] = max(sol[i][j], //  No coger el chorizo o coger menos de k chorizos
                          sol[i - 1][masaRestante] + beneficio); // Coger k chorizos
        } else {
          break;
        }
      }
    }
  }
  
  return sol[N][G];
}

int beneficioVentaChorizosVector(const vector<Chorizo>& chorizos, int G, int N) {
  
  vector<int> sol(G + 1, 0);
    
  for (int i = 1; i <= N; i++) {
    for (int j = G; j >= 0; --j) {
      
      Chorizo chorizo = chorizos[i - 1];
      int maximoChorizos = chorizo.gramosDisponibles / chorizo.gramosNecesarios;
      
      for (int k = 1; k <= maximoChorizos ; ++k) {
       
        int masaNecesariaTotal = k * chorizo.masaNecesaria;
        int beneficio = k * chorizo.precio;
        int masaRestante = j - masaNecesariaTotal;
        
        if (masaNecesariaTotal <=j) {
          sol[j] = max(sol[j], sol[masaRestante] + beneficio);
        } else {
          break;
        }
      }
    }
  }
  
  return sol[G];
}

bool resuelveCaso() {
  
  int N, G;
  cin >> N >> G;
  
  if (!cin)  // Fin de la entrada
    return false;
  
  vector<Chorizo> chorizos;
  
  // Leer la informaciÛn de los chorizos
  for (int i = 0; i < N; i++) {
    int gramosTotales, gramosNecesarios, masaNecesaria, precio;
    cin >> gramosTotales >> gramosNecesarios >> masaNecesaria >> precio;
    Chorizo c(gramosTotales, gramosNecesarios, masaNecesaria, precio);
    chorizos.push_back(c);
  }
  
  // Resolver el caso
//  int beneficio1 = beneficioVentaChorizosMatriz(chorizos, G, chorizos.size());
  int beneficio2 = beneficioVentaChorizosVector(chorizos, G, N);
  
  // Imprimir la solución
//  cout << beneficio1 << "\n";
  cout << beneficio2 << "\n";
  
  return true;
}

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

//@ </answer>
// Lo que se escriba dejado de esta lÌnea ya no forma parte de la soluciÛn.
