#include <bits/stdc++.h>
using namespace std;

/*
    Problem : Given a binary tree, connect the nodes that are at same level.

       10                       10 ------> NULL
      / \                     /     \
     3   5         =>       3 ------> 5 --------> NULL
    / \    \               /  \        \
   4   1   2              4 --> 1 -----> 2 -------> NULL

    Problem Links :
    https://www.geeksforgeeks.org/connect-nodes-at-same-level/
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node
*/

class BFS // O(N) && S(Width of the tree)
{
    // in this method we transverse the tree using level order traversal from right to left
    // using the pointer to the previous element (i.e. next right) we go-on linking the tree nodes
    // we iterate from right to left so that we can mark the next of edge node as NULL first
  public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *nextRight = NULL;
            int n = q.size();
            while (n--)
            {
                Node *curr = q.front();
                q.pop();
                curr->next = nextRight;
                nextRight = curr;

                if (curr->right)
                    q.push(curr->right);
                if (curr->left)
                    q.push(curr->left);
            }
        }
        return root;
    }
};

class DFS // O(N) && S(logN)
{
    // in this method we transverse the tree using pre order traversal recursively
    // connecting the links to the child nodes at each level
    // first we connect the left child next to right, then
  public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        if (root->right)
        {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);

        return root;
    }
};

class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next)
    {
    }
};