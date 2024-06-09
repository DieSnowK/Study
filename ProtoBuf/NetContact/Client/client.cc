#include <iostream>
#include <string>
#include "httplib.h"
#include "add_contact.pb.h"
#include "ContactsException.h"

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
    httplib::Client client(IP, PORT);
    
    // 1.构造req

    // 2.序列化req

    // 3.发起Post调用

    // 4.反序列化 resp

    // 5.结果打印
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

        try
        {
            switch (choice)
            {
            case OPTION::QUIT:
                cout << "Process Quit :P" << endl;
                break;
            case OPTION::ADD:
                AddContact();
            case OPTION::DEL:
                break;
            case OPTION::FIND_ALL:
                break;
            case OPTION::FIND_ONE:
                break;
            default:
                cout << "选择错误，请重新选择:)" << endl;
                break;
            }
        }
        catch(const ContactsException& e)
        {
            cout << "操作通讯录时发生异常" << endl
                 << "异常信息: " << e.What() << endl;
        }
    }
}
