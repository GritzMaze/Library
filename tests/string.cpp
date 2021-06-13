#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "../doctest/doctest.h"
#include "../include/String.h"

TEST_CASE("test 1")
{
    CHECK(1 == 1);
}

TEST_CASE("Constructors")
{
    String s1("text");
    String s2(s1);
    String s3(s2);
    String s;
    //String s5(s);
    CHECK(s1.getLength() == s2.getLength());
    CHECK(s2.getLength() == s3.getLength());
    //std::cout << "Size of s: " << s.getLength() << "\n";
}

TEST_CASE("Assignment")
{
    std::cout << "Assignment:\n";
    String s1("text");
    std::cout << s1 << std::endl;
    String s2 = s1;
    String s3 = "a";
    CHECK(s1.getLength() == 4);
    CHECK(s2.getLength() == s1.getLength());
    CHECK(s3.getLength() == 1);
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s3: " << s3 << "\n";
}

TEST_CASE("operator[]")
{
    String s = "text";
    const String s_const = "text";
    CHECK(s[0] == 't');
    CHECK(s[1] == 'e');
    CHECK(s[2] == 'x');
    CHECK(s[3] == 't');
    CHECK(s_const[0] == 't');
    CHECK(s_const[1] == 'e');
    CHECK(s_const[2] == 'x');
    CHECK(s_const[3] == 't');
    //s_const[0] = 'a';
}

TEST_CASE("Capacity")
{
    String s;
    CHECK(s.getLength() == 0);
    s.setString("text");
    CHECK(s.getLength() > 0);
    CHECK(s.getLength() == 4);
}

TEST_CASE("Operations")
{
    String s1("Vesselin");
    String s2("Jivkov");
    String s3;
    std::cout << "s1 + s2 = " << s1 + s2 << "\n";
    std::cout << "s2 + s1 = " << s2 + s1 << "\n";
    std::cout << "s1 + array = " << s1 + "text"
              << "\n";
    std::cout << "string + char = " << s1 + 'a' << "\n";
    s3 += s1 + s2;
    std::cout << "Name: " << s3 << '\n';
    if (s1 != s2)
    {
        std::cout << "YES\n";
    }
    else
        std::cout << "NO\n";
    s2.insertAt('!', 3);
    CHECK(s2[3] == '!');
    std::cout << "s2 after insert: " << s2 << '\n';
    std::cout << "s1 and s2: " << s1 << " " << s2 << '\n';
    s1 = "text";
}

TEST_CASE("Input && Output")
{
    String s;
    std::cin >> s;
    std::cout << s << '\n';
}