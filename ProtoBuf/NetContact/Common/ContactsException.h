#include <string>

class ContactsException
{
private:
    std::string msg;
public:
    ContactsException(std::string str = "A Problem")
        : msg(str)
    {}

    std::string What() const
    {
        return msg;
    }
};