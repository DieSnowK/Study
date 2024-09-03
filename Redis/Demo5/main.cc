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

void TestSaddAndSmembers(Redis& redis)
{
    redis.flushall();

    // һ�����һ��Ԫ��
    redis.sadd("key", "111");

    // һ����Ӷ��Ԫ��(ʹ�ó�ʼ���б�)
    redis.sadd("key", {"222", "333", "444"});

    // һ����Ӷ��Ԫ��(ʹ�õ�����)
    set<string> elems = {"555", "666", "777"};
    redis.sadd("key", elems.begin(), elems.end());

    // ��ȡ������Ԫ��
    // vector<string> result;
    // auto it = std::back_inserter(result);

    // �˴��������� smembers �Ľ��, ʹ�� set ���ܸ�����.
    set<string> result;

    // ���ڴ˴� set ���Ԫ��˳���ǹ̶���. ָ��һ�� result.end() ���� result.begin() ��������λ�õĵ�����, ������ν
    auto it = std::inserter(result, result.end());
    redis.smembers("key", it);

    PrintContainer(result);
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    TestSaddAndSmembers(redis);
    return 0;
}