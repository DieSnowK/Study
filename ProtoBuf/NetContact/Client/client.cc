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
         << "--------------- ��ѡ���ͨѶ¼�Ĳ��� ----------------" << endl
         << "------------------ 1��������ϵ? --------------------" << endl
         << "------------------ 2��ɾ����ϵ? --------------------" << endl
         << "------------------ 3���鿴��ϵ?�б� ----------------" << endl
         << "------------------ 4���鿴��ϵ?��ϸ��Ϣ ------------" << endl
         << "------------------ 0���˳� --------------------------" << endl
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
        cout << "��ѡ��:>";
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
