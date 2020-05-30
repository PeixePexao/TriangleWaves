#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
void Generator();
int main() {
    cout << "Bem vindo ao TriangleWaves" << endl;

    Generator();
}

void Generator() {

    cout << "Quantas vezes devemos aumentar o x em x² + (x-1)²? Lembrando que x começará como 4: ";
    int vezes, contador;
    cin >> vezes;
    contador = 4;
    double somas[vezes];
    double quadrados[vezes * 2];
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        Generator();
    }

    for (int i = 0; i < vezes; i++) {
        somas[i] = pow(contador, 2) + pow(contador - 1, 2);
        contador++;
    }
    for (int i = 0; i < (vezes * 2); i++) {
        quadrados[i] = pow(i, 2);
    }
    cout << "Initiating checks..." << endl; 
    for (int i = 0; i < vezes; i++) {
        for (int z = 0; z < vezes * 2; z++) {
            if (somas[i] == quadrados[z]) {
                cout << "Match: " << somas[i] << " é igual a " << quadrados[z];
            }
        }
        
    }

}