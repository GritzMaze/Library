#pragma once

#include <iostream>
#include "Draw.h"
#include "String.h"
#include <ctype.h>


class InputHandle {

    public:
    static void errMsg(const String&);
    static String inputWithLimit(const size_t&);
    static String inputValue();
};