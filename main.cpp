
#include <iostream>

#include "list-type_container.hpp"
#include "serial_container.hpp"

template <typename T>
void PrintMyContainer(const T &myContainer) {
	for (size_t i = 0; i < myContainer.size(); i++) {
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << myContainer[i];
	}
	std::cout << std::endl;
}

int main() {
	{  // Работа с Последовательным контейнером
		std::cout << "Последовательный контейнер" << std::endl;
		MySerialContainer<int> serial_container(7, 1);
		for (int i = 0; i < 10; i++) {
			serial_container.push_back(i);
		}

		std::cout << "Содержимое:" << std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)"
				  << std::endl;
		PrintMyContainer(serial_container);

		std::cout << "Размер:" << std::endl;
		std::cout << "(ожидаемый результат: 10)" << std::endl;
		std::cout << serial_container.size() << std::endl;

		std::cout
			<< "Удаление третьего (по счёту), пятого и седьмого элементов:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 3, 5, 7, 8, 9)" << std::endl;
		for (int i = 6; i >= 2; i -= 2) {
			if (serial_container.erase(i) == -1) {
				std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
				return -1;
			}
		}
		PrintMyContainer(serial_container);

		std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9)"
				  << std::endl;
		if (serial_container.insert(10, 0) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(serial_container);

		std::cout << "Добавление элемента 20 в середину контейнера:"
				  << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9)"
				  << std::endl;
		if (serial_container.insert(20, 4) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(serial_container);

		std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)"
				  << std::endl;
		serial_container.push_back(30);
		PrintMyContainer(serial_container);

		std::cout
			<< "Удаление диапазона элементов c седьмого (по счёту) по девятый:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 30)"
				  << std::endl;
		if (serial_container.erase(6, 8) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(serial_container);

		std::cout << "Очистка контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: size = 0, пустой вывод содержимого)"
				  << std::endl;
		serial_container.clear();
		std::cout << "size = " << serial_container.size() << std::endl;
		PrintMyContainer(serial_container);
	}

	std::cout << std::endl
			  << "******************************************************"
			  << std::endl;

	{  // Работа с Контейнером спискового типа
		std::cout << std::endl;
		std::cout << "Контейнер спискового типа" << std::endl;
		MyListTypeContainer<int> listType_container;
		for (int i = 0; i < 10; i++) {
			listType_container.push_back(i);
		}

		std::cout << "Содержимое:" << std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)"
				  << std::endl;
		PrintMyContainer(listType_container);

		std::cout << "Размер:" << std::endl;
		std::cout << "(ожидаемый результат: 10)" << std::endl;
		std::cout << listType_container.size() << std::endl;

		std::cout
			<< "Удаление третьего (по счёту), пятого и седьмого элементов:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 3, 5, 7, 8, 9)" << std::endl;
		for (int i = 6; i >= 2; i -= 2) {
			if (listType_container.erase(i) == -1) {
				std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
				return -1;
			}
		}
		PrintMyContainer(listType_container);

		std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9)"
				  << std::endl;
		if (listType_container.insert(10, 0) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(listType_container);

		std::cout << "Добавление элемента 20 в середину контейнера:"
				  << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9)"
				  << std::endl;
		if (listType_container.insert(20, 4) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(listType_container);

		std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)"
				  << std::endl;
		listType_container.push_back(30);
		PrintMyContainer(listType_container);

		std::cout
			<< "Удаление диапазона элементов c седьмого (по счёту) по девятый:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 30)"
				  << std::endl;
		if (listType_container.erase(6, 8) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(listType_container);

		std::cout << "Очистка контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: size = 0, пустой вывод содержимого)"
				  << std::endl;
		listType_container.clear();
		std::cout << "size = " << listType_container.size() << std::endl;
		PrintMyContainer(listType_container);
	}

	return 0;
}