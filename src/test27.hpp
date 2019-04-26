#include <bits/stdc++.h>
using namespace std;

/**
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
 * 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 **/

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        auto s_size = str.size();
        set<string> strs;
        vector<string> result;
        if(s_size == 0)
            return result;
        Permutation(strs, str, 0, s_size);
        for(auto s_i : strs)
        {
            result.push_back(s_i);
        }
        return result;
    }

    void Permutation(set<string> &strs, string begin, unsigned start, unsigned len)
    {
        if(start == len)
            strs.insert(begin);
        else
        {
            for (auto i = start; i < len; ++i)
            {
                char temp = begin[i];
                begin[i] = begin[start];
                begin[start] = temp;
                Permutation(strs, begin, start + 1, len);
            }
        }
        
    }
};