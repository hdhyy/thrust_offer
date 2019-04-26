#include <bits/stdc++.h>

using namespace std;
/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * 
 **/
class Solution
{
public:
    int jumpFloor(int number)
    {
        // if(number == 0)
        //     return 0;
        // else if(number == 1)
        //     return 1;
        // else if(number == 2)
        //     return 2;
        // else
        // {
        //     return jumpFloor(number - 1) + jumpFloor(number - 2);
        // }
        vector<int> fibo(number + 1, 0);
        for (int i = 0; i <= number; i++)
        {
            if (i == 0)
                fibo[i] = 0;
            else if (i == 1)
                fibo[i] = 1;
            else if (i == 2)
                fibo[i] = 2;
            else
                fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        return fibo[number];
    }
};