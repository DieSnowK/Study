#include <iostream>
#include <fstream>
#include "contacts.pb.h"
using namespace std;

void AddPeopleInfo(contacts2::PeopleInfo* people)
{
    
}

    int main()
{
    contacts2::Contacts contacts;
    // 读取本地已存在的通讯录文件
    fstream input("contacts.bin", ios::in | ios::binary);
    if(!input)
    {
        cerr << "contacts.bin not found, create new file!" << endl;
    }
    else if(!contacts.ParseFromIstream(&input))
    {
        cerr << "Parse Error!" << endl;
        input.close();
        return -1;
    }

    // 向通讯录中添加一个联系人
    AddPeopleInfo(contacts.add_contacts());

    // 将通讯录写入本地文件中
    fstream output("contacts.bin", ios::out | ios::trunc | ios::binary);
    if(!contacts.SerializeToOstream(&output))
    {
        cerr << "Write Error" << endl;
        input.close();
        output.close();
        return -1;
    }
    cout << "Write Success" << endl;

    return 0;
}