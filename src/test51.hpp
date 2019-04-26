#include <bits/stdc++.h>
using namespace std;
/**
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 **/
class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> result(A);
        if(A.empty())
            return result;
        result[0] = 1;
        for (unsigned i = 1; i < A.size(); i++)
        {
            result[i] = result[i - 1] * A[i - 1];
        }
        int temp = 1;
        for (int i = A.size()-2; i > -1; --i)
        {
            temp *= A[i + 1];
            result[i] *= temp;
        }
        return result;
    }
};