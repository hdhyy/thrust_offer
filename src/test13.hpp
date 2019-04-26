#include <bits/stdc++.h>
using namespace std;

/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数
 * 数，偶数和偶数之间的相对位置不变。
 * 
 **/
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int a_size = array.size();
        int even_c = 0;
        for(auto item : array)
        {
            if(item % 2 == 0)
                even_c++;
        }
        for (int i = 0; i < even_c; i++)
        {
            for (int j = 0; j < a_size - 1;j++)
            {
                if (array[j] % 2 == 0 && array[j + 1] % 2 != 0)
                {
                    swap(array, j, j + 1);
                }
            }
        }
        
    }
    void swap(vector<int> &array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
};