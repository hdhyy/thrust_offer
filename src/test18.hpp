#include <bits/stdc++.h>

using namespace std;

/**
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 
 * 二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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
    void Mirror(TreeNode *pRoot)
    {
        if(pRoot == nullptr)
            return;
        swap(pRoot);
        if (pRoot->left != nullptr)
        {
            Mirror(pRoot->left);
        }
        if (pRoot->right != nullptr)
        {
            Mirror(pRoot->right);
        }
    }

    void swap(TreeNode *node)
    {
        if(node != nullptr)
        {
            auto temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
};