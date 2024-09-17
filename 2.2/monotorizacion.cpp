
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
// bool operator >(registro a,registro b){
//    return a<b;
// }
// struct comp_registro{
//    bool operator()(registro a, registro b) {
//       return b.momento <a.momento||(a.momento==b.momento&&b.id<a.id);
//    }
// };


int turno(priority_queue<registro>&cola){
   int t = 0, momento = 0;
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
      cout << endl;
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
