#include <bits/stdc++.h>
using namespace std;
/**
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 * 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
 * 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 * 
 **/
class Solution
{
public:
    string ReverseSentence(string str)
    {
        auto s_size = str.size();
        Reverse(str, 0, s_size - 1);
        int start = 0;
        int end = 0;
        for (int i = 0; i < s_size; i++)
        {
            if(str[i] == ' ')
            {
                end = i - 1;
                Reverse(str, start, end);
                start = i + 1;
            }
        }
        Reverse(str, start, s_size - 1);
        return str;
    }

    void Reverse(string &str, int start, int end)
    {
        if (str.empty() || start < 0 || end > str.size() - 1)
            return;
        while (start < end)
        {
            char tmp = str[end];
            str[end] = str[start];
            str[start] = tmp;

            start++;
            end--;
        }
    }
};