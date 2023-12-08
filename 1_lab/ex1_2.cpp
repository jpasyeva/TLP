/*Условие*/

/*
Написать программу, которая проверяет является ли год високосным.
*/


#include <iostream>

int main() {
    // Объявление переменной для хранения введенного года
    int year;

    // Ввод года
    std::cout << "Enter the year: ";
    std::cin >> year;

    // Проверка на високосность
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << year << " year is a leap year.\n";
    } else {
        std::cout << year << " year is not a leap year.\n";
    }

    system("pause");
    return 0;
}
