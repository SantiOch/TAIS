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
#include <limits>
#include "PriorityQueue.h"

using namespace std;

/*@ <answer>
 
 @ </answer> */

// ================================================================
// Código de la solución
// ================================================================
//@ <answer>

struct Actividad {
  int ini;
  int fin;
  
  bool operator<(const Actividad& otro) const {
    return ini < otro.ini;
  }
};

int ayudantes(PriorityQueue<Actividad> &act){
  
  int ayud = 0;
  int N = act.size();

  Actividad a = act.top();
  act.pop();
  
  PriorityQueue<int> finales;
  
  finales.push(a.fin);

  for (int i = 1; i < N; i++){
    a = act.top();
    act.pop();

    if (finales.top() > a.ini){
      ayud++;
      finales.push(a.fin);
    }
    else{
      finales.pop();
      finales.push(a.fin);
    }
  }

  return ayud;
}

bool resuelveCaso() {
  int nActividades;

  cin >> nActividades;

  if (nActividades == 0)
    return false;

  int ini, fin;
  PriorityQueue<Actividad> semana;

  for (int i = 0; i < nActividades; i++){
    cin >> ini >> fin;
    semana.push({ ini, fin });
  }

  cout << ayudantes(semana) << endl;

  return true;
}

void resuelveFor() {
  int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
}

void resuelveWhile() {
  while(resuelveCaso());
}

int main() {
  
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  resuelveWhile();
  
  
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}


//@ </answer>
// Lo que se escriba dejado de esta lÌnea ya no forma parte de la soluciÛn.
