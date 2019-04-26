#include <bits/stdc++.h>
using namespace std;

/**
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 **/
class Solution
{
public:
    int Add(int left, int right)
    {
        int in = 1;
        while(in)
        {
            in = (left & right) << 1;
            left ^= right;
            right = in;
        }
        return left;
    }
};