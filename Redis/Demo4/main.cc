#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sw/redis++/redis++.h>

#include "utils.hpp"

using namespace std;
using sw::redis::Redis;

void TestPushAndRange(Redis &redis)
{
    redis.flushall();

    // 插入单个元素
    redis.lpush("key", "111");

    // 插入一组元素, 基于初始化列表
    redis.lpush("key", {"222", "333", "444"});

    // 插入一组元素, 基于迭代器
    vector<string> values = {"555", "666", "777"};
    redis.lpush("key", values.begin(), values.end());

    // lrange 获取到列表中的元素
    vector<string> results;
    auto it = std::back_inserter(results);
    redis.lrange("key", 0, -1, it);

    PrintContainer(results);
}

void TestPop(Redis &redis)
{
    redis.flushall();

    // 构造一个 list
    redis.rpush("key", {"1", "2", "3", "4"});

    auto result = redis.lpop("key");
    if (result)
    {
        std::cout << "lpop: " << result.value() << std::endl;
    }

    result = redis.rpop("key");
    if (result)
    {
        std::cout << "rpop: " << result.value() << std::endl;
    }
}

void TestBlpop(Redis &redis)
{
    redis.flushall();

    auto result = redis.blpop({"key", "key2", "key3"}, 10s);

    // 此处可以考虑在其他redis-cli插入数据以便进一步观察效果

    if (result)
    {
        std::cout << "key:" << result->first << std::endl;
        std::cout << "elem:" << result->second << std::endl;
    }
    else
    {
        std::cout << "result 无效!" << std::endl;
    }
}

void TestLlen(Redis &redis)
{
    redis.flushall();

    redis.lpush("key", {"111", "222", "333", "444"});
    long long len = redis.llen("key");
    cout << "len: " << len << endl;
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    // TestPushAndRange(redis);
    // TestPop(redis);
    // TestBlpop(redis);
    TestLlen(redis);
    return 0;
}