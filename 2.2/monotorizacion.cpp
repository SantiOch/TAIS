
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * ALEX GUILLERMO BONILLA TACO (TAIS009)
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;



/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 Usamos unsa estructura registro para guardar sus datos y simular el momento que le corresponde el turno en cada iteracion de tiempo.
 Se leen todos los datos y los metemos en una cola de prioridad de minimos, después se lee las k veces de envíos e iteramos llamando a la función
 turno() que nos devolvera el id correspondiente a la iteracion.
 En la funcion turno, almacenamos en el registro r, el minimo de la cola, sumamos el periodo a su momento y lo volvemos a meter en la cola,
 y devolvemos el id de r.

 El coste es de resuelve caso es O(k log n) sien k el numero de veces que realiza el bucle donde se encuentra la funcion turno() y log n,
 el coste de la funcion turno() puesto que se hace push(), que tiene coste log n.
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
struct registro
{
   int momento;
   int id;
   int periodo;
};

bool operator <(registro const& a,registro const& b){
   return b.momento < a.momento || (b.momento == a.momento && b.id < a.id);
}


int turno(priority_queue<registro>&cola){
   int t = 0;
   registro r;
   r = cola.top();
   t = r.id;
   cola.pop();
   r.momento += r.periodo;
   cola.push(r);
   return t;
}

bool resuelveCaso() {

   // leer los datos de la entrada
   int n;
   cin>>n;
   if (n==0)
      return false;

   // resolver el caso posiblemente llamando a otras funciones
   priority_queue<registro>cola;
   int id,momento;
   registro reg;
   for (int i = 0; i < n; i++){
      cin >> id >> momento;
      reg.id = id;
      reg.momento = momento;
      reg.periodo = momento;
      cola.push(reg);
   }

   // escribir la solución
   int veces;
   cin >>veces;

   while (veces--)
   {
      cout << turno(cola);
      cout << "\n";
   }

   cout<<"---\n";
   

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
