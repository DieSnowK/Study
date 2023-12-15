#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <jsoncpp/json/json.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MYSELF

// 1.报文和报文之间，采用特殊字符来进行粘包问题
// 2.获取一个一个完整的报文，序列和反序列化  --  自定义

// 支持解决粘包问题，处理独立报文
#define SEP "X"
#define SEP_LEN strlen(SEP) // 不能是sizeof，不然会计入\0进长度

// 自己手写序列化&&反序列化
#define SPACE " "
#define SPACE_LEN strlen(SPACE)

// 把传入进来的缓冲区进行切分
// 1.buffer中被切走的，同时也要从buffer中移除
// 2.可能会存在多个报文，多个报文依次放入out
void SpliteMessage(std::string &buffer, std::vector<std::string> *out)
{
    while(true)
    {
        auto pos = buffer.find(SEP);
        if(pos == std::string::npos)
        {
            break;
        }

        std::string msg = buffer.substr(0, pos);
        buffer.erase(0, pos + SEP_LEN);
        out->push_back(msg);
    }
}

std::string Encode(std::string &s)
{
    return s + SEP;
}

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