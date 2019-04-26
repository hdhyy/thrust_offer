#include <bits/stdc++.h>

using namespace std;

/**
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结
 * 形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result, temp;
		if(!root)
			return result;
		int top = 0, len = 0;
		vector<int> t;
		temp.push_back(t);
		dfs(root, temp, top, len);
		for(auto i : temp)
		{
			if (sum(i) == expectNumber)
				result.push_back(i);
		}
		sort(result.begin(), result.end(), cmp);
		return result;
	}

	int sum(vector<int> &t)
	{
		int s = 0;
		for(auto i : t)
		{
			s += i;
		}
		return s;
	}

	void dfs(TreeNode *node, vector<vector<int>> &temp, int &top, int &len)
	{
		temp[len].push_back(node->val);
		if(node->left)
		{
			dfs(node->left, temp, ++top, len);
			if(node->right)
			{
				vector<int> t;
				t.assign(temp[len].begin(), temp[len].begin() + top + 1);
				temp.push_back(t);
				dfs(node->right, temp, ++top, ++len);
			}
		}
		else if(node->right)
		{
			dfs(node->right, temp, ++top, len);
		}
		--top;
	}

	static bool cmp(vector<int> &v1, vector<int> &v2)
	{
		return v1.size() > v2.size();
	}
};