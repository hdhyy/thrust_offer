#include <bits/stdc++.h>
using namespace std;
/**
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 **/
/**
 * 利用递归的思路，运用短路求值原理作为递归结束的条件。
 * 短路求值：
 * 作为"&&"和"||"操作符的操作数表达式，这些表达式在进行求值时，
 * 只要最终的结果已经可以确定是真或假，求值过程便告终止，这称之为短路求值（short-circuit evaluation）。
 * 假如expr1和expr2都是表达式，并且expr1的值为0，在下面这个逻辑表达式的求值过程中：
 * expr1 && expr2
 * expr2将不会进行求值，因为整个逻辑表达式的值已经可以确定为0。
 * 类似地，如果expr1的值不是0，那么在下面的这个逻辑表达式的求值过程中：
 * expr1 || expr2
 * expr2将不会进行求值，因为整个逻辑表达式的值已经确定为1。
 **/
class Solution
{
public:
    int Sum_Solution(int n)
    {
        int sum = n;
        bool b = (n == 0) || (sum += Sum_Solution(n - 1)) > 0;
        return sum;
    }
};