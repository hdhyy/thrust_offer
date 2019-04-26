#include <bits/stdc++.h>
using namespace std;
/**
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 **/
/**
 * （1） 若该节点存在右子树：则下一个节点为右子树最左子节点
 * （2） 若该节点不存在右子树：这时分两种情况：
 * 2.1 该节点为父节点的左子节点，则下一个节点为其父节点
 * 2.2 该节点为父节点的右子节点，则沿着父节点向上遍历，知道找到一个节点的父节点的左子节点为该节点，
 * 则该节点的父节点下一个节点为所求，如节点I，沿着父节点一直向上查找找到B ，B为其父节点的左子节点，则 B 的父节点 A 为下一个节点。
 **/
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if(pNode == nullptr)
            return pNode;
        if(pNode->right != nullptr)
        {
            pNode = pNode->right;
            while(pNode->left != nullptr)
                pNode = pNode->left;
            return pNode;
        }
        if (pNode->next != nullptr && pNode->next->left == pNode)
            return pNode->next;
        if (pNode->next != nullptr && pNode->next->right == pNode)
        {
            while (pNode->next != nullptr && pNode->next->left != pNode)
                pNode = pNode->next;
            return pNode->next;
        }
        return pNode->next;
    }
};