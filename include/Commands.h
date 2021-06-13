#pragma once
#include "Draw.h"
#include "Vector.h"
#include "String.h"
#include <windows.h>
#include <conio.h>
#include "Database.h"
#include "UserDB.h"
#include "BookDB.h"

class Commands
{

private:
    bool isAdmin;
    bool isLogged;
    UserDB users;
    BookDB books;

    void choice();
    void admin_choice();
    void mainmenu();
    void login();
    void close();
    void addBooks();
    void viewBooks();
    void deleteBooks();
    void searchBooks();
    void sortBooks();
    void adminPanel();
    void openDB();
    void saveDB();

public:
    Commands();
    void start();
};