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

void TestZaddAndZrange(Redis &redis)
{
    redis.flushall();

    redis.zadd("key", "ÂÀ²¼", 99);
    redis.zadd("key", {std::make_pair("ÕÔÔÆ", 98),
                       std::make_pair("µäÎ¤", 97)});

    vector<std::pair<string, double>> members = {
        std::make_pair("¹ØÓğ", 95),
        std::make_pair("ÕÅ·É", 93)};
    redis.zadd("key", members.begin(), members.end());

    vector<string> memberResults;
    auto it = std::back_inserter(memberResults);
    redis.zrange("key", 0, -1, it);
    PrintContainer(memberResults);

    vector<std::pair<string, double>> membersWithScore;
    auto it2 = std::back_inserter(membersWithScore);
    redis.zrange("key", 0, -1, it2);
    PrintContainerPair(membersWithScore);
}

void TestZcard(Redis &redis)
{
    redis.flushall();

    redis.zadd("key", "zhangsan", 90);
    redis.zadd("key", "lisi", 91);
    redis.zadd("key", "wangwu", 92);
    redis.zadd("key", "zhaoliu", 93);

    long long result = redis.zcard("key");
    std::cout << "result: " << result << std::endl;
}

void TestZrem(Redis &redis)
{
    redis.flushall();

    redis.zadd("key", "zhangsan", 90);
    redis.zadd("key", "lisi", 91);
    redis.zadd("key", "wangwu", 92);
    redis.zadd("key", "zhaoliu", 93);

    redis.zrem("key", "zhangsan");

    long long result = redis.zcard("key");
    std::cout << "result: " << result << std::endl;
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    // TestZaddAndZrange(redis);
    // TestZcard(redis);
    TestZrem(redis);
   
    return 0;
}