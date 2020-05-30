#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std; //TESTE
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
    cout << "Digite o nome do arquivo no qual os resultados serão escritos: ";
    string nome;
    cin >> nome;
    if (cin.fail()) {
        desastre = true;
        main();
    }
    ofstream arquivo (nome);
    if (!arquivo.is_open()) {
        desastre = true;
        main();
    }

    cout << "Quantas vezes devemos aumentar o x em x² + (x-1)²? Lembrando que x começará como 4: "; //IGNORE
    int vezes, contador;
    cin >> vezes;
    contador = 4;
    double somas[vezes];
    double quadrados[vezes * 2];
    int diario[vezes];
    if (cin.fail()) { //Testa para input inválido
        cout << "Invalid input" << endl;
        desastre = true; //Liga o failsafe
        main();
    }

    for (int i = 0; i < vezes; i++) {
        somas[i] = pow(contador, 2) + pow(contador - 1, 2); //Gera o conjunto X² + (x-1)²
        diario[i] = contador;
        contador++;
        
    }
    for (int i = 0; i < (vezes * 2); i++) {
        quadrados[i] = pow(i, 2); //Gera os quadrados
    }
    
    for (int i = 0; i < vezes; i++) {
        for (int z = 0; z < vezes * 2; z++) {
            if (somas[i] == quadrados[z]) {
                cout << "Match: " << somas[i] << "! Que é formado por " << diario[i] << "² + " << diario[i] - 1 << "²" << endl;
                arquivo << "Match: " << somas[i] << "! Que é formado por " << diario[i] << "² + " << diario[i] - 1 << "²" << endl;
            }
        }
        
    }
    arquivo.close();

}
