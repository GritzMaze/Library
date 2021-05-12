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

bool User::operator==(const User& other) const {
    if(this->username == other.username
        && this->password == other.password) {
            return true;
        }
    return false;
}

bool User::operator!=(const User& other) const {
    return (!(*this == other));
}

const String User::getUsername() const {
    return this->username;
}

const String User::getPassword() const {
    return this->password;
}

bool User::isAdmin() const {
    return this->admin;
}

std::ostream &operator<<(std::ostream &out, const User &user) {
    std::cout << "Username: " << user.getUsername() << std::endl;
    std::cout << "Password: " << user.getPassword() << std::endl;
    std::cout << "Admin: ";
    (user.isAdmin() ? (std::cout << "Yes") : (std::cout << "No"));
    std::cout << std::endl;
    return out;
}
