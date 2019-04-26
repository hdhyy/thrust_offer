#include <bits/stdc++.h>
using namespace std;
/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * 
 **/

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        auto d_size = data.size();
        if(d_size < 2)
            return;
        int temp = 0;
        for(auto n : data)
            temp ^= n;
        int index = 0;
        while((temp&1) == 0)
        {
            temp >>= 1;
            ++index;
        }
        for(auto n : data)
        {
            if((n>>index)&1)
                *num1 ^= n;
            else
                *num2 ^= n;
        }
    }
};