#include <bits/stdc++.h>
using namespace std;

/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 **/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        auto n_size = numbers.size();
        if (n_size == 0)
            return 0;
        int num = 0, c = 0;
        for (unsigned i = 0; i < n_size; i++)
        {
            if(c == 0)
            {
                num = numbers[i];
                c = 1;
            }
            else
            {
                if (numbers[i] == num)
                    ++c;
                else
                    --c;
            }
        }
        unsigned count = 0;
        for(auto n : numbers)
        {
            if(n == num)
                ++count;
        }
        if(count > (n_size)>>1)
            return num;
        else
            return 0;
    }
};