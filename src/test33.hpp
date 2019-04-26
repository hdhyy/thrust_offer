#include <bits/stdc++.h>
using namespace std;
/**
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。
 * 求按从小到大的顺序的第N个丑数。
 * 
 **/
class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if(index <= 0)
            return 0;
        vector<int> uglyNums(index, 0);
        uglyNums[0] = 1;
        int next = 1;
        int mul2 = 0, mul3 = 0, mul5 = 0;
        for (;next < index;)
        {
            int minNum = getMin(uglyNums[mul2] * 2, uglyNums[mul3] * 3, uglyNums[mul5] * 5);
            uglyNums[next] = minNum;
            if (uglyNums[mul2] * 2 <= minNum)
                ++mul2;
            if (uglyNums[mul3] * 3 <= minNum)
                ++mul3;
            if (uglyNums[mul5] * 5 <= minNum)
                ++mul5;
            ++next;
        }
        return uglyNums[index-1];
    }

    int getMin(int a, int b, int c)
    {
        int m = min(a, b);
        int r = min(m, c);
        return r;
    }
};