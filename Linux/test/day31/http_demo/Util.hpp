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

            std::string sub = s.substr(start, pos - start);
            out->push_back(sub);
            start += sub.size();
            start += sep.size();
        }

        if(start < s.size())
        {
            out->push_back(s.substr(start));
        }
    }
};