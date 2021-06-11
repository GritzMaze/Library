#include "../include/UserDB.h"

bool UserDB::remove(const size_t &id)
{
    system("cls");
    size_t size = users.getSize();
    for (size_t i = 0; i < size; ++i)
    {
        if (users[i]->getID() == id)
        {
            delete users[i];
            users.remove(i);
            return true;
        }
    }
    InputHandle::errMsg("404: ID not found.");
    return false;
}

    void UserDB::deleteUser()
    {
        view();
        std::cout << "Enter ID to delete a user: ";
        size_t id = 0;
        std::cin >> id;
        if (std::cin.fail())
        {
            InputHandle::errMsg("Not a number entered for ID!");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteUser();
        }
        if (id == 0)
        {
            return;
        }
        if (remove(id))
        {
            system("cls");
            Draw::gotoxy(15, 7);
            std::cout << "User deleted successfully!";
            Draw::gotoxy(15, 9);
            std::cout << "Press ANY key to continue...";
            if (getch())
            {
                deleteUser();
            }
        }
        return;
}