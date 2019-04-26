#include <bits/stdc++.h>
using namespace std;
/**
 * 输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode *pRoot)
    {
        int deepMax = 0;
        dfs(pRoot, 1, deepMax);
        return deepMax;
    }

    void dfs(TreeNode *node, int deep, int &deepMax)
    {
        if(node == nullptr)
            return;
        if(node->left)
        {
            dfs(node->left, deep + 1, deepMax);
        }
        if(node->right)
        {
            dfs(node->right, deep + 1, deepMax);
        }
        if(deep > deepMax)
        {
            deepMax = deep;
        }
    }
};