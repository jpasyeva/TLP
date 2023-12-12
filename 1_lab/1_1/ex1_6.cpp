/*Условие*/

/*
Написать программу, которая определяет максимальное число 
из введённой с клавиатуры последовательности положительных чисел
(длина последовательности неограниченна)
*/


#include <iostream>

int main() {
    // Объявление переменных для хранения текущего числа и максимального числа
    double currentNumber, maxNumber = -1;

    // Ввод чисел и определение максимального с использованием do while
    std::cout << "Enter a sequence of positive numbers. To complete, enter a negative number.\n";

    do {
        std::cout << "Enter the number: ";
        std::cin >> currentNumber;

        // Проверка на отрицательное число для завершения ввода
        if (currentNumber < 0) {
            break;
        }

        // Проверка на положительное число и обновление максимального, если необходимо
        if (currentNumber > maxNumber) {
            maxNumber = currentNumber;
        }

    } while (true);

    // Вывод результата
    if (maxNumber >= 0) {
        std::cout << "The maximum number from the entered sequence: " << maxNumber << "\n";
    } else {
        std::cout << "No positive numbers entered.\n";
    }

    system("pause");
    return 0;
}
