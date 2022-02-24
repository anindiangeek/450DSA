/*
Question Links:
https://practice.geeksforgeeks.org/problems/level-order-traversal/1/
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

// Using queue to store the elements and then storing them in another vector
// level which stores all the elements of a level
class BFS
{
    vector<vector<int>> levelorder(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans;

        queue<Node *> q;

        q.push(root);
        ans.push_back({root});

        while (!q.empty())
        {
            vector<int> level;
            int Nodestoprocess = q.size();

            while (Nodestoprocess--)
            {
                Nodes *levelnode = q.front();

                if (levelnode->left)
                {
                    q.push(levelnode->left);
                    level.push_back(levelnode->left->data);
                }

                if (levelnode->right)
                {
                    q.push(levelnode->right);
                    level.push_back(levelnode->right->data);
                }

                q.pop();
            }

            if (level.size())
                ans.push_back(level);
        }

        return ans;
    }
}

// O(n^2)
// We are going to each and every level one by one and then storing their children
class recursiveApproach
{
public:
    vector<int> ans;
    void printlevelorder(node *root, int level)
    {
        if (level == 0)
            return;
        if (level == 1)
            ans.push_back(root->data);
        else
        {
            printlevelorder(root->left, level - 1);
            printlevelorder(root->right, level - 1);
        }
    }
    vector<int> levelorder(node *root)
    {
        int h = height(root);
        for (int i = 1; i <= h; i++)
            printlevelorder(root, i);
        return ans;
    }
}
