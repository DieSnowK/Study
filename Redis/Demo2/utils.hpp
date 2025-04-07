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
        // �˴�Ԥ�� elem ��һ�� std::pair
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}

template <typename T>
inline void PrintContainerOptional(const T &container)
{
    for (const auto &elem : container)
    {
        // �˴�Ԥ�� elem ��һ�� optional ���͵�Ԫ��, ��ӡ֮ǰ, ���ж�һ��, ���Ƿ���Ч
        if (elem)
        {
            std::cout << elem.value() << std::endl;
        }
        else
        {
            std::cout << "Ԫ����Ч" << std::endl;
        }
    }
}