#include "../include/BookDB.h"

BookDB::~BookDB()
{
    int size = books.getSize();
    for (int i = 0; i < size; i++)
    {
        if (books[i] != nullptr)
        {
            delete books[i];
        }
    }
}