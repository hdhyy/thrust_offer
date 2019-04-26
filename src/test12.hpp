#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 **/
class Solution
{
public:
    double Power(double base, int exponent)
    {
        static bool invalidInput = false;
        if(Equals(base, 0.0) && exponent < 0)
        {
            invalidInput = true;
            return 0.0;
        }
        int absExponent = abs(exponent);

        double result = PowerWithUint(base, absExponent);
        if(exponent < 0)
        {
            result = 1.0 / result;
        }
        return result;
    }

    double PowerWithUint(double base, int absExponent)
    {
        double result = 1.0;
        for (int i = 1; i <= absExponent; i++)
        {
            result *= base;
        }
        return result;
    }
private:
    bool Equals(double n1, double n2)
    {
        if (n1 - n2 > -0.0000001 && n1 - n2 < 0.0000001)
            return true;
        else
            return false;
    }
};