#include <bits/stdc++.h>
using namespace std;
/**
 * 汇编语言中有一种移位指令叫做循环左移（ROL），
 * 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
 * 即“XYZdefabc”。是不是很简单？OK，搞定它！
 **/
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if(str.empty())
            return str;
        auto s_size = str.size();
        n %= s_size;
        if(n < 0)
            n += s_size;
        int fs = 0;
        int fe = n - 1;
        int ss = n;
        int se = s_size - 1;
        Reverse(str, fs, fe);
        Reverse(str, ss, se);
        Reverse(str, 0, se);
        return str;
    }

    void Reverse(string &str, int start, int end)
    {
        if(str.empty() || start < 0 || end > str.size()-1)
            return;
        while(start < end)
        {
            char tmp = str[end];
            str[end] = str[start];
            str[start] = tmp;

            start++;
            end--;
        }
    }
};