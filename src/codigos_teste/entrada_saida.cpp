#include <iostream>

using namespace std;

int main(){
    
    int numero1, numero2;
    int soma, diferenca;
    
    cout << "Digite o primeiro numero: ";
    cin >> numero1;
    
    cout << "Digite o segundo numero: ";
    cin >> numero2;
    
    soma = numero1 + numero2;
    diferenca = numero1 - numero2;
    
    cout << "Soma: " << numero1 << " + " << numero2 << " = " << soma << endl;
    cout << "Diferenca: " << numero1 << " - " << numero2 << " = " << diferenca << endl;
    
    return 0;
} 