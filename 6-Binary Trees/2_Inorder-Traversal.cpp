#include <bits/stdc++.h>
using namespace std;
/*
Question Links:
Inorder: https://practice.geeksforgeeks.org/problems/inorder-traversal/1
         https://leetcode.com/problems/binary-tree-inorder-traversal/

Preorder: https://practice.geeksforgeeks.org/problems/preorder-traversal/1#
          https://leetcode.com/problems/binary-tree-preorder-traversal/

Postorder: https://practice.geeksforgeeks.org/problems/postorder-traversal/1
           https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
*/

/*
In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order.
To get nodes of BST in non-increasing order
*/

class inorder
{
    vector<int> v;
    vector<int> inorder(Node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            v.push_back(root->data);
            inOrder(root->right);
        }
        return v;
    }
}

/*
Preorder traversal is used to create a copy of the tree.
Preorder traversal is also used to get prefix expression on an expression tree.
Please see http://en.wikipedia.org/wiki/Polish_notation know why prefix expressions are useful.
*/

class preorder
{
    vector<int> v;
    vector<int> preorder(Node *root)
    {
        if (root)
        {
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return v;
    }
}

/*
Postorder traversal is used to delete the tree.
Please see the question for the deletion of a tree for details.
Postorder traversal is also useful to get the postfix expression of an expression tree.
Please see http://en.wikipedia.org/wiki/Reverse_Polish_notation for the usage of postfix expression.
*/

class postorder
{
    vector<int> v;
    vector<int> postorder(Node *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            v.push_back(root->data);
        }
        return v;
    }
}