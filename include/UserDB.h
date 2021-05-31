#pragma once
#include "Database.h"

class UserDB : public Database {
    private:
    Vector<User> users;

    public:
    UserDB();
    ~UserDB() {};

    void add() override {}
    void remove(const Database *) override {}

    void login(bool&, bool&);
};