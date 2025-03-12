# pragma onece
# include <cstddef>

template <typename T>
struct MyNode {
    MyNode() : m_prev{nullptr}, m_next{nullptr}, m_data{0} {}
    MyNode(T v) : m_prev{nullptr}, m_next{nullptr}, m_data{v} {}
    T m_data;
    MyNode* m_prev;
    MyNode* m_next;
};

template <typename T>
class MyListTypeContainer {
public:
    MyListTypeContainer() : m_head{nullptr}, m_tail{nullptr}, m_size{0} {}
    ~MyListTypeContainer();
    void push_back(T value);
    int insert(T value, size_t N);
    int erase(size_t first, size_t last);
    int erase(size_t index);
    size_t size() { return m_size; }
    T operator[](size_t N);
private:
    MyNode<T>* m_head;
    MyNode<T>* m_tail;
    size_t m_size;
};

template <typename T>
MyListTypeContainer<T>::~MyListTypeContainer() {
    if ( m_head != nullptr && m_tail != nullptr) {
        for ( MyNode<T>* temp = m_tail->m_prev; temp != nullptr; temp = temp->m_prev) {
            delete temp->m_next;
        }
        delete m_head;
    }
}

template <typename T>
void MyListTypeContainer<T>::push_back(T value) {
    MyNode<T>* new_node = new MyNode<T>(value);
    if (m_head == nullptr)
    {
        m_head = new_node;
    }
    if (m_tail != nullptr) {
        new_node->m_prev = m_tail;
        m_tail->m_next = new_node;
    }
    m_tail = new_node;
    m_size += 1;
}

template <typename T>
int MyListTypeContainer<T>::insert(T value, size_t N) {
    if(N >= m_size) {
        return -1;
    }
    MyNode<T>* new_node = new MyNode<T>(value);
    if (m_size == 0) {
        m_head = new_node;
        m_tail = new_node;
    }
    else {
        MyNode<T>* node = m_head;
        for (size_t i = 0; i < N; ++i) {
            node = node->m_next;
        }
        if (node->m_prev != nullptr) {
            new_node->m_prev = node->m_prev;
            node->m_prev->m_next = new_node;
        }
        else {
            m_head = new_node;
        }
        node->m_prev = new_node;
        new_node->m_next = node;
    }
    m_size += 1;
    return 0;
}

template <typename T>
int MyListTypeContainer<T>::erase(size_t first, size_t last) {
    if (first >= m_size || last >= m_size) {
        return -1;
    }
    if ( first == 0 && last == m_size -1) {
        for ( MyNode<T>* temp = m_tail->m_prev; temp != nullptr; temp = temp->m_prev) {
            delete temp->m_next;
        }
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    else {
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
        }
        else {
            lastNode->m_next->m_prev = nullptr;
            m_head = lastNode->m_next;
        }
        if (lastNode->m_next != nullptr) {
            lastNode->m_next->m_prev = firstNode->m_prev;
        }
        else {
            firstNode->m_prev->m_next = nullptr;
            m_tail = firstNode->m_prev;
        }
        if (first != last) {
            firstNode->m_prev = nullptr;
            for ( MyNode<T>* temp = lastNode->m_prev; temp != nullptr; temp = temp->m_prev) {
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
T MyListTypeContainer<T>::operator[](size_t N) {
    MyNode<T>* node = m_head;
    if (N != 0) {
        for (size_t i = 0; i < N; ++i) {
            node = node->m_next;
        }
    }
    return node->m_data;
}
