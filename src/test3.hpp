#include <bits/stdc++.h>

using namespace std;
/**
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 **/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};
class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> result;
        //需要判断head未NULL的情况
        while(head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};