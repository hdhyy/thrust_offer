#include <bits/stdc++.h>
using namespace std;

/**
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表
 * head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * 
 **/


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        auto np = pHead;
        if(!np)
            return nullptr;
        while(np != nullptr)
        {
            RandomListNode *nnp = new RandomListNode(np->label);
            nnp->next = np->next;
            nnp->random = nullptr;

            np->next = nnp;
            np = nnp->next;
        }
        connectRandom(pHead);
        return reconnect(pHead);
    }

    void connectRandom(RandomListNode *pHead)
    {
        auto np = pHead;
        while(np != nullptr)
        {
            auto nnp = np->next;
            if(np->random)
                nnp->random = np->random->next;
            np = nnp->next;
        }
    }

    RandomListNode *reconnect(RandomListNode *pHead)
    {
        auto node = pHead;
        RandomListNode *nHead = nullptr, *nNode = nullptr;
        if(node != nullptr)
        {
            nHead = node->next;
            nNode = node->next;
            node->next = nNode->next;
            node = node->next;
        }

        while(node != nullptr)
        {
            nNode->next = node->next;
            nNode = nNode->next;

            node->next = nNode->next;
            node = node->next;
        }
        return nHead;
    }
};