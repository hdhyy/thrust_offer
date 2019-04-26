#include <bits/stdc++.h>
using namespace std;
/**
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
 * 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
 * 那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 **/

class Solution
{
private:
    map<int, int> dics;
    int n_size = 0;
public:
    void Insert(int num)
    {
        ++n_size;
        auto it = dics.find(num);
        if(it != dics.end())
            ++dics[num];
        else
            dics[num] = 1;
    }

    double GetMedian()
    {
        bool b = (n_size%2 == 0) ? true : false;
        int half = (n_size + 1) >> 1;
        int sum = 0;
        double median = 0.0;
        for (auto it = dics.begin(); it != dics.end(); ++it)
        {
            sum += it->second;
            if(!b && sum >= half)
            {
                median = it->first;
                break;
            }
            else if (b && sum >= half)
            {
                if(sum > half)
                {
                    median = it->first;
                }
                else
                {
                    double a1 = it->first, a2 = (++it)->first;
                    median = (a1 + a2) / 2;
                }
                break;
            }
        }
        return median;
    }
};