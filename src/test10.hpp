#include <bits/stdc++.h>

using namespace std;
/**
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 第一种是最后是由一个2*(n-1)的矩形加上一个竖着的2*1的矩形
 * 另一种是由一个2*(n-2)的矩形，加上两个横着的2*1的矩形
 * 因此我们可以得出，
 * 第2*n个矩形的覆盖方法等于第2*(n-1)加上第2*(n-2)的方法。
 **/
class Solution
{
public:
    int rectCover(int number)
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
                fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        return fibo[number];
    }
};