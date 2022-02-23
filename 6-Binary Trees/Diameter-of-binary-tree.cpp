#include <bits/stdc++.h>
using namespace std;
/*
    Problem : Given the root of a binary tree, return the length of the diameter of the tree.
              The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path
   may or may not pass through the root.

    Problem Links : https://leetcode.com/problems/diameter-of-binary-tree/
                    https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/

    Intution :
    leaf node in the extreme left below and extreme right below will have to travel the maximum to reach each
    other, so they will be farthest from each other.

*/

class OptimisedSolution // O(N) & S(H) recursive call stack.
{
    /*
     * we can get the diameter while getting the height of nodes nodes only.
     * to avoid using a global variable answer we can pass it through function
     */
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

class Bruteforce // O(N^2) && S(Height)
{
  public:
    int height(struct TreeNode *root)
    {
        // base case tree is empty
        if (root == NULL)
            return 0;

        // If tree is not empty then height = 1 + max of left
        // height and right heights
        return 1 + max(height(root->left), height(root->right));
    }
    int diameter(struct TreeNode *tree)
    {
        // base case where tree is empty
        if (tree == NULL)
            return 0;

        // get the height of left and right sub-trees
        int lheight = height(tree->left);
        int rheight = height(tree->right);

        // get the diameter of left and right sub-trees
        int ldiameter = diameter(tree->left);
        int rdiameter = diameter(tree->right);

        // Return max of following three
        // 1) Diameter of left subtree
        // 2) Diameter of right subtree
        // 3) Height of left subtree + height of right subtree + 1
        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
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