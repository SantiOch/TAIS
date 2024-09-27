
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El problema se resuelve con dos colas de prioridad, de maximos que almacenara la carga disponible de cada tipo de pila, 
 tambien se usa dos unordered_multiset para almacenar la carga de las pilas al terminar cada sabado, por su coste O(1) al insertar,
 para luego recorrerla y pushear de nuevo a la cola de prioridad correspondiente. Y volver a realizar tantas iteraciones hasta que una 
 de las colas este vacia, y acumulando en la variable horasVuelo, el numero de horas total que se podrán poner a volar los drones.
 Por ultimo, en cada caso mostramos por pantalla las horas de vuelo en cada iteracion.

 El coste de resuelveCaso() es O(K N log n), siendo K el numero maximo de pilas entre los dos tipos, N el tamaño del unordered_multiset
 y log n, el coste de la funcion push() de priority_queue
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int nDrones, nPilas9V, nPilas1V, horasVuelo;

  priority_queue<int> pilas9V;
  priority_queue<int> pilas1V;
  unordered_multiset<int> almacen9V;
  unordered_multiset<int> almacen1V;
  
  cin >> nDrones;
  
  if (!cin) return false;
  
  cin >> nPilas9V >> nPilas1V;
  
  for (int i = 0; i < nPilas9V; i++) { //O(N log n)
    cin >> horasVuelo;
    pilas9V.push(horasVuelo); //O(log n)
  }
  
  for (int i = 0; i < nPilas1V; i++) { //O(N log n)
    cin >> horasVuelo;
    pilas1V.push(horasVuelo); //O(log n)
  }
  
  if (pilas1V.size() == 0 || pilas9V.size() == 0) return true; //no hace falta por la precondicion
  
  while (pilas1V.size() > 0 && pilas9V.size() > 0) { //O(K * N *log n)
    
    int horasTotales = 0;
    
    for(int i = 0; i < nDrones; i++) { //O(N)
      if (pilas1V.size() > 0 && pilas9V.size() > 0){
        
        int pila1 = pilas1V.top(); //O(1)
        int pila9 = pilas9V.top(); //O(1)
        
        pilas9V.pop();
        pilas1V.pop();
        
        if(pila1 == pila9) {
          horasTotales += pila1;
        } else if (pila1 > pila9) {
          horasTotales += pila9;
          almacen1V.insert((pila1 - pila9)); //O(1)
        } else {
          horasTotales += pila1;
          almacen9V.insert((pila9 - pila1)); //O(1)
        }
      }
    }
    
    for(auto it = almacen1V.begin(); it != almacen1V.end(); it++) {  //O(N log n)
      pilas1V.push(*it); //O(log n)
    }
    
    for(auto it = almacen9V.begin(); it != almacen9V.end(); it++) { //O(N log n)
      pilas9V.push(*it); //O(log n)
    }
    
    almacen1V.clear();
    almacen9V.clear();
    
    cout << horasTotales << " ";
  }
  
  cout << "\n";
  
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
