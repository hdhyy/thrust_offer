#include <bits/stdc++.h>
using namespace std;
/**
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        queue<TreeNode *> quene1, quene2;
        TreeNode *node;
        quene1.push(pRoot);
        while (!quene1.empty() || !quene2.empty())
        {
            vector<int> data;
            if (!quene1.empty())
            {
                while (!quene1.empty())
                {
                    node = quene1.front();
                    data.push_back(node->val);
                    quene1.pop();
                    if (node->left != nullptr)
                        quene2.push(node->left);
                    if (node->right != nullptr)
                        quene2.push(node->right);
                }
                result.push_back(data);
            }
            else if (!quene2.empty())
            {
                while (!quene2.empty())
                {
                    node = quene2.front();
                    data.push_back(node->val);
                    quene2.pop();
                    if (node->left != nullptr)
                        quene1.push(node->left);
                    if (node->right != nullptr)
                        quene1.push(node->right);
                }
                result.push_back(data);
            }
        }
        return result;
    }
};