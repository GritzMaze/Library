#pragma once
#include "Draw.h"
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
            Vector<User> users;

            void choice();
            void mainmenu();
            void login();
            void close();

        public:
            Commands();
            void start();
    };