#include <iostream>
#include "httplib.h"
#include "ContactsException.h"
#include "add_contact.pb.h"

using std::cerr;
using std::cout;
using std::endl;

const int PORT = 6330;

int main()
{
    cout << "-----------Server Start----------" << endl;
    httplib::Server svr;

    svr.Post("/contacts/add", [](const httplib::Request &req, const httplib::Response &resp)
    { 
        cout << "接收到Post请求" << endl;
        
        // 1.反序列化req -> req.body
        AddCont::AddContactRequest request;
        AddCont::AddContactResponse response;
        try
        {
            request.ParseFromString(req.body);
        }
        catch (const ContactsException& e)
        {

        }

    });

    svr.listen("0.0.0.0", PORT);

    return 0;
}