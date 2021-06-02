#pragma once
#include "Database.h"

class UserDB : public Database {
    private:
    Vector<User> users;

    public:
    UserDB();
    ~UserDB() {};

    void add() override {}
    bool remove(const size_t&) override {return false;}

    void login(bool&, bool&);
};