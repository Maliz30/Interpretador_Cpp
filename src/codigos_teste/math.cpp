#include <iostream>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;
    
    int soma, sub, mult, div, rest;

    soma = a + b;
    sub = a - b; 
    mult = a * b;
    div = a / b;
    rest = a % b;

    cout << "Soma: " << a << " + " << b << " = " << soma << endl;

    cout << "Subtração: " << a << " - " << b << " = " << sub << endl;

    cout << "Multiplicação: " << a << " x " << b << " = " << mult << endl;

    cout << "Divisão: " << a << " / " << b << " = " << div << endl;

    cout << "Resto: " << a << " % " << b << " = " << rest << endl;

    return 0;
}