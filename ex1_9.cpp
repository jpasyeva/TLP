/*Условие*/

/*
Создайте структуру с именем student, содержащую поля: фамилия и инициалы, номер группы, успеваемость (массив из пяти элементов). 
Создать массив из десяти элементов такого типа, упорядочить записи по возрастанию среднего балла. 
Добавить возможность вывода фамилий и номеров групп студентов, имеющих оценки, равные только 4 или 5
*/



#include <iostream>
#include <algorithm> 
#include <iomanip>  

// Структура student
struct Student {
    std::string name;      // Фамилия и инициалы
    int groupNumber;       // Номер группы
    double grades[5];       // Успеваемость
    double averageGrade;    // Средний балл

    // Конструктор для инициализации структуры
    Student(const std::string& n, int group, double g1, double g2, double g3, double g4, double g5): name(n), groupNumber(group) {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
        grades[3] = g4;
        grades[4] = g5;

        // Расчет среднего балла
        averageGrade = (g1 + g2 + g3 + g4 + g5) / 5.0;
    }
};

// Функция для сравнения средних баллов студентов
bool compareByAverageGrade(const Student& s1, const Student& s2) {
    return s1.averageGrade < s2.averageGrade;
}

// Функция для вывода студентов с оценками 4 и 5
void printHighAchievers(const Student students[], int size) {
    std::cout << "Студенты с оценками 4 или 5:\n";
    for (int i = 0; i < size; ++i) {
        if (students[i].grades[0] >= 4 && students[i].grades[1] >= 4 &&
            students[i].grades[2] >= 4 && students[i].grades[3] >= 4 &&
            students[i].grades[4] >= 4) {
            std::cout << "Фамилия: " << students[i].name << "\tНомер группы: " << students[i].groupNumber << "\n";
        }
    }
}

int main() {
    // Создание массива структур Student
    Student students[10] = {
        {"Иванов А.И.", 1, 4, 5, 4, 3, 5},
        {"Петров Б.В.", 2, 5, 5, 4, 5, 5},
        {"Сидоров В.А.", 1, 4, 4, 3, 4, 5},
        {"Козлов Г.Г.", 2, 3, 4, 5, 3, 4},
        {"Смирнов Д.С.", 1, 5, 5, 5, 5, 5},
        {"Андреев Е.П.", 2, 4, 3, 4, 4, 5},
        {"Никитин Ж.В.", 1, 5, 4, 5, 4, 5},
        {"Захаров И.И.", 2, 4, 3, 3, 4, 4},
        {"Григорьев К.С.", 1, 3, 4, 5, 4, 3},
        {"Борисов Л.А.", 2, 5, 5, 4, 5, 5}
    };

    // Упорядочивание записей по возрастанию среднего балла
    std::sort(students, students + 10, compareByAverageGrade);

    // Вывод отсортированного массива
    std::cout << "Упорядоченные записи по возрастанию среднего балла:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << std::setw(20) << students[i].name << "\tГруппа: " << students[i].groupNumber << "\tСредний балл: " << students[i].averageGrade << "\n";
    }

    // Вывод студентов с оценками 4 и 5
    printHighAchievers(students, 10);

    return 0;
}
