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

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    // TestSetWithExpire(redis);
    TestSetNXAndXX(redis);
    return 0;
}