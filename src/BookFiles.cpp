#include "../include/BookDB.h"

void BookDB::save(const String& filename) {
    //char tmp[256];
    //getcwd(tmp, 256);
    String filenameExt;
    //filenameExt = "\\Database\\";
    filenameExt = filename;
    filenameExt += ".books";
    std::ofstream file;
    file.open(filenameExt.getString(), std::ios::out);
    if(file.fail()) {
        InputHandle::errMsg("File did not open!");
        return;
    }
    size_t size = books.getSize();
    for(int i = 0; i < size; ++i) {
        books[i]->save(file);
    }
    file.close();
    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Database was successfully saved!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void BookDB::open(const String& filename) {
    String filenameExt = filename;
    filenameExt += ".books";
    if(!doesItExist(filenameExt)) {
        std::ofstream in(filenameExt.getString());
        in.close();
        return;
    }

    std::ifstream file;
    file.open(filenameExt.getString());
    if(!file) {
            InputHandle::errMsg("File was not open!");
            return;
    }
    bool isEmptyFile = file.peek() == std::ifstream::traits_type::eof();
    if(isEmptyFile) {
        InputHandle::errMsg("File is empty!");
        return;
    }

    String title, author, genre, description, tags;
    int year = 0;
    double rating = 0.0;

    while(1) {
        Book *book = new Book;
        file >> title;
        book->setTitle(title);
        file >> author;
        book->setAuthor(author);
        file >> genre;
        book->setGenre(genre);
        file >> description;
        book->setDesc(description);
        file >> tags;
        book->setKeyWordsFromString(tags);
        file >> year;
        book->setYOP(year);
        file >> rating;
        book->setRating(rating);
        books.pushBack(book);
        if (file.eof())
            break;
    }
    file.close();
}