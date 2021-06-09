#include "../include/InputHandle.h"

void InputHandle::errMsg(const String& err) {
   system("cls");
   Draw::gotoxy(15,7);
   std::cout << "The Following error ocurred: " << err;
   Draw::gotoxy(15,9);
   std::cout << "Press ANY key to continue...";
   getch();
   system("cls");
}

String InputHandle::inputValue() {
    system("cls");
    String temp;
    Draw::gotoxy(15, 7);
    std::cout << "Enter text: ";
    std::cin >> temp;
    return temp;
}


String InputHandle::inputWithLimit(const size_t& limit) {
    char ch;
    char input[150];
    const char BACKSPACE = 8;
    const char RETURN = 13;
    int i = 0;

    while (ch != RETURN)
    {
        ch = getch();
        if (ch != RETURN && ch != BACKSPACE && i < limit)
        {
            std::cout << ch;
            input[i] = ch;
            i++;
        }
        if (ch == BACKSPACE && i > 0)
        {
            --i;
            std::cout << "\b \b";
            continue;
        }
    }
    input[i] = '\0';
    String temp = input;
    return temp;
}