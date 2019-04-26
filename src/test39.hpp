#include <bits/stdc++.h>
using namespace std;
/**
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 
 **/
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        int deep = balance(pRoot, pRoot);
        return deep == -1 ? false : true;
    }

    int balance(TreeNode *node, TreeNode *head)
    {
        if(node == nullptr)
            return 0;
        int left = balance(node->left, head);
        int right = balance(node->right, head);

        int x = abs(left - right);
        if(x > 1 && node == head)
            return -1;
        return left > right ? left + 1 : right + 1;
    }
};