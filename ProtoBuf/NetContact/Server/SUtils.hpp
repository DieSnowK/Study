#include <iostream>
#include "httplib.h"
#include "ContactsException.h"
#include "add_contact.pb.h"

using std::cerr;
using std::cout;
using std::endl;

void PrintContact(const AddCont::AddContactRequest &req)
{
    cout << "联系人姓名: " << req.name() << endl;
    cout << "联系人年龄: " << req.age() << endl;
    for (int i = 0; i < req.phone_size(); i++)
    {
        const AddCont::AddContactRequest_Phone &phone = req.phone(i);
        cout << "联系人电话" << i + 1 << ": " << phone.number()
             << "(" << phone.PhoneType_Name(phone.type()) << ")" << endl;
    }
}

static unsigned int RandomChar()
{
    // ⽤于随机数引擎获得随机种⼦
    std::random_device rd;

    // mt19937是C++11新特性，它是⼀种随机数算法，⽤法与rand()函数类似，但是mt19937具有速度快，周期⻓的特点
    // 作⽤是⽣成伪随机数
    std::mt19937 gen(rd());

    // 随机⽣成⼀个整数i 范围[0, 255]
    std::uniform_int_distribution<> dis(0, 255);

    return dis(gen);
}

// ⽣成 UUID(通⽤唯⼀标识符)
static std::string GenerateHex(const unsigned int len)
{
    std::stringstream ss;

    // ⽣成 len 个16进制随机数，将其拼接⽽成
    for (int i = 0; i < len; i++)
    {
        const auto rc = RandomChar();
        std::stringstream hexStream;
        hexStream << std::hex << rc;
        auto hex = hexStream.str();
        ss << (hex.length() < 2 ? '0' + hex : hex);
    }

    return ss.str();
}