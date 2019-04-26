#include <bits/stdc++.h>
using namespace std;
/**
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
    bool isSymmetrical(TreeNode *pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }

    bool isSymmetrical(TreeNode *pLeft, TreeNode *pRight)
    {
        if (pLeft == nullptr && pRight == nullptr)
            return true;
        if (pLeft == nullptr || pRight == nullptr)
            return false;
        if(pLeft->val != pRight->val)
            return false;
        return isSymmetrical(pLeft->left, pRight->right) && isSymmetrical(pLeft->right, pRight->left);
    }
};