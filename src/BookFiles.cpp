#include "../include/BookDB.h"
#include <cmath>

int toInt(const String &text)
{
    {
        int Integer = 0;
        int Length = text.getLength();
        for (int Caret = Length - 1, Digit = 1; Caret >= 0; --Caret, Digit *= 10)
        {
            if (text[Caret] == '-')
                return Integer * -1;
            Integer += (text[Caret] - '0') * Digit;
        }

        return Integer;
    }
}

double toDouble(const String &text)
{
    {
        double Double = 0;
        int Length = text.getLength();
        for (int Caret = Length - 1, Digit = 1; Caret >= 0; --Caret, Digit *= 10)
        {
            if (text[Caret] == '-')
                return Double * -1;
            Double += (text[Caret] - '0') * Digit;
        }

        return Double;
    }
}

void BookDB::save(const String &filename)
{
    //char tmp[256];
    //getcwd(tmp, 256);
    String filenameExt;
    //filenameExt = "\\Database\\";
    filenameExt = filename;
    filenameExt += ".books";
    std::ofstream file;
    file.open(filenameExt.getString(), std::ios::out);
    if (file.fail())
    {
        InputHandle::errMsg("File did not open!");
        return;
    }
    size_t size = books.getSize();
    for (int i = 0; i < size; ++i)
    {
        books[i]->save(file);
        if (i < size - 1)
            file << "\n";
    }
    file.close();
    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Books were successfully saved!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void BookDB::open(const String &filename)
{
    String filenameExt;
    filenameExt = filename;
    filenameExt += ".books";
    if (!doesItExist(filenameExt))
    {
        std::ofstream in(filenameExt.getString());
        in.close();
        return;
    }

    std::ifstream file;
    file.open(filenameExt.getString());
    if(!file.is_open()) {
        InputHandle::errMsg("Books: File was unable to open!");
        file.close();
        return;
    }

    bool isEmptyFile = file.peek() == std::ifstream::traits_type::eof();
    if (isEmptyFile)
    {
        InputHandle::errMsg("Books: File is empty!");
        file.close();
        return;
    }

    if (!file)
    {
        InputHandle::errMsg("Books: File was not open!");
        file.close();
        return;
    }

    String title, author, genre, description, tags;
    int year = 0;
    double rating = 0.0;
    char *buffer = new char[1000];

    while (!file.eof())
    {
        
        Book *book = new Book;
        file.getline(buffer, 1000, '\n');
        book->setTitle(buffer);
        file.getline(buffer, 1000, '\n');
        book->setAuthor(buffer);
        file.getline(buffer, 1000, '\n');
        book->setGenre(buffer);
        file.getline(buffer, 1000, '\n');
        book->setDesc(buffer);
        file.getline(buffer, 1000, '\n');
        book->setKeyWordsFromString(buffer);
        file.getline(buffer, 1000, '\n');
        year = toInt(buffer);
        book->setYOP(year);
        file.getline(buffer, 1000, '\n');
        rating = toDouble(buffer);
        book->setRating(rating);
        books.pushBack(book);
    }
    delete[] buffer;
    file.close();

    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Books were successfully opened!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}