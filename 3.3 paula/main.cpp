#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include "IndexPQ.h"

using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct citados {
        int veces = 0;
        int id;

        bool operator<(const citados& otro)const {
                if (this->veces == otro.veces) return this->id > otro.id;//ultima vez citado
                return this->veces > otro.veces;
        }
};

bool resuelveCaso() {
        // leer los datos de la entrada
        int n; //eventos
        cin >> n;

        if (!std::cin)  // fin de la entrada
                return false;

        IndexPQ<string, citados> eventos;//nombres con su id
        map<string, citados> m; //key nombre, num veces //le cambio el tipo es necesario guardar el id en todo momento, puesto que cuando llega la op de borrar hay que mantener el id anterior.


        string letra;
        int idaux = 0;
        string nombre;
        int veces;
        citados c_aux;//
        for (int i = 0; i < n; i++) {
                cin >> letra;
                if (letra == "C") {
                        cin >> nombre >> veces;
                        bool encontrado = m.count(nombre); //O(1)

                        citados c;

                        if (encontrado) {
                                c_aux = m[nombre];//O(n)
                                c_aux.veces += veces;
                                c_aux.id = i;//
                                eventos.update(nombre, c_aux);
                                m[nombre] = c_aux;//
                        }
                        else {
                                c.veces = veces;
                                c.id = i;//
                                eventos.update(nombre, c);
                                m[nombre] = c;
                        }

                }
                else if (letra == "E") {
                        cin >> nombre >> veces;
                        bool encontrado = m.count(nombre); //O(1)
                        if (encontrado) {
                                c_aux = m[nombre];//O(n)
                                c_aux.veces -= veces;

                                eventos.update(nombre, c_aux);//O(log n)
                        }
                }
                else {
                        vector<pair<string, citados>> top3;
                        int k = 0;
                        while (!eventos.empty() && k < 3 && eventos.top().prioridad.veces != 0)
                        {
                                auto c_salida = eventos.top();
                                cout << k + 1 << " " << c_salida.elem << '\n';
                                top3.push_back({c_salida.elem, c_salida.prioridad});

                                eventos.pop();

                                k++;
                        }
                        for (const auto &t : top3)
                                eventos.push(t.first, t.second);
                }
        }


        cout << "---\n";
        return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
        // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
        std::ifstream in("casos.txt");
        if (!in.is_open())
                std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

        while (resuelveCaso());

        // para dejar todo como estaba al principio
#ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        std::cout << "Pulsa Intro para salir..." << std::flush;
        std::cin.get();
#endif
        return 0;
}