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
         << "------------------ 1、新增联系⼈ --------------------" << endl
         << "------------------ 2、删除联系⼈ --------------------" << endl
         << "------------------ 3、查看联系⼈列表 ----------------" << endl
         << "------------------ 4、查看联系⼈详细信息 ------------" << endl
         << "------------------ 0、退出 --------------------------" << endl
         << "-----------------------------------------------------" << endl;
}

void BuildAddContactRequest(AddCont::AddContactRequest &req)
{
    cout << "请输入联系人姓名:>";
    std::string name;
    getline(cin, name);
    req.set_name(name);

    cout << "请输入联系人年龄:>";
    int age = 0;
    cin >> age;
    cin.ignore(256, '\n');
    req.set_age(age);

    for (int i = 0;; i++)
    {
        cout << "请输入联系人电话" << i + 1 << "(只输入回车完成电话新增):>";
        std::string number;
        getline(cin, number);
        if (number.empty())
        {
            break;
        }

        AddCont::AddContactRequest_Phone *phone = req.add_phone();
        phone->set_number(number);

        cout << "请输入该电话类型(1.移动电话  2.固定电话):> ";
        int type = 0;
        cin >> type;
        cin.ignore(256, '\n');
        switch (type)
        {
        case 1:
            phone->set_type(AddCont::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_MP);
            break;
        case 2:
            phone->set_type(AddCont::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_TEL);
            break;
        default:
            cout << "选择有误，默认为[移动电话]" << endl;
            break;
        }
    }

    cout << "Done" << endl
         << endl;
}

void AddContact()
{
    httplib::Client client(IP, PORT);

    // 1.构造req
    AddCont::AddContactRequest req;
    BuildAddContactRequest(req);

    // 2.序列化req
    std::string reqStr;
    if (!req.SerializeToString(&reqStr))
    {
        throw ContactsException("AddContactRequest序列化失败!");
    }

    // 3.发起Post调用
    auto ret = client.Post("/contacts/add", reqStr, "application/protobuf");
    if (!ret)
    {
        std::string errDesc;
        errDesc.append("/contacts/add 链接失败! 错误信息: ")
            .append(httplib::to_string(ret.error()));
        throw ContactsException(errDesc);
    }

    // 4.反序列化 resp
    AddCont::AddContactResponse resp;
    bool parse = resp.ParseFromString(ret->body);

    // 差错处理
    if (ret->status != 200 && !parse)
    {
        std::string errDesc;
        errDesc.append("/contacts/add 调用失败")
            .append(std::to_string(ret->status))
            .append("(")
            .append(ret->reason)
            .append(")");
        throw ContactsException(errDesc);
    }
    else if (ret->status != 200)
    {
        std::string errDesc;
        errDesc.append("/contacts/add 调用失败")
            .append(std::to_string(ret->status))
            .append("(")
            .append(ret->reason)
            .append(") 错误原因: ")
            .append(resp.error_desc());
        throw ContactsException(errDesc);
    }
    else if (!resp.success())
    {
        std::string errDesc;
        errDesc.append("/contacts/add 结果异常")
            .append("异常原因: ")
            .append(resp.error_desc());
        throw ContactsException(errDesc);
    }

    // 5.结果打印
    cout << "新增联系人成功, 联系人ID: " << resp.uid() << endl;
}