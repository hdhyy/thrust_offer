#include <bits/stdc++.h>

using namespace std;

/**
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 * 
 **/

class Solution {
private:
    vector<int> stack;
    vector<int> assit;
public:
    void push(int value) {
        stack.push_back(value);
        if(assit.empty() || value <= assit.back())
            assit.push_back(value);
    }
    void pop() {
        if(assit.back() == stack.back())
        {
            stack.pop_back();
            assit.pop_back();
        }
        else
        {
            stack.pop_back();
        }
    }
    int top() {
        if(stack.empty())
            return -1;
        else
            return stack.back();
    }
    int min() {
        if(assit.empty())
            return -1;
        else
            return assit.back();
    }
};