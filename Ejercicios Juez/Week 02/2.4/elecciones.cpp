
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
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Para resolver el problema se ha creado una estructura Partido que contiene los votos, los escanyos, el coeficiente y la posición de entrada.
 Se ha creado un comparador para la cola de prioridad que compara los partidos por coeficiente, votos y posición con criterios del enunciado.
 En resuelveCaso se leen los datos de entrada y se guardan en una cola de prioridad y en una lista. Se calculan los escanyos de cada partido en cada iteracion
 y se van pusheando en la cola de prioridad actualizando el coeficiente que tiene con la formula de e𝑘 = 𝑣𝑘/(1+𝑒𝑘) del enunciado.
 La lista se usa para mejorar su coste y tener un acceso mas rapido a los partidos segun su posicion.
 Finalmente se recorre la lista de partidos y se imprime el numero de escanyos de cada uno.

 El coste de resuelveCaso es O(k logn) en el peor de los casos donde n es el numero de partidos y k el numero de escanyos a repartir. Siendo k mayor que n.
 Si n es mayor que k el coste es O(n logn) considerando que el coste de la funcion viene determinado por el bucle donde se leen los datos par insertarlos en cola de prioridad y en la lista.

 
  @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct Partido{
   int votos;
   int escanyos;
   float coeficiente;
   int pos;
   Partido(int v,int e,int c,int p): votos(v), escanyos(e), coeficiente(c), pos(p) {}
};

struct Comparator {
   bool operator()(const Partido *a, const Partido *b) {
      return b->coeficiente > a->coeficiente || (a->coeficiente == b->coeficiente && b->votos > a->votos) || (a->coeficiente == b->coeficiente && a->votos==b->votos &&  b->pos < a->pos);
   }
};

void cal_num_escanyos(priority_queue<Partido*,vector<Partido*>,Comparator>&cola){
   Partido *p;
   p = cola.top(); // 0(1)
   cola.pop();     // 0(1)
   p->escanyos++;
   p->coeficiente = p->votos / (1.0 + p->escanyos);
   cola.push(p); // 0(logn)   
}
bool resuelveCaso() {

   // leer los datos de la entrada
   int c,n;
   cin>>c>>n;
   if (c == 0 && n == 0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<Partido*,vector<Partido*>,Comparator> cola;
   list <Partido*>lista;
   int e = 0, v = 0, p = 0;
   Partido *partido;
   for (int i = 0; i < c; i++){
      cin >> v;
      partido = new Partido(v, e, v / 1.0, p);
      cola.push(partido);
      lista.push_back(partido);
      p++;
   }
   
   // escribir la solución 
   for (int i = 0; i < n; i++){ // 0(k)
      cal_num_escanyos(cola); // 0(logn)
   }

   for (auto it = lista.begin(); it != lista.end(); it++){ // 0(n)
      cout<<(*it)->escanyos; // 0(1)
      cout<<" ";
      delete *it;
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
