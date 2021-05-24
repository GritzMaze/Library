#include "../include/String.h"

void String::copy(const String &other)
{
    setString(other.data);
    setSize(other.size);
    setCapacity(other.capacity);
}

void String::erase()
{
    this->size = 0;
    this->capacity = 0;
    if(data != nullptr) {
    delete[] this->data;
    }
}

String::String()
{
    this->size = 0;
    this->capacity = 6;
    this->data = new char[1];
    this->data[1] = '\0';
}

void String::resize()
{
    this->capacity *= 2;
    char *biggerString = new char[this->capacity];
    for (int i = 0; i < size; i++)
    {
        biggerString[i] = this->data[i];
    }
    delete [] data;
    this->data = biggerString;
}

String::String(const String &other)
{
    copy(other);
}

String::String(const char *other)
{
    data = new char(strlen(other) + 1);
    strncpy(data, other, strlen(other) + 1);
    size = strlen(other);
}

String::~String()
{
    if(data != nullptr) {
    erase();
    }
}

String& String::operator=(const String &other) {
    if(this != &other && other.data != nullptr) {
    this->copy(other);
    }
    return *this;
}

String &String ::operator=(const char *other)
{
    char *temp = new char[strlen(other) + 1];
    strncpy(temp, other, strlen(other) + 1);
    if (data != nullptr)
    {
        erase();
    }
    data = temp;
    size = strlen(other);
    return *this;
}

String &String ::operator=(const Vector<char> &other)
{
    char *temp = new char[other.getSize()];
    if (data != nullptr)
    {
        erase();
    }
    for(int i = 0; i < other.getSize(); i++) {
        temp[i] = other[i];
    }
    data = temp;
    size = strlen(data);
    delete [] temp;
    return *this;
}

String String::operator+(const String &other)
{
    String temp;
    temp = *this;
    for (int i = 0; i < other.size; i++)
    {
        temp.add(other.data[i]);
    }
    return temp;
}

String& String::operator+=(const String &other)
{
    return *this = *this + other;
}

bool String::operator==(const String &other) const
{
    if (this->size != other.size){
        return false;
    }
    else {
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] != other.data[i])
            return false;
    }
    return true;
    }
}

bool String ::operator==(const char *other) const
{
    if (this->size != strlen(other))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] != other[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool String ::operator==(const char &other) const
{
    if (this->size > 1)
    {
        return false;
    }
    if (data[0] != other)
    {
        return false;
    }
    return true;
}

bool String::operator!=(const String &other) const 
{
    return !(*this == other);
}

bool String ::operator!=(const char *other) const { return !(*this == other); }

const char& String::operator[](const int &index) const
{
    return this->data[index];
}

char& String::operator[](int &index)
{
    return this->data[index];
}

std::ostream &operator<<(std::ostream& out, const String& string) {
    
        out << string.data;

    return out;
}

std::istream &operator>>(std::istream& in, String& string) {
    // std::cout << "Enter size: ";
    // in >> string.size;
    // string.capacity = string.size;
    // std::cout << "Enter string: ";
    // for(int i = 0; i < string.size; i++) {
    //     in >> string.string[i];
    // }

    char ch;
    int i = 0;

    // while not Enter
    while (ch != 13)
    {
        ch = getch();
        std::cout << ch;
        // if(ch == 8) {
        //         --i;
        //        putch('\b');
        //     continue;
        // }

        // While not Enter or Backspace
        if (ch != 13 && ch != 8)
        {
            string.data[i] = ch;
            i++;
        }
    }
    string[i] = '\0';
    string.size = i;
    string.capacity = string.size + 1;

        return in;
    }

    void String::add(const char &symb)
{
    if (capacity + 1 <= this->size)
        this->resize();

    this->data[this->size++] = symb;
    this->data[this->size] = '\0';
}

void String::insertAt(const char &symb, int index)
{
    if (capacity + 1 <= this->size)
        this->resize();
    if (index > this->size)
        index = this->size;
    int i = this->size;
    for (; i > index; i--)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = symb;
}

void String::removeAt(int& index)
{
    if (size <= 0)
        return;
    if (index > this->size)
        index = size;
    int i = index;
    for (; i < this->size; i++)
    {
        this->data[i] = data[i + 1];
    }
    this->size--;
}

void String::trimStart()
{
    if (size <= 0)
        return;
    int i = 0;
    for (; i < this->size; i++)
    {
        this->data[i] = data[i + 1];
    }
    this->size--;
}

void String::trimEnd()
{
    if (size > 0)
    {
        this->size--;
        this->data[size] = '\0';
    }
}

void String::trimStart(int num)
{
    if (size <= 0)
        return;
    for (int k = num; k > 0; k--)
    {
        for (int i = num; i < this->size; i++)
        {
            this->data[i] = data[i + 1];
        }
        num--;
        this->size--;
    }
}

void String::trimEnd(int& num)
{
    if (size > 0)
    {
        this->size -= num;
        this->data[size] = '\0';
    }
}

const int String::getLength() const
{
    return this->size;
}

const char *String::getString() const
{
    return this->data;
}

const int String::getCapacity() const
{
    return this->capacity;
}

void String::setString(const char *other)
{
    if(this->data != nullptr) {
    erase();
    }
    this->size = strlen(other);
    this->capacity = this->size + 1;
    this->data = new char[size];
    strncpy(this->data, other, strlen(other) + 1);
}

// Kinda not secure and deff not necessary but im gonna put it anyway
void String::setSize(const int size)
{
    if (size > this->size)
        this->size = size;
}

void String::setCapacity(const int capacity)
{
    if (capacity > this->size)
        this->capacity = capacity;
}

const void String::print() const
{
    std::cout << "String: " << this->data << std::endl;
    std::cout << "Size: " << this->size << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
}