
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco 
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <iterator>
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
struct Partido
{
   int votos;
   int escanyos;
   float coeficiente;
   int pos;
};
bool operator < (const Partido & a, const Partido & b){
   bool es_menor=b.coeficiente < a.coeficiente || (a.coeficiente == b.coeficiente && b.pos < a.pos);
   return es_menor;
}
// bool operator > (const Partido &a, const Partido &b){
//    return a.coeficiente > b.coeficiente || (a.coeficiente == b.coeficiente && a.pos < b.pos);
// } 

void cal_num_escanyos(priority_queue<Partido> &cola)
{
   Partido p;
   p=cola.top();
   cola.pop();
   p.escanyos++;
   p.coeficiente = p.votos / (1.0 + p.escanyos);
   cola.push(p);
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int c,n;
   cin>>c>>n;
   if (c == 0 && n == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<Partido> cola;
   list <Partido>lista;
   int e = 0, v = 0, p = 0;
   Partido partido;
   for (int i = 0; i < c; i++)
   {
      cin >> v;
      partido.pos = p;
      partido.votos = v;
      partido.escanyos = e;
      partido.coeficiente = v / 1.0;
      cola.push(partido);
      lista.push_back(partido);
      p++;
   }
   
   // escribir la solución
   for (int i = 0; i < n; i++)
   {
      cal_num_escanyos(cola);
   }

   for (auto it = lista.begin(); it != lista.end(); it++)
   {
      cout<<it->escanyos;
      cout<<" ";
   }
   
   
   cout<<"\n";
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
