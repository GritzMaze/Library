#pragma once
#include <iostream>
#include "Vector.h"
#include "String.h"
#include "windows.h"
#include <conio.h>
#include "User.h"

    class Commands
    {

        private:
            User currentUser;
            bool isLogged;

            void choice();

        public:
            Commands();
            void start();
            void mainmenu();
            void login();
            void close();
    };