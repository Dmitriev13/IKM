#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>

using namespace std;

// Функция для умножения строки числа на целое число
string StrMultInt(const string& num, int umn) {
    string result;
    int ost = 0; // Переменная для хранения остатка
    for (int i = num.length() - 1; i >= 0; i--)  //num.leght()- 1 последняя цифра строки
    { 
        int digit = num[i] - '0';
        int a = digit * umn + ost; // Переменная для поразрядного умножения
        result.push_back((a % 10) + '0'); 
        ost = a / 10;
    }
    while (ost > 0) 
    {
        result.push_back((ost % 10) + '0');
        ost = ost / 10;
    }
    // Переворачиваем строку
    string reverseRes;
    for (int i = result.length() - 1; i >= 0; i--) 
    {
        reverseRes.push_back(result[i]);
    }
    return reverseRes;
}


// Функция для сложения двух строк чисел
string StrPlusStr(const string& num1, const string& num2) {
    string res;
    int ost = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 or j >= 0 or ost > 0) {
        int digit1;
        if (i >= 0)
        {
            digit1 = num1[i--] - '0';
        }
        else
        {
            digit1 = 0;
        }

        int digit2;
        if (j >= 0)
        {
            digit2 = num2[j--] - '0';
        }
        else
        {
            digit2 = 0;
        }

        int sum = digit1 + digit2 + ost;
        res.push_back((sum % 10) + '0');
        ost = sum / 10;
    }
    // Переворачиваем строку
    string reversedResult;
    for (int i = res.length() - 1; i >= 0; --i) {
        reversedResult.push_back(res[i]);
    }
    return reversedResult;
}


// Функция для возведения строки в степень
string PowStr(int base, int stepen) {
    string result = "1";
    for (int i = 0; i < stepen; ++i) {
        result = StrMultInt(result, base);
    }
    return result;
}



// Функция для проверки и получения корректного ввода от пользователя
int proverka() {
    string input;
    while (true) {
        cout << "\nВведите целое число n (n >= 10): ";
        cin >> input;
        // Проверка, что введено целое число
        bool good = true;
        for (char c : input) {
            if (!isdigit(c)) {
                good = false;
                break;
            }
        }
        if (good) {
            int value = stoi(input);
            if (value >= 10) {
                return value;
            }
        }
        cout << "Неверный ввод! Введите целое число, большее или равное 10." << endl;
    }
}