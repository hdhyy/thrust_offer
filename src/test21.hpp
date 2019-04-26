#include <bits/stdc++.h>

using namespace std;

/**
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4
 * 5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度
 * 相等的）
 * 
 **/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;
        auto v_size = pushV.size();
        decltype(v_size) ipush = 0, ipop = 0;
        vector<int> v_stack;
        for (; ipush < v_size; ipush++)
        {
            v_stack.push_back(pushV[ipush]);
            while(!v_stack.empty() && v_stack.back() == popV[ipop])
            {
                v_stack.pop_back();
                ipop++;
            }
        }
        return v_stack.empty();
    }

    bool IsPopOrder2(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;
        auto v_size = pushV.size();
        decltype(v_size) ipush = 0, ipop = 0;
        vector<int> v_stack;
        while (ipush < v_size && ipop < v_size)
        {
            if(pushV[ipush] == popV[ipop])
            {
                ipush++;
                ipop++;
                while(!v_stack.empty() && v_stack.back() == popV[ipop])
                {
                    v_stack.pop_back();
                    ipop++;
                }
            }
            else
            {
                v_stack.push_back(pushV[ipush]);
                ipush++;
            }
        }
        return v_stack.empty();
    }
};