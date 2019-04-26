#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * 
 **/
class Solution
{
public:
    int NumberOf1(int n)
    {
        bitset<sizeof(n)*8> bit_n(n);
        return bit_n.count();
    }
};