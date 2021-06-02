#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "String.h"

class Draw {

    public:
    static void drawMenu(const bool&, const bool&);
    static void drawExit();
    static void drawStart();
    static void drawHeader(const String&);
    static void drawFooter(const int&);
    static void drawSubmenu(const String&, const String&, const String&, const String&);
    static void drawMenuElem(const String&, const String&, const int& y);
    static void pressAny(const int&);
    static void gotoxy(const int& x, const int& y);

};