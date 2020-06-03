#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>

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
    cout << "Digite o nome do arquivo no qual os resultados serão escritos (.csv será adicionado automaticamente): ";
    string nome;
    cin >> nome;
    if (cin.fail()) { //Testa se o nome é inválido
        desastre = true; //Se sim, ativa o failsafe e volta para main
        main();
    }
    

    cout << "Quantas vezes devemos aumentar o x em x² + (x-1)²? Lembrando que x começará como 4: "; //IGNORE
    long unsigned int vezes, contador;
    cin >> vezes;
    
    contador = 4;
    double soma;
    double quadrados;
    int diario;
    if (cin.fail()) { //Testa para input inválido
        cout << "Invalid input" << endl;
        desastre = true; //Liga o failsafe
        main();
    }
    ofstream arquivo ((nome + ".csv"), ios::out);
    if (!arquivo.is_open()) {
        desastre = true;
        main();
    }
    arquivo << "x,x-1,c,c²\n";
    for (int i = 0; i < vezes; i++) {
        soma = (pow(contador, 2) + pow(contador - 1, 2));
        for (int z = 0; z < vezes * 2; z++) {
            quadrados = pow(z, 2);
            if (quadrados == soma) {
                cout << "Match\n";
                arquivo << contador << "," << contador - 1 << "," << sqrt(soma) << "," << soma << endl;
            }
        }
        contador++;

    }
    
    
   
    arquivo.close();
}
/*A idéia básica desse projeto é testar quando a hipotenusa de um
triângulo com catetos x e x -1 vai ser um numero natural.

Esse código faz isso, primeiramente gerando uma array que contém todos os quadrados perfeitos até um certo
limite imposto pelo usuário, depois gerando uma array com os valores que a hipotenusa pode ser(x² + (x-1)²) e comparando as duas   */ 
