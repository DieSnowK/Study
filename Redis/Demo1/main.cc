#include <iostream>
#include <string>
#include <sw/redis++/redis++.h>
using namespace std;

int main()
{
    // 构建Redis对象的时候，在构造函数中，指定Redis服务器的地址和端口
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    string ret = redis.ping();
    cout << ret << endl;
    return 0;
}