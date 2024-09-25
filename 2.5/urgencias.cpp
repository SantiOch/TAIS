
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco 
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Paciente {
    int orden;
    string nombre;
    int gravedad;

    Paciente(int ordenEntra, string nombreEntra, int gravedadEntra): orden(ordenEntra), nombre(nombreEntra), gravedad(gravedadEntra) { }
};

bool operator<(Paciente const &p1, Paciente const &p2) {
    return p1.gravedad < p2.gravedad || (p1.gravedad == p2.gravedad && p1.orden > p2.orden);
}

void tratarPaciente(priority_queue<Paciente> &cola) {
    Paciente p = cola.top();
    cola.pop();
    cout << p.nombre << "\n";
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int num;
   cin >> num;

   if (!num) return false;

   priority_queue<Paciente> cola;

   for (int i = 0; i < num; i++) {
       char caso;
       cin >> caso;

       string nombre;
       int gravedad;

       if (caso == 'I') {
           cin >> nombre >> gravedad;
           cola.emplace(i, nombre, gravedad);
       }
       else {
        tratarPaciente(cola);
       }
   }

   cout << "---\n";
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
