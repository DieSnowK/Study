#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <unistd.h>
#include <sys/types.h>

typedef std::function<void()> func; // 包装器，给出统一函数形式

std::vector<func> callbacks;
std::unordered_map<int, std::string> desc;

void readMySQL()
{
    std::cout << "sub process[" << getpid() << "] 执行访问数据库的任务\n"
              << std::endl;
}

void execuleUrl()
{
    std::cout << "sub process[" << getpid() << "] 执行url解析\n"
              << std::endl;
}

void cal()
{
    std::cout << "sub process[" << getpid() << "] 执行加密任务\n"
              << std::endl;
}

void save()
{
    std::cout << "sub process[" << getpid() << "] 执行数据持久化任务\n"
              << std::endl;
}

void load()
{
    desc.insert({callbacks.size(), "readMySQL：读取数据库"}); // 统一的列表初始化
    callbacks.push_back(readMySQL);

    desc.insert({callbacks.size(), "execuleUrl：进行url解析"});
    callbacks.push_back(execuleUrl);

    desc.insert({callbacks.size(), "execuleUrl：执行加密任务"});
    callbacks.push_back(cal);

    desc.insert({callbacks.size(), "execuleUrl：执行数据持久化任务"});
    callbacks.push_back(save);
}

void showHandler()
{
    for(const auto &iter : desc)
    {
        std::cout << iter.first << "\t" << iter.second << std::endl;
    }
}

int handlerSize()
{
    return callbacks.size();
}