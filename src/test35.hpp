#include <bits/stdc++.h>
using namespace std;
/**
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，
 * 则这两个数字组成一个逆序对。输入一个数组,
 * 求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
 * 
 **/
/**
 * 输入描述
 * 题目保证输入的数组中没有的相同的数字
 * 数据范围：
 * 对于%50的数据,size<=10^4
 * 对于%75的数据,size<=10^5
 * 对于%100的数据,size<=2*10^5
 * 
 * 输入
 * 1,2,3,4,5,6,7,0
 * 输出
 * 7
 **/

class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        if(data.empty())
            return 0;
        int count = mergeCount(data, 0, data.size() - 1);
        return count;
    }
    static long mergeCount(vector<int> &data, int start, int end)
    {
        if(start >= end)
            return 0;
        int mid = (start + end) >> 1;
        long left_c = mergeCount(data, start, mid);
        long right_c = mergeCount(data, mid + 1, end);
        long count = mergeCount(data, start, mid, end);

        return (left_c + right_c + count) % 1000000007;
    }

    static long mergeCount(vector<int> &data, int start, int mid, int end)
    {
        vector<int> temp(end-start+1);
        temp.assign(data.begin() + start, data.begin() + end + 1);
        int left = 0, right = mid - start + 1, index = start;
        long count = 0;
        while (left < mid - start + 1 && right < end - start + 1)
        {
            if(temp[left] <= temp[right])
            {
                data[index++] = temp[left++];
            }
            else
            {
                data[index++] = temp[right++];
                count += (mid - start) - left + 1;
            }
        }
        while (left < mid - start + 1)
            data[index++] = temp[left++];
        while (right < end - start + 1)
            data[index++] = temp[right++];
        return count;
    }
};