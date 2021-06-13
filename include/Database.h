#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"
#include <windows.h>
#include "Draw.h"

class Database
{
protected:
    virtual void view() = 0;

public:
    Database(){};
    virtual ~Database(){};

    virtual void add() = 0;
    virtual bool remove(const size_t &) = 0;
    virtual void open(const String &) = 0;
    virtual void save(const String &) = 0;
    virtual bool doesItExist(const String &) = 0;
};