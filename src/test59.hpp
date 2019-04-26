#include <bits/stdc++.h>
using namespace std;
/**
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> result;
        if (pRoot == nullptr)
            return result;
        stack<TreeNode *> stack1, stack2;
        TreeNode *node;
        stack1.push(pRoot);
        while(!stack1.empty() || !stack2.empty())
        {
            vector<int> data;
            if (!stack1.empty())
            {
                while (!stack1.empty())
                {
                    node = stack1.top();
                    data.push_back(node->val);
                    stack1.pop();
                    if (node->left != nullptr)
                        stack2.push(node->left);
                    if (node->right != nullptr)
                        stack2.push(node->right);
                }
                result.push_back(data);
            }
            else if (!stack2.empty())
            {
                while (!stack2.empty())
                {
                    node = stack2.top();
                    data.push_back(node->val);
                    stack2.pop();
                    if (node->right != nullptr)
                        stack1.push(node->right);
                    if (node->left != nullptr)
                        stack1.push(node->left);
                }
                result.push_back(data);
            }
        }
        return result;
    }
};