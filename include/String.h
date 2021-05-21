#pragma once
#include <iostream>
#include <cstring>
#include <conio.h>
#include "Vector.h"

class String
{
private:
    char *data;
    int size;
    int capacity;

    void copy(const String &);
    void erase();
    void resize();

public:
    String();
    String(const String &);
    String(const char *);
    ~String();
    String &operator=(const String &);
    String &operator+=(const String &);
    String operator+(const String &);
    bool operator==(const String &) const;
    bool operator!=(const String &) const;

    String &operator=(const char *);
    String &operator=(const Vector<char>&);

    bool operator==(const char *) const;
    bool operator==(const char &) const;
    bool operator!=(const char *) const;

    const char& operator[](const int&) const;
    char& operator[](int&);

    friend std::ostream &operator<<(std::ostream&, const String&);
    friend std::istream &operator>>(std::istream&, String&);

    void add(const char &);
    void insertAt(const char &, int);
    void removeAt(int&);
    void trimStart();
    void trimEnd();
    void trimStart(int);
    void trimEnd(int&);

    const int getLength() const;
    const char* getString() const;
    const int getCapacity() const;

    void setString(const char*);
    void setSize(const int);
    void setCapacity(const int);

    const void print() const;
};