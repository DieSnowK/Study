#include <iostream>
#include <string>
#include "contacts.pb.h"

int main()
{
    std::string people_str;
    {
        contacts::PeopleInfo people;
        people.set_name("SnowK");
        people.set_age(18);
        if(!people.SerializeToString(&people_str))
        {
            std::cerr << "序列化联系人失败" << std::endl;
            return -1;
        }
        std::cout << "序列化成功，结果: " << people_str << std::endl;
    }
    
    {
        contacts::PeopleInfo people;
        if(!people.ParseFromString(people_str))
        {
            std::cerr << "反序列化联系人失败" << std::endl;
            return -1;
        }
        std::cout << "反序列化成功" << std::endl
                  << "姓名:" << people.name() << std::endl
                  << "年龄:" << people.age() << std::endl;
    }
    
    return 0;
}