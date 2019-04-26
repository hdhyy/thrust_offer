#include <bits/stdc++.h>

using namespace std;

/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
 **/
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> fibo(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            if(i == 0)
                fibo[i] = 0;
            else if(i == 1)
                fibo[i] = 1;
            else
                fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        return fibo[n];
    }
};