#ifndef _Moshkovich_MATHTASK_H_
#define _Moshkovich_MATHTASK_H_
#include <string>
#include <iostream>
using namespace std;
bool UserInput(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    //попытаться
    try {
        //преобразование введенного значения в тип int
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода целых чисел
void EnterNumber(int& varLink, string label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
};
bool UserInputDbl(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    //попытаться
    try {
        //преобразование введенного значения в тип int
        int number = stod(input);
        if (number < 0) return false;
    }
    catch (...) //если возникла ошибка в блоке try
    {
        return false;
    }
    return true;
}
//вспомогательная функция для ввода целых чисел
void EnterDouble(double& varLink, string label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInputDbl(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stod(raw_input);
};
void EnterString(string& varLink, string label) {
    cout << label << " = ";
    getline(cin, varLink);
};
void EnterNumberX() {
    int X;
    EnterNumber(X, "Введите натуральное число: ");
    if (X == int(X) && X > 0) {
        cout << "Число " << X << " натуральное!\n";
    }
    else {
        cout << "Число " << X << " не натуральное.\n";
    }
    cout << endl;
}
void EnterCalcNumber() {
    int X, Z;
    EnterNumber(X, "Введите натуральное число: ");
    if (X == int(X) && X > 0) {
        int chislo = 0;
        int count = 0;
        while (X) {
            Z = X % 10;
            if (count == 0)
                chislo = Z;
            count++;
            X /= 10;
        }
        if (chislo == Z) cout << "Начальная и конечная цифры в числе одинаковые" << endl;
        else {
            cout << "Начальная и конечная цифры в числе разные" << endl;
        }
    }
    else {
        cout << "Число " << X << " не натуральное.\n";
    }
}
void EnterNumberKonec() {
    int X;
    EnterNumber(X, "Введите натуральное число: ");
    if (X == int(X) && X > 0) {
        if ((X % 10) % 2 != 0) {
            cout << "Число заканчивается нечётной цифрой." << endl;
        }
        else {
            cout << "Число заканчивается чётной цифрой,введите другое число." << endl;
        }
    }
    else {
        cout << "Число " << X << " не натуральное.\n";
    }
}
#endif