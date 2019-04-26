#include <bits/stdc++.h>
using namespace std;
/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 **/

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr || *string == '\0')
            return false;
        return isNumeric(string, false, false);
    }

    bool isNumeric(char *string, bool e, bool p)
    {
        if (*string == '+' || *string == '-')
            string += 1;
        while (isNum(*string))
            ++string;
        if ((*string == 'e' || *string == 'E') && !e)
        {
            return isNumeric(string + 1, true, true);
        }
        else if (*string == '.' && !p)
        {
            return isNumeric(string + 1, false, true);
        }
        while (isNum(*string))
            ++string;
        if (*string == '\0' && *(string - 1) != 'e')
            return true;
        return false;
    }

    bool isNum(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        else
            return false;
    }

};