#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 * 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 
 **/

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> result;
        auto rows = matrix.size();
        while(rows != 0)
        {
            auto v = matrix.front();
            result.insert(result.end(), v.begin(), v.end());
            if(rows == 1)
                break;
            matrix.erase(matrix.begin());
            matrix = turnMatrix(matrix);
            rows = matrix.size();
        }
        return result;
    }

    vector<vector<int>> turnMatrix(vector<vector<int>> matrix)
    {
        auto rows = matrix.size();
        auto cols = matrix[0].size();
        if(rows == 1)
        {
            reverse(matrix[0].begin(), matrix[0].end());
            return matrix;
        }
        vector<vector<int>> reverseM;
        for(decltype(rows) j = 0; j < cols; ++j)
        {
            vector<int> temp;
            for (decltype(rows) i = 0; i < rows; ++i)
            {
                temp.push_back(matrix[i][j]);
            }
            reverseM.push_back(temp);
        }
        reverse(reverseM.begin(), reverseM.end());
        return reverseM;
    }
};