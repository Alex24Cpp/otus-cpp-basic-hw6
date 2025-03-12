# pragma onece
# include <cstddef>

template <typename T>
class MySerialContainer {
public:
    inline MySerialContainer() : m_container{nullptr}, m_size{0} {
    }
    inline ~MySerialContainer() {
        delete [] m_container;
    }
    void push_back(T value);
    int insert(T value, size_t N);
    int erase(size_t first, size_t last);
    int erase(size_t index);
    size_t size() { return m_size; }
    T operator[](size_t N);
private:
    T* m_container;
    size_t m_size;
};

template <typename T>
void MySerialContainer<T>::push_back(T value) {
    T* new_region = new T[m_size + 1];          // новая область памяти
    for (size_t i = 0; i < m_size; ++i) {
        new_region[i] = m_container[i];         // копирование элементов
    }
    new_region[m_size] = value;                 // добавление нового элемента
    delete [] m_container;                      // удаление старой области
    m_container = new_region;                   // сохранение новой в мембер
    m_size += 1;
}

template <typename T>
int MySerialContainer<T>::insert(T value, size_t N) {
    if (N >= m_size) {
        return -1;
    }
    T* new_region = new T[m_size + 1];
    if (m_size != 0) {
        for (size_t i = 0; i <= N; ++i) {
            new_region[i] = m_container[i];
        }
    }
    new_region[N] = value;
    if (m_size != 0) {
        for (size_t i = N + 1; i <= m_size; ++i) {
        new_region[i] = m_container[i - 1];
        }
        delete [] m_container;  
    }
    m_container = new_region;
    m_size += 1;
    return 0;
}

template <typename T>
int MySerialContainer<T>::erase(size_t first, size_t last) {
    if (first >= m_size || last >= m_size) {
        return -1;
    }
    for( size_t i = 0; i < m_size - (last + 1); i++) {
        m_container[first + i] = m_container[(last +1) + i];
    }
    m_size -= (last - first) + 1;
    return 0;
}

template <typename T>
int MySerialContainer<T>::erase(size_t index) {
    return erase(index, index);
}


template <typename T>
T MySerialContainer<T>::operator[](size_t N) {
    return m_container[N];
}

