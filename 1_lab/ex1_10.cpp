/*Условие*/

/*
Создайте структуру с именем train, содержащую поля: название пункта назначения, номер поезда, время отправления. 
Ввести данные в массив из пяти элементов типа train, упорядочить элементы по номерам поездов. 
Добавить возможность вывода информации о поезде, номер которого введен пользователем. 
Добавить возможность сортировки массив по пункту назначения, причем поезда с одинаковыми пунктами назначения должны быть упорядочены по времени отправления.
*/


#include <iostream>
#include <algorithm>

// Структура train
struct Train {
    std::string destination; // Название пункта назначения
    int trainNumber;         // Номер поезда
    std::string departureTime; // Время отправления

    // Конструктор для инициализации структуры
    Train(const std::string& dest, int number, const std::string& time)
        : destination(dest), trainNumber(number), departureTime(time) {}

    // Перегрузка оператора < для сравнения по номерам поездов
    bool operator<(const Train& other) const {
        return trainNumber < other.trainNumber;
    }

    // Перегрузка оператора < для сравнения по пункту назначения и времени отправления
    bool operator<(const Train& other) {
        if (destination == other.destination) {
            return departureTime < other.departureTime;
        }
        return destination < other.destination;
    }
};

// Функция для вывода информации о поезде по его номеру
void printTrainInfo(const Train trains[], int size, int trainNumber) {
    for (int i = 0; i < size; ++i) {
        if (trains[i].trainNumber == trainNumber) {
            std::cout << "Train number: " << trains[i].trainNumber << "\n";
            std::cout << "Destination: " << trains[i].destination << "\n";
            std::cout << "Departure time: " << trains[i].departureTime << "\n";
            return;
        }
    }
    std::cout << "Train number " << trainNumber << " has not been found.\n";
}

int main() {
    // Создание массива структур Train
    Train trains[5] = {
        {"Cambridge", 102, "10:30"},
        {"Liverpool", 215, "12:45"},
        {"Sudbury", 125, "09:15"},
        {"Stratford", 330, "14:05"},
        {"Stratford", 142, "14:00"}
    };

    // Упорядочивание элементов по номерам поездов
    std::sort(trains, trains + 5);

    // Вывод отсортированного массива по номерам поездов
    std::cout << "Ordered entries by train numbers:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Train number: " << trains[i].trainNumber << "\tDestination: " << trains[i].destination << "\tDeparture time: " << trains[i].departureTime << "\n";
    }

    // Ввод номера поезда для вывода информации
    int inputTrainNumber;
    std::cout << "Enter train number for information: ";
    std::cin >> inputTrainNumber;

    // Вывод информации о введенном поезде
    printTrainInfo(trains, 5, inputTrainNumber);

    // Упорядочивание массива по пункту назначения и времени отправления
    std::sort(trains, trains + 5);

    // Вывод отсортированного массива по пункту назначения и времени отправления
    std::cout << "\nOrdered records by destination and departure time:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Train number: " << trains[i].trainNumber << "\tDestination: " << trains[i].destination << "\tDeparture time: " << trains[i].departureTime << "\n";
    }


    return 0;
}
