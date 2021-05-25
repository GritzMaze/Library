#include "include/Commands.h"
#include <iostream>
#include "include/Book.h"
#include "include/Vector.h"
#include "include/String.h"

int main() {
    // Vector<String> keywords;
    // String tag1 = "qko";
    // String tag2 = "qko2";
    // String tag3 = "qko3";
    // std::cout << tag1;
    // keywords.pushBack(tag1);
    // keywords.pushBack(tag2);
    // keywords.pushBack(tag3);
    // Book book1("Avtoras", "zaglavieto", "ekshan", "malko opisanie",2013, keywords,4.5);
    // Book book2(tag1, tag2, tag3, tag1,2013, keywords,4.5);
    // book1.print();
    // book1.getKeywords().print();
    // std::cout << std::endl;

    // book1.partlyPrint();
    // book2.partlyPrint();

     Commands app;
     app.start();

    return 0;
}
