
#include <iostream>

#include "list-type_container.hpp"
#include "serial_container.hpp"
#include "unidir_list-type_container.hpp"

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

template <typename T>
int Func(T &myContainer) {
		for (int i = 0; i < 10; i++) {
			myContainer.push_back(i);
		}

		std::cout << "Содержимое:" << std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)"
				  << std::endl;
		PrintMyContainer(myContainer);

		std::cout << "Размер:" << std::endl;
		std::cout << "(ожидаемый результат: 10)" << std::endl;
		std::cout << myContainer.size() << std::endl;

		std::cout
			<< "Удаление третьего (по счёту), пятого и седьмого элементов:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 0, 1, 3, 5, 7, 8, 9)" << std::endl;
		for (int i = 6; i >= 2; i -= 2) {
			if (myContainer.erase(i) == -1) {
				std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
				return -1;
			}
		}
		PrintMyContainer(myContainer);

		std::cout << "Добавление элемента 10 в начало контейнера (insert):" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9)"
				  << std::endl;
		if (myContainer.insert(10, 0) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(myContainer);

		std::cout << "Добавление элемента 20 в середину контейнера:"
				  << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9)"
				  << std::endl;
		if (myContainer.insert(20, 4) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(myContainer);

		std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30)"
				  << std::endl;
		myContainer.push_back(30);
		PrintMyContainer(myContainer);

		std::cout
			<< "Удаление диапазона элементов c седьмого (по счёту) по девятый:"
			<< std::endl;
		std::cout << "(ожидаемый результат: 10, 0, 1, 3, 20, 5, 30)"
				  << std::endl;
		if (myContainer.erase(6, 8) == -1) {
			std::cout << "ОШИБКА!: недопустимый индекс" << std::endl;
			return -1;
		}
		PrintMyContainer(myContainer);

		std::cout << "Добавление элемента 11 в начало контейнера (push_front):" << std::endl;
		std::cout << "(ожидаемый результат: 11, 10, 0, 1, 3, 20, 5, 30)"
				  << std::endl;
		myContainer.push_front(11);
		PrintMyContainer(myContainer);

		std::cout << "Очистка контейнера (clear):" << std::endl;
		std::cout << "(ожидаемый результат: size = 0, пустой вывод содержимого)"
				  << std::endl;
		myContainer.clear();
		std::cout << "size = " << myContainer.size() << std::endl;
		PrintMyContainer(myContainer);
	return 0;
}

int main() {
/*
	{  // Работа с Последовательным контейнером
		std::cout << "Последовательный контейнер" << std::endl;
		MySerialContainer<int> serial_container;
		if (Func(serial_container) == -1) {
			return -1;
		}
	}

	std::cout << std::endl
			  << "******************************************************"
			  << std::endl;

	{  // Работа с Контейнером спискового типа (двунаправленный список)
		std::cout << std::endl;
		std::cout << "Контейнер спискового типа (двунаправленный список)" << std::endl;
		MyListTypeContainer<int> listType_container;
		if (Func(listType_container) == -1) {
			return -1;
		}
	}
*/
	std::cout << std::endl
			  << "******************************************************"
			  << std::endl;

	{  // Работа с Контейнером спискового типа (однонаправленный список)
		std::cout << std::endl;
		std::cout << "Контейнер спискового типа (однонаправленный список)" << std::endl;
		MyUniDirListTypeContainer<int> uniDirListType_container;
		if (Func(uniDirListType_container) == -1) {
			return -1;
		}
	}

	return 0;
}