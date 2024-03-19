#pragma once
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
        : _capacity(capacity)
    {}

    int get(int key)
    {
        auto ret = _hashMap.find(key);
        if (ret != _hashMap.end())
        {
            LtIter it = ret->second;

            // 更新key对应值的位置，splice转移结点
            _LRUList.splice(_LRUList.begin(), _LRUList, it);

            return it->second;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {

        auto ret = _hashMap.find(key);
        if (ret == _hashMap.end()) // 1.新增
        {
            if (_hashMap.size() == _capacity)
            {
                // 若满，则先删除LRU的数据
                pair<int, int> back = _LRUList.back();
                _hashMap.erase(back.first);
                _LRUList.pop_back();
            }

            _LRUList.push_front({ key, value });
            _hashMap[key] = _LRUList.begin();
        }
        else // 2.更新
        {
            LtIter it = ret->second;
            it->second = value; // 更新

            // 更新key对应值的位置，splice转移结点
            _LRUList.splice(_LRUList.begin(), _LRUList, it);
        }
    }
private:
    typedef list<pair<int, int>>::iterator LtIter;

    // hash做到查找更新是O(1)，value值存的是list的iterator
    unordered_map<int, LtIter> _hashMap;

    // LRU，假设尾部数据就是最近最少用
    list<pair<int, int>> _LRUList;
    size_t _capacity;
};