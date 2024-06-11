#include "CUtil.hpp"

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
                return 0;
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

    return 0;
}
