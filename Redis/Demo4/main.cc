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

    // ���뵥��Ԫ��
    redis.lpush("key", "111");

    // ����һ��Ԫ��, ���ڳ�ʼ���б�
    redis.lpush("key", {"222", "333", "444"});

    // ����һ��Ԫ��, ���ڵ�����
    vector<string> values = {"555", "666", "777"};
    redis.lpush("key", values.begin(), values.end());

    // lrange ��ȡ���б��е�Ԫ��
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