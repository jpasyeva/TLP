// task01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

//в стеке последний вошел, первый вышел
#define LIST_MAX_SIZE 5 //макс размер стека

struct ListItem {
	float data;
};

class ListStatic {
private:
	int _size;
	ListItem* arr[LIST_MAX_SIZE];
public:
	ListStatic() {
		_size = 0;
	}
	bool is_empty();
	bool is_full();
	void insert();
	void insert_before();
	void remove();
	void print();
	void search();
	~ListStatic();
};



bool ListStatic::is_empty() {
	return _size == 0;
}

bool ListStatic::is_full() {
	return _size == LIST_MAX_SIZE;
}

void ListStatic::print() {
	if (is_empty()) {
		std::cout << "List is empty\n\n";
		return;
	}
	std::cout << "List is [";
	for (int i = 0; i < _size; i++) {
		std::cout << arr[i]->data << ((_size - i == 1) ? "" : " ");
	}
	std::cout << "]\n\n";
}

void ListStatic::insert() {
	if (is_full()) {
		std::cout << "List is full\n\n";
		return;
	}
	std::cout << "Enter value to insert in list: ";
	ListItem *temp = new ListItem();
	std::cin >> temp->data;
	int index;
	std::cout << "Enter the index after which you want to insert the value: ";
	std::cin >> index;
	std::cout << "\n\n";
	if (index >= _size) {
		arr[_size++] = temp;
	} else {
		int i;
		for (i = _size; i > index + 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[i] = temp;
		_size++;
	}
}

void ListStatic::insert_before() {
	if (is_full()) {
		std::cout << "List is full\n\n";
		return;
	}
	std::cout << "Enter value to insert in list: ";
	ListItem *temp = new ListItem();
	std::cin >> temp->data;
	int index;
	std::cout << "Enter the index before which you want to insert the value: ";
	std::cin >> index;
	std::cout << "\n\n";
	if (index > _size) {
		arr[_size++] = temp;
	}
	else {
		int i;
		for (i = _size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[i] = temp;
		_size++;
	}
}


void ListStatic::remove() {
	if (is_empty()) {
		std::cout << "List is empty\n\n";
		return;
	}
	std::cout << "Enter the index which element remove: ";
	int index;
	std::cin >> index;
	std::cout << "\n\n";
	if (index >= _size) {
		return;
	}
	else {
		int i;
		delete arr[index];
		for (i = index; i < _size; i++) {
			arr[i] = arr[i + 1];
		}
		_size--;
	}
}

void ListStatic::search() {
	if (is_empty()) {
		std::cout << "-1\n\n";
		return;
	}
	std::cout << "Enter the element to find: ";
	float elem;
	std::cin >> elem;
	int i;
	
	for (int i = 0; i < _size; i++) {
		if (arr[i]->data == elem) {
			std::cout << i << "\n\n";
			return;
		}
	}
	std::cout << "-1\n\n";
}


int main() {
	std::cout << "Chapter 1, Theme 3, Task 1\n";
	ListStatic* list = new ListStatic();
	while (1)
	{
		std::cout << "available actions:\n";
		std::cout << "1 - check list is empty\n";
		std::cout << "2 - insert after\n";
		std::cout << "3 - insert before\n";
		std::cout << "4 - remove\n";
		std::cout << "5 - print\n";
		std::cout << "6 - search element\n";
		std::cout << "7 - check list is full\n";
		std::cout << "q - exit\n\n > ";
		std::string res;
		std::cin >> res;
		float value;

		if (res == "1") {
			if (list->is_empty())
				std::cout << "List is empty\n\n";
			else
				std::cout << "List is not empty\n\n";
		}
		else if (res == "2") {
			list->insert();
		}
		else if (res == "3") {
			list->insert_before();
		}
		else if (res == "4") {
			list->remove();
		}
		else if (res == "5") {
			list->print();
		}
		else if (res == "6") {
			list->search();
		}
		else if (res == "7") {
			if (list->is_full())
				std::cout << "List is full\n\n";
			else
				std::cout << "List is not full\n\n";
		}
		else if (res == "q") {
			break;
		}
		else {
			std::cout << "Wrong action!\n\n";
		}
	}
}
