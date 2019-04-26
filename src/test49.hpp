#include <bits/stdc++.h>
using namespace std;
/**
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
 * 但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
 * 数值为0或者字符串不是一个合法的数值则返回0。
 **/
/**
 * 输入一个字符串,包括数字字母符号,可以为空
 * 如果是合法的数值表达则返回该数字，否则返回0
 * in
 * +2147483647
 * 1a33
 * out
 * 2147483647
 * 0
 **/
/**
 * （1）考虑输入的字符串是否是NULL、空字符串
 * （2）考虑输入的字符串是否包含正负号或者是否是只包含正负号
 * （3）考虑输入的字符串是否会发生上溢或下溢（正整数的最大值是0x7FFFFFFF，最小的负整数是0x80000000）
 * （4）考虑如何区分正常返回数字0和返回输入是否合法的标识
 **/
struct ConvertResult
{
    int valid;
    int number;
    bool minus;
};

class Solution
{
public:
    int StrToInt(string str)
    {
        if(str.empty())
            return 0;
        ConvertResult result{0, 0, false};
        int start = 0;
        if(str[start] == '+')
            ++start;
        else if (str[start] == '-')
        {
            ++start;
            result.minus = true;
        }
        if(start != str.size())
        {
            StrToIntCore(str, result, start);
        }
        return result.number;
    }

    void StrToIntCore(string str, ConvertResult &result, int index)
    {
        long num = 0;
        while(index < str.size())
        {
            if (str[index] >= '0' && str[index] <= '9')
            {
                int flag = result.minus ? -1 : 1;
                num = num * 10 + flag * (str[index] - '0');
                if ((flag == 1 && num > INT_MAX) || (flag == -1 && num < INT_MIN))
                {
                    num = 0;
                    break;
                }
            }
            else
            {
                num = 0;
                break;
            }
            index++;
        }
        if (index == str.size())
        {
            result.valid = 1;
            result.number = (int)num;
        }
    }
};