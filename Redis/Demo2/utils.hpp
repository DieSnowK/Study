#pragma once

#include <iostream>
#include <vector>
#include <string>

template <typename T>
inline void PrintContainer(const T &container)
{
    for (const auto &elem : container)
    {
        std::cout << elem << std::endl;
    }
}

template <typename T>
inline void PrintContainerPair(const T &container)
{
    for (auto &elem : container)
    {
        // 此处预期 elem 是一个 std::pair
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}

template <typename T>
inline void PrintContainerOptional(const T &container)
{
    for (const auto &elem : container)
    {
        // 此处预期 elem 是一个 optional 类型的元素, 打印之前, 先判定一下, 看是否有效
        if (elem)
        {
            std::cout << elem.value() << std::endl;
        }
        else
        {
            std::cout << "元素无效" << std::endl;
        }
    }
}