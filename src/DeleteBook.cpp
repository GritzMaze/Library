#include "../include/BookDB.h"

bool BookDB::remove(const size_t &id)
{
    size_t size = books.getSize();
    for (size_t i = 0; i < size; ++i)
    {
        if (books[i]->getID() == id)
        {
            delete books[i];
            books.remove(i);
            return true;
        }
    }
    InputHandle::errMsg("404: ID not found.");
    return false;
}

void BookDB::deleteBooks()
{
    view();
    std::cout << "Enter ID to delete a book: ";
    size_t id = 0;
    std::cin >> id;
    if (std::cin.fail())
    {
        InputHandle::errMsg("Not a number entered for ID!");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        deleteBooks();
    }
    if (id == 0)
    {
        return;
    }
    if (remove(id))
    {
        std::cout << "Book deleted sucessfuly!";
        std::cout << "Press ANY key to continue...";
        if (getch())
        {
            deleteBooks();
        }
    }
    deleteBooks();
    return;
}