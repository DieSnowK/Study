#include "SUtils.hpp"

const int PORT = 6330;

int main()
{
    cout << "-----------Server Start----------" << endl;
    httplib::Server svr;

    svr.Post("/contacts/add", [](const httplib::Request &req, httplib::Response &resp)
    { 
        cout << "接收到Post请求" << endl;
        
        // 1.反序列化req -> req.body
        AddCont::AddContactRequest request;
        AddCont::AddContactResponse response;
        try
        {
            if (!request.ParseFromString(req.body))
            {
                throw ContactsException("AddContactRequest反序列化失败");
            }

            // 2.新增联系人: 持久化存储通讯录 -> 打印新增的联系人
            PrintContact(request);

            // 3.构造response
            response.set_success(true);
            response.set_uid(GenerateHex(10));

            // 4.序列化response
            std::string response_str;
            if(!response.SerializeToString(&response_str))
            {
                throw ContactsException("AddContactResponse序列化失败");
            }

            // 5.构建resp
            resp.status = 200;
            resp.body = response_str;
            resp.set_header("Content-Type", "application/protobuf");
        }
        catch (const ContactsException& e)
        {
            resp.status = 500;
            response.set_success(false);
            response.set_error_desc(e.What());

            std::string response_str;
            if(response.SerializeToString(&response_str))
            {
                resp.body = response_str;
                resp.set_header("Content-Type", "application/protobuf");
            }

            cout << "/contacts/add 发生异常，异常信息: " << e.What() << endl;
        }

    });

    svr.listen("0.0.0.0", PORT);

    return 0;
}