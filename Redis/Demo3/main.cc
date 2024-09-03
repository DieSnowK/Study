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

void TestMset(Redis &redis)
{
    redis.flushall();

    // ��һ��д��, ʹ�ó�ʼ���б����������ֵ��
    // redis.mset({ std::make_pair("key1", "111"), std::make_pair("key2", "222"), std::make_pair("key3", "333") });

    // �ڶ���д��, ���԰Ѷ����ֵ����ǰ��֯��������. �Ե���������ʽ���� mset
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