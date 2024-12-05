/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

#ifndef DOMJUDGE
    #include "../../../Plantillas Juez/teoria/EnterosInf.h"  // descomentar para local
    #include "../../../Plantillas Juez/teoria/Matriz.h"  // descomentar para local
#endif
#ifdef DOMJUDGE
   #include "EnterosInf.h" // descomentar para juez
   #include "Matriz.h" // descomentar para juez
#endif
/*@ <answer>
 
 El problema se resuelve con programacion dinamica de forma recursiva, N es el numero de peliculas.
 Siendo siendo i el indice de la pelicula actual y j el indice de la ultima pelicula.
 
 *Definicion
  Pelis(i, j) es el maximo de peliculas que se pueden ver si se empieza en la pelicula i y se termina en la pelicula j
 
 *Caso base
   Pelis(i,j) = 0 si i > j
 *Caso recursivo
   Pelis(i, j) = max(Pelis(i + 1, j), duracion(i) + Pelis(k, j)) donde k es el primer indice tal que fin(i) <= ini(k))
 
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================

//@ <answer>

struct Pelicula {
  int ini;
  int dur;
  int fin;
  
  Pelicula(int ini, int dur) : ini(ini), dur(dur), fin(ini + dur + 10) { }
  
  bool operator<(const Pelicula& otro) const {
    return ini == otro.ini ? fin < otro.fin : ini < otro.ini;
  }
};

int pelis(int i, int j, const vector<Pelicula>& v, Matriz<int>& m) {

  if (m[i][j] != -1) return m[i][j];
  
  if (i > j) {
    m[i][j] = 0;
    return 0;
  }
  
  int& res = m[i][j];
  
  int k = i + 1;
  
  while (k <= j && !(v[i].fin <= v[k].ini)) { k++; }
  
  res = max(pelis(i + 1, j, v, m), v[i].dur + pelis(k, j, v, m));
  
  return res;
}

bool resuelveCaso() {
  
  int N;
  cin >> N;
  if (N == 0) return false;
  
  vector<Pelicula> peliculas;
  
  for (int i = 0; i < N; ++i) {

    string horaEnString;
    cin >> horaEnString;
    int duracion;
    cin >> duracion;

    int hora = stoi(horaEnString.substr(0, 2));
    int minuto = stoi(horaEnString.substr(3, 2));
    
    int ini = hora * 60 + minuto;

    peliculas.push_back({ini, duracion});
  }
  
  Matriz<int> m(N + 1, N + 1, -1);
  
  sort(peliculas.begin(), peliculas.end());
  
  cout << pelis(0, N - 1, peliculas, m) << "\n";
  
  return true;
}


//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.
int main() {
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while(resuelveCaso());
  
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
