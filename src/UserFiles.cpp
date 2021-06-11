#include "../include/UserDB.h"

bool toBool(const String &text)
{
    if (text == "true" || text == "1")
        return true;
    else
        return false;
}

void UserDB::save(const String &filename)
{
    //char tmp[256];
    //getcwd(tmp, 256);
    String filenameExt;
    //filenameExt = "\\Database\\";
    filenameExt = filename;
    filenameExt += ".users";
    std::ofstream file;
    file.open(filenameExt.getString(), std::ios::out);
    if (file.fail())
    {
        InputHandle::errMsg("File did not open!");
        return;
    }
    size_t size = users.getSize();
    for (int i = 0; i < size; ++i)
    {
        users[i]->save(file);
        if(i < size-1) file << "\n";
    }
    file.close();
    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Users successfully saved!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void UserDB::open(const String &filename)
{
    String filenameExt = filename;
    filenameExt += ".users";
    if (!doesItExist(filenameExt))
    {
        std::ofstream in(filenameExt.getString());
        in.close();
        return;
    }

    std::ifstream file;
    file.open(filenameExt.getString());

    bool isEmptyFile = file.peek() == std::ifstream::traits_type::eof();
    if (isEmptyFile)
    {
        InputHandle::errMsg("File is empty!");
        file.close();
        return;

    }
    if (!file)
    {
        InputHandle::errMsg("File was not open!");
        file.close();
        return;
    }

    String username, password;
    bool admin;
    char *buffer = new char[1000];

    while (!file.eof())
    {
        User *user = new User;
        file.getline(buffer, 1000, '\n');
        user->setUsername(buffer);
        file.getline(buffer, 1000, '\n');
        user->setPass(buffer);
        file.getline(buffer, 1000, '\n');
        admin = toBool(buffer);
        user->setAdmin(admin);
        users.pushBack(user);
    }
    delete[] buffer;
    file.close();
}