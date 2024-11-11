/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

#include "ConjuntosDisjuntos.h"// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Mapa = vector<string>;

class ManchaMasGrande {
private: 
        vector<pair<int, int>> dir = { {1,0},{-1,0},{0,1},{0,-1}, {1,1},{1,-1},{-1,-1},{-1,1} };

public:
        ManchaMasGrande(const Mapa& map, int row, int col) :visitado(row, vector<bool>(col, false)), rowM(row), colM(col), cd(row* col) {

                for (int i = 0; i < row; i++) {
                        for (int j = 0; j < col; j++) {
                                if (estaEnRango(i, j) && map[i][j] == '#' && !visitado[i][j]) {
                                        dfs(map, i, j);
                                        mayores.push(cd.cardinal(i * col + j));
                                }
                        }
                }
        }

        void anyadirMancha(Mapa& map, int row, int col) {

                int tam;
                for (auto d : dir) {
                        int i = row + d.first, j = col + d.second;
                        if (estaEnRango(i, j) && map[i][j] == '#' && !cd.unidos(row * colM + col, i * colM + j)) {
                                cd.unir(row * colM + col, i * colM + j);
                        }
                }
                mayores.push(cd.cardinal(row * colM + col));
        }

        int manchaMayor() {
                return (mayores.empty() ? 0 : mayores.top());
        }

private:

        ConjuntosDisjuntos cd;
        vector<vector<bool>> visitado;
        int rowM, colM;
        PriorityQueue<int, greater<int>> mayores;

        void dfs(const Mapa& map, int row, int col) {

                visitado[row][col] = true;
                for (auto d : dir) {
                        int i = row + d.first, j = col + d.second;
                        if (estaEnRango(i, j) && map[i][j] == '#' && !visitado[i][j] && !cd.unidos(row * colM + col, i * colM + j)) {
                                cd.unir(row * colM + col, i * colM + j);
                                dfs(map, i, j);
                        }
                }
        }

        bool estaEnRango(int row, int col) {

                return row >= 0 && row < rowM && col >= 0 && col < colM;
        }
};

bool resuelveCaso() {
        // leer los datos de la entrada

        int row, col;
        cin >> row;
        if (!std::cin)  // fin de la entrada
                return false;
        cin >> col;

        Mapa mar;
        string linea;
        for (int i = 0; i < row; i++) {
                cin >> linea;
                mar.push_back(linea);
        }

        ManchaMasGrande mmg(mar, row, col);
        // resolver el caso posiblemente llamando a otras funciones
        cout << mmg.manchaMayor() << " ";

        int anyadir;
        cin >> anyadir;

        for (int i = 0; i < anyadir; i++) {
                cin >> row >> col;
                mmg.anyadirMancha(mar, row - 1, col - 1);
                cout << mmg.manchaMayor() << " ";
        }
        cout << endl;
        // escribir la solución

        return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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