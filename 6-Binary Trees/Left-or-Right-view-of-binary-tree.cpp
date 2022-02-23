#include <bits/stdc++.h>
using namespace std;

/*
    Problem : Given a Binary tree print it's left (or right view).

    Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      / \
  4     5   6    7
    \
     8

    Problem Links :
    https://www.geeksforgeeks.org/print-left-view-binary-tree/
    https://leetcode.com/problems/binary-tree-right-side-view/
*/

class BFS // O(N) && S(Number of Nodes in a level of tree)
{
  public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};

        vector<int> view;

        queue<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = todo.front();
                todo.pop();
                /*
                    for Left view
                    if(i==0) view.push_back(node->val);
                */
                if (i == size - 1)
                    view.push_back(node->val);
                if (node->left)
                    todo.push(node->left);
                if (node->right)
                    todo.push(node->right);
            }
        }
        return view;
    }
};

class DFS // O(N) & S(LOGN)--S(N) recursive stack space
{
    // DFS solution : we will maintain a level and upon reaching a new level we will add desired value to our answer.
  public:
    // a recursive helper function.
    void Helper(TreeNode *root, vector<int> &v, int level)
    {
        if (!root) // base case.
            return;

        // as for every level we will have one node only so we will push the first node.
        if (v.size() == level)
            v.push_back(root->val);

        // we go deep right and add first node to our answer, similarly for the left we will go left first.
        Helper(root->right, v, level + 1);
        Helper(root->left, v, level + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> RightView;
        int level = 0;
        Helper(root, RightView, level);
        return RightView;
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
