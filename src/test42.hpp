#include <bits/stdc++.h>
using namespace std;
/**
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
 * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 
 **/
/**
 * 对应每个测试案例，输出两个数，小的先输出。
 **/
class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> result;
        if(array.size() < 2)
            return result;
        auto ib = array.begin(), ie = array.end() - 1;
        while(ib != ie && *ib+*ie != sum)
        {
            if (*ib + *ie > sum)
                --ie;
            else
                ++ib;
        }
        if (ib != ie)
        {
            result.push_back(*ib);
            result.push_back(*ie);
        }
        return result;
    }
};