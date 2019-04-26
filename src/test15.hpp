#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一个链表，反转链表后，输出新链表的表头。
 * 
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
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *p1 = pHead;
        ListNode *p2 = p1;
        ListNode *p3;
        if (p1 == nullptr)
            return nullptr;
        p2 = p1->next;
        if (p2 == nullptr)
            return p1;
        p3 = p2->next;
        p1->next = nullptr;
        while(p3 != nullptr)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};