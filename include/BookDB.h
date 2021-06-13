#pragma once
#include "Database.h"
#include "Draw.h"
#include "InputHandle.h"
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <unistd.h>

class BookDB : public Database
{
private:
    Vector<Book *> books;

    void view() override;

    void sortChoice();
    void sortChoice2(const String &);
    void sortCross(const String &, const String &);
    void sortBy(const String &);
    void sortByYear(const String &);
    void sortByRating(const String &);
    void sortByTitle(const String &);
    void sortByAuthor(const String &);
    void sort(const String &, const String &);

    void searchChoice();
    void viewSearched(const String &);
    int searchByTitle(const String &);
    int searchByAuthor(const String &);
    int searchByByKeyword(const String &);

public:
    BookDB(){};
    ~BookDB();

    void add() override;
    bool remove(const size_t &) override;

    void viewBooks();

    void deleteBooks();

    const bool printByID(const unsigned int &) const;

    void search();

    void sortBooks();

    void open(const String &) override;
    void save(const String &) override;

    bool doesItExist(const String &name) override
    {
        std::ifstream f(name.getString());
        bool st = f.good();
        f.close();
        return st;
    }
};