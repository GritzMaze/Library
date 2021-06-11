#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "../doctest/doctest.h"
#include "../include/String.h"
#include "../include/Vector.h"


TEST_CASE("Split words manual input")
{
    String command;
    std::cin >> command;
    command.toLower();
    command.removeSpaces();
    Vector<String> words;
    VectorString::splitIntoWords(command, words);
    words.print();
    CHECK(words[0] == "save");
    CHECK(words[1] == "as");
    CHECK(words.getSize() == 2);
}

TEST_CASE("Split words auto input")
{
    String sentence = "   TEST   a  sd  PO- kOf   ";
    sentence.toLower();
    sentence.removeSpaces();
    Vector<String> words;
    VectorString::splitIntoWords(sentence, words);
    words.print();
    CHECK(words[0] == "test");
    CHECK(words[1] == "a");
    CHECK(words[2] == "sd");
    CHECK(words[3] == "po-");
    CHECK(words[4] == "kof");
    CHECK(words.getSize() == 5);
}

TEST_CASE("Empty word")
{
    String sentence = "   ";
    sentence.toLower();
    sentence.removeSpaces();
    std::cout << sentence;
    Vector<String> words;
    VectorString::splitIntoWords(sentence, words);
    words.print();
    //CHECK(words[0] == nullptr);
    CHECK(words.getSize() == 0);
}