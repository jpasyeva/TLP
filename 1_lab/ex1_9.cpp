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
    std::cout << "Students with grades 4 or 5:\n";
    for (int i = 0; i < size; ++i) {
        if (students[i].grades[0] >= 4 && students[i].grades[1] >= 4 &&
            students[i].grades[2] >= 4 && students[i].grades[3] >= 4 &&
            students[i].grades[4] >= 4) {
            std::cout << "Lastname: " << students[i].name << "\tGroup number: " << students[i].groupNumber << "\n";
        }
    }
}

int main() {
    // Создание массива структур Student
    Student students[10] = {
        {"Smith A.I.", 1, 4, 5, 4, 3, 5},
        {"Johnson Y.R.", 2, 5, 5, 4, 5, 5},
        {"Williams V.A.", 1, 4, 4, 3, 4, 5},
        {"Brown G.G.", 2, 3, 4, 5, 3, 4},
        {"Jones D.S.", 1, 5, 5, 5, 5, 5},
        {"Garcia W.R.", 2, 4, 3, 4, 4, 5},
        {"Miller J.V.", 1, 5, 4, 5, 4, 5},
        {"Davis I.I.", 2, 4, 3, 3, 4, 4},
        {"Rodriguez K.S.", 1, 3, 4, 5, 4, 3},
        {"Martinez Z.A.", 2, 5, 5, 4, 5, 5}
    };

    // Упорядочивание записей по возрастанию среднего балла
    std::sort(students, students + 10, compareByAverageGrade);

    // Вывод отсортированного массива
    std::cout << "Ordered entries in ascending order of the average score:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << std::setw(20) << students[i].name << "\tGroup: " << students[i].groupNumber << "\tAverage score: " << students[i].averageGrade << "\n";
    }

    // Вывод студентов с оценками 4 и 5
    printHighAchievers(students, 10);

    system("pause");
    return 0;
}
