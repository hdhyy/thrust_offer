#include <bits/stdc++.h>

using namespace std;

/**
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 **/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int space_c;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
            {
                space_c++;
            }
        }
        int add_c = space_c * 2;
        char *p1 = str + length -1;
        char *p2 = str + length + add_c - 1;
        int c = length;
        while(c--)
        {
            if (*p1 != ' ')
            {
                *p2 = *p1;
                p2--;
                p1--;
            }
            else
            {
                *p2 = '0';
                *(p2 - 1) = '2';
                *(p2 - 2) = '%';
                p2 -= 3;
                p1--;
            }
        }
	}
};