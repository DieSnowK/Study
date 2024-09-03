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



int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    TestPushAndRange(redis);
    return 0;
}