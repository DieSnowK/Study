#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <jsoncpp/json/json.h>
#include <sys/socket.h>
#include <sys/types.h>

// #define MYSELF
#define SPACE " "
#define SPACE_LEN strlen(SPACE)
#define SEP "\r\n"
#define SEP_LEN strlen(SEP) // 不能是sizeof，不然会计入\0进长度
#define SIZE 1024

// 1.尝试自主实现一个协议demo "length\r\n_x _op _y\r\n"
// 2.使用现成方案

class Request
{
public:
    Request()
    {}

    Request(int x, int y, int op)
    : _x(x), _y(y), _op(op)
    {}

    ~Request()
    {}

    // _x _op _y
    std::string Serialize()
    {
#ifdef MYSELF
        std::string str;
        str = std::to_string(_x);
        str += SPACE;
        str += _op;
        str += SPACE;
        str += std::to_string(_y);
        return str;
#else
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["op"] = _op;
        Json::FastWriter writer;
        return writer.write(root);
#endif
    }

    bool DeSerialize(const std::string &str)
    {
#ifdef MYSELF
        size_t left = str.find(SPACE);
        if(left == std::string::npos)
        {
            return false;
        }

        size_t right = str.rfind(SPACE);
        if (right == std::string::npos)
        {
            return false;
        }

        _x = atoi(str.substr(0, left).c_str());
        _y = atoi(str.substr(right + SPACE_LEN).c_str());
        
        if(left + SPACE_LEN < str.size())
        {
            _op = str[left + SPACE_LEN];
            return true;
        }
        else
        {
            return false;
        }
#else
        Json::Value root;
        Json::Reader reader;
        reader.parse(str, root);
        _x = root["x"].asInt();
        _y = root["y"].asInt();
        _op = root["op"].asInt();
        return true;
#endif
    }

public:
    int _x;
    int _y;
    char _op;
};

class Response
{
public:
    Response()
    {}

    Response(int ret, int code)
    : _code(code)
    , _ret(ret)
    {}

    ~Response()
    {}

    // _code _ret
    std::string Serialize()
    {
#ifdef MYSELF
        std::string str = std::to_string(_code);
        str += SPACE;
        str += std::to_string(_ret);
        return str;
#else
        Json::Value root;
        root["code"] = _code;
        root["result"] = _ret;
        Json::FastWriter writer;
        return writer.write(root);
#endif
    }

    bool DeSerialize(std::string &str)
    {
#ifdef MYSELF
        size_t pos = str.find(SPACE);
        if(pos == std::string::npos)
        {
            return false;
        }

        _code = atoi(str.substr(0, pos).c_str());
        _ret = atoi(str.substr(pos + SPACE_LEN).c_str());

        return true;
#else
        Json::Value root;
        Json::Reader reader;
        reader.parse(str, root);
        _code = root["code"].asInt();
        _ret = root["result"].asInt();
        return true;

#endif
    }

public:
    int _ret;  // 计算结果
    int _code; // 计算结果的状态码
};

// TCP面向字节流
// 期望，必须返回一个完整的报文
// Recv无法保证返回的是一个完整的报文
// 需要进一步定制协议
bool Recv(int sock, std::string *out)
{
    char buffer[SIZE];
    ssize_t s = recv(sock, buffer, sizeof buffer - 1, 0);
    if(s > 0)
    {
        buffer[s] = 0;
        *out += buffer;
    }
    else if(s == 0)
    {
        return false;
    }
    else
    {
        return false;
    }

    return true;
}

void Send(int sock, const std::string str)
{
    int n = send(sock, str.c_str(), str.size(), 0);
    if (n < 0)
    {
        std::cout << "send error" << std::endl;
    }
}

// "length\r\n_x _op _y\r\n..."
std::string Decode(std::string &buffer)
{
    size_t pos = buffer.find(SEP);
    if(pos == std::string::npos)
    {
        return "";
    }

    int size = atoi(buffer.substr(0, pos).c_str());
    int surplus = buffer.size() - pos - 2 * SEP_LEN;
    if(surplus >= size)
    {
        // buffer里至少有一个合法且完整的报文，可提取
        buffer.erase(0, pos + SEP_LEN);
        std::string str = buffer.substr(0, size);
        buffer.erase(0, size + SEP_LEN);
        return str;
    }
    else
    {
        return "";
    }
}

std::string Encode(std::string &s)
{
    std::string package = std::to_string(s.size());
    package += SEP;
    package += s;
    package += SEP;
    return package;
}