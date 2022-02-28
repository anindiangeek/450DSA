/*
Question Link: https://leetcode.com/problems/balanced-binary-tree/
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1


Approach: Calculate the height of right sub-tree and left sub-tree
          Then check if the left and right subtree are balanced or not and also if the current node is balanced or not
*/

class naiveSol // O(n^2) & S(1)
{

    int height(Node *root)
    {
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(Node *root)
    {
        if (!root)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;

        return 0;
    }
};

/*
Approach: In above solution calculation of height is adding adiotional complexity which we can reduce
As we know that height can never be negative so,
*/

class betterSol
{
    int balanced(Node *root)
    {
        if (!root)
            return 0;

        int lh = balanced(root->left);
        if (lh == -1)
            return -1;
        int rh = balanced(root->right);
         if (rh == -1)
            return -1;
      

        if (abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(Node *root)
    {
        return ((balanced(root) != -1) ? 1 : 0);
    }
}