#pragma once
#include <iostream>
#include "String.h"

class User {
    private:
        String username;
        String password;
        bool admin;

        void copy(const User&);

    public:
        User();
        User(const String&);
        User(const String&, const String&, bool);
        User(const User&);

    User& operator=(const User&);
    bool operator==(const User&) const;
    bool operator!=(const User&) const;

    void setUsername(const String&);
    void setPass(const String&);
    void setAdmin(bool);

    const String getUsername() const;
    const String getPassword() const;
    bool isAdmin() const;

    friend std::ostream &operator<<(std::ostream &, const User &);
};
