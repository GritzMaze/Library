#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"
#include <windows.h>
#include "Draw.h"

class Database {
public:
    Database() {};
    virtual ~Database() {};

    
    virtual void add() = 0;
    virtual bool remove(const size_t&) = 0;
};