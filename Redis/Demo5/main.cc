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

    // 一次添加一个元素
    redis.sadd("key", "111");

    // 一次添加多个元素(使用初始化列表)
    redis.sadd("key", {"222", "333", "444"});

    // 一次添加多个元素(使用迭代器)
    set<string> elems = {"555", "666", "777"};
    redis.sadd("key", elems.begin(), elems.end());

    // 获取到上述元素
    // vector<string> result;
    // auto it = std::back_inserter(result);

    // 此处用来保存 smembers 的结果, 使用 set 可能更合适.
    set<string> result;

    // 由于此处 set 里的元素顺序是固定的. 指定一个 result.end() 或者 result.begin() 或者其他位置的迭代器, 都无所谓
    auto it = std::inserter(result, result.end());
    redis.smembers("key", it);

    PrintContainer(result);
}

void TestSismember(Redis& redis)
{
    redis.flushall();

    redis.sadd("key", {"111", "222", "333", "444"});

    bool result = redis.sismember("key", "555");
    cout << "result: " << result << endl;
}

void TestScard(Redis &redis)
{
    redis.flushall();

    redis.sadd("key", {"111", "222", "333"});
    long long result = redis.scard("key");
    cout << "result: " << result << endl;
}

void TestSpop(Redis& redis)
{
    redis.flushall();

    redis.sadd("key", {"111", "222", "333", "444"});
    auto result = redis.spop("key");
    if (result)
    {
        std::cout << "result: " << result.value() << std::endl;
    }
    else
    {
        std::cout << "result 无效!" << std::endl;
    }
}

void TestSinter(Redis &redis)
{
    redis.flushall();

    redis.sadd("key1", {"111", "222", "333"});
    redis.sadd("key2", {"111", "222", "444"});

    set<string> result;
    auto it = std::inserter(result, result.end());
    redis.sinter({"key1", "key2"}, it);

    PrintContainer(result);
}

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    // TestSaddAndSmembers(redis);
    // TestSismember(redis);
    // TestScard(redis);
    // TestSpop(redis);
    TestSinter(redis);

    return 0;
}