
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#include "IndexPQ.h" // propios o los de las estructuras de datos de clase

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct tema {
  string nombre;
  int numeroCitado;
  int ultimaVezCitado;
  tema(string nom="",int n=0,int u=0):nombre(nom), numeroCitado(n),ultimaVezCitado(u){}
  bool operator<(const tema &otro) const {
    return numeroCitado > otro.numeroCitado || (numeroCitado == otro.numeroCitado && ultimaVezCitado > otro.ultimaVezCitado);
  }
};
struct datos_tema
{
  int posicion_cola;
  int num_citas;
  int ultima_mencion;
};

void imprime(IndexPQ<tema> &cola) {
  int contador = 1;
  vector<pair<int,tema>> perdidos;
  while (!cola.empty() && contador <= 3 && cola.top().prioridad.numeroCitado != 0) {
    auto t = cola.top();
    cout << contador << " " << t.prioridad.nombre << "\n";
    perdidos.push_back({t.elem, t.prioridad});
    cola.pop();
    contador++;
  }
  for(const auto& t: perdidos) {
    cola.push(t.first, t.second);
  }
  
}

bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n;
  cin >> n;
  if (!std::cin)  // fin de la entrada
    return false;

  IndexPQ<tema> cola(n);
  unordered_map<string,datos_tema>mapa_datos;
  string letras;
  string nombre;
  int posCola = 0;
  int num;
  for(int i = 0; i < n; i++) {
    cin >> letras;
    
    if (letras == "E") {
      cin >> nombre;
      cin >> num;

      datos_tema dt =mapa_datos[nombre];
      dt.num_citas-=num;
      mapa_datos[nombre]=dt;
      cola.update(dt.posicion_cola,{nombre,dt.num_citas,dt.ultima_mencion});
      
    } else if (letras == "C") {
      
      cin >> nombre;
      cin >> num;
      
      tema t(nombre, num, i);
      if(mapa_datos.find(nombre)==mapa_datos.end()){
        mapa_datos[nombre]={posCola,num,i};
        cola.push(posCola++, t);
      } else{
        datos_tema dt = mapa_datos[nombre]; 
        dt.num_citas+=num;
        t.numeroCitado=dt.num_citas;
        mapa_datos[nombre]=dt;
        cola.update(dt.posicion_cola,t);
      }
    } else {
      imprime(cola);
      // Resolver
    }
  }
  cout << "---\n";

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
