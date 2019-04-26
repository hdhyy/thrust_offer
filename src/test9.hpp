#include <bits/stdc++.h>

using namespace std;
/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 
 **/
class Solution
{
public:
    int jumpFloorII(int number)
    {
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
            {
                int sum = 0;
                for(int j = 0; j < i; j++)
                {
                    sum += fibo[j];
                }
                fibo[i] = sum + 1;
            }
        }
        return fibo[number];
    }
};