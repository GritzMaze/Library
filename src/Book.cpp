#include "../include/Book.h"
    size_t Book::_id = 0;

Book::Book() {
    author = "";
    title = "";
    genre = "";
    description = "";
    yearOfPublish = 0;
    rating = 0.0;
    id = ++_id;    
}

Book::Book(const String &_author, const String &_title, const String &_genre,
            const String &_desc, const size_t &_yop, const Vector<String> &_keywords, const double &_rating) {
        this->author = _author;
        this->title = _title;
        this->genre = _genre;
        this->description = _desc;
        this->yearOfPublish = _yop;
        this->keywords = _keywords;
        this->rating = _rating;
        id = ++_id;
        }

Book::Book(const char*_author, const char*_title, const char*_genre,
            const char*_desc, const size_t &_yop, const Vector<String> &_keywords, const double &_rating) {
        this->author = _author;
        this->title = _title;
        this->genre = _genre;
        this->description = _desc;
        this->yearOfPublish = _yop;
        this->keywords = _keywords;
        this->rating = _rating;
        id = ++_id;
        }


Book& Book::operator=(const Book& other) {
    this->author = other.author;
    this->title = other.title;
    this->genre = other.genre;
    this->description = other.description;
    this->yearOfPublish = other.yearOfPublish;
    this->keywords = other.keywords;
    this->rating = other.rating;

    return *this;
}


void Book::setAuthor(const String& author) {
    this->author = author;
}

void Book::setTitle(const String& title) {
    this->title = title;
}

void Book::setGenre(const String& genre) {
    this->genre = genre;
}

void Book::setDesc(const String& description) {
    this->description = description;
}

void Book::setYOP(const size_t& yearOfPublish) {
    this->yearOfPublish = yearOfPublish;
}

void Book::setKeyWords(const Vector<String>& keywords) {
    this->keywords = keywords;
}

void Book::setKeyWordsFromInput() {
    String temp;
    std::cin >> temp;
    String keyword = "";
    char ch;
    const char SPACE = ' ';

    int size = temp.getLength();
    for(int i = 0; i < size; i++) {
        ch = temp[i];
        if(ch == SPACE) {
            keywords.pushBack(keyword);
            keyword = "";
            
            }
            
        keyword += ch;
    }
    if(keyword.getLength() > 0) {
    keywords.pushBack(keyword);
    }
}

void Book::setAuthorFromInput() {
    String temp = InputHandle::inputWithLimit(20);
    this->author = temp;
}

void Book::setTitleFromInput() {
    String temp = InputHandle::inputWithLimit(30);
    this->title = temp;
}

void Book::setGenreFromInput() {
    String temp = InputHandle::inputWithLimit(15);
    this->genre = temp;
}

void Book::setDescFromInput() {
    String temp = InputHandle::inputWithLimit(150);
    this->description = temp;
}

void Book::setYOPFromInput() {
    int temp = 0;
    std::cin >> temp;
    this->yearOfPublish = temp;

}

void Book::setRatingFromInput() {
    double temp = 0.0;
    std::cin >> temp;
    this->rating = temp;
}

void Book::setRating(const double& rating) {
    this->rating = rating;
} 

const String& Book::getAuthor() const {
    return this->author;
}

const String& Book::getTitle() const {
    return this->title;
}

const String& Book::getDesc() const {
    return this->description;
}

const size_t& Book::getYOP() const {
    return this->yearOfPublish;
}

const Vector<String>& Book::getKeywords() const {
    return this->keywords;
}

const double& Book::getRating() const {
    return this->rating;
}

const size_t& Book::getID() const {
    return this->id;
}

const void Book::partlyPrintVertical(const int& y) const {
    Draw::gotoxy(20,y);
    std::cout << this->title;
    Draw::gotoxy(50, y);
    std::cout << this->author;
    Draw::gotoxy(70, y);
    std::cout << this->genre;
    Draw::gotoxy(90, y);
    std::cout << this->id;
}

const void Book::partlyPrint() const {
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Genre:  " << this->genre << std::endl;
    std::cout << "ID: " << this->id << std::endl;
}

const void Book::print() const {
        std::cout << "Title: " << this->title << std::endl;
        std::cout << "Author: " << this->author << std::endl;
        std::cout << "Genre:  " << this->genre << std::endl;
        std::cout << "Description: " << this->description<< std::endl;
        std::cout << "Keywords: ";
        this->keywords.print();
        std::cout << "Year: " << this->yearOfPublish << std::endl;
        std::cout << "Rating: " << this->rating << std::endl;
        std::cout << "ID: " << this->id << std::endl;
}