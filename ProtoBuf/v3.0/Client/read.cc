#include <iostream>
#include <fstream>
#include "contacts.pb.h"
using namespace std;

void PrintContacts(c_contacts3::Contacts& contacts)
{
    for (int i = 0; i < contacts.contacts_size(); i++)
    {
        const c_contacts3::PeopleInfo& people = contacts.contacts(i);
        cout << "联系人姓名: " << people.name() << endl;
        cout << "联系人年龄: " << people.age() << endl;

        for (int j = 0; j < people.phone_size(); j++)
        {
            const ::c_contacts3::PeopleInfo_Phone& phone = people.phone(j);
            cout << "联系人电话" << i + 1 << ":" << phone.number() << endl;
        }

        // 获取未知字段
        const google::protobuf::Reflection* reflection = c_contacts3::PeopleInfo::GetReflection();
        const google::protobuf::UnknownFieldSet& set = reflection->GetUnknownFields(people);
        for (int j = 0; j < set.field_count(); j++)
        {
            const google::protobuf::UnknownField& unknown_field = set.field(j);
            cout << "未知字段" << j + 1 << ": 编号" << unknown_field.number();
            switch(unknown_field.type())
            {
            case google::protobuf::UnknownField::Type::TYPE_VARINT:
                cout << " 值" << unknown_field.varint() << endl;
                break;
            case google::protobuf::UnknownField::Type::TYPE_LENGTH_DELIMITED:
                cout << " 值" << unknown_field.length_delimited() << endl;
                break;
            // case ... 其余类型相同，不一一列举
            }
        }

        cout << endl;
    }
}

int main()
{
    c_contacts3::Contacts contacts;
    // 读取本地已经存在的通讯录文件
    fstream input("contacts.bin", ios::in | ios::binary);
    if (!input)
    {
        cerr << "contacts.bin not found, create new file!" << endl;
    }
    else if (!contacts.ParseFromIstream(&input))
    {
        cerr << "Parse Error!" << endl;
        input.close();
        return -1;
    }

    // 打印通讯录列表
    PrintContacts(contacts);
    input.close();

    return 0;
}