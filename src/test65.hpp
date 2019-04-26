#include <bits/stdc++.h>
using namespace std;
/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
 * 例如 
 * a b c e 
 * s f c s 
 * a d e e 
 * 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
 * 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 **/

class Solution
{
private:
    int r;
    int c;
public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == nullptr || str == nullptr || *str == '\0')
            return false;
        r = rows, c = cols;
        vector<bool> visied(rows * cols, false);
        int i = 0, j = 0;
        while(i != r)
        {
            if (hasPathCore(visied, matrix, str, i, j))
                return true;
            if(++j == c)
            {
                i += 1, j = 0;
            }
        }
        return false;
    }

    bool hasPathCore(vector<bool> visied, char *matrix, char *str, int i, int j)
    {
        if(*str == '\0')
            return true;
        if (i >= r || i < 0 || j >= c || j < 0 || visied[i * c + j])
            return false;
        if (*(matrix + i * c + j) == *str)
        {
            visied[i * c + j] = true;
            bool bottom = hasPathCore(visied, matrix, str + 1, i + 1, j);
            bool top = hasPathCore(visied, matrix, str + 1, i - 1, j);
            bool left = hasPathCore(visied, matrix, str + 1, i, j - 1);
            bool right = hasPathCore(visied, matrix, str + 1, i, j + 1);
            if(left || right || top || bottom)
                return true;
        }
        return false;
    }
};