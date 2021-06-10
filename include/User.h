#pragma once
#include <iostream>
#include "String.h"
#include "Draw.h"
#include <fstream>

class User {
    private:
        String username;
        String password;
        bool admin;
        size_t id;
        static size_t _id;

        void copy(const User&);

    public:
        User();
        User(const String&);
        User(const String&, const String&, bool);
        User(const User&);

    User& operator=(const User&);
    bool operator==(User*);
    bool operator==(const User&) const;
    bool operator!=(const User&) const;
    bool operator!=(User*);

    void setUsername(const String&);
    void setPass(const String&);
    void setAdmin(bool);

    const String getUsername() const;
    const String getPassword() const;
    const size_t getID() const;
    bool isAdmin() const;

    friend std::ostream &operator<<(std::ostream &, const User &);

    void print() const;
    const void printVertical(const int&) const;

    const void save(std::ofstream&) const;
    void load(std::ifstream&);
};
