#include <bits/stdc++.h>
using namespace std;
/**
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 * 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
 * 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 **/

class Solution
{
private:
    int moveC = 0;
    int r;
    int c;
    int th;
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows < 1 || cols < 1)
            return 0;
        r = rows, c = cols, th = threshold;
        vector<bool> visit(r * c, false);
        move(0, 0, visit);
        return moveC;
    }

    void move(int i, int j, vector<bool> &visit)
    {
        if (i >= r || i < 0 || j >= c || j < 0 || countK(i, j) > th || visit[i * c + j])
            return;
        ++moveC;
        visit[i * c + j] = true;
        move(i + 1, j, visit);
        move(i - 1, j, visit);
        move(i, j + 1, visit);
        move(i, j - 1, visit);
    }

    int countK(int i, int j)
    {
        int sum = 0;
        while(i != 0 || j != 0)
        {
            int x = i % 10;
            int y = j % 10;
            sum += x + y;
            i /= 10, j /= 10;
        }
        return sum;
    }
};