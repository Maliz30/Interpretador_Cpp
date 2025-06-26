#include <iostream>

using namespace std;

int main() {
    // Erro 1: Variável não declarada sendo usada
    soma = a + b;
    
    // Erro 2: Variável declarada mas não inicializada sendo usada
    int x;
    resultado = x + 10;
    
    // Erro 3: Tipos incompatíveis em operação
    int numero = 5;
    bool flag = true;
    resultado = numero + flag;  // int + bool = erro
    
    // Erro 4: Operação inválida entre tipos
    char letra = 'A';
    float decimal = 3.14;
    resultado = letra % decimal;  // char % float = erro
    
    // Erro 5: Variável redeclarada
    int y = 10;
    int y = 20;  // redeclaração
    
    // Erro 6: Operação lógica com tipos não booleanos
    int a = 5, b = 3;
    if (a && b) {  // int && int = erro
        cout << "Erro!" << endl;
    }
    
    // Erro 7: Atribuição de tipo incompatível
    int inteiro = 42;
    string texto = "hello";
    inteiro = texto;  // int = string = erro
    
    return 0;
}