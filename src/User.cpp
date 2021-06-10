#include "../include/User.h"

size_t User::_id = 0;

User::User() : username("empty"), password(""), admin(false)
{
    id = ++_id;
}
//User::User(const String& username_) : username(username_), password(""), admin(false) {}
User::User(const String &username_, const String &password_ = "", bool admin_ = false) : username(username_), password(password_), admin(admin_)
{
    id = ++_id;
}
User::User(const User &other)
{
    this->copy(other);
    id = ++_id;
}

void User::copy(const User &other)
{
    setUsername(other.username);
    setPass(other.password);
    setAdmin(other.admin);
}

void User::setUsername(const String &username)
{
    this->username = username;
}

void User::setPass(const String &password)
{
    this->password = password;
}

void User::setAdmin(bool admin)
{
    this->admin = admin;
}

User &User::operator=(const User &other)
{
    this->copy(other);
    return *this;
}

bool User::operator==(User *other)
{
    if (this->username == other->username && this->password == other->password)
    {
        this->admin = other->admin;
        return true;
    }
    return false;
}

bool User::operator==(const User &other) const
{
    if (this->username == other.username && this->password == other.password)
    {
        return true;
    }
    return false;
}

bool User::operator!=(const User &other) const
{
    return (!(*this == other));
}

bool User::operator!=(User *other)
{
    return (!(this == other));
}

const String User::getUsername() const
{
    return this->username;
}

const String User::getPassword() const
{
    return this->password;
}

const size_t User::getID() const
{
    return this->id;
}

bool User::isAdmin() const
{
    return this->admin;
}

const void User::save(std::ofstream &file) const
{
    file << this->username << "\n";
    file << this->password << "\n";
    file << std::boolalpha << this->admin;
}

void User::load(std::ifstream& file) {
    char *buffer = new char[1000];
    file.getline(buffer, '\n');
    this->username = buffer;
    file.clear();
    file.ignore(10000, '\n');
    file.getline(buffer, '\n');
    this->password = buffer;
    file.clear();
    file.ignore(10000,'\n');
    file >> this->admin;
    delete [] buffer;
    // file >> this->username >> this->password >> this->admin;
    // file.ignore(10000, '\n');
}

std::ostream &operator<<(std::ostream &out, const User &user)
{
    out << "Username: " << user.getUsername() << std::endl;
    out << "Password: " << user.getPassword() << std::endl;
    out << "Admin: ";
    (user.isAdmin() ? (out << "Yes") : (out << "No"));
    out << std::endl;
    out << "ID: " << user.getID() << std::endl;
    return out;
}

void User::print() const
{
    std::cout << "Username: " << this->getUsername() << std::endl;
    std::cout << "Password: " << this->getPassword() << std::endl;
    std::cout << "Admin: ";
    (this->isAdmin() ? (std::cout << "Yes") : (std::cout << "No"));
    std::cout << std::endl;
    std::cout << "ID: " << this->getID() << std::endl;
}

const void User::printVertical(const int& y) const {
    Draw::gotoxy(20, y);
    std::cout << this->username;
    Draw::gotoxy(70, y);
    std::cout << std::boolalpha << this->admin;
    Draw::gotoxy(90, y);
    std::cout << this->id;
}