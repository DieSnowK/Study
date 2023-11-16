#pragma once

#include <iostream>
#include <string>
#include <vector>

class Util
{
public:
    static void CutString(std::string s, const std::string &sep, std::vector<std::string> *out)
    {
        size_t start = 0;
        while(start < s.size())
        {
            auto pos = s.find(sep, start);
            if(pos == std::string::npos)
            {
                break;
            }


        }
    }
};