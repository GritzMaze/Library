#pragma once
#include <iostream>

template <typename T>
class Vector
{
    T *arr;
    size_t capacity;
    size_t size;

    void erase();
    void resize();
    void copy(const Vector<T>&);

public:

    Vector();
    Vector(const T*, const size_t&, const size_t&);
     Vector<T> &operator=(const Vector<T>&);
    ~Vector();

    const T& operator[] (const int&) const;
    T& operator[] (int&);


    void pushBack(const T&);
    void pushFront(const T&);
    const T& back() const;
    const T& front() const;
    void popBack();
    void remove(const size_t&);
    bool isExist(const T&) const;
    void swap(T&, T&);


    const T getElem(const size_t&) const;
    const size_t getSize() const;
    const size_t getcapacity() const;
    
    const void print() const;

    friend std::ostream &operator<<(std::ostream &out, Vector<T> &vect)
    {
        for (int i = 0; i < vect.getSize(); i++)
        {
            out << vect.arr[i] << " " << std::endl;
        }
        return out;
    }
};

template <typename T>
void Vector<T>::erase()
{
    if(arr != nullptr) {
    delete [] arr;
    }
}

template <typename T>
void Vector<T>::resize()
{
    capacity *= 2;
    T *temp = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}

template <typename T>
void Vector<T>::copy(const Vector<T> &other)
{
    arr = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Vector<T>::Vector() : size{0}, capacity{1}, arr{nullptr}
{
    try
    {
        arr = new T[capacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot create default constructor: " << e.what() << '\n';
    }
}

template <typename T>
Vector<T>::Vector(const T *o_arr, const size_t &o_size, const size_t &o_capacity) : size{o_size}, capacity{o_capacity}
{
    size = o_size;
    capacity = o_capacity;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        arr[i] = o_arr[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    erase();
    size = 0;
    capacity = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
T &Vector<T>::operator[](int &index)
{
    return arr[index];
}

template <typename T>
const T& Vector<T>::operator[](const int &index) const
{
        return arr[index];
}

template <typename T>
void Vector<T>::pushBack(const T &elem)
{
    if (size >= capacity)
    {
        resize();
    }

    arr[size] = elem;
    size++;
}

template <typename T>
void Vector<T>::pushFront(const T &elem)
{
    if (size >= capacity)
    {
        resize();
    }
    for (int i = size; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = elem;
    size++;
}

template <typename T>
void Vector<T>::popBack()
{
    this->size--;
}

template<class T>
void Vector<T>::remove(const size_t &position)
{
    if (position > size)
    {
        throw std::out_of_range("Out of range");
    }
    for (size_t i = position; i < size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
}

template <typename T>
const T &Vector<T>::front() const
{
    return arr[0];
}

template <typename T>
const T &Vector<T>::back() const
{
    return arr[size - 1];
}

template <class T>
bool Vector<T>::isExist(const T& elem) const {
    for(int i = 0; i < this->size; i++) {
        if(elem == arr[i]) { 
            return true;
        }
    }
    return false;
}

template <class T>
void Vector<T>::swap(T& elem1, T& elem2) {
    T temp = elem1;
    elem1 = elem2;
    elem2 = temp;

}

template <typename T>
const T Vector<T>::getElem(const size_t &index) const
{

    if (index < size) {
        return this->arr[index];
    }
    return arr[size];
}

template <typename T>
const size_t Vector<T>::getSize() const
{
    return this->size;
}

template <typename T>
const size_t Vector<T>::getcapacity() const
{
    return this->capacity;
}

template <typename T>
const void Vector<T>::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        (i<size-1 ? std::cout << ", " : std::cout << "");
    }
    std::cout << std::endl;
}