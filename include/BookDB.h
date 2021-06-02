#pragma once
#include "Database.h"
#include "Draw.h"
#include "InputHandle.h"
#include <ios>              //used to get stream size
#include <limits>           //used to get numeric limits

class BookDB : public Database {
    private:
        Vector<Book*> books;
    public:
    BookDB() {};
    ~BookDB();

    void add() override;
    bool remove(const size_t&) override;

    void view();
    void viewBooks();
    void deleteBooks();
    const bool printByID(const unsigned int&) const;
};