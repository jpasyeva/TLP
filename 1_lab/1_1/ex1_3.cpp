/*Условие*/

/*
Написать программу решения квадратного уравнения. 
Программа должна проверять правильность исходных данных и в случае, 
если коэффициент при второй степени неизвестного равен нулю, 
выводить соответствующее сообщение
*/


#include <iostream>
#include <cmath>

int main() {
    // Объявление переменных для коэффициентов уравнения
    double a, b, c;

    // Ввод коэффициентов
    std::cout << "Enter the coefficient a: ";
    std::cin >> a;

    std::cout << "Enter the coefficient b: ";
    std::cin >> b;

    std::cout << "Enter the coefficient c: ";
    std::cin >> c;

    // Проверка на правильность исходных данных
    if (a == 0) {
        std::cout << "The coefficient for the second degree of the unknown cannot be zero. The equation is not square.\n";
        return 0;
    }

    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;

    // Проверка дискриминанта
    if (discriminant > 0) {
        // Два корня
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "The equation has two roots:\n";
        std::cout << "Root 1 = " << x1 << "\n";
        std::cout << "Root 2 = " << x2 << "\n";
    } else if (discriminant == 0) {
        // Один корень
        double x = -b / (2 * a);
        std::cout << "The equation has one root:\n";
        std::cout << "Root = " << x << "\n";
    } else {
        // Нет действительных корней
        std::cout << "The equation has no real roots.\n";
    }

    system("pause");
    return 0;
}
