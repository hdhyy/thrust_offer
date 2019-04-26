#include <bits/stdc++.h>
using namespace std;

/**
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一
 * 二维数组和一个整数，判断数组中是否含有该整数。
 * 
 * tips:用二分法做更好
 **/
class Solution
{
  public:
    bool Find(int target, vector<vector<int>> array)
    {
        if (array.size() == 0)
        {
            return false;
        }
        decltype(array.size()) i = 0;
        int j = (int)array[0].size() - 1;
        while (i != array.size() && j != -1)
        {
            if (target > array[i][j])
            {
                i++;
            }
            else if (target < array[i][j])
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};