///////////////////////////////////////////////////////////////////////////////////
// V1.0
///////////////////////////////////////////////////////////////////////////////////
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

    int Get(int key)
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

    void Put(int key, int value)
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

///////////////////////////////////////////////////////////////////////////////////
// V2.0
///////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <utility> // pair<> && move()
#include <stdexcept>

template <typename K, typename V>
class LRUCache
{
public:
    explicit LRUCache(size_t capacity) 
        : cap_(capacity)
    {
        if (cap_ == 0)
        {
            throw std::invalid_argument("capacity must be > 0")
        }
    }

    // 命中返回 true, 并把 value 写入 out; 同时将节点移动到表头
    bool Get(const K& key, V& out)
    {
        auto it = index_.find(key);
        if (it == index_.end())
        {
            return false;
        }
        
        items_.splice(items_.begin(), items_, it->second);  // O(1) move to front
        out = it->second->second;
        return true;
    }

    // 插入或更新: 存在则更新并挪到表头; 不存在则可能淘汰尾部后头插
    void Put(const K& key, V value)
    {
        auto it = index_.find(key);
        if (it != index_.end())
        {
            it->second->second = std::move(value);
            items_.splice(items_.begin(), items_, it->second);
            return;
        }

        if (items_.size() == cap_)
        {
            auto& old = items_.back();
            index_.erase(old.first);
            items_.pop_back();
        }

        items_.emplace_front(key, std::move(value));
        index_[items_.front().first] = items_.begin();
    }

    void Erase(const K& key)
    {
        auto it = index_.find(key);
        if (it == index_.end())
        {
            return;
        }
        
        items_.erase(it->second);
        index_.erase(it);
    }

    void Clear()
    {
        items_.clear();
        index_.clear();
    }

    size_t Size() const
    {
        return items_.size();
    }

    size_t Capacity() const
    {
        return cap_;
    }

    // 调整容量(若变小则立即淘汰多余元素)
    void Resize(size_t newcap)
    {
        if (newcap == 0)
        {
            throw std::invalid_argument("newcap must be > 0");
        }
        
        cap_ = newcap;
        while (items_.size() > cap_)
        {
            auto& old = items_.back();
            index_.erase(old.first);
            items_.pop_back();
        }
    }

    // 仅用于演示打印当前从新到旧的顺序
    void DebugPrint() const
    {
        std::cout << "[MRU→LRU] ";
        for (auto it = items_.begin(); it != items_.end(); ++it)
        {
            std::cout << "(" << it->first << ":" << it->second << ") ";
        }
        std::cout << std::endl;
    }

private:
    size_t cap_;
    std::list<std::pair<K, V>> items_;
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> index_;
};