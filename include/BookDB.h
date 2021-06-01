#pragma once
#include "Database.h"
#include "Draw.h"
#include "InputHandle.h"


class BookDB : public Database {
    private:
        Vector<Book*> books;
    public:
    BookDB() {};
    ~BookDB();

    void add() override;
    void remove(const Database *) override {};

    void view();
};