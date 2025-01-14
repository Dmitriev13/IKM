#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>
#include "Header.h"

using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Приветствую! Эта программа вычисляет сумму 1^n + 2^n + ... + n^n для n >= 10." << endl;

    int n = proverka();
    string Summa = "0";

    for (int i = 1; i <= n; ++i) {
        string power = PowStr(i, n);
        Summa = StrPlusStr(Summa, power);
        cout << "Добавляем " << i << "^" << n << " = " << power << endl;
    }

    cout << "Значение итоговой суммы: \n";
    cout << Summa << endl;

    return 0;
}
