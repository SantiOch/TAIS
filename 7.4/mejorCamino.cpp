
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 * TAIS009 Alex Guillermo Bonilla Taco
 * TAIS069 Santiago Ochoa de Zabalegui Velasco
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <list>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
class Dijkstra {
public:
  Dijkstra(GrafoValorado<int> const &g, int orig,int fin) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
    bfs(g,orig,fin);
    if(distanciaMasCortaBFS != INF){
      dijkstra(g);
      caminoDijkstra(orig,fin);
    }
    
  }
  
  bool hayCamino(int v) const { return dist[v] != INF; }
  bool esCaminoMasCorto(int v) const { return distanciaMasCortaBFS ==distanciaDijkstra; }
  
  int distancia(int v) const { return dist[v]; }
  
  void caminoDijkstra(int ini,int fin){
    Arista<int> a;
    list<int> cam;
    for (int v = fin; v != ini; v = ulti[v]) {
      cam.push_front(v);
    }
    cam.push_front(ini);
    distanciaDijkstra = cam.size()-1;
  }
  
private:
  const int INF = std::numeric_limits<int>::max();
  int origen;
  vector<int> dist;
  vector<int> ulti;
  IndexPQ<int> pq;
  int distanciaMasCortaBFS;
  int distanciaDijkstra;

  void dijkstra(GrafoValorado<int> const &g) {
    dist[origen] = 0;
    pq.push(origen, 0);
    while (!pq.empty()) {
      int v = pq.top().elem;
      pq.pop();
      for (auto a : g.ady(v))
        relajar(a, v);
    }
  }

  void bfs(GrafoValorado <int> g, int ini,int fin ){
    distanciaMasCortaBFS = INF;
    queue<int> q;
    vector<int> distancias(g.V(), INF);
    distancias[ini] = 0;
    q.push(ini);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (Arista<int> a : g.ady(v)) {
        int w = a.otro(v);
        if (distancias[w] == INF) {
          distancias[w] = distancias[v] + 1;
          q.push(w);
        }
      }
    }
    distanciaMasCortaBFS = distancias[fin];
  }
  void relajar(Arista<int> a, int v) {
    int w = a.otro(v);
    if (dist[w] > dist[v] + a.valor()) {
      dist[w] = dist[v] + a.valor();
      ulti[w] = v;
      pq.update(w, dist[w]);
    }
  }
};
bool resuelveCaso() {
  
  // leer los datos de la entrada
  int n,c,k,ini,fin;
  cin>>n>>c;
  if (!std::cin)  // fin de la entrada
    return false;
  GrafoValorado<int> g(n);
  int a, b, v;
  for(int i=0;i<c;i++){
    cin >> a >> b >>v;
    g.ponArista({a-1,b-1,v});
  }
  
  // resolver el caso posiblemente llamando a otras funciones
  // escribir la solución
  cin>>k;
  for(int i=0;i<k;i++){
    cin>>ini>>fin;
    Dijkstra d(g, ini - 1,fin -1);
    if(d.hayCamino(fin - 1)){
      cout<<d.distancia(fin - 1)<<" ";
      if(d.esCaminoMasCorto(fin - 1))
        cout<<"SI\n";
      else
        cout<<"NO\n";
    }else{
      cout<<"SIN CAMINO\n";
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
