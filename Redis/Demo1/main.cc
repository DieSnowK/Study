#include <iostream>
#include <string>
#include <sw/redis++/redis++.h>
using namespace std;

int main()
{
    // ����Redis�����ʱ���ڹ��캯���У�ָ��Redis�������ĵ�ַ�Ͷ˿�
    sw::redis::Redis redis("tcp://127.0.0.1:6379");
    string ret = redis.ping();
    cout << ret << endl;
    return 0;
}