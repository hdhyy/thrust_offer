#include <bits/stdc++.h>
using namespace std;
/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return nullptr;
        auto pFast = pHead;
        auto pSlow = pHead;

        while(pFast != nullptr && pFast->next != nullptr)
        {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if(pFast == pSlow)
                break;
        }
        if (pFast != nullptr && pFast->next != nullptr)
        {
            pSlow = pHead;
            while(pSlow != pFast)
            {
                pSlow = pSlow->next;
                pFast = pFast->next;
            }
            return pSlow;
        }
        return nullptr;
    }
};
