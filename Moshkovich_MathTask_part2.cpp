#include <iostream>
#include <map>
#include <functional>
#include "Moshkovich_MathTask_part2.h"

struct MenuItem {
    string title;             //Название пункта меню
    function<void()> action;  //Действие,выполняемое при выборе пункта
};
int main() {
    //Создание меню с использованием map
    map<int, MenuItem> menu = {
    {1, {"Введите натуральное число X", EnterNumberX}},
    {2, {"Начинается ли оно и заканчивается одной и той же цифрой?", EnterCalcNumber}},
    {3, {"Заканчивается ли оно нечетной цифрой?",EnterNumberKonec }},
    };
    int choice = 0;
    // Основной цикл программы
    setlocale(LC_ALL, "RU");
    std::cout << "Меню: " << endl;
    // Вывод всех пунктов меню
    for (const auto& item : menu) {
        cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Выход" << endl; // пункт для выхода из программы

    while (true) {
        // Ввод выбора пользователя
        EnterNumber(choice, "Введите номер пункта: ");
        // Выход из программы, если выбран пункт 0
        if (choice == 0) {
            cout << "2025 FirstName LastName" << endl;
            break;
        }
        cout << endl;
        // Проверка существует ли выбранный пункт меню
        if (menu.find(choice) != menu.end()) {
            menu[choice].action(); // Выполнение действия, связанного с пунктом меню
        }
        else {
            cout << "Некорректный ввод. "; // сообщение об ошибке, если пункт не найден
        }
        cout << endl << endl;
    }
    return 0;
}