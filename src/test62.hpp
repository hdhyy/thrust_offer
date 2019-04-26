#include <bits/stdc++.h>
using namespace std;
/**
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如，(5，3，7，2，4，6，8)中，按结点数值大小顺序第三小结点的值为4。
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
    TreeNode *ans = nullptr;
    int cnt = 0;

public:
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if(pRoot == nullptr || k < 1)
            return nullptr;
        if(pRoot->left != nullptr)
            KthNode(pRoot->left, k);
        ++cnt;
        if(cnt == k)
            ans = pRoot;
        else if(cnt < k)
            KthNode(pRoot->right, k);
        return ans;
    }
};