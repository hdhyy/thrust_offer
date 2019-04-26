#include <bits/stdc++.h>
using namespace std;

/**
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * 
 **/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *lastNodeInList = nullptr;
        recursion(pRootOfTree, lastNodeInList);

        while (pRootOfTree != nullptr && pRootOfTree->left != nullptr)
        {
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }

    void recursion(TreeNode *node, TreeNode *&lastNodeInList)
    {
        if(node == nullptr)
        {
            return;
        }
        TreeNode *currentNode = node;
        if(currentNode->left != nullptr)
        {
            recursion(currentNode->left, lastNodeInList);
        }
        currentNode->left = lastNodeInList;
        if(lastNodeInList != nullptr)
        {
            lastNodeInList->right = currentNode;
        }
        lastNodeInList = currentNode;
        if (currentNode->right != nullptr)
        {
            recursion(currentNode->right, lastNodeInList);
        }
    }
};