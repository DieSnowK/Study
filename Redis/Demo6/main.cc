#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <chrono>
#include <thread>
#include <sw/redis++/redis++.h>

#include "utils.hpp"

using namespace std;
using sw::redis::Redis;

void TestHsetAndHget(Redis &redis)
{
    redis.flushall();

    redis.hset("key", "f1", "111");
    redis.hset("key", std::make_pair("f2", "222"));

    // hset 能够一次性插入多个 field-value 对
    redis.hset("key", {std::make_pair("f3", "333"),
                       std::make_pair("f4", "444")});
                       
    vector<std::pair<string, string>> fields = {
        std::make_pair("f5", "555"),
        std::make_pair("f6", "666")};
    redis.hset("key", fields.begin(), fields.end());

    auto result = redis.hget("key", "f3");
    if (result)
    {
        std::cout << "result: " << result.value() << std::endl;
    }
    else
    {
        std::cout << "result 无效!" << std::endl;
    }
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    TestHsetAndHget(redis);
    return 0;
}