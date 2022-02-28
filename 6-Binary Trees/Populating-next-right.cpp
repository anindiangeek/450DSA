#include <bits/stdc++.h>
using namespace std;

/*
    Problem : Given a binary tree, connect the nodes that are at same level.
              There is a extra pointer in the structre of tree that is a next node, make that next node point to it's
   proper place. "We are given a perfect binary tree and we need to populate next pointers in each node of the tree".
              the is not necessarily perfect is another question.

       10                       10 ------> NULL
      / \                     /     \
     3   5         =>       3 ------> 5 --------> NULL
    / \    \               /  \        \
   4   1   2              4 --> 1 -----> 2 -------> NULL

    Problem Links :
    * Note : There are two different questions 1 where given tree is perfect and other where it is not perfect.
    https://www.geeksforgeeks.org/connect-nodes-at-same-level/
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node   //  <---  Given Tree is perfect.
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/  // <-- Tree is not perfect.

    Explanation :
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/962162/C%2B%2B-Iterative-Constant-Space-Solution-Explained-~100-Time-~75-Space
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/962414/C%2B%2B-Recursion-and-Iteration-with-comments-and-figure-illustration
*/

class SpecialBFS // O(N) && S(1)
{
public:
    Node *connect(Node *root)
    {
        auto head = root;
        for (; root; root = root->left)
            // traverse each level - it's just BFS taking advantage of next pointers
            for (auto cur = root; cur; cur = cur->next)
                if (cur->left)
                {
                    // update next pointers of children if they exist
                    cur->left->next = cur->right;
                    if (cur->next)
                        cur->right->next = cur->next->left;
                }
                else
                    break; // if no children exist, stop iteration

        return head;
    }
};
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

class DFS // O(N) && S(height of binary tree)
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