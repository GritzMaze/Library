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
    T& back();
    T& front();
    void popBack();


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
    T temp2;
    for(int i = size; i < capacity; i++) {
        temp[i] = temp2;
    }
    erase();
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
Vector<T>::Vector() : size{0}, capacity{1}
{
    T temp;
    arr = new T[capacity];
    arr[0] = temp;
}

template <typename T>
Vector<T>::Vector(const T *o_arr, const size_t &o_size, const size_t &o_capacity)
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
    if(arr != nullptr) {
    erase();
    }
    size = 0;
    capacity = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
    {
        if(arr != nullptr) {
        erase();
        }
        copy(other);
    }
    return *this;
}

template <typename T>
const T& Vector<T>::operator[](const int &index) const
{
    if (index <= size)
    {
        return arr[index];
    }
    else
    {
        return arr[size];
    }
}

template <typename T>
T& Vector<T>::operator[](int &index)
{
    if (index <= size)
    {
        return arr[index];
    }
    else
    {
        return arr[size];
    }
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

template <typename T>
T &Vector<T>::front()
{
    return arr[0];
}

template <typename T>
T &Vector<T>::back()
{
    return arr[size - 1];
}

template <typename T>
const T Vector<T>::getElem(const size_t &index) const
{

    if (index < size)
        return this->arr[index];
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
        std::cout << arr[i] << " " << std::endl;
    }
    std::cout << std::endl;
}