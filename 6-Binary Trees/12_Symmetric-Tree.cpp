/*
Question Link: https://leetcode.com/problems/symmetric-tree/
https://practice.geeksforgeeks.org/problems/symmetric-tree/1

Approach: Basic Solution would be that we take root->left child and right child and go on comparing them
But when calling the function recursively reverse the order
*/

class recSolution
{
    bool helper(Node *p, Node *q)
    {
        if (!p && !q)
        {
            return true;
        }
        else if (!p || !q)
        {
            return false;
        }

        if (p->data != q->data)
        {
            return false;
        }

        return helper(p->left, q->right) && helper(p->right, q->left);
    }

    bool isSymmetric(Node *root)
    {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
}

class iterativeSol
{
    bool isSymmetric(Node *root)
    {
        if (!root)
            return true;

        queue<Node *> q1, q2;

        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty())
        {
            Node *left = q1.front();
            q1.pop();

            Node *right = q2.front();
            q2.pop();
            if (!left && !right)
                continue;
            if (!left || !right)
                return false;

            if (left->data != right->data)
                return false;

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }

        return true;
    }
}