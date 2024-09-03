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

    // set �����ذ汾��, û�е����ṩ NX �� XX �İ汾, ����������ʱ��İ汾��ʹ��
    // ����ʱ����0s��Ϊ��������
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