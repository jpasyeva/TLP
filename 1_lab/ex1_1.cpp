/*Условие*/

/*
Написать программу, которая сравнивает два введённых с клавиатуры числа. 
Программа должна указать, какое число больше или, если числа равны, вывести соответствующее сообщение.
*/


#include <iostream>

int main() {

    // Объявление переменных для хранения введенных чисел
    double number1, number2;

    // Ввод первого числа
    std::cout << "Enter the first number: ";
    std::cin >> number1;

    // Ввод второго числа
    std::cout << "Enter the second number: ";
    std::cin >> number2;

    // Сравнение чисел и вывод результата
    if (number1 > number2) {
        std::cout << "The first number is greater than the second\n";
    } else if (number1 < number2) {
        std::cout << "The second number is greater than the first\n";
    } else {
        std::cout << "The entered numbers are equal\n";
    }

    system("pause");
    return 0;
}
