#include <bits/stdc++.h>
using namespace std;
/**
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
 * 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 * 
 **/

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> dics;
        for (auto c : str)
        {
            auto it = dics.find(c);
            if(it != dics.end())
                ++dics[c];
            else
                dics[c] = 1;
        }
        for (unsigned i = 0; i < str.size(); ++i)
        {
            auto it = dics.find(str[i]);
            if(it->second == 1)
            {
                return i;
            }
        }
        return -1;
    }
};