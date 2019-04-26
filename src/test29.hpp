#include <bits/stdc++.h>
using namespace std;

/**
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 **/

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        multimap<int, int> leasts;
        vector<int> result;
        if (k < 1 || input.size() < (unsigned)k)
        {
            return result;
        }
        for (unsigned i = 0; i < input.size(); i++)
        {
            int num = input[i];
            if(leasts.size() < (unsigned)k)
            {
                leasts.insert(pair<int, int>(num, num));
            }
            else
            {
                auto iend = leasts.end();
                int great = (--iend)->second;
                if(num < great)
                {
                    leasts.erase(iend);
                    leasts.insert(pair<int, int>(num, num));
                }
            }
        }
        for (auto ibegin = leasts.begin(); ibegin != leasts.end(); ++ibegin)
        {
            result.push_back(ibegin->second);
        }
        return result;
    }
};