#include "../include/UserDB.h"

UserDB::UserDB()
{
    User *defaultUser = new User("admin", "admin", true);
    users.pushBack(defaultUser);
}

UserDB::~UserDB()
{
    int size = users.getSize();
    for (int i = 0; i < size; i++)
    {
        if (users[i] != nullptr)
        {
            delete users[i];
        }
    }
}
