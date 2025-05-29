#pragma once
#include <cstddef>

template <typename T>
class MySerialContainer {
public:
	MySerialContainer(size_t capacity = 5, size_t adding_capacity = 3)	// capacity = 5, adding_capacity = 3 
		: m_capacity{capacity}, m_adding_capacity{adding_capacity} {	// для проверки резервирования памяти
		m_container = new T[m_capacity];
	}
	~MySerialContainer() {
		delete[] m_container;
	}
	void push_back(T value) {
		insert(value, m_size);
	}
	void push_front (T value) {
		insert(value, 0);
	}
	int insert(T value, size_t n) {
		if (n > m_size) {  								// проверка на вставку без разрыва
			return -1;
		}

		if (m_capacity == m_size) {
			m_capacity += m_adding_capacity;
			T* new_region = new T[m_capacity]; 	 		// новая область памяти
			for (size_t i = 0; i < m_size; ++i) {
				new_region[i] = m_container[i];  		// копирование элементов
			}
			delete[] m_container;  						// удаление старой области
			m_container = new_region;  					// сохранение новой в мембер
		}

		if (m_size != n) {
			for (size_t i = m_size; i > n; --i) {
				m_container[i] = m_container[i - 1];
			}
		}
		m_container[n] = value;
		++m_size;
		return 0;
	}
	int erase(size_t first, size_t last) {
		if (first >= m_size || last >= m_size) {
			return -1;
		}
		for (size_t i = 0; i < m_size - (last + 1); i++) {
			m_container[first + i] = m_container[(last + 1) + i];
		}
		m_size -= (last - first) + 1;
		return 0;
	}
	int erase(size_t index) {
		return erase(index, index);
	}
	size_t size() const {
		return m_size;
	}
	T operator[](size_t n) const {
		return m_container[n];
	}
	size_t capacity() const {
		return m_capacity;
	}
	void clear() {
		m_size = 0;
	}
private:
	T* m_container{nullptr};
	size_t m_size{0};
	size_t m_capacity{5};
	size_t m_adding_capacity{3};
};
