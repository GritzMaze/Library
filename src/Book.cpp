#include "../include/Book.h"
size_t Book::_id = 0;

Book::Book()
{
    author = "";
    title = "";
    genre = "";
    description = "";
    yearOfPublish = 0;
    rating = 0.0;
    id = ++_id;
}

Book::Book(const String &_author, const String &_title, const String &_genre,
           const String &_desc, const size_t &_yop, const Vector<String> &_keywords, const double &_rating)
{
    this->author = _author;
    this->title = _title;
    this->genre = _genre;
    this->description = _desc;
    this->yearOfPublish = _yop;
    this->keywords = _keywords;
    this->rating = _rating;
    id = ++_id;
}

Book::Book(const char *_author, const char *_title, const char *_genre,
           const char *_desc, const size_t &_yop, const Vector<String> &_keywords, const double &_rating)
{
    this->author = _author;
    this->title = _title;
    this->genre = _genre;
    this->description = _desc;
    this->yearOfPublish = _yop;
    this->keywords = _keywords;
    this->rating = _rating;
    id = ++_id;
}

Book &Book::operator=(const Book &other)
{
    this->author = other.author;
    this->title = other.title;
    this->genre = other.genre;
    this->description = other.description;
    this->yearOfPublish = other.yearOfPublish;
    this->keywords = other.keywords;
    this->rating = other.rating;

    return *this;
}

void Book::setAuthor(const String &author)
{
    this->author = author;
}

void Book::setTitle(const String &title)
{
    this->title = title;
}

void Book::setGenre(const String &genre)
{
    this->genre = genre;
}

void Book::setDesc(const String &description)
{
    this->description = description;
}

void Book::setYOP(const size_t &yearOfPublish)
{
    this->yearOfPublish = yearOfPublish;
}

void Book::setKeyWords(const Vector<String> &keywords)
{
    this->keywords = keywords;
}

void Book::setKeyWordsFromInput()
{
    String temp;
    std::cin >> temp;
    setKeyWordsFromString(temp);
}

void Book::setKeyWordsFromString(const String &tags)
{
    String keyword = "";
    char ch;
    const char SPACE = ' ';

    int size = tags.getLength();
    for (int i = 0; i < size; i++)
    {
        ch = tags[i];
        if (ch == SPACE)
        {
            if (keyword.getLength() > 1)
            {
                keywords.pushBack(keyword);
            }
            keyword = "";
        }
        else
        {
            keyword += ch;
        }
    }
    if (keyword.getLength() > 0)
    {
        keywords.pushBack(keyword);
    }
}

void Book::setAuthorFromInput()
{
    String temp = InputHandle::inputWithLimit(20);
    this->author = temp;
}

void Book::setTitleFromInput()
{
    String temp = InputHandle::inputWithLimit(30);
    this->title = temp;
}

void Book::setGenreFromInput()
{
    String temp = InputHandle::inputWithLimit(15);
    this->genre = temp;
}

void Book::setDescFromInput()
{
    String temp = InputHandle::inputWithLimit(150);
    this->description = temp;
}

void Book::setYOPFromInput()
{
    int temp = 0;
    std::cin >> temp;
    this->yearOfPublish = temp;
}

void Book::setRatingFromInput()
{
    double temp = 0.0;
    std::cin >> temp;
    this->rating = temp;
}

void Book::setRating(const double &rating)
{
    this->rating = rating;
}

const String &Book::getAuthor() const
{
    return this->author;
}

const String &Book::getTitle() const
{
    return this->title;
}

const String &Book::getDesc() const
{
    return this->description;
}

const size_t &Book::getYOP() const
{
    return this->yearOfPublish;
}

const Vector<String> &Book::getKeywords() const
{
    return this->keywords;
}

const double &Book::getRating() const
{
    return this->rating;
}

const size_t &Book::getID() const
{
    return this->id;
}

const void Book::save(std::ofstream &file) const
{
    file << this->title << "\n";
    file << this->author << "\n";
    file << this->genre << "\n";
    file << this->description << "\n";
    for (int i = 0; i < this->keywords.getSize(); ++i)
    {
        file << this->keywords[i] << " ";
    }
    file << "\n";
    file << this->yearOfPublish << "\n";
    file << this->rating;
}

const void Book::partlyPrintVertical(const int &y) const
{
    Draw::gotoxy(20, y);
    std::cout << this->title;
    Draw::gotoxy(50, y);
    std::cout << this->author;
    Draw::gotoxy(70, y);
    std::cout << this->genre;
    Draw::gotoxy(90, y);
    std::cout << this->id;
}

const void Book::partlyPrint() const
{
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Genre:  " << this->genre << std::endl;
    std::cout << "ID: " << this->id << std::endl;
}

const void Book::print() const
{
    Draw::drawHeader("BOOK INFO");
    Draw::gotoxy(20, 5);
    std::cout << "Title: " << this->title;
    Draw::gotoxy(20, 7);
    std::cout << "Author: " << this->author;
    Draw::gotoxy(20, 9);
    std::cout << "Genre:  " << this->genre;
    Draw::gotoxy(20, 11);
    std::cout << "Description: " << this->description;
    Draw::gotoxy(20, 13);
    std::cout << "Keywords: ";
    this->keywords.print();
    Draw::gotoxy(20, 15);
    std::cout << "Year: " << this->yearOfPublish;
    Draw::gotoxy(20, 17);
    std::cout << "Rating: " << this->rating;
    Draw::gotoxy(20, 19);
    std::cout << "ID: " << this->id;
    Draw::drawFooter(21);
}
