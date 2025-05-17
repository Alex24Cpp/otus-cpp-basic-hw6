
#include <iostream>

#include "list-type_container.hpp"
#include "serial_container.hpp"

int main() {
	std::cout << "Последовательный контейнер" << std::endl;
	MySerialContainer<int> serial_container;
	for (int i = 0; i < 10; i++) {
		serial_container.push_back(i);
	}

	std::cout << "Содержимое:" << std::endl;
	std::cout << "(ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)"
			  << std::endl;
	for (size_t i = 0; i < serial_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << serial_container[i];
	}
	std::cout << std::endl;

	std::cout << "Размер:" << std::endl;
	std::cout << "(ожидаемый результат: 10)" << std::endl;
	std::cout << serial_container.size() << std::endl;

	std::cout << "Удаление третьего (по счёту), пятого и седьмого элементов:"
			  << std::endl;
	std::cout << "(ожидаемый результат: 0, 1, 3, 5, 7, 8, 9)" << std::endl;
	for (int i = 6; i >= 2; i -= 2) {
		serial_container.erase(i);
	}
	for (size_t i = 0; i < serial_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << serial_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9)" << std::endl;
	serial_container.insert(10, 0);
	for (size_t i = 0; i < serial_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << serial_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 20 в середину контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9)"
			  << std::endl;
	serial_container.insert(20, 4);
	for (size_t i = 0; i < serial_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << serial_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)"
			  << std::endl;
	serial_container.push_back(30);
	for (size_t i = 0; i < serial_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << serial_container[i];
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Контейнер спискового типа" << std::endl;
	MyListTypeContainer<int> listType_container;
	for (int i = 0; i < 10; i++) {
		listType_container.push_back(i);
	}

	std::cout << "Содержимое:" << std::endl;
	std::cout << "(ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)"
			  << std::endl;
	for (size_t i = 0; i < listType_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << listType_container[i];
	}
	std::cout << std::endl;

	std::cout << "Размер:" << std::endl;
	std::cout << "(ожидаемый результат: 10)" << std::endl;
	std::cout << listType_container.size() << std::endl;

	std::cout << "Удаление третьего (по счёту), пятого и седьмого элементов:"
			  << std::endl;
	std::cout << "(ожидаемый результат: 0, 1, 3, 5, 7, 8, 9)" << std::endl;
	for (int i = 6; i >= 2; i -= 2) {
		listType_container.erase(i);
	}
	for (size_t i = 0; i < listType_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << listType_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9)" << std::endl;
	listType_container.insert(10, 0);
	for (size_t i = 0; i < listType_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << listType_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 20 в середину контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9)"
			  << std::endl;
	listType_container.insert(20, 4);
	for (size_t i = 0; i < listType_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << listType_container[i];
	}
	std::cout << std::endl;

	std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
	std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)"
			  << std::endl;
	listType_container.push_back(30);
	for (size_t i = 0; i < listType_container.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << listType_container[i];
	}
	std::cout << std::endl;

	return 0;
}