/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class leetCodeSolution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        ans.push_back({root->val});
        while (!q.empty())
        {
            vector<int> level;
            TreeNode *levelnodes;
            int nodestoprocess = q.size();
            while (nodestoprocess--)
            {

                levelnodes = q.front();
                if (levelnodes->left)
                {
                    level.push_back(levelnodes->left->val);
                    q.push(levelnodes->left);
                }
                if (levelnodes->right)
                {
                    level.push_back(levelnodes->right->val);
                    q.push(levelnodes->right);
                }
                q.pop();
            }

            if (level.size())
                ans.push_back(level);
        }

        return ans;
    }
};