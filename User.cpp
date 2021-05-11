#include "User.h"

User::User() : username("empty"), password(""), admin(false) {}
//User::User(const String& username_) : username(username_), password(""), admin(false) {}
User::User(const String& username_, const String& password_ = "", bool admin_ = false) : username(username_), password(password_), admin(admin_) {}
User::User(const User& other) {this->copy(other);}

void User::copy(const User& other) {
    setUsername(other.username);
    setPass(other.password);
    setAdmin(other.admin);
}

void User::setUsername(const String& username) {
    this->username = username;
}

void User::setPass(const String& password) {
    this->password = password;
}

void User::setAdmin(bool admin) {
    this->admin = admin;
}

User& User::operator=(const User& other) {
    this->copy(other);
    return *this;
}

const String User::getUsername() const {
    return this->username;
}

const String User::getPassword() const {
    return this->password;
}

bool User::isAdmin() {
    return this->admin;
}
