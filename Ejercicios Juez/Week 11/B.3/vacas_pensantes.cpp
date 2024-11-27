#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;

int comidaMaxima(const vector<int>& cubos, int i, int j, Matriz<int>& dp) {
    int N = cubos.size();
    int& res = dp[i][j];

    // Caso base: si solo queda un cubo, la vaca come ese cubo
    if (i>j)
        res = 0;
    else if (i == j) {
        res = cubos[i];
    }
    else {
        // Selecci�n del mejor valor m�ximo entre las posibles opciones
        int x1,x2,y1,y2;
        if(cubos[i+1]>cubos[j]){
            x1 = i+2;
            y1= j;
        }
        else{
            x1 = i+1;
            y1=j-1;
        }
        if(cubos[j-1]>cubos[i]){
            x2=i;
            y2=j-2;

        }
        else{
            x2=i+1;
            y2=j-1;
        }
        res = std::max({
            comidaMaxima(cubos, x1, y1, dp) + cubos[i],
            comidaMaxima(cubos, x2, y2, dp) + cubos[j]
            });
    }

    return res; // El resultado se guarda en dp[i][j]
}

bool resuelveCaso() {
    int N;
    cin >> N;

    if (N == 0) return false;

    vector<int> cubos(N);
    for (int i = 0; i < N; ++i) {
        cin >> cubos[i];
    }

    Matriz<int> dp(N+1, N+1, -1);

    // Llamar a la funci�n para calcular la cantidad m�xima que puede comer la vaca
    cout << comidaMaxima(cubos, 0, N-1 , dp) << "\n";

    return true;
}

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
