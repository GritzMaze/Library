#pragma once
#include <iostream>
#include "windows.h"
#include <conio.h>

class Draw {

    public:
    static void drawMenu(const bool&, const bool&);
    static void drawExit();
    static void drawStart();
    static void gotoxy(const int& x, const int& y);

};