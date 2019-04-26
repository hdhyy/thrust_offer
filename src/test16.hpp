#include <bits/stdc++.h>

using namespace std;

/**
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * 
 **/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        ListNode *temp;
        if(p1 == nullptr || p2 == nullptr)
            return p1 == nullptr ? p2 : p1;
        if(p1->val < p2->val)
        {
            temp = p1;
            p1 = p1->next;
        }
        else
        {
            temp = p2;
            p2 = p2->next;
        }
        auto head = temp;
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1->val < p2->val)
            {
                temp->next = p1;
                p1 = p1->next;
            }
            else
            {
                temp->next = p2;
                p2 = p2->next;
            }
            temp = temp->next;
        }
        if(p1 == nullptr)
            temp->next = p2;
        if(p2 == nullptr)
            temp->next = p1;
        return head;
    }
};