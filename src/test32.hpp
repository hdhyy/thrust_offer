#include <bits/stdc++.h>
using namespace std;
/**
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 * 
 **/
class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string result;
        if(numbers.empty())
        {
            return result;
        }
        sort(numbers.begin(), numbers.end(), cmp);
        for (auto i : numbers)
        {
            result += to_string(i);
        }
        return result;
    }

    static bool cmp(int a, int b)
    {
        string a1 = to_string(a);
        string b1 = to_string(b);
        return (a1 + b1) < (b1 + a1);
    }
};