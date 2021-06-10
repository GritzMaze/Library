#pragma once
#include "Database.h"
#include "InputHandle.h"
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <unistd.h>
#include <string>
#include <iostream>

class UserDB : public Database {
    private:
    Vector<User*> users;

    void view();

    public:
    UserDB();
    ~UserDB();

    void add() override;
    bool remove(const size_t&) override;

    void addUser();
    void deleteUser();
    void viewUsers();

    void login(bool&, bool&);

    void open(const String &);
    void save(const String &);
};