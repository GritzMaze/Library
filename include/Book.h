#pragma once
#include "String.h"
#include "Vector.h"
#include "Draw.h"
#include "InputHandle.h"
#include <fstream>

class Book {
    private:
    String author;
    String title;
    String genre;
    String description;
    size_t yearOfPublish;
    Vector<String> keywords;
    double rating;
    size_t id;
    static size_t _id;

    public:
        Book();
        Book(const String&, const String&, const String&, const String&, const size_t&, const Vector<String>&, const double&);
        Book(const char*, const char*, const char*, const char*, const size_t&, const Vector<String>&, const double&);

        Book& operator=(const Book&);

    void setAuthor(const String&);
    void setTitle(const String&);
    void setGenre(const String&);
    void setDesc(const String&);
    void setYOP(const size_t&);
    void setKeyWords(const Vector<String>&);
    void setRating(const double&);
    void setAuthorFromInput();
    void setTitleFromInput();
    void setGenreFromInput();
    void setDescFromInput();
    void setYOPFromInput();
    void setKeyWordsFromInput();
    void setKeyWordsFromString(const String&);
    void setRatingFromInput();

    const String& getAuthor() const;
    const String& getTitle() const;
    const String& getGenre() const;
    const String& getDesc() const;
    const size_t& getYOP() const;
    const Vector<String>& getKeywords() const;
    const double& getRating() const;
    const size_t& getID() const;

    const void save(std::ofstream&) const; 
    const void open(const std::fstream&);

    const void partlyPrint() const;
    const void partlyPrintVertical(const int&) const;
    const void print() const;
};