#pragma once
#include "Database.h"
#include "InputHandle.h"
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits

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
};