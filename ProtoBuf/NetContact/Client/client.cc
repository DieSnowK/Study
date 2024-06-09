#include <iostream>
#include <string>
#include "httplib.h"
#include "add_contact.pb.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

const std::string IP = "127.0.0.1";
const int PORT = 6330;

void Menu()
{
    cout << "-----------------------------------------------------" << endl
         << "--------------- 请选择对通讯录的操作 ----------------" << endl
         << "------------------ 1、新增联系? --------------------" << endl
         << "------------------ 2、删除联系? --------------------" << endl
         << "------------------ 3、查看联系?列表 ----------------" << endl
         << "------------------ 4、查看联系?详细信息 ------------" << endl
         << "------------------ 0、退出 --------------------------" << endl
         << "-----------------------------------------------------" << endl;
}

void AddContact()
{
    
}

int main()
{
    enum OPTION
    {
        QUIT,
        ADD,
        DEL,
        FIND_ALL,
        FIND_ONE
    };

    while (1)
    {
        Menu();
        cout << "请选择:>";
        int choice = 0;
        cin >> choice;
        cin.ignore(256, '\n');

        switch(choice)
        {
        case OPTION::QUIT:
            cout << "Process Quit :P" << endl;
            break;
        case OPTION::ADD:
            AddContact();
        }
    }
}
