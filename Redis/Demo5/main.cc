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

int main()
{
    Redis redis("tcp://127.0.0.1:6379");
    TestSaddAndSmembers(redis);
    return 0;
}