#include <bits/stdc++.h>
using namespace std;
/**
 * 统计一个数字在排序数组中出现的次数。
 * 
 **/

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        auto start = lower_bound(data.begin(), data.end(), k);
        auto end = upper_bound(data.begin(), data.end(), k);
        return end - start + (end == data.end() - 1 ? 1 : 0);
    }
};