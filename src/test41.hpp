#include <bits/stdc++.h>
using namespace std;
/**
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
 * 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
 * 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 * 
 **/

class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> result;
        for (int i = 2; i < (int)sqrt(2 * sum) + 1; i++)
        {
            if ((i % 2 == 0 && sum % i == i / 2) || (i % 2 == 1 && sum % i == 0))
            {
                int start = (i % 2 == 0) ? (sum / i - i / 2 + 1) : (sum / i - i / 2);
                vector<int> temp(i);
                for (int j = 0; j < i; j++)
                {
                    temp[j] = start + j;
                }
                result.push_back(temp);
            }
        }
        sort(result.begin(), result.end(), cmp);
        return result;
    }

    static bool cmp(vector<int> v1, vector<int> v2)
    {
        return v1[0] < v2[0];
    }
};