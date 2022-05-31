/*
Question Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1
https://leetcode.com/problems/validate-binary-search-tree/
*/

// Approach: In Recursive method, we Take one variable which stores the maximum value int the tree
//  Then we just keep on checking all the trees recursively
// We follow inorder traversal to make it easy

#include <bits/stdc++.h>
using namespace std;
class recSolution
{
    int last = INT_MIN;
    bool isBST(Node *root)
    {
        if (!root)
            return 1;

        if (!isBST(root->left))
            return 0;

        if (last >= root->data)
            return 0;
        last = root->data;

        return (isBST(root->right));
    }
};

/*
We will use iterative inorder traversal and rest is the same
*/

class iterativeSol
{
    bool isBST(Node *root)
    {
        if (!root)
            return 1;

        stack<Node *> s;

        Node *last = nullptr;
        while (root != nullptr || !s.empty())
        {
            while (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            if (last != nullptr && root->data <= last->data)
                return false;

            last = root;
            root = root->right;
        }
        return true;
    }
}