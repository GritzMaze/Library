#pragma once
#include "String.h"
#include "Vector.h"

class Book {
    private:
    String author;
    String title;
    String genre;
    String description;
    unsigned int yearOfPublish;
    Vector<String> keywords;
    double rating;
    unsigned int id;

    public:
        Book();
};