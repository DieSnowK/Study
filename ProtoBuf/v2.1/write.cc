#include <iostream>
#include <fstream>
#include "contacts.pb.h"

using namespace std;

void AddPeopleInfo(contacts2::PeopleInfo* people)
{
    cout << "----------------新增联系人----------------" << endl;
    cout << "请输入联系人姓名:>" << endl;
    string name;
    getline(cin, name);
    people->set_name(name);

    cout << "请输入联系人年龄" << endl;
    int age = 0;
    cin >> age;
    people->set_age(age);

    cin.ignore(256, '\n'); // 清空输入缓冲区直到256字符或者遇到'\n'

    for (int i = 0; ; i++)
    {
        cout << "请输入联系人电话" << i + 1 << ":>(只输入回车结束电话新增)" << endl;
        string tele;
        getline(cin, tele);
        if(tele.empty())
        {
            break;
        }

        contacts2::PeopleInfo_Phone* phone = people->add_phone();
        phone->set_number(tele);
    }

    cout << "----------------新增联系人成功----------------" << endl;
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
    input.close();
    output.close();

    return 0;
}