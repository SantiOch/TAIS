
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Peli {
public:
  
  int horaEnMinutos;
  int duracion;
  
  Peli(): horaEnMinutos(0), duracion(0) { }
  
  Peli(int hora, int minuto, int dur): horaEnMinutos(hora * 60 + minuto), duracion(dur) { }
  
  bool operator<(const Peli& otro) const{
    return horaEnMinutos < otro.horaEnMinutos;
  }
};

int victorias(vector<Peli>& peliculas) {
    
  int totalUsadas = 1;
  sort(peliculas.begin(), peliculas.end());
  
  Peli peliculaActual = peliculas[0];
  
  for (int i = 1; i < peliculas.size(); i++) {
    if (peliculaActual.horaEnMinutos + peliculaActual.duracion + 10 <= peliculas[i].horaEnMinutos) {
      totalUsadas++;
      peliculaActual = peliculas[i];
    } else if (peliculaActual.horaEnMinutos + peliculaActual.duracion > peliculas[i].horaEnMinutos + peliculas[i].duracion) {
      peliculaActual = peliculas[i];
    }
  }
  // Lógica de cálculo (sin implementar en tu código original)
  // Se puede añadir aquí el cálculo según el problema específico

  return totalUsadas;
}

bool resuelveCaso() {
  int n;
  cin >> n;
  if (n == 0)  // fin de la entrada
      return false;

  vector<Peli> peliculas(n);

  for (int i = 0; i < n; i++) {
    string horaEnString;
    cin >> horaEnString;
    int duracion;
    cin >> duracion;

    int hora = stoi(horaEnString.substr(0, 2));
    int minuto = stoi(horaEnString.substr(3, 2));

    peliculas[i] = {hora, minuto, duracion};
  }

  // Ejecuta la función `victorias` (si necesitas la lógica de cálculo)
  int sol = victorias(peliculas);
  
  // escribir la solución
  cout << sol << "\n";
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
