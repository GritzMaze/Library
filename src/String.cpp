#include "../include/String.h"

void String::copy(const char* other)
{
    size = strlen(other);
    capacity = size + 1;
    char *buffer = nullptr;
    buffer = create(size + 1);
    strncpy(buffer, other, size + 1);
    data = buffer;
}

void String::erase()
{
    this->size = 0;
    this->capacity = 0;
    if (data != nullptr)
    {
        delete[] this->data;
    }
}

char *String ::create(const size_t &reserve) const
{
    char *buffer = nullptr;
    try
    {
        buffer = new char[reserve + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return buffer;
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
    char* biggerString = nullptr;
    this->capacity *= 2;
    try
    {
        biggerString = new char[this->capacity];
    }
    catch (const std::exception &e)
    {
        std::cerr << "Resize String: " << e.what() << '\n';
    }

    for (int i = 0; i < size; i++)
    {
        biggerString[i] = this->data[i];
    }
    delete[] data;
    this->data = biggerString;
}

String::String(const String &other)
{
    copy(other.data);
}

String::String(const char *other)
{
    try {
    data = new char[strlen(other) + 1];
    }
    catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    strncpy(data, other, strlen(other) + 1);
    size = strlen(other);
    capacity = size + 1;
}

String::~String()
{
    if (data != nullptr)
    {
        erase();
    }
}

String &String::operator=(const String &other)
{
    if (this != &other && other.data != nullptr)
    {
        this->copy(other.data);
    }
    return *this;
}

String &String ::operator=(const char *other)
{
    char *temp = nullptr;
    try {
    temp = new char[strlen(other) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
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
    char *temp = nullptr;
    try
    {
        temp = new char[other.getSize() + 1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    if (data != nullptr)
    {
        erase();
    }
    for (int i = 0; i < other.getSize(); i++)
    {
        temp[i] = other[i];
    }
    data = temp;
    size = strlen(data);
    delete[] temp;
    return *this;
}

String String::operator+(const String &other) const
{
    String result;
    result.size += this->size + other.size;
    result.capacity = result.size + 1;
    char *buffer = nullptr;
    buffer = create(result.size);
    for (size_t i = 0; i < size; ++i)
    {
        buffer[i] = data[i];
    }
    for (size_t i = size, j = 0; i < result.size && j < other.size; ++i, ++j)
    {
        buffer[i] = other.data[j];
    }
    buffer[result.size] = '\0';
    result.data = buffer;
    return result;
    // String temp;
    // temp = *this;
    // for(int i = 0; i < other.size; ++i) {
    //     temp.add(other.data[i]);
    // }
    // return temp;
}

String &String::operator+=(const String &other)
{
    *this = *this + other;
    return *this;
}

String String::operator+(const char *other) const
{
    String result;
    result.size += this->size + strlen(other);
    result.capacity = result.size + 1;
    char *buffer = nullptr;
    buffer = create(result.size);
    for (size_t i = 0; i < size; ++i)
    {
        buffer[i] = data[i];
    }
    for (size_t i = size, j = 0; i < result.size && j < strlen(other); ++i, ++j)
    {
        buffer[i] = other[j];
    }
    buffer[result.size] = '\0';
    result.data = buffer;
    return result;
    // String temp;
    // String temp2{other};
    // temp = *this + temp2;
    // return temp;
}

String String::operator+(const char &other) const
{
    String temp;
    temp = *this;
    temp.add(other);
    return temp;
}

String &String::operator+=(const char &other)
{
    *this = *this + other;
    return *this;
}

String &String::operator+=(const char *other)
{
    *this = *this + other;
    return *this;
}

bool String::operator==(const String &other) const
{
    if (this->size != other.size)
    {
        return false;
    }
    else
    {
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

bool String::operator>(const String &other) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] != other[i])
        {
            if (data[i] > other[i])
                return true;
            else
                return false;
        }
    }
    return true;
}

bool String::operator<(const String &other) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] != other[i])
        {
            if (data[i] < other[i])
                return true;
            else
                return false;
        }
    }
    return true;
}

bool String ::operator!=(const char *other) const { return !(*this == other); }

const char &String::operator[](const int &index) const
{
    if (index > size)
    {
        throw std::out_of_range("index out of bound");
    }
    return this->data[index];
}

char &String::operator[](int &index)
{
    if (index > size)
    {
        throw std::out_of_range("index out of bound");
    }
    return this->data[index];
}

std::ostream &operator<<(std::ostream &out, const String &string)
{

    out << string.data;

    return out;
}

std::istream &operator>>(std::istream &in, String &string)
{
    char *buffer = nullptr;
    try {
        buffer = new char[1000];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    in.getline(buffer, 1000);
    in.clear();
    string = String{buffer};
    delete[] buffer;
    return in;
}

String String::inputProtected()
{
    String temp;
    char ch;
    char str[30];
    const char BACKSPACE = 8;
    const char RETURN = 13;
    int i = 0;
    while (ch != RETURN)
    {
        ch = getch();
        if (ch != RETURN && ch != BACKSPACE && i < 30)
        {
            putch('*');
            str[i] = ch;
            i++;
        }
        if (ch == BACKSPACE && i > 0)
        {
            --i;
            std::cout << "\b \b";
            continue;
        }
    }
    str[i] = '\0';
    temp = str;
    return temp;
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
    ++size;
    for (size_t i = size; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = symb;
}

void String::removeAt(int &index)
{
    try
    {
        if (index > size)
        {
            throw std::out_of_range("index out of bound");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
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
        if (num > size)
        {
            throw std::out_of_range("index out of bound");
        }
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

void String::trimEnd(int &num)
{
    if (size > 0)
    {
        this->size -= num;
        this->data[size] = '\0';
    }
}

bool String::findElem(const char &elem) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == elem)
            return true;
    }
    return false;
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
    if (this->data != nullptr)
    {
        erase();
    }
    this->size = strlen(other);
    this->capacity = this->size + 1;
    try
    {
    this->data = new char[size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
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