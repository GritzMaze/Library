#include "include/Commands.h"
#include <iostream>
#include <fstream>
#include "include/Book.h"
#include "include/UserDB.h"
#include "include/Vector.h"
#include "include/String.h"

int main()
{

      Commands app;
     app.start();
    //  String tag1 = "tag1";
    //  String tag2 = "tag2";
    //  Vector<String> tags;
    //  tags.pushBack(tag1);
    //  tags.pushBack(tag2);

    //  Book book("Game of Thrones", "Az sam avtorat", "fantyasy", "malko opisanie", 2013, tags, 2.5);
    //  Book book2("Game of Thrones2", "Az sam avtorat2", "fantyas2y", "malk2o opisanie", 20123, tags, 2.35);
    //  system("cls");
    //  book.print();
    // BookDB books;
    // books.add();
    // //books.add();
    // String filename = "books2.books";
    // std::ofstream file;
    // file.open(filename.getString());
    // books.save(filename);
    // if (!file)
    // {
    //     std::cout << "eror";
    // }
    // // file << "pesho";
    // book.save(file);
    // book2.save(file);
    // file.close();

    // char tmp[256];
    // getcwd(tmp,256);
    //     String path = tmp;
    //     path += "\\test.txt";
    //     std::ofstream MyFile;
    //     std::cout << path;
    //     MyFile.open(path.getString(), std::ios::out);
    //     if (MyFile.fail())
    //     {
    //         std::cout << "neshtofailna";
    //     }
    //     if (!MyFile.is_open())
    //     {
    //         std::cout << " ne se otvarq";
    //     }

    //     std::string str = "pesho";
    //     if (!MyFile)
    //         std::cout << "????";
    //     // Write to the file
    //     MyFile << str;
    //     MyFile << 23223322323;
    //     std::cout << str;
    //     // Close the file
    //     MyFile.close();
    //     std::cout << "??????????";
    return 0;
}
