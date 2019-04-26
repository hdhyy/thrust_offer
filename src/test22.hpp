#include <bits/stdc++.h>

using namespace std;

/**
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        queue<TreeNode*> printTree;
        printTree.push(root);
        vector<int> result;
        while(!printTree.empty())
        {
            TreeNode* node = printTree.front();
            result.push_back(node->val);
            if(node->left != nullptr)
                printTree.push(node->left);
            if(node->right != nullptr)
                printTree.push(node->right);
            printTree.pop();
        }
        return result;
    }
};