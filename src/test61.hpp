#include <bits/stdc++.h>
using namespace std;
/**
 * 请实现两个函数，分别用来序列化和反序列化二叉树
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
private:
    vector<int> tree;

public:
    void dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            tree.push_back(INT_MAX);
            return;
        }
        tree.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    TreeNode *ds(int *&str)
    {
        if(*str == INT_MAX)
        {
            ++str;
            return nullptr;
        }
        TreeNode *node = new TreeNode(*str);
        ++str;
        node->left = ds(str);
        node->right = ds(str);
        return node;
    }
    char *Serialize(TreeNode *root)
    {
        dfs(root);
        if(tree.empty())
            return nullptr;
        else
        {
            int *p = &tree[0];
            return (char *)p;
        }
    }
    TreeNode *Deserialize(char *str)
    {
        int *t = (int *)str;
        return ds(t);
    }
};