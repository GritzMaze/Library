#include "../include/UserDB.h"
User *defaultUser = new User("admin", "i<3c++", true);

UserDB::UserDB()
{
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
