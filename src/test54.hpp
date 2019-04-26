#include <bits/stdc++.h>
using namespace std;
/**
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 
 * 如果当前字符流没有存在出现一次的字符，返回#字符。
 **/

class Solution
{
private:
    int index = 0;
    map<char, int> dics;

public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        ++index;
        auto it = dics.find(ch);
        if(it != dics.end())
            dics[ch] = -2;
        else
            dics[ch] = index - 1;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int index = -1;
        char result;
        for (auto it = dics.begin(); it != dics.end();++it)
        {
            if(it->second != -2)
            {
                if (index == -1 || it->second < index)
                {
                    index = it->second;
                    result = it->first;
                }  
            }
        }
        if(index == -1)
            return '#';
        else
            return result;
    }
};