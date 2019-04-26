#include <bits/stdc++.h>
using namespace std;
/**
 * 输入两个链表，找出它们的第一个公共结点。
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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int len1 = 0, len2 = 0;
        auto np1 = pHead1, np2 = pHead2;
        if(np1 == nullptr || np2 == nullptr)
            return nullptr;
        while (np1 != nullptr)
        {
            np1 = np1->next;
            ++len1;
        }
        while (np2 != nullptr)
        {
            np2 = np2->next;
            ++len2;
        }
        int x = abs(len1 - len2);
        np1 = pHead1;
        np2 = pHead2;
        if(len1 > len2)
        {
            for (int i = 0; i < x; i++)
            {
                np1 = np1->next;
            }
            
        }
        else if(len1 < len2)
        {
            for (int i = 0; i < x; i++)
            {
                np2 = np2->next;
            }
        }
        while (np1 != np2 && np1 != nullptr && np2 != nullptr)
        {
            np1 = np1->next;
            np2 = np2->next;
        }
        return (np1 == nullptr || np2 == nullptr) ? nullptr : np1;
    }
};