#pragma once
#include <cstddef>


template <typename T>
struct MyUniDirNode {
	MyUniDirNode() = default;
	MyUniDirNode(T v) : m_data{v} {
	}
	MyUniDirNode* m_next{nullptr};
	T m_data{0};
};

template <typename T>
class MyUniDirListTypeContainer {
public:
	MyUniDirListTypeContainer() = default;
	~MyUniDirListTypeContainer();
	void push_back(T value);
	void push_front (T value) ;
	int insert(T value, size_t index);
	int erase(size_t first, size_t last);
	int erase(size_t index);
	size_t size() const;
	T operator[](size_t index) const;
	void clear();
private:
	MyUniDirNode<T>* m_head{nullptr};
	MyUniDirNode<T>* m_tail{nullptr};
	size_t m_size{0};
	void free_up_memory();
};

template <typename T>
MyUniDirListTypeContainer<T>::~MyUniDirListTypeContainer() {
	free_up_memory();
}

template <typename T>
void MyUniDirListTypeContainer<T>::push_back(T value) {
	MyUniDirNode<T>* new_node = new MyUniDirNode<T>(value);
	if (m_head == nullptr) {
		m_head = new_node;
	}
	if (m_tail != nullptr) {
		m_tail->m_next = new_node;
	}
	m_tail = new_node;
	++m_size;
}

template <typename T>
void MyUniDirListTypeContainer<T>::push_front(T value) {
	MyUniDirNode<T>* new_node = new MyUniDirNode<T>(value);
	if (m_tail == nullptr) {
		m_tail = new_node;
	} else {
		new_node->m_next = m_head;
	}
	m_head = new_node;
	++m_size;
}

template <typename T>
int MyUniDirListTypeContainer<T>::insert(T value, size_t index) {
	if (index >= m_size) {
		return -1;
	}
	MyUniDirNode<T>* new_node = new MyUniDirNode<T>(value);
	MyUniDirNode<T>* node = m_head;
	if (index == 0) {
		m_head = new_node;
		new_node->m_next = node;
	} else {
		for (size_t i = 0; i < index-1 || i == 1; ++i) {
			node = node->m_next;
		}
		new_node->m_next = node->m_next;
		node->m_next = new_node;
	}

	++m_size;
	return 0;
}

template <typename T>
int MyUniDirListTypeContainer<T>::erase(size_t index) {
	if (index >= m_size) {
		return -1;
	} else {
		MyUniDirNode<T>* nodeDel{nullptr};
		MyUniDirNode<T>* preNode{nullptr};
		nodeDel = m_head;
		if (index == 0) {
			m_head = m_head->m_next;
		} else {
			for (size_t i = 0; i <= index-1; ++i) {
				preNode = nodeDel;
				nodeDel = nodeDel->m_next;
			}
			preNode->m_next = nodeDel->m_next; 
		}
		delete nodeDel;
	}
	--m_size;
	return 0;
}

template <typename T>
int MyUniDirListTypeContainer<T>::erase(size_t first, size_t last) {
	if (first >= m_size || last >= m_size || first > last) {
		return -1;
	} else {
		MyUniDirNode<T>* nodeDelStart{nullptr};
		MyUniDirNode<T>* nodeDelEnd = m_head;
		MyUniDirNode<T>* preNode = m_head;
		MyUniDirNode<T>* afterNode{nullptr};
		if (first == 0) {
			if (m_head == m_tail) {
				delete m_head;
				m_head = m_tail = {nullptr};
				return 0;
			}
			nodeDelStart = m_head;
		} else {
			for (size_t i = 0; i < first-1 || i == 1; ++i) {
				preNode = preNode->m_next;
			}
			nodeDelStart = preNode->m_next;
		}
		
		if (last == m_size - 1) {
			for (size_t i = 0; i < last || i == 1; ++i) {
				nodeDelEnd = nodeDelEnd->m_next;
			}
			nodeDelEnd = m_tail;
			afterNode = nullptr;
			m_tail = preNode;
		} else {
			for (size_t i = 0; i < last || i == 1; ++i) {
				nodeDelEnd = nodeDelEnd->m_next;
			}
			afterNode = nodeDelEnd->m_next;
		}
		if (first == 0)	{
			m_head = afterNode;
		} else {
			preNode->m_next = afterNode;
		}
		for (size_t i = 0; i < last - first; ++i) {
			nodeDelEnd = nodeDelStart->m_next;
			delete nodeDelStart;
			nodeDelStart = nodeDelEnd;
		}
		m_size -= last - first + 1;
	}
	return 0;
}

template <typename T>
size_t MyUniDirListTypeContainer<T>::size() const {
	return m_size;
}

template <typename T>
T MyUniDirListTypeContainer<T>::operator[](size_t index) const {
	MyUniDirNode<T>* node = m_head;
	if (index != 0) {
		for (size_t i = 0; i < index; ++i) {
			node = node->m_next;
		}
	}
	return node->m_data;
}

template <typename T>
void MyUniDirListTypeContainer<T>::clear() {
	free_up_memory();
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template <typename T>
void MyUniDirListTypeContainer<T>::free_up_memory() {
	if (m_head != nullptr && m_tail != nullptr) {
		for (MyUniDirNode<T>* temp; m_head != nullptr;
			 m_head = temp) {
				temp = m_head->m_next;
				delete m_head;
		}
	}
}