#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *p1 = pListHead;
        if(p1 == nullptr)
            return nullptr;
        for (int i = 0; i < k-1; i++)
        {
            p1 = p1->next;
            if(p1 == nullptr)
                return nullptr;
        }
        ListNode *p2 = pListHead;
        for (; p1->next != nullptr;)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};