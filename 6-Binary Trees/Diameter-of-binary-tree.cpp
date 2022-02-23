/*

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;

  public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int LeftHeight = height(root->left);
        int RightHeight = height(root->right);

        ans = max(ans, LeftHeight + RightHeight);

        return 1 + max(LeftHeight, RightHeight);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return ans;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};