#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * 
 **/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        auto s_size = sequence.size();
        while(--s_size)
        {
            int i = 0;
            while(sequence[i++] < sequence[s_size]);
            while(sequence[i++] > sequence[s_size]);
            if(i < s_size)
                return false;
        }
        return true;
    }

    bool VerifySquenceOfBST2(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return judge(sequence, 0, sequence.size()-1);
    }

    bool judge(vector<int> sequence, int start, int end)
    {
        if(start >= end)
            return true;
        int i = end - 1;
        while(i > start && sequence[i] > sequence[end])
            i--;
        int j = start;
        while(j < i)
        {
            if(sequence[j] > sequence[end])
                return false;
            ++j;
        }
        return judge(sequence, start, i) && judge(sequence, i+1, end-1);
    }
};