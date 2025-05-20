#pragma once
#include <cstddef>

template <typename T>
struct MyNode {
	MyNode() = default;
	MyNode(T v) : m_data{v} {
	}
	MyNode* m_prev{nullptr};
	MyNode* m_next{nullptr};
	T m_data{0};
};

template <typename T>
class MyListTypeContainer {
public:
	MyListTypeContainer() = default;
	~MyListTypeContainer();
	void push_back(T value);
	int insert(T value, size_t index);
	int erase(size_t first, size_t last);
	int erase(size_t index);
	size_t size() const;
	T operator[](size_t index) const;
	void clear();
private:
	MyNode<T>* m_head{nullptr};
	MyNode<T>* m_tail{nullptr};
	size_t m_size{0};
	void free_up_memory();
};

template <typename T>
MyListTypeContainer<T>::~MyListTypeContainer() {
	free_up_memory();
}

template <typename T>
void MyListTypeContainer<T>::push_back(T value) {
	MyNode<T>* new_node = new MyNode<T>(value);
	if (m_head == nullptr) {
		m_head = new_node;
	}
	if (m_tail != nullptr) {
		new_node->m_prev = m_tail;
		m_tail->m_next = new_node;
	}
	m_tail = new_node;
	++m_size;
}

template <typename T>
int MyListTypeContainer<T>::insert(T value, size_t index) {
	if (index >= m_size) {
		return -1;
	}
	MyNode<T>* new_node = new MyNode<T>(value);
	if (m_size == 0) {
		m_head = new_node;
		m_tail = new_node;
	} else {
		MyNode<T>* node = m_head;
		for (size_t i = 0; i < index; ++i) {
			node = node->m_next;
		}
		if (node->m_prev != nullptr) {
			new_node->m_prev = node->m_prev;
			node->m_prev->m_next = new_node;
		} else {
			m_head = new_node;
		}
		node->m_prev = new_node;
		new_node->m_next = node;
	}
	++m_size;
	return 0;
}

template <typename T>
int MyListTypeContainer<T>::erase(size_t first, size_t last) {
	if (first >= m_size || last >= m_size) {
		return -1;
	}
	if (first == 0 && last == m_size - 1) {
		free_up_memory();
		m_head = nullptr;
		m_tail = nullptr;
	} else {
		MyNode<T>* firstNode = m_head;
		for (size_t i = 0; i < first; ++i) {
			firstNode = firstNode->m_next;
		}
		MyNode<T>* lastNode = firstNode;
		for (size_t i = 0; i < last - first; ++i) {
			lastNode = lastNode->m_next;
		}
		if (firstNode->m_prev != nullptr) {
			firstNode->m_prev->m_next = lastNode->m_next;
		} else {
			lastNode->m_next->m_prev = nullptr;
			m_head = lastNode->m_next;
		}
		if (lastNode->m_next != nullptr) {
			lastNode->m_next->m_prev = firstNode->m_prev;
		} else {
			firstNode->m_prev->m_next = nullptr;
			m_tail = firstNode->m_prev;
		}
		if (first != last) {
			firstNode->m_prev = nullptr;
			for (MyNode<T>* temp = lastNode->m_prev; temp != nullptr;
				 temp = temp->m_prev) {
				delete temp->m_next;
			}
		}
		delete firstNode;
	}
	m_size -= (last - first) + 1;
	return 0;
}

template <typename T>
int MyListTypeContainer<T>::erase(size_t index) {
	return erase(index, index);
}

template <typename T>
size_t MyListTypeContainer<T>::size() const {
	return m_size;
}

template <typename T>
T MyListTypeContainer<T>::operator[](size_t index) const {
	MyNode<T>* node = m_head;
	if (index != 0) {
		for (size_t i = 0; i < index; ++i) {
			node = node->m_next;
		}
	}
	return node->m_data;
}

template <typename T>
void MyListTypeContainer<T>::clear() {
	free_up_memory();
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template <typename T>
void MyListTypeContainer<T>::free_up_memory() {
	if (m_head != nullptr && m_tail != nullptr) {
		for (MyNode<T>* temp = m_tail->m_prev; temp != nullptr;
			 temp = temp->m_prev) {
			delete temp->m_next;
		}
		delete m_head;
	}
}