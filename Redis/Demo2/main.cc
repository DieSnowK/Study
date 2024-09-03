#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sw/redis++/redis++.h>

#include "utils.hpp"

using namespace std;

void TestGetAndSet(sw::redis::Redis& redis)
{
    // ������ݿ⣬����֮ǰ���������ݸ���
    redis.flushall();

    // ʹ��set����key
    redis.set("key1", "233");
    redis.set("key2", "666");
    redis.set("key3", "888");

    // ʹ��get��ȡ��key��Ӧ��value
    auto value1 = redis.get("key1");

    // optional ������ʽת�� bool ����, ����ֱ���� if ���ж�. �������ЧԪ��, ���Ƿ��� false
    if(value1)
    {
        cout << "value1=" << value1.value() << endl; // sw::redis::OptionalStringû������<<
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
        // ��������жϣ�����ڴ˴��׳��쳣 std::bad_optional_acess
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

    // exists()��������ʽ��������һ����ʼ���б���
    ret = redis.exists({"key1", "key2", "key3"});
    cout << ret << endl;
}

void TestDel(sw::redis::Redis &redis)
{
    redis.flushall();

    redis.set("key1", "111");
    redis.set("key2", "111");

    // redis.del("key");

    // redis.del()Ҳ�����˳�ʼ���б��εİ汾
    auto ret = redis.del({"key1", "key2", "key3"});
    cout << ret << endl;

    ret = redis.exists({"key1", "key2"});
    cout << ret << endl;
}

void TestKeys(sw::redis::Redis &redis)
{
    redis.flushall();

    redis.set("key1", "111");
    redis.set("key2", "222");
    redis.set("key3", "333");
    redis.set("key4", "444");
    redis.set("key5", "555");
    redis.set("key6", "666");

    // keys �ĵڶ�������, ��һ�� "���������". ��Ҫ��׼����һ��������������.
    // �������ٴ���һ�����������ָ��������λ��. �Ϳ��԰� keys ��ȡ���Ľ������ͨ���ղŵĲ�����������뵽������ָ��λ������.
    // ��������� -> λ�� + ����
    vector<string> ret;
    auto it = std::back_inserter(ret);
    redis.keys("*", it);
    PrintContainer(ret);
}

void TestExpireAndTTL(sw::redis::Redis &redis)
{
    redis.flushall();

    redis.set("key", "111");
    // 10s -> std::chrono::seconds(10);
    redis.expire("key", 10s);

    std::this_thread::sleep_for(3s);

    auto time = redis.ttl("key");
    cout << time << endl;
}

void TestType(sw::redis::Redis& redis)
{
    redis.flushall();

    redis.set("key1", "111");
    string result = redis.type("key");
    cout << "key1: " << result << endl;

    redis.lpush("key2", "111");
    result = redis.type("key2");
    cout << "key2: " << result << endl;

    redis.hset("key3", "aaa", "111");
    result = redis.type("key3");
    cout << "key3: " << result << endl;

    redis.sadd("key4", "aaa");
    result = redis.type("key4");
    cout << "key4: " << result << endl;

    redis.zadd("key5", "����", 99);
    result = redis.type("key5");
    cout << "key5: " << result << endl;
}

int main()
{
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    // TestGetAndSet(redis);
    // TestExists(redis);
    // TestDel(redis);
    // TestKeys(redis);
    // TestExpireAndTTL(redis);
    TestType(redis);

    return 0;
}