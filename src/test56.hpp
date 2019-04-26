#include <bits/stdc++.h>
using namespace std;
/**
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
 * 重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 **/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *dummy = new ListNode(INT_MAX);
        dummy->next = pHead;
        ListNode *pre = dummy;
        auto p = pHead;
        while(p != nullptr)
        {
            if(p->next != nullptr && p->next->val == p->val)
            {
                while (p->next != nullptr && p->next->val == p->val)
                    p = p->next;
            }
            else
            {
                pre->next = p;
                pre = p;
            }
            p = p->next;
        }
        pre->next = p;
        return dummy->next;
    }
};