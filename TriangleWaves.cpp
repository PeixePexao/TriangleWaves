#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
void Generator();
bool desastre = false;
int main() {
    if (desastre == false) { //Testa se o failsafe foi ativado
        cout << "Bem vindo ao TriangleWaves" << endl;

        Generator();
    }
    else { //Se for desligue o programa
        return 0;
    }
    
}

void Generator() {

    cout << "Quantas vezes devemos aumentar o x em x² + (x-1)²? Lembrando que x começará como 4: ";
    int vezes, contador;
    cin >> vezes;
    contador = 4;
    double somas[vezes];
    double quadrados[vezes * 2];
    if (cin.fail()) { //Testa para input inválido
        cout << "Invalid input" << endl;
        desastre = true; //Liga o failsafe
        main();
    }

    for (int i = 0; i < vezes; i++) {
        somas[i] = pow(contador, 2) + pow(contador - 1, 2); //Gera o conjunto X² + (x-1)²
        contador++;
    }
    for (int i = 0; i < (vezes * 2); i++) {
        quadrados[i] = pow(i, 2); //Gera os quadrados
    }
    
    for (int i = 0; i < vezes; i++) {
        for (int z = 0; z < vezes * 2; z++) {
            if (somas[i] == quadrados[z]) {
                cout << "Match: " << somas[i] << " é igual a " << quadrados[z] << endl;
            }
        }
        
    }

}