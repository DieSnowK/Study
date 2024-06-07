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

        cout << "请输入该电话类型(1.移动电话  2.固定电话)" << endl;
        int type = 0;
        cin >> type;
        cin.ignore(256, '\n');
        switch(type)
        {
        case 1:
            phone->set_type(contacts2::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MP);
            break;
        case 2:
            phone->set_type(contacts2::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TEL);
            break;
        default:
            cout << "选择有误! (默认为MP)" << endl;
            break;
        }
    }

    contacts2::Address address;
    cout << "请输入家庭地址:>" << endl;
    string home_address;
    getline(cin, home_address);
    address.set_home_address(home_address);
    cout << "请输入单位地址:>" << endl;
    string unit_address;
    getline(cin, unit_address);
    address.set_unit_address(unit_address);
    // Address -> Any
    people->mutable_data()->PackFrom(address);

    cout << "请选择要添加的其他联系方式(1.QQ  2.VX):>" << endl;
    int other_contact = 0;
    cin >> other_contact;
    cin.ignore(256, '\n');
    if (other_contact == 1)
    {
        cout << "请输入联系人的QQ号:>" << endl;
        string qq;
        getline(cin, qq);
        people->set_qq(qq);
    }
    else if(other_contact == 2)
    {
        cout << "请输入联系人的VX号:>" << endl;
        string vx;
        getline(cin, vx);
        people->set_wechat(vx);
    }
    else
    {
        cout << "选择有误，未成功设置其他联系方式" << endl;
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