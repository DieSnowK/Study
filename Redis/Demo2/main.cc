#include <iostream>
#include <string>
#include <sw/redis++/redis++.h>
using namespace std;

void TestGetAndSet(sw::redis::Redis& redis)
{
    // 清空数据库，避免之前残留的数据干扰
    redis.flushall();

    // 使用set设置key
    redis.set("key1", "233");
    redis.set("key2", "666");
    redis.set("key3", "888");

    // 使用get获取到key对应的value
    auto value1 = redis.get("key1");

    // optional 可以隐式转成 bool 类型, 可以直接在 if 中判定. 如果是无效元素, 就是返回 false
    if(value1)
    {
        cout << "value1=" << value1.value() << endl; // sw::redis::OptionalString没有重载<<
    }

    auto value2 = redis.get("key2");
    if(value2)
    {
        cout << "value2=" << value2.value() << endl;
    }

    auto value3 = redis.get("key3");
    if (value2)
    {
        cout << "value3=" << value3.value() << endl;
    }

    auto value4 = redis.get("key4");
    if (value4)
    {
        // 如果不加判断，则会在此处抛出异常 std::bad_optional_acess
        cout << "value4=" << value4.value() << endl;
    }
}

void TestExists(sw::redis::Redis &redis)
{
    redis.flushall();

    redis.set("key1", "111");
    redis.set("key3", "111");

    auto ret = redis.exists("key1");
    cout << ret << endl;

    ret = redis.exists("key2");
    cout << ret << endl;

    // exists()的重载形式，可以用一个初始化列表传参
    ret = redis.exists({"key1", "key2", "key3"});
    cout << ret << endl;
}

void TestDel(sw::redis::Redis &redis)
{
    redis.flushall();

    redis.set("key1", "111");
    redis.set("key2", "111");

    // redis.del("key");

    // redis.del()也重载了初始化列表传参的版本
    auto ret = redis.del({"key1", "key2", "key3"});
    cout << ret << endl;

    ret = redis.exists({"key1", "key2"});
    cout << ret << endl;
}

int main()
{
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    // TestGetAndSet(redis);
    // TestExists(redis);
    TestDel(redis);

    return 0;
}