/*Условие*/

/*
Проверить на чётность введённое с клавиатуры число
*/

#include <iostream>

int main() {
    // Объявление переменной для хранения введенного числа
    int number;

    // Ввод числа
    std::cout << "Enter the number: ";
    std::cin >> number;

    // Проверка на четность
    if (number % 2 == 0) {
        std::cout << "The number is " << number << " even.\n";
    } else {
        std::cout << "The number is " << number << " odd.\n";
    }

    system("pause");
    return 0;
}
