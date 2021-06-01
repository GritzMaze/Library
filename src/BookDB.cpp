#include "../include/BookDB.h"

BookDB::~BookDB() {
    int size = books.getSize();
    for(int i = 0; i < size; i++) {
        if(books[i] != nullptr) {
            delete books[i];
        }
    }
}

void BookDB::add() {
    Book *book = new Book();
    String temp;
    int year = 0;
    double rating = 0.0;
    Draw::drawHeader("ADD A BOOK");
    Draw::gotoxy(20,19);
    Draw::drawFooter(21);
    Draw::gotoxy(20, 5); std::cout << "Title(Max 30 ch): ";
    book->setTitleFromInput();
    Draw::gotoxy(20, 7); std::cout << "Author (Max 20 ch): ";
    book->setAuthorFromInput();
    Draw::gotoxy(20, 9); std::cout << "Genre(Max 15 ch): ";
    book->setGenreFromInput();
    Draw::gotoxy(20, 11); std::cout << "Description(Max 150 ch): ";
    book->setDescFromInput();
    Draw::gotoxy(20, 13); std::cout << "Year of publish: ";
    std::cin >> year;
    if(std::cin.fail()) {
        InputHandle::errMsg("NaN input in year");
        delete book;
        add();
    }
    book->setYOP(year);
    Draw::gotoxy(20, 15); std::cout << "Keywords(with spaces): ";
    book->setKeyWordsFromInput();
    Draw::gotoxy(20, 17); std::cout << "Rating(1-5): ";
    std::cin >> rating;
    if (std::cin.fail())
    {
        InputHandle::errMsg("NaN input in rating");
        delete book;
        add();
    }
    book->setRating(rating);
    

    books.pushBack(book);
    system("cls");
    Draw::gotoxy(15,7);
    std::cout << "Entry Successful!";
    Draw::gotoxy(15,9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void BookDB::view() {
    Draw::drawHeader("BOOK LIST");
    Draw::drawSubmenu("TITLE", "AUTHOR", "GENRE", "ID");
    int size = books.getSize();
    int i = 0;
    for(; i < size; ++i) {
        books[i]->partlyPrintVertical(7 + i);
    }
    if(i < 10) {
        i = 10;
    }
    Draw::drawFooter(i + 2);
}