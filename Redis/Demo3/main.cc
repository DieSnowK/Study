#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sw/redis++/redis++.h>

#include "utils.hpp"

using namespace std;
using sw::redis::Redis;

// Test String Commands

void TestSetWithExpire(Redis& redis)
{
    redis.flushall();

    redis.set("key", "111", 10s);

    std::this_thread::sleep_for(3s);

    long long time = redis.ttl("key");
    std::cout << "time: " << time << std::endl;
}

void TestSetNXAndXX(Redis &redis)
{
    redis.flushall();

    redis.set("key", "111");

    // set 的重载版本中, 没有单独提供 NX 和 XX 的版本, 必须搭配过期时间的版本来使用
    // 过期时间填0s则为永不过期
    redis.set("key", "222", 0s, sw::redis::UpdateType::EXIST);

    auto value = redis.get("key");
    if (value)
    {
        std::cout << "value: " << value.value() << std::endl;
    }
}

void TestMset(Redis &redis)
{
    redis.flushall();

    // 第一种写法, 使用初始化列表描述多个键值对
    // redis.mset({ std::make_pair("key1", "111"), std::make_pair("key2", "222"), std::make_pair("key3", "333") });

    // 第二种写法, 可以把多个键值对提前组织到容器中. 以迭代器的形式告诉 mset
    vector<pair<string, string>> keys = {
        {"key1", "111"},
        {"key2", "222"},
        {"key3", "333"}
    };
    redis.mset(keys.begin(), keys.end());

    auto value = redis.get("key1");
    if (value)
    {
        std::cout << "value: " << value.value() << std::endl;
    }

    value = redis.get("key2");
    if (value)
    {
        std::cout << "value: " << value.value() << std::endl;
    }

    value = redis.get("key3");
    if (value)
    {
        std::cout << "value: " << value.value() << std::endl;
    }
}

void TestMget(Redis &redis)
{
    redis.flushall();

    vector<std::pair<string, string>> keys = {
        {"key1", "111"},
        {"key2", "222"},
        {"key3", "333"}};
    redis.mset(keys.begin(), keys.end());

    vector<sw::redis::OptionalString> result;
    auto it = std::back_inserter(result);
    redis.mget({"key1", "key2", "key3", "key4"}, it);

    PrintContainerOptional(result);
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    // TestSetWithExpire(redis);
    // TestSetNXAndXX(redis);
    // TestMset(redis);
    TestMget(redis);

    return 0;
}