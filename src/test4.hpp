#include <bits/stdc++.h>

using namespace std;
// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,
 * 3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 **/
class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
        {
            return nullptr;
        }
        else
        {
            return constructBinaryTree(pre, vin, 0, 0, vin.size() - 1);
        }
    }

    TreeNode *constructBinaryTree(vector<int> pre, vector<int> vin, int presta, int vinsta, int vinend)
    {
        if (vinsta > vinend)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(pre[presta]);
        for (int i = vinsta; i <= vinend; i++)
        {
            if (pre[presta] == vin[i])
            {
                root->left = constructBinaryTree(pre, vin, presta + 1, vinsta, i - 1);
                root->right = constructBinaryTree(pre, vin, presta + i - vinsta +1, i+1, vinend);
                break;
            }
        }
        return root;
    }
};